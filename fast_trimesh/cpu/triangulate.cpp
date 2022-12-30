#include "triangulate.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace triangulate {

void add_modules(py::module &m) {
    py::class_<Polygon>(m, "Polygon")
        .def(py::init<>())
        .def("add_vertex", &Polygon::add_vertex, "x"_a, "y"_a)
        .def_property_readonly("vertices", &Polygon::get_vertices);
}

}  // namespace triangulate
}  // namespace cpu
}  // namespace fast_trimesh
