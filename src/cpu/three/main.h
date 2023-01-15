#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace three {

void add_3d_modules(py::module &m);

}
}  // namespace cpu
}  // namespace fast_trimesh
