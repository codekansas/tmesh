#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace shapes {

types::Polygon2D rectangle(float width, float height, bool center = false);

types::Polygon2D regular_polygon(float radius, int n);

types::Trimesh3D cuboid(float width, float height, float depth,
                        bool center = false);

types::Trimesh3D tetrahedron(float radius);

types::Trimesh3D icosphere(float radius, int n);

types::Trimesh3D uv_sphere(float radius, int n, int m);

void add_modules(py::module &m);

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh
