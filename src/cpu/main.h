#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

namespace py = pybind11;

namespace trimesh {

void add_cpu_modules(py::module &m);

}
