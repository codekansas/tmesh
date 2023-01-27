#include "boolean.h"

#include <algorithm>

#include "bvh.h"

using namespace pybind11::literals;

namespace trimesh {

enum boolean_2d_op { INTERSECTION, COMPLEMENT };

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
    for (size_t b_face_id = 0; b_face_id < b_mesh.faces().size(); b_face_id++) {
        auto &b_face = b_mesh.faces()[b_face_id];
        auto &[b_a, b_b, b_c] = b_face;
        auto &b_tri = b_mesh.get_triangle(b_face);

        // Splits triangles at edges.
        for (auto &edge : b_face.get_edges()) {
            line_2d_t b_edge{b_mesh.vertices()[edge.a],
                             b_mesh.vertices()[edge.b]};

            for (size_t a_face_id = 0; a_face_id < a_mesh.faces().size();
                 a_face_id++) {
                auto &a_tree = a_trees[a_face_id];
                auto t_ids = a_tree.get_leaf_triangles_which_intersect(b_edge);

                for (auto &t_id : t_ids) {
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

    // Removes vertices that are not used by any face and remaps faces.
    auto [new_vertices, new_faces] =
        trimesh_2d_t::remove_unused_vertices(vertices, faces);

    return {new_vertices, new_faces};
}

trimesh_2d_t mesh_op(const trimesh_2d_t &mesh_a, const trimesh_2d_t &mesh_b,
                     boolean_2d_op op, bool validate, bool cleanup) {
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
            case INTERSECTION:
                if (a_face_inside[a_face_id]) faces.insert(a_face);
                break;
            case COMPLEMENT:
                if (!a_face_inside[a_face_id]) faces.insert(a_face);
                break;
        }
    }

    auto [remapped_vertices, remapped_faces] =
        trimesh_2d_t::merge_vertices(vertices, faces);

    if (cleanup) {
        auto [new_vertices, new_faces] =
            trimesh_2d_t::merge_triangles(remapped_vertices, remapped_faces);
        return {new_vertices, new_faces, validate};
    } else {
        auto [new_vertices, new_faces] = trimesh_2d_t::remove_unused_vertices(
            remapped_vertices, remapped_faces);
        return {new_vertices, new_faces, validate};
    }
}

trimesh_2d_t combine(const trimesh_2d_t &a, const trimesh_2d_t &b,
                     bool validate, bool cleanup) {
    std::vector<point_2d_t> vertices;
    vertices.insert(vertices.end(), a.vertices().begin(), a.vertices().end());
    vertices.insert(vertices.end(), b.vertices().begin(), b.vertices().end());

    face_set_t faces;
    faces.insert(a.faces().begin(), a.faces().end());
    size_t offset = a.vertices().size();
    for (auto &face : b.faces()) {
        faces.insert(face + offset);
    }

    auto [remapped_vertices, remapped_faces] =
        trimesh_2d_t::merge_vertices(vertices, faces);

    if (cleanup) {
        auto [new_vertices, new_faces] =
            trimesh_2d_t::merge_triangles(remapped_vertices, remapped_faces);
        return {new_vertices, new_faces, validate};
    } else {
        auto [new_vertices, new_faces] = trimesh_2d_t::remove_unused_vertices(
            remapped_vertices, remapped_faces);
        return {new_vertices, new_faces, validate};
    }
}

trimesh_2d_t mesh_union(const trimesh_2d_t &a, const trimesh_2d_t &b) {
    auto c = mesh_op(b, a, COMPLEMENT, false, false);
    auto d = mesh_op(a, b, COMPLEMENT, false, false);
    auto e = mesh_op(a, b, INTERSECTION, false, false);
    auto f = combine(c, d, false, false);
    return combine(f, e, true, true);
    return c;
}

trimesh_2d_t mesh_intersection(const trimesh_2d_t &a, const trimesh_2d_t &b) {
    return mesh_op(a, b, INTERSECTION, true, true);
}

trimesh_2d_t mesh_difference(const trimesh_2d_t &a, const trimesh_2d_t &b) {
    return mesh_op(a, b, COMPLEMENT, true, true);
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
