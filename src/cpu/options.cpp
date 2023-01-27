#include "options.h"

namespace trimesh {

using namespace pybind11::literals;

float __global_tolerance = 1e-5;

void set_tolerance(float tolerance) { __global_tolerance = tolerance; }

float get_tolerance() { return __global_tolerance; }

void add_options_modules(py::module &m) {
    m.def("set_tolerance", &set_tolerance,
          "Sets the global tolerance for operations which consider small "
          "epsilon differences to be equivalent",
          "tolerance"_a);
    m.def("get_tolerance", &get_tolerance, "Returns the global tolerance");
}

}  // namespace trimesh
