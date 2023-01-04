#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

trimesh::Trimesh3D &mesh_union(trimesh::Trimesh3D &mesh1,
                               trimesh::Trimesh3D &mesh2,
                               float tolerance = 1e-6);

trimesh::Trimesh3D &mesh_intersection(trimesh::Trimesh3D &mesh1,
                                      trimesh::Trimesh3D &mesh2,
                                      float tolerance = 1e-6);

trimesh::Trimesh3D &mesh_difference(trimesh::Trimesh3D &mesh1,
                                    trimesh::Trimesh3D &mesh2,
                                    float tolerance = 1e-6);

void add_modules(py::module &m);

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
