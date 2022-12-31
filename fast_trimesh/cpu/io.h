#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

#include "trimesh.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace io {

void save_stl(const std::string &filename, const trimesh::Trimesh3D &mesh);

trimesh::Trimesh3D load_stl(const std::string &filename);

void add_modules(py::module &m);

}  // namespace io
}  // namespace cpu
}  // namespace fast_trimesh
