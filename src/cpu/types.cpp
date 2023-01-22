#include "types.h"

#include <iostream>
#include <numeric>
#include <sstream>

using namespace pybind11::literals;

#define TOLERANCE 1e-6

namespace trimesh {

face_t::face_t(size_t a, size_t b, size_t c) : a(a), b(b), c(c) {}

bool face_t::operator==(const face_t &f) const {
    return a == f.a && b == f.b && c == f.c;
}

bool face_t::operator!=(const face_t &f) const { return !(*this == f); }

bool face_t::operator<(const face_t &f) const {
    return std::tie(a, b, c) < std::tie(f.a, f.b, f.c);
}

std::vector<size_t> face_t::get_vertices() const { return {a, b, c}; }

std::vector<std::tuple<size_t, size_t>> face_t::get_edges() const {
    return {{a, b}, {b, c}, {c, a}};
}

std::string face_t::to_string() const {
    return "(" + std::to_string(a) + ", " + std::to_string(b) + ", " +
           std::to_string(c) + ")";
}

/* ---------------------- *
 * BarycentricCoordinates *
 * ---------------------- */

BarycentricCoordinates::BarycentricCoordinates(float u, float v, float w)
    : u(u), v(v), w(w) {}

bool BarycentricCoordinates::operator==(const BarycentricCoordinates &b) const {
    return std::abs(u - b.u) < TOLERANCE && std::abs(v - b.v) < TOLERANCE &&
           std::abs(w - b.w) < TOLERANCE;
}

bool BarycentricCoordinates::operator!=(const BarycentricCoordinates &b) const {
    return !(*this == b);
}

std::string BarycentricCoordinates::to_string() const {
    std::ostringstream ss;
    ss << "BarycentricCoordinates(" << u << ", " << v << ", " << w << ")";
    return ss.str();
}

void add_types_modules(py::module &m) {
    // Defines the classes first, so that methods can resolve types
    // correctly.
    auto face = py::class_<face_t>(m, "Face");
    auto barycentric_coordinates =
        py::class_<BarycentricCoordinates>(m, "BarycentricCoordinates");

    // Defines Face methods.
    face.def(py::init<size_t, size_t, size_t>())
        .def_readwrite("a", &face_t::a, "First vertex index.")
        .def_readwrite("b", &face_t::b, "Second vertex index.")
        .def_readwrite("c", &face_t::c, "Third vertex index.")
        .def("__eq__", &face_t::operator==)
        .def("__ne__", &face_t::operator!=)
        .def("__lt__", &face_t::operator<)
        .def("get_vertices", &face_t::get_vertices)
        .def("get_edges", &face_t::get_edges)
        .def("__repr__", &face_t::to_string);

    // Defines BarycentricCoordinates methods.
    barycentric_coordinates
        .def(py::init<float, float, float>(), "Barycentric coordinates", "u"_a,
             "v"_a, "w"_a)
        .def_readwrite("u", &BarycentricCoordinates::u,
                       "The first barycentric coordinate")
        .def_readwrite("v", &BarycentricCoordinates::v,
                       "The second barycentric coordinate")
        .def_readwrite("w", &BarycentricCoordinates::w,
                       "The third barycentric coordinate")
        .def("__str__", &BarycentricCoordinates::to_string, py::is_operator())
        .def("__repr__", &BarycentricCoordinates::to_string, py::is_operator())
        .def("__eq__", &BarycentricCoordinates::operator==,
             "Checks if two barycentric coordinates are equal", "other"_a,
             py::is_operator())
        .def("__ne__", &BarycentricCoordinates::operator!=,
             "Checks if two barycentric coordinates are not equal", "other"_a,
             py::is_operator());
}

}  // namespace trimesh
