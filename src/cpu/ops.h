#pragma once

#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "three/types.h"
#include "two/types.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace ops {

using namespace fast_trimesh::cpu::types;
using namespace fast_trimesh::cpu::two::types;
using namespace fast_trimesh::cpu::three::types;

Trimesh3D linear_extrude(const Polygon2D &polygon, float height);
Trimesh3D linear_extrude(const Polygon2D &polygon,
                         const std::function<float(float, float)> &height_func);
Trimesh3D linear_extrude(const Trimesh2D &polygon, float height);
Trimesh3D linear_extrude(const Trimesh2D &mesh,
                         const std::function<float(float, float)> &height_func);

Trimesh3D rotate_extrude(const Polygon2D &polygon, float angle, int n,
                         int axis = 0);
Trimesh3D rotate_extrude(const Polygon2D &polygon, int n, int axis = 0);

void add_ops_modules(py::module &m);

}  // namespace ops
}  // namespace cpu
}  // namespace fast_trimesh
