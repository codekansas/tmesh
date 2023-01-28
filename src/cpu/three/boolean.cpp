#include "boolean.h"

#include <iostream>

#include "bvh.h"

using namespace pybind11::literals;

namespace trimesh {

enum boolean_3d_op { UNION, INTERSECTION, DIFFERENCE };

tetramesh_3d_t mesh_op(const tetramesh_3d_t &mesh_a,
                       const tetramesh_3d_t &mesh_b, boolean_3d_op op) {
    throw std::runtime_error("Not implemented yet.");
}

tetramesh_3d_t mesh_union(const tetramesh_3d_t &a, const tetramesh_3d_t &b) {
    return mesh_op(a, b, UNION);
}

tetramesh_3d_t mesh_intersection(const tetramesh_3d_t &a,
                                 const tetramesh_3d_t &b) {
    return mesh_op(a, b, INTERSECTION);
}

tetramesh_3d_t mesh_difference(const tetramesh_3d_t &a,
                               const tetramesh_3d_t &b) {
    return mesh_op(a, b, DIFFERENCE);
}

void add_3d_boolean_modules(py::module &m) {
    m.def("union", &mesh_union, "Union of two meshes", "a"_a, "b"_a);
    m.def("intersection", &mesh_intersection, "Intersection of two meshes",
          "a"_a, "b"_a);
    m.def("difference", &mesh_difference, "Difference of two meshes", "a"_a,
          "b"_a);
}

}  // namespace trimesh
