#pragma once

#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "three/types.h"
#include "two/types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

tetramesh_3d_t linear_extrude(const polygon_2d_t &polygon, double height,
                              bool delaunay = false);
tetramesh_3d_t linear_extrude(
    const polygon_2d_t &polygon,
    const std::function<double(double, double)> &height_func,
    bool delaunay = false);
tetramesh_3d_t linear_extrude(const trimesh_2d_t &polygon, double height);
tetramesh_3d_t linear_extrude(
    const trimesh_2d_t &mesh,
    const std::function<double(double, double)> &height_func);

void add_ops_modules(py::module &m);

}  // namespace trimesh
