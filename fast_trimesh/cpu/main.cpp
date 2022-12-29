#include "main.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {

void add_modules(py::module &m) {
    auto s = m.def_submodule("cpu");

    s.doc() = "CPU backend";

    py::class_<Trimesh>(s, "Trimesh")
        .def(py::init<>())
        .def("add_vertex", &Trimesh::add_vertex, "x"_a, "y"_a, "z"_a)
        .def("add_face", &Trimesh::add_face, "i"_a, "j"_a, "k"_a)
        .def_property_readonly("vertices", &Trimesh::get_vertices)
        .def_property_readonly("faces", &Trimesh::get_faces)
        .def("__add__", &Trimesh::operator+)
        .def("__iadd__", &Trimesh::operator+=);
}

}  // namespace cpu
}  // namespace fast_trimesh
