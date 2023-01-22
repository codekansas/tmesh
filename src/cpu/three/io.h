#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

// Functions for saving and loading STLs.
void save_stl(const std::string &filename, const trimesh_3d_t &mesh);
trimesh_3d_t load_stl(const std::string &filename);

// Functions for saving and loading STLs as text.
void save_stl_text(const std::string &filename, const trimesh_3d_t &mesh);
trimesh_3d_t load_stl_text(const std::string &filename);

// Functions for saving and loading OBJs.
void save_obj(const std::string &filename, const trimesh_3d_t &mesh);
trimesh_3d_t load_obj(const std::string &filename);

// Functions for saving and loading PLYs.
void save_ply(const std::string &filename, const trimesh_3d_t &mesh);
trimesh_3d_t load_ply(const std::string &filename);

void add_3d_io_modules(py::module &m);

}  // namespace trimesh
