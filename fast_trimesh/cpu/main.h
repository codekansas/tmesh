#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

#include "trimesh.h"
#include "util.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {

void add_modules(py::module &m);

}  // namespace cpu
}  // namespace fast_trimesh
