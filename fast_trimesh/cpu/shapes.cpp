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
    if (width < 0 || height < 0 || depth < 0)
        throw std::runtime_error("Cuboid dimensions must be positive.");

    // Gets cuboid bounding box.
    geometry::BoundingBox3D bbox = {{0, 0, 0}, {width, height, depth}};

    // Converts bounding box to a mesh.
    trimesh::Trimesh3D mesh;
    mesh.set_vertices(geometry::bbox_corners(bbox));
    mesh.set_faces(geometry::bbox_triangle_indices());

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
