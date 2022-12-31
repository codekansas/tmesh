#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace shapes {

trimesh::Trimesh2D rectangle(float width, float height);

trimesh::Trimesh3D cuboid(float width, float height, float depth);

void add_modules(py::module &m);

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh
