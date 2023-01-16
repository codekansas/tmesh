#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

// Given a triangle and a set of points, return a trimesh that is the
// triangulation of the triangle with respect to the points.
Trimesh2D triangulation(const Triangle2D &triangle,
                        const std::vector<Point2D> &points);

Trimesh2D mesh_union(const Trimesh2D &a, const Trimesh2D &b);
Trimesh2D mesh_intersection(const Trimesh2D &a, const Trimesh2D &b);
Trimesh2D mesh_difference(const Trimesh2D &a, const Trimesh2D &b);

void add_2d_boolean_modules(py::module &m);

}  // namespace trimesh
