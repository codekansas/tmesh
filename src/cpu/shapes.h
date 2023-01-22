#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "three/types.h"
#include "two/types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

polygon_2d_t rectangle(float width, float height, bool center = false);

polygon_2d_t regular_polygon(float radius, size_t n);

trimesh_2d_t regular_polygon_mesh(float radius, size_t n);

trimesh_3d_t cuboid(float width, float height, float depth,
                    bool center = false);

trimesh_3d_t tetrahedron(float radius);

trimesh_3d_t icosphere(float radius, size_t n);

trimesh_3d_t uv_sphere(float radius, size_t n, size_t m);

void add_shapes_modules(py::module &m);

}  // namespace trimesh
