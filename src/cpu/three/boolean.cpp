#include "boolean.h"

#include <iostream>

#include "bvh.h"

using namespace pybind11::literals;

namespace trimesh {

enum boolean_3d_op { UNION, INTERSECTION, DIFFERENCE };

trimesh_3d_t triangulation(const triangle_3d_t &triangle,
                           const std::vector<point_3d_t> &points) {
    std::vector<point_3d_t> vertices;
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
            triangle_3d_t triangle{vertices[a], vertices[b], vertices[c]};
            if (point.projects_to_triangle(triangle)) {
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

trimesh_3d_t mesh_union_no_intersections(const trimesh_3d_t &a,
                                         const trimesh_3d_t &b) {
    const size_t n = a.vertices().size();

    std::vector<point_3d_t> vertices;
    face_set_t faces;

    // Adds all vertices to the output mesh.
    vertices.insert(vertices.end(), a.vertices().begin(), a.vertices().end());
    vertices.insert(vertices.end(), b.vertices().begin(), b.vertices().end());

    // Adds first mesh's faces to the output mesh.
    for (auto &face : a.faces()) {
        auto &[a, b, c] = face;
        faces.insert(face_t(a, b, c));
    }

    // Adds second mesh's faces to the output mesh, offset by n.
    for (auto &face : b.faces()) {
        auto &[a, b, c] = face;
        faces.insert(face_t(a + n, b + n, c + n));
    }

    return {vertices, faces};
}

bool is_inside(const triangle_3d_t &triangle, const point_3d_t &face_pt,
               const point_3d_t &pt) {
    point_3d_t normal = triangle.normal();
    point_3d_t vec = pt - face_pt;
    float dp = normal.dot(vec);
    return dp < 0;
}

trimesh_3d_t mesh_op(const trimesh_3d_t &mesh_a, const trimesh_3d_t &mesh_b,
                     boolean_3d_op op) {
    throw std::runtime_error("Not implemented yet.");
}

trimesh_3d_t mesh_union(const trimesh_3d_t &a, const trimesh_3d_t &b) {
    return mesh_op(a, b, UNION);
}

trimesh_3d_t mesh_intersection(const trimesh_3d_t &a, const trimesh_3d_t &b) {
    return mesh_op(a, b, INTERSECTION);
}

trimesh_3d_t mesh_difference(const trimesh_3d_t &a, const trimesh_3d_t &b) {
    return mesh_op(a, b, DIFFERENCE);
}

void add_3d_boolean_modules(py::module &m) {
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
