#include "ops.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace ops {

trimesh::Trimesh3D linear_extrude(const trimesh::Trimesh2D &mesh,
                                  float height) {
    trimesh::Trimesh3D mesh3d;

    return mesh3d;
}

void add_modules(py::module &m) {
    py::module o = m.def_submodule("ops");
    o.doc() = "Mesh operations.";

    o.def("linear_extrude", &linear_extrude, "Linearly extrudes a 2D mesh",
          "mesh"_a, "height"_a);
}

}  // namespace ops
}  // namespace cpu
}  // namespace fast_trimesh
