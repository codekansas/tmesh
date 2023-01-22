#include "boolean.h"

#include <algorithm>
#include <iostream>

#include "bvh.h"

#define TOLERANCE 1e-6

using namespace pybind11::literals;

namespace trimesh {

enum boolean_2d_op { UNION, INTERSECTION, DIFFERENCE };

trimesh_2d_t triangulation(const triangle_2d_t &triangle,
                           const std::vector<point_2d_t> &points) {
    std::vector<point_2d_t> vertices;
    face_set_t faces;

    // Checks that all points are inside the triangle.
    for (auto &point : points) {
        if (!triangle.contains(point))
            throw std::runtime_error("Point " + point.to_string() +
                                     " is not inside triangle " +
                                     triangle.to_string() + ".");
    }

    // Adds vertices to mesh.
    for (auto &point : triangle.vertices()) vertices.push_back(point);
    for (auto &point : points) vertices.push_back(point);

    // Adds super triangle to mesh.
    faces.insert(face_t(0, 1, 2));

    for (size_t i = 0; i < points.size(); i++) {
        auto &point = points[i];

        // Gets the triangle that contains the point.
        bool found_triangle = false;
        for (auto &face : faces) {
            auto &[a, b, c] = face;
            triangle_2d_t triangle{vertices[a], vertices[b], vertices[c]};
            if (point.is_inside_triangle(triangle)) {
                faces.insert(face_t(a, b, i + 3));
                faces.insert(face_t(b, c, i + 3));
                faces.insert(face_t(c, a, i + 3));
                faces.erase(face);
                found_triangle = true;
                break;
            }
        }
        if (!found_triangle) {
            throw std::runtime_error("Point " + point.to_string() +
                                     " was outside of the triangle " +
                                     triangle.to_string());
        }
    }

    return {vertices, faces};
}

trimesh_2d_t split_at_all_intersections(const trimesh_2d_t &a_mesh,
                                        const trimesh_2d_t &b_mesh) {
    std::vector<point_2d_t> vertices = a_mesh.vertices();

    // Keeps track of the faces that have been split.
    std::vector<triangle_split_tree_2d_t> a_trees;
    for (auto &a_face : a_mesh.faces()) {
        a_trees.push_back({a_face, vertices});
    }

    // Checks each triangle in B against each triangle in A.
    // This could be made more efficient by indexing the vertices of B to
    // efficiently find the vertices which intersect a triangle in A.
    for (size_t a_face_id = 0; a_face_id < a_mesh.faces().size(); a_face_id++) {
        auto &a_tree = a_trees[a_face_id];

        for (size_t b_face_id = 0; b_face_id < b_mesh.faces().size();
             b_face_id++) {
            auto &b_face = b_mesh.faces()[b_face_id];
            auto &[b_a, b_b, b_c] = b_face;
            auto &b_tri = b_mesh.get_triangle(b_face);

            // Splits triangles at vertices.
            for (auto &b_id : {b_a, b_b, b_c}) {
                for (auto &t_id : a_tree.get_leaf_triangles_which_intersect(
                         b_mesh.vertices()[b_id])) {
                    a_tree.split_triangle(b_mesh.vertices()[b_id], t_id);
                }
            }

            // Splits triangles at edges.
            for (auto &[b_id_a, b_id_b] : b_face.get_edges()) {
                line_2d_t b_edge{b_mesh.vertices()[b_id_a],
                                 b_mesh.vertices()[b_id_b]};
                for (auto &t_id :
                     a_tree.get_leaf_triangles_which_intersect(b_edge)) {
                    a_tree.split_triangle(b_edge, t_id);
                }
            }
        }
    }

    // Adds all faces from the split trees to the new mesh.
    face_set_t faces;
    for (auto &a_tree : a_trees) {
        size_t offset = vertices.size();
        auto a_vertices = a_tree.get_vertices();
        vertices.insert(vertices.end(), a_vertices.begin(), a_vertices.end());
        for (auto &face : a_tree.get_leaf_faces(offset)) {
            faces.insert(face);
        }
    }

    // Removes any unused vertices and remaps the faces.
    std::unordered_map<size_t, size_t> vertex_id_map;
    for (auto f : faces) {
        vertex_id_map[f.a] = 0;
        vertex_id_map[f.b] = 0;
        vertex_id_map[f.c] = 0;
    }
    std::vector<point_2d_t> new_vertices;
    for (auto &[old_id, new_id] : vertex_id_map) {
        new_id = new_vertices.size();
        new_vertices.push_back(vertices[old_id]);
    }
    face_set_t new_faces;
    for (auto f : faces) {
        const auto &a = new_vertices[vertex_id_map[f.a]],
                   &b = new_vertices[vertex_id_map[f.b]],
                   &c = new_vertices[vertex_id_map[f.c]];

        if ((b - a).cross(c - a) < 0) {
            new_faces.insert(
                {vertex_id_map[f.a], vertex_id_map[f.c], vertex_id_map[f.b]});
        } else {
            new_faces.insert(
                {vertex_id_map[f.a], vertex_id_map[f.b], vertex_id_map[f.c]});
        }
    }

    return {new_vertices, new_faces};
}

trimesh_2d_t mesh_op(const trimesh_2d_t &a_mesh, const trimesh_2d_t &b_mesh,
                     boolean_2d_op op) {
    // TODO: This is just testing the splitting algorithm.
    return split_at_all_intersections(a_mesh, b_mesh);
}

trimesh_2d_t mesh_union(const trimesh_2d_t &a, const trimesh_2d_t &b) {
    return mesh_op(a, b, UNION);
}

trimesh_2d_t mesh_intersection(const trimesh_2d_t &a, const trimesh_2d_t &b) {
    return mesh_op(a, b, INTERSECTION);
}

trimesh_2d_t mesh_difference(const trimesh_2d_t &a, const trimesh_2d_t &b) {
    return mesh_op(a, b, DIFFERENCE);
}

void add_2d_boolean_modules(py::module &m) {
    m.def("triangulation", &triangulation,
          "Gets a triangulation of a triangle and a set of points",
          "triangle"_a, "points"_a);
    m.def("union", &mesh_union, "Union of two meshes", "a"_a, "b"_a);
    m.def("intersection", &mesh_intersection, "Intersection of two meshes",
          "a"_a, "b"_a);
    m.def("difference", &mesh_difference, "Difference of two meshes", "a"_a,
          "b"_a);
}

}  // namespace trimesh
