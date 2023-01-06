#include "boolean.h"

#include <iostream>
#include <queue>

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

TrimeshAdjacency::TrimeshAdjacency(const types::Trimesh3D &mesh) {
    // Initializes adjacency lists.
    vertex_to_faces.resize(mesh.vertices().size());
    face_to_vertices.resize(mesh.faces().size());
    face_to_faces.resize(mesh.faces().size());

    // Populates adjacency lists.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        vertex_to_faces[a].push_back(i);
        vertex_to_faces[b].push_back(i);
        vertex_to_faces[c].push_back(i);
        face_to_vertices[i] = {a, b, c};
    }

    // Populates edge-to-face map.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        edge_to_faces[{a, b}] = i;
        edge_to_faces[{b, c}] = i;
        edge_to_faces[{c, a}] = i;
    }

    // Populates face-to-face adjacency list.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        edge_t ba = {b, a}, cb = {c, b}, ac = {a, c};
        for (const edge_t &e : {ba, cb, ac}) {
            if (edge_to_faces.find(e) == edge_to_faces.end()) {
                throw std::runtime_error("Mesh is not manifold; edge " +
                                         std::to_string(std::get<0>(e)) + ", " +
                                         std::to_string(std::get<1>(e)) +
                                         " is not shared.");
            }
        }
        face_to_faces[i] = {edge_to_faces[ba], edge_to_faces[cb],
                            edge_to_faces[ac]};
    }
}

void TrimeshAdjacency::validate() const {
    // Checks that all faces are connected.
    std::vector<bool> visited(face_to_faces.size(), false);
    std::queue<size_t> queue;
    queue.push(0);
    while (!queue.empty()) {
        auto &i = queue.front();
        queue.pop();
        auto &[ja, jb, jc] = face_to_faces[i];
        for (auto &j : {ja, jb, jc}) {
            if (!visited[j]) queue.push(j);
            visited[j] = true;
        }
    }
    size_t num_invalid = 0;
    for (const auto &v : visited)
        if (!v) {
            num_invalid++;
            std::cout << "Vertex " << std::to_string(&v - &visited[0])
                      << " is not connected." << std::endl;
        }
    if (num_invalid > 0)
        throw std::runtime_error("Mesh is not connected; found " +
                                 std::to_string(num_invalid) +
                                 " unconnected vertices.");
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
    std::cout << "normal: " << normal.to_string() << std::endl;
    float dp = normal.dot(vec);
    std::cout << "dp: " << dp << std::endl;
    return dp < 0;
}

void populate_vals(const types::Trimesh3D &mesh, const bvh::BVH3D &tree,
                   std::vector<int> &vals) {
    const types::Trimesh3D &other_mesh = *tree.get_trimesh();

    // TODO: This probably isn't necessary but should delete later.
    TrimeshAdjacency adjacency(mesh);
    adjacency.validate();
    TrimeshAdjacency other_adjacency(other_mesh);
    other_adjacency.validate();

    // First, find the intersecting lines. We can determine if each endpoint
    // is inside or outside of the other mesh by computing the dot product
    // between the normal of the face and the vector from the face to the
    // endpoint.
    for (auto &face : mesh.faces()) {
        for (auto &[a, b] : get_edges(face)) {
            types::Point3D pt_a = mesh.vertices()[a], pt_b = mesh.vertices()[b];
            types::Line3D line{pt_a, pt_b};
            std::vector<std::tuple<types::face_t, types::Point3D>>
                intersections = tree.intersections(line);
            if (intersections.size() == 0) continue;

            std::sort(intersections.begin(), intersections.end(),
                      [&](const std::tuple<types::face_t, types::Point3D> &a,
                          const std::tuple<types::face_t, types::Point3D> &b) {
                          return std::get<1>(a).distance_to_point(pt_a) <
                                 std::get<1>(b).distance_to_point(pt_a);
                      });

            types::Triangle3D a_triangle = other_mesh.get_triangle(
                                  std::get<0>(intersections.front())),
                              b_triangle = other_mesh.get_triangle(
                                  std::get<0>(intersections.back()));

            types::Point3D a_point = std::get<1>(intersections.front()),
                           b_point = std::get<1>(intersections.back());

            std::cout << "a triangle: " << a_triangle.to_string() << std::endl;
            std::cout << "b triangle: " << b_triangle.to_string() << std::endl;

            std::cout << "a coplanar: " << a_point.is_coplanar(a_triangle)
                      << std::endl;
            std::cout << "b coplanar: " << b_point.is_coplanar(b_triangle)
                      << std::endl;

            std::cout << "a_point to pt_a: " << a_point.distance_to_point(pt_a)
                      << std::endl;
            std::cout << "b_point to pt_b: " << b_point.distance_to_point(pt_b)
                      << std::endl;

            std::cout << "a_point: " << a_point.to_string()
                      << ", pt_a: " << pt_a.to_string() << std::endl;
            std::cout << "b_point: " << b_point.to_string()
                      << ", pt_b: " << pt_b.to_string() << std::endl;

            int a_val =
                is_inside(a_triangle, std::get<1>(intersections[1]), pt_a) ? 1
                                                                           : 2;
            int b_val =
                is_inside(b_triangle, std::get<1>(intersections[1]), pt_b) ? 1
                                                                           : 2;

            std::cout << "setting vertex " << a << " to " << a_val << std::endl;
            std::cout << "setting vertex " << b << " to " << b_val << std::endl;
            if (vals[a] != 0 && vals[a] != a_val)
                throw std::runtime_error("mesh_op: inconsistent values (a) " +
                                         std::to_string(vals[a]) + " " +
                                         std::to_string(a_val) +
                                         " for vertex " + std::to_string(a));
            if (vals[b] != 0 && vals[b] != b_val)
                throw std::runtime_error("mesh_op: inconsistent values (b) " +
                                         std::to_string(vals[b]) + " " +
                                         std::to_string(b_val) +
                                         " for vertex " + std::to_string(b));

            vals[a] = a_val;
            vals[b] = b_val;
        }
    }

    // Next, flood fill the inside/outside values, throwing an error if we
    // encounter a conflict. After this, any points which still have a value
    // of 0 are not connected to any of the intersecting lines.
    TrimeshAdjacency adj(mesh);
    std::queue<size_t> q;
    for (size_t i = 0; i < vals.size(); i++) {
        if (vals[i] != 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        size_t i = q.front();
        q.pop();
        for (auto &j : adj.vertex_to_faces[i]) {
            auto &[ka, kb, kc] = adj.face_to_faces[j];
            for (auto &k : {ka, kb, kc}) {
                auto &[la, lb, lc] = adj.face_to_vertices[k];
                for (auto &l : {la, lb, lc}) {
                    if (vals[l] != 0 && vals[l] != vals[i])
                        throw std::runtime_error(
                            "mesh_op: inconsistent values (c)" +
                            std::to_string(vals[l]) + " " +
                            std::to_string(vals[i]) + " for vertex " +
                            std::to_string(l) + " and " + std::to_string(i));
                    if (vals[l] == 0) {
                        vals[l] = vals[i];
                        q.push(l);
                    }
                }
            }
        }
    }
}

types::Trimesh3D mesh_op(const types::Trimesh3D &a, const types::Trimesh3D &b,
                         boolean_op op) {
    const size_t n = a.vertices().size();

    std::cout << "a:" << std::endl;
    for (size_t i = 0; i < a.vertices().size(); i++) {
        auto &v = a.vertices()[i];
        std::cout << i << " " << v.to_string() << std::endl;
    }

    std::cout << "b:" << std::endl;
    for (size_t i = 0; i < b.vertices().size(); i++) {
        auto &v = b.vertices()[i];
        std::cout << i << " " << v.to_string() << std::endl;
    }

    bvh::BVH3D a_tree(a), b_tree(b);

    types::vertices3d_t vertices;
    types::face_set_t faces;

    // 0 = unknown, 1 = inside, 2 = outside
    std::vector<int> a_vals(a.vertices().size(), 0),
        b_vals(b.vertices().size(), 0);

    std::cout << "populating a vals" << std::endl;
    populate_vals(a, b_tree, a_vals);
    std::cout << "populating b vals" << std::endl;
    populate_vals(b, a_tree, b_vals);

    // Debugging: Print info
    std::cout << "a_vals: ";
    for (size_t i = 0; i < a_vals.size(); i++) {
        if (i != 0) std::cout << ", ";
        std::cout << i << ": " << a_vals[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "b_vals: ";
    for (size_t i = 0; i < b_vals.size(); i++) {
        if (i != 0) std::cout << ", ";
        std::cout << i << ": " << b_vals[i] << " ";
    }
    std::cout << std::endl;

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

    py::class_<TrimeshAdjacency>(s, "TrimeshAdjacency")
        .def(py::init<const types::Trimesh3D &>())
        .def_readonly("vertex_to_faces", &TrimeshAdjacency::vertex_to_faces)
        .def_readonly("face_to_vertices", &TrimeshAdjacency::face_to_vertices)
        .def_readonly("face_to_faces", &TrimeshAdjacency::face_to_faces)
        .def("validate", &TrimeshAdjacency::validate);

    s.def("union", &mesh_union, "Union of two meshes", "mesh"_a, "meshes"_a);
    s.def("intersection", &mesh_intersection, "Intersection of two meshes",
          "mesh"_a, "meshes"_a);
    s.def("difference", &mesh_difference, "Difference of two meshes", "mesh"_a,
          "meshes"_a);
}

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
