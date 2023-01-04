#include "main.h"

namespace fast_trimesh {
namespace cpu {

void add_modules(py::module &m) {
    py::module s = m.def_submodule("cpu");
    s.doc() = "CPU backend";

    types::add_modules(s);
    trimesh::add_modules(s);
    io::add_modules(s);
    shapes::add_modules(s);
    bvh::add_modules(s);
    ops::add_modules(s);
    boolean::add_modules(s);
}

}  // namespace cpu
}  // namespace fast_trimesh
