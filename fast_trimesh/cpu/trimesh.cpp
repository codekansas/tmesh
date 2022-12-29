#include "trimesh.h"

namespace fast_trimesh {
namespace cpu {

    int add(int i, int j) { return i + j; }

    int sub(int i, int j) { return i - j; }

    void add_modules(py::module &m) {
        m.def("add", &add, "A function which adds two numbers");
        m.def("sub", &sub, "A function which subtracts two numbers");
    }

}  // namespace cpu
}  // namespace fast_trimesh
