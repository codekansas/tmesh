#include "types.h"

#include <iostream>
#include <numeric>
#include <sstream>

#include "options.h"

using namespace pybind11::literals;

namespace trimesh {

face_t::face_t(size_t a, size_t b, size_t c) : a(a), b(b), c(c) {}

bool face_t::operator==(const face_t &f) const {
    return (a == f.a && b == f.b && c == f.c) ||
           (a == f.b && b == f.c && c == f.a) ||
           (a == f.c && b == f.a && c == f.b);
}

bool face_t::operator!=(const face_t &f) const { return !(*this == f); }

bool face_t::operator<(const face_t &f) const {
    return *this != f && std::tie(a, b, c) < std::tie(f.a, f.b, f.c);
}

std::vector<size_t> face_t::get_vertices() const { return {a, b, c}; }

std::vector<std::tuple<size_t, size_t>> face_t::get_edges() const {
    return {{a, b}, {b, c}, {c, a}};
}

std::string face_t::to_string() const {
    return "(" + std::to_string(a) + ", " + std::to_string(b) + ", " +
           std::to_string(c) + ")";
}

/* ------------------------- *
 * barycentric_coordinates_t *
 * ------------------------- */

barycentric_coordinates_t::barycentric_coordinates_t(float u, float v, float w)
    : u(u), v(v), w(w) {}

bool barycentric_coordinates_t::operator==(
    const barycentric_coordinates_t &b) const {
    return std::abs(u - b.u) < get_tolerance() &&
           std::abs(v - b.v) < get_tolerance() &&
           std::abs(w - b.w) < get_tolerance();
}

bool barycentric_coordinates_t::operator!=(
    const barycentric_coordinates_t &b) const {
    return !(*this == b);
}

std::string barycentric_coordinates_t::to_string() const {
    std::ostringstream ss;
    ss << "barycentric_coordinates_t(" << u << ", " << v << ", " << w << ")";
    return ss.str();
}

void add_types_modules(py::module &m) {
    // Defines the classes first, so that methods can resolve types
    // correctly.
    auto face = py::class_<face_t>(m, "Face");
    auto barycentric_coordinates =
        py::class_<barycentric_coordinates_t>(m, "BarycentricCoordinates");

    // Defines Face methods.
    face.def(py::init<size_t, size_t, size_t>(), "a"_a, "b"_a, "c"_a,
             "Defines a triangle face")
        .def_readwrite("a", &face_t::a, "First vertex index.")
        .def_readwrite("b", &face_t::b, "Second vertex index.")
        .def_readwrite("c", &face_t::c, "Third vertex index.")
        .def("__eq__", &face_t::operator==, "other"_a,
             "Checks if two faces are equal.", py::is_operator())
        .def("__ne__", &face_t::operator!=, "other"_a,
             "Checks if two faces are not equal.", py::is_operator())
        .def("__lt__", &face_t::operator<, "other"_a,
             "Checks if one face is less than another.", py::is_operator())
        .def("get_vertices", &face_t::get_vertices, "Returns the vertices.")
        .def("get_edges", &face_t::get_edges, "Returns the edges.")
        .def("__repr__", &face_t::to_string, "Returns a string representation.",
             py::is_operator());

    // Defines BarycentricCoordinates methods.
    barycentric_coordinates
        .def(py::init<float, float, float>(), "Barycentric coordinates", "u"_a,
             "v"_a, "w"_a)
        .def_readwrite("u", &barycentric_coordinates_t::u,
                       "The first barycentric coordinate")
        .def_readwrite("v", &barycentric_coordinates_t::v,
                       "The second barycentric coordinate")
        .def_readwrite("w", &barycentric_coordinates_t::w,
                       "The third barycentric coordinate")
        .def("__str__", &barycentric_coordinates_t::to_string,
             "Returns a string representation.", py::is_operator())
        .def("__repr__", &barycentric_coordinates_t::to_string,
             py::is_operator())
        .def("__eq__", &barycentric_coordinates_t::operator==,
             "Checks if two barycentric coordinates are equal", "other"_a,
             py::is_operator())
        .def("__ne__", &barycentric_coordinates_t::operator!=,
             "Checks if two barycentric coordinates are not equal", "other"_a,
             py::is_operator());
}

}  // namespace trimesh
