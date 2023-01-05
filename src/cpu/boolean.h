#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

trimesh::Trimesh3D delaunay_triangulation(
    const types::Triangle3D &triangle,
    const std::vector<types::Point3D> &points);

trimesh::Trimesh3D mesh_union(trimesh::Trimesh3D &mesh,
                              const std::vector<trimesh::Trimesh3D> &meshes);

trimesh::Trimesh3D mesh_intersection(
    trimesh::Trimesh3D &mesh, const std::vector<trimesh::Trimesh3D> &meshes);

trimesh::Trimesh3D mesh_difference(
    trimesh::Trimesh3D &mesh, const std::vector<trimesh::Trimesh3D> &meshes);

void add_modules(py::module &m);

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
