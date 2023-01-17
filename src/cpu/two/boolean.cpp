#include "boolean.h"

#include <algorithm>
#include <iostream>

#include "bvh.h"

#define TOLERANCE 1e-6

using namespace pybind11::literals;

namespace trimesh {

enum boolean_2d_op { UNION, INTERSECTION, DIFFERENCE };

Trimesh2D triangulation(const Triangle2D &triangle,
                        const std::vector<Point2D> &points) {
    std::vector<Point2D> vertices;
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
            Triangle2D triangle{vertices[a], vertices[b], vertices[c]};
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

Trimesh2D split_at_all_intersections(const Trimesh2D &a_mesh,
                                     const Trimesh2D &b_mesh) {
    std::vector<Point2D> vertices = a_mesh.vertices();

    // Keeps track of the faces that have been split.
    std::vector<TriangleSplitTree2D> a_trees;
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
            // for (auto &[b_id_a, b_id_b] : b_face.get_edges()) {
            //     Line2D b_edge{b_mesh.vertices()[b_id_a],
            //                   b_mesh.vertices()[b_id_b]};
            //     for (auto &t_id :
            //          a_tree.get_leaf_triangles_which_intersect(b_edge)) {
            //         a_tree.split_triangle(b_edge, t_id);
            //     }
            // }
        }

        // TODO: Just testing.
        // break;
    }

    // Adds all faces from the split trees to the new mesh.
    face_set_t faces;
    size_t a_vertex_offset = a_mesh.vertices().size();
    for (auto &a_tree : a_trees) {
        for (auto &face : a_tree.get_leaf_faces(vertices.size())) {
            faces.insert(face);
        }

        vertices.insert(vertices.end(), a_tree.get_vertices().begin(),
                        a_tree.get_vertices().end());
    }

    // Removes any unused vertices and remaps the faces.
    std::unordered_map<size_t, size_t> vertex_id_map;
    for (auto f : faces) {
        vertex_id_map[f.a] = 0;
        vertex_id_map[f.b] = 0;
        vertex_id_map[f.c] = 0;
    }
    std::vector<Point2D> new_vertices;
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

Trimesh2D mesh_op(const Trimesh2D &a_mesh, const Trimesh2D &b_mesh,
                  boolean_2d_op op) {
    // TODO: This is just testing the splitting algorithm.
    return split_at_all_intersections(a_mesh, b_mesh);
}

Trimesh2D mesh_union(const Trimesh2D &a, const Trimesh2D &b) {
    return mesh_op(a, b, UNION);
}

Trimesh2D mesh_intersection(const Trimesh2D &a, const Trimesh2D &b) {
    return mesh_op(a, b, INTERSECTION);
}

Trimesh2D mesh_difference(const Trimesh2D &a, const Trimesh2D &b) {
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
