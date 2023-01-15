#include "types.h"

#include <iostream>
#include <numeric>
#include <sstream>

using namespace pybind11::literals;

#define TOLERANCE 1e-6

namespace trimesh {

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
    auto barycentric_coordinates =
        py::class_<BarycentricCoordinates>(m, "BarycentricCoordinates");

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
