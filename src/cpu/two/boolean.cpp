#include "boolean.h"

#include <iostream>

#include "bvh.h"

#define TOLERANCE 1e-6

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace two {
namespace boolean {

std::vector<std::tuple<size_t, size_t>> get_edges(const types::face_t &face) {
    auto &[a, b, c] = face;
    return {{a, b}, {b, c}, {c, a}};
}

enum boolean_op { UNION, INTERSECTION, DIFFERENCE };

types::Trimesh2D triangulation(const types::Triangle2D &triangle,
                               const std::vector<types::Point2D> &points) {
    types::vertices2d_t vertices;
    types::face_set_t faces;

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
    faces.insert(types::face_t(0, 1, 2));

    for (size_t i = 0; i < points.size(); i++) {
        auto &point = points[i];

        // Gets the triangle that contains the point.
        bool found_triangle = false;
        for (auto &face : faces) {
            auto &[a, b, c] = face;
            types::Triangle2D triangle{vertices[a], vertices[b], vertices[c]};
            if (point.is_inside_triangle(triangle)) {
                faces.insert(types::face_t(a, b, i + 3));
                faces.insert(types::face_t(b, c, i + 3));
                faces.insert(types::face_t(c, a, i + 3));
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

types::Trimesh2D mesh_op(const types::Trimesh2D &a, const types::Trimesh2D &b,
                         boolean_op op) {
    throw std::runtime_error("Not implemented yet.");
}

types::Trimesh2D mesh_union(const types::Trimesh2D &a,
                            const types::Trimesh2D &b) {
    return mesh_op(a, b, UNION);
}

types::Trimesh2D mesh_intersection(const types::Trimesh2D &a,
                                   const types::Trimesh2D &b) {
    return mesh_op(a, b, INTERSECTION);
}

types::Trimesh2D mesh_difference(const types::Trimesh2D &a,
                                 const types::Trimesh2D &b) {
    return mesh_op(a, b, DIFFERENCE);
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("boolean");
    s.doc() = "Boolean operations";

    s.def("triangulation", &triangulation,
          "Gets a triangulation of a triangle and a set of points",
          "triangle"_a, "points"_a);
    s.def("union", &mesh_union, "Union of two meshes", "a"_a, "b"_a);
    s.def("intersection", &mesh_intersection, "Intersection of two meshes",
          "a"_a, "b"_a);
    s.def("difference", &mesh_difference, "Difference of two meshes", "a"_a,
          "b"_a);
}

}  // namespace boolean
}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
