#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

// Functions for saving and loading SVGs.
void save_svg(const std::string &filename, const trimesh_2d_t &mesh,
              double stroke_width_mul = 1.0);

void add_2d_io_modules(py::module &m);

}  // namespace trimesh
