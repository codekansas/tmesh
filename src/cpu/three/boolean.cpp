#include "boolean.h"

#include <iostream>

#include "bvh.h"

#define TOLERANCE 1e-6

using namespace pybind11::literals;

namespace trimesh {

enum boolean_3d_op { UNION, INTERSECTION, DIFFERENCE };

Trimesh3D triangulation(const Triangle3D &triangle,
                        const std::vector<Point3D> &points) {
    std::vector<Point3D> vertices;
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
            Triangle3D triangle{vertices[a], vertices[b], vertices[c]};
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

Trimesh3D mesh_union_no_intersections(const Trimesh3D &a, const Trimesh3D &b) {
    const size_t n = a.vertices().size();

    std::vector<Point3D> vertices;
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

bool is_inside(const Triangle3D &triangle, const Point3D &face_pt,
               const Point3D &pt) {
    Point3D normal = triangle.normal();
    Point3D vec = pt - face_pt;
    float dp = normal.dot(vec);
    return dp < 0;
}

std::tuple<Trimesh3D, Trimesh3D> split_at_all_intersections(
    const Trimesh3D &a, const Trimesh3D &b) {
    std::vector<Point3D> a_vertices, b_vertices;
    face_set_t a_faces, b_faces;

    // Adds all vertices to the output mesh.
    a_vertices.insert(a_vertices.end(), a.vertices().begin(),
                      a.vertices().end());
    b_vertices.insert(b_vertices.end(), b.vertices().begin(),
                      b.vertices().end());

    // Gets BVH for each mesh.
    BVH3D a_bvh(a), b_bvh(b);

    // Stores IDs of vertices which are shared between meshes.
    std::vector<std::tuple<size_t, size_t>> vertex_pairs;

    return {{a_vertices, a_faces}, {b_vertices, b_faces}};
}

Trimesh3D mesh_op(const Trimesh3D &a, const Trimesh3D &b, boolean_3d_op op) {
    throw std::runtime_error("Not implemented yet.");
}

Trimesh3D mesh_union(const Trimesh3D &a, const Trimesh3D &b) {
    return mesh_op(a, b, UNION);
}

Trimesh3D mesh_intersection(const Trimesh3D &a, const Trimesh3D &b) {
    return mesh_op(a, b, INTERSECTION);
}

Trimesh3D mesh_difference(const Trimesh3D &a, const Trimesh3D &b) {
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
