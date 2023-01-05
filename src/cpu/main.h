#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

#include "boolean.h"
#include "bvh.h"
#include "io.h"
#include "ops.h"
#include "shapes.h"
#include "trimesh.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {

void add_modules(py::module &m);

}  // namespace cpu
}  // namespace fast_trimesh
