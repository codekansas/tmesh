#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace shapes {

types::Polygon2D rectangle(float width, float height, bool center = false);

types::Polygon2D regular_polygon(float radius, int n);

trimesh::Trimesh3D cuboid(float width, float height, float depth,
                          bool center = false);

trimesh::Trimesh3D tetrahedron(float radius);

void add_modules(py::module &m);

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh
