#include "trimesh.h"

#include <iostream>

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

bool is_ear(const util::Polygon2D &polygon, int vi, int vj, int vk) {
    util::Point2D pi = polygon[vi], pj = polygon[vj], pk = polygon[vk];

    // Checks if the triangle is convex.
    if (!util::is_convex(pi, pj, pk)) return false;

    // Checks if the triangle contains any other points.
    for (int l = 0; l < polygon.size(); l++) {
        if (l == vi || l == vj || l == vk) continue;
        if (util::is_inside(polygon[l], {pi, pj, pk})) return false;
    }

    return true;
}

Trimesh2D triangulate(const util::Polygon2D &polygon, bool is_convex) {
    if (polygon.size() < 3) throw std::runtime_error("Invalid polygon.");

    Trimesh2D result;

    // Gets the vertex indices from 0 to n - 1.
    std::vector<int> indices(polygon.size());
    std::iota(indices.begin(), indices.end(), 0);

    // Ensures that the polygon is counter-clockwise.
    if (util::is_clockwise(polygon)) {
        std::reverse(indices.begin(), indices.end());
    }

    // Add vertices to the mesh using indices.
    for (int i = 0; i < polygon.size(); i++) result.add_vertex(polygon[i]);

    // Runs ear clipping algorithm.
    while (indices.size() > 3) {
        bool found = false;
        int n = indices.size();
        std::cout << "Number of indices: " << n << std::endl;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            std::cout << "Checking: " << i << ", " << j << ", " << k
                      << std::endl;
            int vi = indices[i], vj = indices[j], vk = indices[k];
            util::Point2D pi = polygon[vi], pj = polygon[vj], pk = polygon[vk];
            if (is_convex || is_ear(polygon, vi, vj, vk)) {
                result.add_face(vi, vj, vk);
                indices.erase(indices.begin() + j);
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Unable to triangulate polygon.");
        }
    }
    result.add_face(indices[0], indices[1], indices[2]);

    return result;
}

void add_modules(py::module &m) {
    // 2D trimesh.
    py::class_<Trimesh2D>(m, "Trimesh2D")
        .def(py::init<>())
        .def("add_vertex", &Trimesh2D::add_vertex, "vertex"_a)
        .def("add_face", &Trimesh2D::add_face, "i"_a, "j"_a, "k"_a)
        .def("get_vertex", &Trimesh2D::get_vertex, "i"_a)
        .def("get_face", &Trimesh2D::get_face, "i"_a)
        .def_property_readonly("vertices", &Trimesh2D::get_vertices)
        .def_property_readonly("faces", &Trimesh2D::get_faces)
        .def("num_vertices", &Trimesh2D::num_vertices)
        .def("num_faces", &Trimesh2D::num_faces)
        .def("__add__", &Trimesh2D::operator+)
        .def("__iadd__", &Trimesh2D::operator+=);

    // 3D trimesh.
    py::class_<Trimesh3D>(m, "Trimesh3D")
        .def(py::init<>())
        .def("add_vertex", &Trimesh3D::add_vertex, "vertex"_a)
        .def("add_face", &Trimesh3D::add_face, "i"_a, "j"_a, "k"_a)
        .def("get_vertex", &Trimesh3D::get_vertex, "i"_a)
        .def("get_face", &Trimesh3D::get_face, "i"_a)
        .def_property_readonly("vertices", &Trimesh3D::get_vertices)
        .def_property_readonly("faces", &Trimesh3D::get_faces)
        .def("num_vertices", &Trimesh3D::num_vertices)
        .def("num_faces", &Trimesh3D::num_faces)
        .def("__add__", &Trimesh3D::operator+)
        .def("__iadd__", &Trimesh3D::operator+=);

    m.def("triangulate", &triangulate, "polygon"_a, "is_convex"_a = false);
}

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
