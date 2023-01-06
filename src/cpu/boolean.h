#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

types::Trimesh3D triangulation(const types::Triangle3D &triangle,
                               const std::vector<types::Point3D> &points);

types::Trimesh3D mesh_union(const types::Trimesh3D &a,
                            const types::Trimesh3D &b);

types::Trimesh3D mesh_intersection(const types::Trimesh3D &a,
                                   const types::Trimesh3D &b);

types::Trimesh3D mesh_difference(const types::Trimesh3D &a,
                                 const types::Trimesh3D &b);

void add_modules(py::module &m);

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
