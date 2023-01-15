#include "main.h"

namespace py = pybind11;

namespace trimesh {

PYBIND11_MODULE(fast_trimesh, m) {
    m.doc() = "Fast trimesh implementation";

    add_cpu_modules(m);

#ifdef WITH_CUDA
    add_cuda_modules(m);
#endif
}

}  // namespace trimesh
