#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace three {
namespace boolean {

using namespace fast_trimesh::cpu::types;
using namespace fast_trimesh::cpu::three::types;

Trimesh3D triangulation(const Triangle3D &triangle,
                        const std::vector<Point3D> &points);

Trimesh3D mesh_union(const Trimesh3D &a, const Trimesh3D &b);
Trimesh3D mesh_intersection(const Trimesh3D &a, const Trimesh3D &b);
Trimesh3D mesh_difference(const Trimesh3D &a, const Trimesh3D &b);

void add_3d_boolean_modules(py::module &m);

}  // namespace boolean
}  // namespace three
}  // namespace cpu
}  // namespace fast_trimesh
