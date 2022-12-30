#include "trimesh.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

using Trimesh2D = Trimesh<std::tuple<float, float>>;
using Trimesh3D = Trimesh<std::tuple<float, float, float>>;

void add_modules(py::module &m) {
    // 2D trimesh.
    py::class_<Trimesh2D>(m, "Trimesh2D")
        .def(py::init<>())
        .def("add_vertex", &Trimesh2D::add_vertex, "vertex"_a)
        .def("add_face", &Trimesh2D::add_face, "i"_a, "j"_a, "k"_a)
        .def_property_readonly("vertices", &Trimesh2D::get_vertices)
        .def_property_readonly("faces", &Trimesh2D::get_faces)
        .def("__add__", &Trimesh2D::operator+)
        .def("__iadd__", &Trimesh2D::operator+=);

    // 3D trimesh.
    py::class_<Trimesh3D>(m, "Trimesh3D")
        .def(py::init<>())
        .def("add_vertex", &Trimesh3D::add_vertex, "vertex"_a)
        .def("add_face", &Trimesh3D::add_face, "i"_a, "j"_a, "k"_a)
        .def_property_readonly("vertices", &Trimesh3D::get_vertices)
        .def_property_readonly("faces", &Trimesh3D::get_faces)
        .def("__add__", &Trimesh3D::operator+)
        .def("__iadd__", &Trimesh3D::operator+=);
}

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
