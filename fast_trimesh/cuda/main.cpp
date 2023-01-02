#include "main.h"

namespace fast_trimesh {
namespace cuda {

void add_modules(py::module &m) {
    py::module s = m.def_submodule("cuda");
    s.doc() = "CUDA backend";
}

}  // namespace cuda
}  // namespace fast_trimesh
