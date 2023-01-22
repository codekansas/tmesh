#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace trimesh {

void set_tolerance(float tolerance);
float get_tolerance();

void add_options_modules(py::module &m);

}  // namespace trimesh
