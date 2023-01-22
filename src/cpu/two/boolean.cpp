#include "boolean.h"

#include <algorithm>
#include <iostream>

#include "bvh.h"

using namespace pybind11::literals;

namespace trimesh {

enum boolean_2d_op { UNION, INTERSECTION, DIFFERENCE };

trimesh_2d_t triangulation(const triangle_2d_t &triangle,
                           const std::vector<point_2d_t> &points) {
    std::vector<point_2d_t> vertices;
    face_set_t faces;

    // Checks that all points are inside the triangle.
    for (auto &point : points) {
        if (!triangle.contains_point(point))
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
                for (auto &t_id :
                     a_tree.get_leaf_triangles_which_intersect_point(
                         b_mesh.vertices()[b_id])) {
                    a_tree.split_triangle_at_point(b_mesh.vertices()[b_id],
                                                   t_id);
                }
            }

            // Splits triangles at edges.
            for (auto &[b_id_a, b_id_b] : b_face.get_edges()) {
                line_2d_t b_edge{b_mesh.vertices()[b_id_a],
                                 b_mesh.vertices()[b_id_b]};
                for (auto &t_id :
                     a_tree.get_leaf_triangles_which_intersect_line(b_edge)) {
                    a_tree.split_triangle_at_line(b_edge, t_id);
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

trimesh_2d_t mesh_op(const trimesh_2d_t &mesh_a, const trimesh_2d_t &mesh_b,
                     boolean_2d_op op) {
    const trimesh_2d_t a_split = split_at_all_intersections(mesh_a, mesh_b),
                       b_split = split_at_all_intersections(mesh_b, mesh_a);

    // Classifies each face in A as inside or outside B, and each face in B
    // as inside or outside A.
    bvh_2d_t a_bvh(mesh_a), b_bvh(mesh_b);
    std::vector<bool> a_face_inside(a_split.faces().size()),
        b_face_inside(b_split.faces().size());
    for (size_t a_face_id = 0; a_face_id < a_split.faces().size();
         a_face_id++) {
        auto &a_face = a_split.faces()[a_face_id];
        auto &a_tri = a_split.get_triangle(a_face);
        a_face_inside[a_face_id] = b_bvh.get_containing_face(a_tri).has_value();
    }
    for (size_t b_face_id = 0; b_face_id < b_split.faces().size();
         b_face_id++) {
        auto &b_face = b_split.faces()[b_face_id];
        auto &b_tri = b_split.get_triangle(b_face);
        b_face_inside[b_face_id] = a_bvh.get_containing_face(b_tri).has_value();
    }

    // Adds all vertices from A to the new mesh. We will clean up unused
    // vertices later.
    std::vector<point_2d_t> vertices;
    vertices.insert(vertices.end(), a_split.vertices().begin(),
                    a_split.vertices().end());

    // Creates a new trimesh with the desired faces depending on the operation.
    // For unions, add all faces from A, and all faces from B which are not
    // inside A. For intersections, add all faces from A which are inside B.
    // For differences, add all faces from A which are not inside B.
    face_set_t faces;
    for (size_t a_face_id = 0; a_face_id < a_split.faces().size();
         a_face_id++) {
        auto &a_face = a_split.faces()[a_face_id];
        switch (op) {
            case UNION:
                faces.insert(a_face);
                break;
            case INTERSECTION:
                if (a_face_inside[a_face_id]) faces.insert(a_face);
                break;
            case DIFFERENCE:
                if (!a_face_inside[a_face_id]) faces.insert(a_face);
                break;
        }
    }
    if (op == UNION) {
        vertices.insert(vertices.end(), b_split.vertices().begin(),
                        b_split.vertices().end());
        for (size_t b_face_id = 0; b_face_id < b_split.faces().size();
             b_face_id++) {
            auto &b_face = b_split.faces()[b_face_id];
            if (!b_face_inside[b_face_id])
                faces.insert({b_face.a + a_split.vertices().size(),
                              b_face.b + a_split.vertices().size(),
                              b_face.c + a_split.vertices().size()});
        }
    }

    // Merges any vertices which are within the tolerance of each other.
    // This works because point_2d_t::operator< will be false if the points
    // are within the tolerance of each other. We can therefore remap
    // vertices to the lowest matched vertex ID.
    std::map<point_2d_t, size_t> vertex_to_id_map;
    for (size_t i = 0; i < vertices.size(); i++) {
        auto &v = vertices[i];
        if (vertex_to_id_map.find(v) == vertex_to_id_map.end())
            vertex_to_id_map[v] = i;
    }
    face_set_t remaped_faces;
    for (auto f : faces) {
        remaped_faces.insert({vertex_to_id_map[vertices[f.a]],
                              vertex_to_id_map[vertices[f.b]],
                              vertex_to_id_map[vertices[f.c]]});
    }

    // Removes any unused vertices and remaps the faces.
    std::unordered_map<size_t, size_t> vertex_id_map;
    for (auto f : remaped_faces) {
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
    for (auto f : remaped_faces) {
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
