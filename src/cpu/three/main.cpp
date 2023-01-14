#include "main.h"

namespace fast_trimesh {
namespace cpu {
namespace three {

void add_modules(py::module &m) {
    py::module s = m.def_submodule("three");
    s.doc() = "Three-dimensional components";

    bvh::add_modules(s);
    boolean::add_modules(s);
}

}  // namespace three
}  // namespace cpu
}  // namespace fast_trimesh
