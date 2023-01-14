#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

#include "boolean.h"
#include "bvh.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace two {

void add_modules(py::module &m);

}
}  // namespace cpu
}  // namespace fast_trimesh
