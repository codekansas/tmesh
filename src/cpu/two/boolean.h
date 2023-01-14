#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace two {
namespace boolean {

// Given a triangle and a set of points, return a trimesh that is the
// triangulation of the triangle with respect to the points.
types::Trimesh2D triangulation(const types::Triangle2D &triangle,
                               const std::vector<types::Point2D> &points);

// Given two trimeshes, splits the trimeshes at all intersections between
// them. Returns a pair of trimeshes, where
types::Trimesh2D split_at_all_intersections(const types::Trimesh2D &a,
                                            const types::Trimesh2D &b);

types::Trimesh2D mesh_union(const types::Trimesh2D &a,
                            const types::Trimesh2D &b);
types::Trimesh2D mesh_intersection(const types::Trimesh2D &a,
                                   const types::Trimesh2D &b);
types::Trimesh2D mesh_difference(const types::Trimesh2D &a,
                                 const types::Trimesh2D &b);

void add_modules(py::module &m);

}  // namespace boolean
}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
