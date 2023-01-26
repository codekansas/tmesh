#include "types.h"

#include <iostream>
#include <numeric>
#include <sstream>

#include "options.h"

using namespace pybind11::literals;

namespace trimesh {

/* ------ *
 * edge_t *
 * ------ */

edge_t::edge_t(size_t a, size_t b, bool directed)
    : a(a), b(b), directed(directed) {}

bool edge_t::operator==(const edge_t &e) const {
    if (e.directed != directed) throw std::runtime_error("Cannot compare");
    if (directed) return a == e.a && b == e.b;
    return (a == e.a && b == e.b) || (a == e.b && b == e.a);
}

bool edge_t::operator!=(const edge_t &f) const { return !(*this == f); }

bool edge_t::operator<(const edge_t &f) const {
    if (f.directed != directed) throw std::runtime_error("Cannot compare");
    auto a1 = a, b1 = b, a2 = f.a, b2 = f.b;
    if (!directed) {
        if (a1 > b1) std::swap(a1, b1);
        if (a2 > b2) std::swap(a2, b2);
    }
    return std::tie(a1, b1) < std::tie(a2, b2);
}

std::string edge_t::to_string() const {
    if (directed)
        return "(" + std::to_string(a) + ", " + std::to_string(b) +
               ", directed)";
    if (a < b) return "(" + std::to_string(a) + ", " + std::to_string(b) + ")";
    return "(" + std::to_string(b) + ", " + std::to_string(a) + ")";
}

/* ------ *
 * face_t *
 * ------ */

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

face_t face_t::operator+(size_t offset) const {
    return {a + offset, b + offset, c + offset};
}

std::vector<size_t> face_t::get_vertices() const { return {a, b, c}; }

std::vector<edge_t> face_t::get_edges(bool directed) const {
    return {{a, b, directed}, {b, c, directed}, {c, a, directed}};
}

bool face_t::has_edge(const edge_t &e) const {
    return (e.a == a && e.b == b) || (e.a == b && e.b == a) ||
           (e.a == b && e.b == c) || (e.a == c && e.b == b) ||
           (e.a == c && e.b == a) || (e.a == a && e.b == c);
}

size_t face_t::get_other_vertex(const edge_t &e) const {
    if ((e.a == a && e.b == b) || (e.a == b && e.b == a)) return c;
    if ((e.a == b && e.b == c) || (e.a == c && e.b == b)) return a;
    if ((e.a == c && e.b == a) || (e.a == a && e.b == c)) return b;
    throw std::runtime_error("Edge is not part of face");
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
    auto edge = py::class_<edge_t>(m, "Edge");
    auto face = py::class_<face_t>(m, "Face");
    auto barycentric_coordinates =
        py::class_<barycentric_coordinates_t>(m, "BarycentricCoordinates");

    // Defines Edge methods.
    edge.def(py::init<size_t, size_t, bool>(), "a"_a, "b"_a,
             "directed"_a = false, "Defines a directed triangle edge")
        .def("__eq__", &edge_t::operator==, "other"_a,
             "Checks if two edges are equal.", py::is_operator())
        .def("__ne__", &edge_t::operator!=, "other"_a,
             "Checks if two edges are not equal.", py::is_operator())
        .def("__lt__", &edge_t::operator<, "other"_a,
             "Checks if one face is less than another.", py::is_operator())
        .def("__repr__", &edge_t::to_string, "Returns a string representation.",
             py::is_operator());

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
        .def("get_edges", &face_t::get_edges, "directed"_a = false,
             "Returns the edges.")
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
