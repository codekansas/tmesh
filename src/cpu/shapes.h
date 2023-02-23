#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "three/types.h"
#include "two/types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

polygon_2d_t rectangle(double width, double height, bool center = false);

polygon_2d_t regular_polygon(double radius, size_t n);

trimesh_2d_t regular_polygon_mesh(double radius, size_t n);

trimesh_3d_t cuboid(double width, double height, double depth,
                    bool center = false);

trimesh_3d_t tetrahedron(double radius);

trimesh_3d_t icosphere(double radius, size_t n);

trimesh_3d_t uv_sphere(double radius, size_t n, size_t m);

void add_shapes_modules(py::module &m);

}  // namespace trimesh
