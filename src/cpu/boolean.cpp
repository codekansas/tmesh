#include "boolean.h"

#include <iostream>

#include "bvh.h"

#define TOLERANCE 1e-6

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

types::Trimesh3D triangulation(const types::Triangle3D &triangle,
                               const std::vector<types::Point3D> &points) {
    types::vertices3d_t vertices;
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
            types::Triangle3D triangle{vertices[a], vertices[b], vertices[c]};
            if (point.projects_to_triangle(triangle)) {
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

types::Trimesh3D mesh_union_no_intersections(const types::Trimesh3D &a,
                                             const types::Trimesh3D &b) {
    const size_t n = a.vertices().size();

    types::vertices3d_t vertices;
    types::face_set_t faces;

    // Adds all vertices to the output mesh.
    vertices.insert(vertices.end(), a.vertices().begin(), a.vertices().end());
    vertices.insert(vertices.end(), b.vertices().begin(), b.vertices().end());

    // Adds first mesh's faces to the output mesh.
    for (auto &face : a.faces()) {
        auto &[a, b, c] = face;
        faces.insert(types::face_t(a, b, c));
    }

    // Adds second mesh's faces to the output mesh, offset by n.
    for (auto &face : b.faces()) {
        auto &[a, b, c] = face;
        faces.insert(types::face_t(a + n, b + n, c + n));
    }

    return {vertices, faces};
}

std::vector<std::tuple<size_t, size_t>> get_edges(const types::face_t &face) {
    auto &[a, b, c] = face;
    return {{a, b}, {b, c}, {c, a}};
}

enum boolean_op { UNION, INTERSECTION, DIFFERENCE };

bool is_inside(const types::Triangle3D &triangle, const types::Point3D &face_pt,
               const types::Point3D &pt) {
    types::Point3D normal = triangle.normal();
    types::Point3D vec = pt - face_pt;
    // std::cout << "normal: " << normal.to_string() << std::endl;
    float dp = normal.dot(vec);
    // std::cout << "dp: " << dp << std::endl;
    return dp < 0;
}

std::tuple<types::Trimesh3D, types::Trimesh3D> split_at_all_intersections(
    const types::Trimesh3D &a, const types::Trimesh3D &b) {
    types::vertices3d_t a_vertices, b_vertices;
    types::face_set_t a_faces, b_faces;

    // Adds all vertices to the output mesh.
    a_vertices.insert(a_vertices.end(), a.vertices().begin(),
                      a.vertices().end());
    b_vertices.insert(b_vertices.end(), b.vertices().begin(),
                      b.vertices().end());

    // Gets BVH for each mesh.
    bvh::BVH3D a_bvh(a), b_bvh(b);

    // Stores IDs of vertices which are shared between meshes.
    std::vector<std::tuple<size_t, size_t>> vertex_pairs;

    return {{a_vertices, a_faces}, {b_vertices, b_faces}};
}

types::Trimesh3D mesh_op(const types::Trimesh3D &a, const types::Trimesh3D &b,
                         boolean_op op) {
    const size_t n = a.vertices().size();

    // std::cout << "a:" << std::endl;
    for (size_t i = 0; i < a.vertices().size(); i++) {
        auto &v = a.vertices()[i];
        // std::cout << i << " " << v.to_string() << std::endl;
    }

    // std::cout << "b:" << std::endl;
    for (size_t i = 0; i < b.vertices().size(); i++) {
        auto &v = b.vertices()[i];
        // std::cout << i << " " << v.to_string() << std::endl;
    }

    bvh::BVH3D a_tree(a), b_tree(b);

    types::vertices3d_t vertices;
    types::face_set_t faces;

    return mesh_union_no_intersections(a, b);
}

types::Trimesh3D mesh_union(const types::Trimesh3D &a,
                            const types::Trimesh3D &b) {
    return mesh_op(a, b, UNION);
}

types::Trimesh3D mesh_intersection(const types::Trimesh3D &a,
                                   const types::Trimesh3D &b) {
    return mesh_op(a, b, INTERSECTION);
}

types::Trimesh3D mesh_difference(const types::Trimesh3D &a,
                                 const types::Trimesh3D &b) {
    return mesh_op(a, b, DIFFERENCE);
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("boolean");
    s.doc() = "Boolean operations";

    s.def("triangulation", &triangulation,
          "Gets a triangulation of a triangle and a set of points",
          "triangle"_a, "points"_a);

    s.def("union", &mesh_union, "Union of two meshes", "mesh"_a, "meshes"_a);
    s.def("intersection", &mesh_intersection, "Intersection of two meshes",
          "mesh"_a, "meshes"_a);
    s.def("difference", &mesh_difference, "Difference of two meshes", "mesh"_a,
          "meshes"_a);
}

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
