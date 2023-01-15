#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace trimesh {

void add_cuda_modules(py::module &m);

}
