#include "main.h"

namespace py = pybind11;

namespace fast_trimesh {

PYBIND11_MODULE(fast_trimesh, m) {
    m.doc() = "Fast trimesh implementation";

    cpu::add_modules(m);

#ifdef WITH_CUDA
    cuda::add_modules(m);
#endif
}

}  // namespace fast_trimesh
