#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace three {
namespace io {

using namespace fast_trimesh::cpu::types;
using namespace fast_trimesh::cpu::three::types;

// Functions for saving and loading STLs.
void save_stl(const std::string &filename, const Trimesh3D &mesh);
Trimesh3D load_stl(const std::string &filename);

// Functions for saving and loading STLs as text.
void save_stl_text(const std::string &filename, const Trimesh3D &mesh);
Trimesh3D load_stl_text(const std::string &filename);

// Functions for saving and loading OBJs.
void save_obj(const std::string &filename, const Trimesh3D &mesh);
Trimesh3D load_obj(const std::string &filename);

// Functions for saving and loading PLYs.
void save_ply(const std::string &filename, const Trimesh3D &mesh);
Trimesh3D load_ply(const std::string &filename);

void add_3d_io_modules(py::module &m);

}  // namespace io
}  // namespace three
}  // namespace cpu
}  // namespace fast_trimesh
