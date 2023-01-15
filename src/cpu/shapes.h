#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "three/types.h"
#include "two/types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

Polygon2D rectangle(float width, float height, bool center = false);

Polygon2D regular_polygon(float radius, int n);

Trimesh2D regular_polygon_mesh(float radius, int n);

Trimesh3D cuboid(float width, float height, float depth, bool center = false);

Trimesh3D tetrahedron(float radius);

Trimesh3D icosphere(float radius, int n);

Trimesh3D uv_sphere(float radius, int n, int m);

void add_shapes_modules(py::module &m);

}  // namespace trimesh
