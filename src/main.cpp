#include "main.h"

namespace py = pybind11;

namespace trimesh {

PYBIND11_MODULE(tmesh, m) {
    m.doc() = "Implementation of operations on triangular meshes";

    add_cpu_modules(m);

#ifdef WITH_CUDA
    add_cuda_modules(m);
#endif
}

}  // namespace trimesh
