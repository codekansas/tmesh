#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

trimesh_3d_t triangulation(const triangle_3d_t &triangle,
                           const std::vector<point_3d_t> &points);

trimesh_3d_t mesh_union(const trimesh_3d_t &a, const trimesh_3d_t &b);
trimesh_3d_t mesh_intersection(const trimesh_3d_t &a, const trimesh_3d_t &b);
trimesh_3d_t mesh_difference(const trimesh_3d_t &a, const trimesh_3d_t &b);

void add_3d_boolean_modules(py::module &m);

}  // namespace trimesh
