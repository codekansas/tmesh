#include "boolean.h"

#include "aabb_tree.h"

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

TrimeshAdjacency compute_adjacency(const types::Trimesh3D &mesh) {
    TrimeshAdjacency adjacency;

    // Initializes adjacency lists.
    adjacency.vertex_to_faces.resize(mesh.vertices().size());
    adjacency.face_to_vertices.resize(mesh.faces().size());
    adjacency.face_to_faces.resize(mesh.faces().size());

    // Populates adjacency lists.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        adjacency.vertex_to_faces[a].push_back(i);
        adjacency.vertex_to_faces[b].push_back(i);
        adjacency.vertex_to_faces[c].push_back(i);
        adjacency.face_to_vertices[i] = {a, b, c};
    }

    // Populates face-to-face adjacency list.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        for (auto &j : adjacency.vertex_to_faces[a]) {
            if (j == i) continue;
            auto &[d, e, f] = mesh.faces()[j];
            if (b == d || b == e || b == f || c == d || c == e || c == f) {
                adjacency.face_to_faces[i].push_back(j);
            }
        }
    }

    return adjacency;
}

enum boolean_op { UNION, INTERSECTION, DIFFERENCE };

types::Trimesh3D mesh_op(const types::Trimesh3D &a, const types::Trimesh3D &b,
                         boolean_op op) {
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
