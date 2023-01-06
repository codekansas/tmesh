#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace ops {

types::Trimesh3D linear_extrude(const types::Polygon2D &polygon, float height);
types::Trimesh3D linear_extrude(const types::Polygon2D &polygon, float height,
                                float twist);

types::Trimesh3D rotate_extrude(const types::Polygon2D &polygon, float angle,
                                int n, int axis = 0);
types::Trimesh3D rotate_extrude(const types::Polygon2D &polygon, int n,
                                int axis = 0);

void add_modules(py::module &m);

}  // namespace ops
}  // namespace cpu
}  // namespace fast_trimesh
