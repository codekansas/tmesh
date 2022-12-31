#include "shapes.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace shapes {

trimesh::Trimesh2D rectangle(float width, float height) {
    trimesh::Trimesh2D mesh;
    mesh.set_vertices({{0, 0}, {0, height}, {width, height}, {width, 0}});
    mesh.set_faces({{0, 1, 2}, {0, 2, 3}});
    return mesh;
}

trimesh::Trimesh3D cuboid(float width, float height, float depth) {
    trimesh::Trimesh3D mesh;
    mesh.set_vertices({{0, 0, 0},
                       {width, 0, 0},
                       {width, height, 0},
                       {0, height, 0},
                       {0, 0, depth},
                       {width, 0, depth},
                       {width, height, depth},
                       {0, height, depth}});
    mesh.set_faces({{0, 2, 1},
                    {0, 3, 2},
                    {0, 5, 4},
                    {0, 1, 5},
                    {1, 6, 5},
                    {1, 2, 6},
                    {2, 7, 6},
                    {2, 3, 7},
                    {3, 4, 7},
                    {3, 0, 4},
                    {4, 6, 7},
                    {4, 5, 6}});
    return mesh;
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("shapes");
    s.doc() = "Shape constructor functions.";

    s.def("rectangle", &rectangle, "Gets a 2D rectangle mesh", "width"_a,
          "height"_a);
    s.def("cuboid", &cuboid, "Gets a 3D cuboid mesh", "width"_a, "height"_a,
          "depth"_a);
}

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh