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

trimesh::Trimesh2D circle(float radius, int slices) {
    if (radius < 0) throw std::runtime_error("Circle radius must be positive.");
    if (slices < 3)
        throw std::runtime_error("Circle must have at least 3 slices.");

    // Gets circle boundary points.
    geometry::Polygon2D vertices;
    for (int i = 0; i < slices; i++) {
        float theta = 2 * M_PI * i / slices;
        vertices.push_back({radius * cos(theta), radius * sin(theta)});
    }

    // Converts boundary points to a mesh.
    return trimesh::triangulate(vertices);
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

trimesh::Trimesh3D sphere(float radius, int slices, int stacks) {
    if (radius < 0) throw std::runtime_error("Sphere radius must be positive.");
    if (slices < 3)
        throw std::runtime_error("Sphere must have at least 3 slices.");
    if (stacks < 3)
        throw std::runtime_error("Sphere must have at least 3 stacks.");

    // TODO: Implement this.
    // There are two ways to do this:
    // 1. Create an arc, then rotate extrude it 360 degrees.
    // 2. Create a circle, then linear extrude it with varying heights.

    trimesh::Trimesh3D mesh;
    return mesh;
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("shapes");
    s.doc() = "Shape constructor functions.";

    s.def("rectangle", &rectangle, "Gets a 2D rectangle mesh", "width"_a,
          "height"_a);
    s.def("circle", &circle, "Gets a 2D circle mesh", "radius"_a, "slices"_a);
    s.def("cuboid", &cuboid, "Gets a 3D cuboid mesh", "width"_a, "height"_a,
          "depth"_a);
    s.def("sphere", &sphere, "Gets a 3D sphere mesh", "radius"_a, "slices"_a,
          "stacks"_a);
}

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh
