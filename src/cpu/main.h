#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {

void add_cpu_modules(py::module &m);

}  // namespace cpu
}  // namespace fast_trimesh
