#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace two {
namespace boolean {

using namespace fast_trimesh::cpu::types;
using namespace fast_trimesh::cpu::two::types;

// Given a triangle and a set of points, return a trimesh that is the
// triangulation of the triangle with respect to the points.
Trimesh2D triangulation(const Triangle2D &triangle,
                        const std::vector<Point2D> &points);

// Given two trimeshes, splits the trimeshes at all intersections between
// them. Returns a pair of trimeshes, where
Trimesh2D split_at_all_intersections(const Trimesh2D &a, const Trimesh2D &b);

Trimesh2D mesh_union(const Trimesh2D &a, const Trimesh2D &b);
Trimesh2D mesh_intersection(const Trimesh2D &a, const Trimesh2D &b);
Trimesh2D mesh_difference(const Trimesh2D &a, const Trimesh2D &b);

void add_2d_boolean_modules(py::module &m);

}  // namespace boolean
}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
