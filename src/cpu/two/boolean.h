#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

// Given a triangle and a set of points, return a trimesh that is the
// triangulation of the triangle with respect to the points.
trimesh_2d_t triangulation(const triangle_2d_t &triangle,
                           const std::vector<point_2d_t> &points);

trimesh_2d_t mesh_union(const trimesh_2d_t &a, const trimesh_2d_t &b);
trimesh_2d_t mesh_intersection(const trimesh_2d_t &a, const trimesh_2d_t &b);
trimesh_2d_t mesh_difference(const trimesh_2d_t &a, const trimesh_2d_t &b);

void add_2d_boolean_modules(py::module &m);

}  // namespace trimesh
