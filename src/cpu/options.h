#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace trimesh {

void set_tolerance(double tolerance);
double get_tolerance();

void add_options_modules(py::module &m);

}  // namespace trimesh
