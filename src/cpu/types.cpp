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

edge_t edge_t::flip() const {
    if (!directed) throw std::runtime_error("Cannot flip undirected edge");
    return edge_t(b, a, true);
}

std::string edge_t::to_string() const {
    if (directed)
        return "Edge(" + std::to_string(a) + ", " + std::to_string(b) +
               ", directed=True)";
    if (a < b) return "(" + std::to_string(a) + ", " + std::to_string(b) + ")";
    return "Edge(" + std::to_string(b) + ", " + std::to_string(a) + ")";
}

size_t __edge_hash_fn::operator()(const edge_t &e) const {
    auto hf = std::hash<size_t>();
    auto [a, b, directed] = e;
    if (!directed && a > b) std::swap(a, b);
    return hf(e.a) ^ hf(e.b);
}

/* ------ *
 * face_t *
 * ------ */

face_t::face_t(size_t a, size_t b, size_t c) {
    // Put the smallest vertex first.
    auto min = std::min({a, b, c});
    if (min == a) {
        this->a = a;
        this->b = b;
        this->c = c;
    } else if (min == b) {
        this->a = b;
        this->b = c;
        this->c = a;
    } else {
        this->a = c;
        this->b = a;
        this->c = b;
    }
}

bool face_t::operator==(const face_t &f) const {
    return a == f.a && b == f.b && c == f.c;
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

bool face_t::has_vertex(size_t v) const { return v == a || v == b || v == c; }

size_t face_t::get_other_vertex(const edge_t &e) const {
    if ((e.a == a && e.b == b) || (e.a == b && e.b == a)) return c;
    if ((e.a == b && e.b == c) || (e.a == c && e.b == b)) return a;
    if ((e.a == c && e.b == a) || (e.a == a && e.b == c)) return b;
    throw std::runtime_error("Edge is not part of face");
}

face_t face_t::flip() const { return {c, b, a}; }

std::string face_t::to_string() const {
    return "Face(" + std::to_string(a) + ", " + std::to_string(b) + ", " +
           std::to_string(c) + ")";
}

size_t face_hash_fn(const face_t &f) {
    auto hf = std::hash<size_t>();
    return hf(f.a) ^ hf(f.b) ^ hf(f.c);
}

size_t __face_hash_fn::operator()(const face_t &f) const {
    return face_hash_fn(f);
}

/* -------- *
 * volume_t *
 * -------- */

volume_t::volume_t(size_t a, size_t b, size_t c, size_t d) {
    auto min = std::min({a, b, c, d});

    if (min == a) {
        this->a = a;
        auto min2 = std::min({b, c, d});
        if (min2 == b) {  // 0 1 2 3
            this->b = b;
            this->c = c;
            this->d = d;
        } else if (min2 == c) {  // 0 3 1 2
            this->b = c;
            this->c = d;
            this->d = b;
        } else {  // 0 2 3 1
            this->b = d;
            this->c = b;
            this->d = c;
        }
    } else if (min == b) {
        this->a = b;
        auto min2 = std::min({a, c, d});
        if (min2 == a) {  // 1 0 3 2
            this->b = a;
            this->c = d;
            this->d = c;
        } else if (min2 == c) {  // 1 2 0 3
            this->b = c;
            this->c = a;
            this->d = d;
        } else {  // 1 3 2 0
            this->b = d;
            this->c = c;
            this->d = a;
        }
    } else if (min == c) {
        this->a = c;
        auto min2 = std::min({a, b, d});
        if (min2 == a) {  // 2 0 1 3
            this->b = a;
            this->c = b;
            this->d = d;
        } else if (min2 == b) {  // 2 1 3 0
            this->b = b;
            this->c = d;
            this->d = a;
        } else {  // 2 3 0 1
            this->b = d;
            this->c = a;
            this->d = b;
        }
    } else {
        this->a = d;
        auto min2 = std::min({a, b, c});
        if (min2 == a) {  // 3 0 2 1
            this->b = a;
            this->c = c;
            this->d = b;
        } else if (min2 == b) {  // 3 1 0 2
            this->b = b;
            this->c = a;
            this->d = c;
        } else {  // 3 2 1 0
            this->b = c;
            this->c = b;
            this->d = a;
        }
    }
}

bool volume_t::operator==(const volume_t &f) const {
    return a == f.a && b == f.b && c == f.c && d == f.d;
}

bool volume_t::operator!=(const volume_t &f) const { return !(*this == f); }

bool volume_t::operator<(const volume_t &f) const {
    return *this != f && std::tie(a, b, c, d) < std::tie(f.a, f.b, f.c, f.d);
}

volume_t volume_t::operator+(size_t offset) const {
    return {a + offset, b + offset, c + offset, d + offset};
}

face_list_t volume_t::faces() const {
    return {{a, c, b}, {a, d, c}, {a, b, d}, {b, c, d}};
}

volume_t volume_t::flip() const { return {d, c, b, a}; }

std::string volume_t::to_string() const {
    return "(" + std::to_string(a) + ", " + std::to_string(b) + ", " +
           std::to_string(c) + ", " + std::to_string(d) + ")";
}

size_t volume_hash_fn(const volume_t &v) {
    auto hf = std::hash<size_t>();
    return hf(v.a) ^ hf(v.b) ^ hf(v.c) ^ hf(v.d);
}

size_t __volume_hash_fn::operator()(const volume_t &v) const {
    return volume_hash_fn(v);
}

/* ------------------------- *
 * barycentric_coordinates_t *
 * ------------------------- */

barycentric_coordinates_t::barycentric_coordinates_t(double u, double v,
                                                     double w)
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

/* --------- *
 * Utilities *
 * --------- */

void check_file_ext(const std::string &filename, const std::string &ext) {
    const auto ref_ext = filename.substr(filename.find_last_of(".") + 1);
    if (ref_ext != ext) {
        throw std::runtime_error("File extension must be ." + ext + ", not ." +
                                 ref_ext);
    }
}

void add_types_modules(py::module &m) {
    // Defines the classes first, so that methods can resolve types
    // correctly.
    auto edge = py::class_<edge_t>(m, "Edge");
    auto face = py::class_<face_t>(m, "Face");
    auto volume = py::class_<volume_t>(m, "Volume");
    auto barycentric_coordinates =
        py::class_<barycentric_coordinates_t>(m, "BarycentricCoordinates");

    // Defines Edge methods.
    edge.def(py::init<size_t, size_t, bool>(), "a"_a, "b"_a,
             "directed"_a = false, "Defines a directed triangle edge")
        .def_readwrite("a", &edge_t::a, "First vertex index.")
        .def_readwrite("b", &edge_t::b, "Second vertex index.")
        .def("__eq__", &edge_t::operator==, "other"_a,
             "Checks if two edges are equal.", py::is_operator())
        .def("__ne__", &edge_t::operator!=, "other"_a,
             "Checks if two edges are not equal.", py::is_operator())
        .def("__lt__", &edge_t::operator<, "other"_a,
             "Checks if one face is less than another.", py::is_operator())
        .def("__str__", &edge_t::to_string, py::is_operator())
        .def("__repr__", &edge_t::to_string, py::is_operator());

    // Defines Face methods.
    face.def(py::init<size_t, size_t, size_t>(), "a"_a, "b"_a, "c"_a,
             "Defines a triangle face")
        .def_readwrite("a", &face_t::a, "First vertex index.")
        .def_readwrite("b", &face_t::b, "Second vertex index.")
        .def_readwrite("c", &face_t::c, "Third vertex index.")
        .def("__hash__", &face_hash_fn, py::is_operator())
        .def("get_vertices", &face_t::get_vertices, "Returns the vertices.")
        .def("get_edges", &face_t::get_edges, "directed"_a = false,
             "Returns the edges.")
        .def("flip", &face_t::flip, "Returns the flipped face.")
        .def("__contains__", &face_t::has_edge, "edge"_a,
             "Checks if an edge is in the face.", py::is_operator())
        .def("__contains__", &face_t::has_vertex, "vertex"_a,
             "Checks if a vertex is in the face.", py::is_operator())
        .def("__eq__", &face_t::operator==, "other"_a,
             "Checks if two faces are equal.", py::is_operator())
        .def("__ne__", &face_t::operator!=, "other"_a,
             "Checks if two faces are not equal.", py::is_operator())
        .def("__lt__", &face_t::operator<, "other"_a,
             "Checks if one face is less than another.", py::is_operator())
        .def("__str__", &face_t::to_string, py::is_operator())
        .def("__repr__", &face_t::to_string, py::is_operator());

    // Defines Volume methods.
    volume
        .def(py::init<size_t, size_t, size_t, size_t>(), "a"_a, "b"_a, "c"_a,
             "d"_a, "Defines a tetrahedron volume")
        .def_readwrite("a", &volume_t::a, "First vertex index.")
        .def_readwrite("b", &volume_t::b, "Second vertex index.")
        .def_readwrite("c", &volume_t::c, "Third vertex index.")
        .def_readwrite("d", &volume_t::d, "Fourth vertex index.")
        .def("flip", &volume_t::flip, "Returns the flipped volume.")
        .def("__eq__", &volume_t::operator==, "other"_a,
             "Checks if two volumes are equal.", py::is_operator())
        .def("__ne__", &volume_t::operator!=, "other"_a,
             "Checks if two volumes are not equal.", py::is_operator())
        .def("__hash__", &volume_hash_fn, py::is_operator())
        .def("__lt__", &volume_t::operator<, "other"_a,
             "Checks if one volumes is less than another.", py::is_operator())
        .def("__str__", &volume_t::to_string, py::is_operator())
        .def("__repr__", &volume_t::to_string, py::is_operator());

    // Defines BarycentricCoordinates methods.
    barycentric_coordinates
        .def(py::init<double, double, double>(), "Barycentric coordinates",
             "u"_a, "v"_a, "w"_a)
        .def_readwrite("u", &barycentric_coordinates_t::u,
                       "The first barycentric coordinate")
        .def_readwrite("v", &barycentric_coordinates_t::v,
                       "The second barycentric coordinate")
        .def_readwrite("w", &barycentric_coordinates_t::w,
                       "The third barycentric coordinate")
        .def("__str__", &barycentric_coordinates_t::to_string,
             py::is_operator())
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
