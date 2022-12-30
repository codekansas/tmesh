#include "main.h"

namespace fast_trimesh {
namespace cpu {

void add_modules(py::module &m) {
    auto s = m.def_submodule("cpu");

    s.doc() = "CPU backend";

    triangulate::add_modules(s);
    trimesh::add_modules(s);
    util::add_modules(s);
}

}  // namespace cpu
}  // namespace fast_trimesh
