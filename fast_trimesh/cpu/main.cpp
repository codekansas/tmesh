#include "main.h"

namespace fast_trimesh {
namespace cpu {

void add_modules(py::module &m) {
    auto s = m.def_submodule("cpu");
    s.doc() = "CPU backend";

    trimesh::add_modules(s);
    geometry::add_modules(s);
    io::add_modules(s);
    shapes::add_modules(s);
}

}  // namespace cpu
}  // namespace fast_trimesh
