#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace fast_trimesh {
namespace cuda {

void add_modules(py::module &m);

}  // namespace cuda
}  // namespace fast_trimesh
