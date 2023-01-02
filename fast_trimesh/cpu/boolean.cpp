#include "boolean.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

trimesh::Trimesh3D &mesh_union(trimesh::Trimesh3D &mesh1,
                               trimesh::Trimesh3D &mesh2, float tolerance) {
    // TODO: Implement this.
    return mesh1;
}

trimesh::Trimesh3D &mesh_intersection(trimesh::Trimesh3D &mesh1,
                                      trimesh::Trimesh3D &mesh2,
                                      float tolerance) {
    // TODO: Implement this.
    return mesh1;
}

trimesh::Trimesh3D &mesh_difference(trimesh::Trimesh3D &mesh1,
                                    trimesh::Trimesh3D &mesh2,
                                    float tolerance) {
    // TODO: Implement this.
    return mesh1;
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("boolean");
    s.doc() = "Boolean operations";

    s.def("union", &mesh_union, "Union of two meshes", "mesh1"_a, "mesh2"_a,
          "tolerance"_a = 1e-6);
    s.def("intersection", &mesh_intersection, "Intersection of two meshes",
          "mesh1"_a, "mesh2"_a, "tolerance"_a = 1e-6);
    s.def("difference", &mesh_difference, "Difference of two meshes", "mesh1"_a,
          "mesh2"_a, "tolerance"_a = 1e-6);
}

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
