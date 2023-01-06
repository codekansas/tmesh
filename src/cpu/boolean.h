#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

trimesh::Trimesh3D triangulation(const types::Triangle3D &triangle,
                                 const std::vector<types::Point3D> &points);

trimesh::Trimesh3D mesh_union(const trimesh::Trimesh3D &a,
                              const trimesh::Trimesh3D &b);

trimesh::Trimesh3D mesh_intersection(const trimesh::Trimesh3D &a,
                                     const trimesh::Trimesh3D &b);

trimesh::Trimesh3D mesh_difference(const trimesh::Trimesh3D &a,
                                   const trimesh::Trimesh3D &b);

void add_modules(py::module &m);

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
