#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

tetramesh_3d_t mesh_union(const tetramesh_3d_t &a, const tetramesh_3d_t &b);
tetramesh_3d_t mesh_intersection(const tetramesh_3d_t &a,
                                 const tetramesh_3d_t &b);
tetramesh_3d_t mesh_difference(const tetramesh_3d_t &a,
                               const tetramesh_3d_t &b);

void add_3d_boolean_modules(py::module &m);

}  // namespace trimesh
