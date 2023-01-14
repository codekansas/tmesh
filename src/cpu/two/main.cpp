#include "main.h"

namespace fast_trimesh {
namespace cpu {
namespace two {

void add_modules(py::module &m) {
    py::module s = m.def_submodule("two");
    s.doc() = "Two-dimensional components";

    bvh::add_modules(s);
    boolean::add_modules(s);
}

}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
