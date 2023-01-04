#include "shapes.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace shapes {

types::Polygon2D rectangle(float width, float height, bool center) {
    if (center) {
        std::vector<types::Point2D> vertices = {{-width / 2, -height / 2},
                                                {width / 2, -height / 2},
                                                {width / 2, height / 2},
                                                {-width / 2, height / 2}};
        return {vertices};
    } else {
        std::vector<types::Point2D> vertices = {
            {0, 0}, {width, 0}, {width, height}, {0, height}};
        return {vertices};
    }
}

types::Polygon2D regular_polygon(float radius, int n) {
    if (radius < 0)
        throw std::runtime_error("Polygon radius must be positive.");
    if (n < 3) throw std::runtime_error("Polygon must have at least 3 sides.");
    std::vector<types::Point2D> vertices;
    for (int i = 0; i < n; i++) {
        float theta = 2 * M_PI * i / n;
        vertices.push_back({radius * cos(theta), radius * sin(theta)});
    }
    return {vertices};
}

trimesh::Trimesh3D cuboid(float width, float height, float depth, bool center) {
    if (width < 0 || height < 0 || depth < 0)
        throw std::runtime_error("Cuboid dimensions must be positive.");

    // Gets cuboid bounding box.
    types::BoundingBox3D bbox;
    if (center) {
        bbox = {{-width / 2, -height / 2, -depth / 2},
                {width / 2, height / 2, depth / 2}};
    } else {
        bbox = {{0, 0, 0}, {width, height, depth}};
    }

    // Converts bounding box to a mesh.
    trimesh::Trimesh3D mesh;
    mesh.set_vertices(bbox.corners());
    mesh.set_faces(bbox.triangle_indices());

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

    s.def("rectangle", &rectangle, "Gets a 2D rectangle", "width"_a, "height"_a,
          "center"_a = false);
    s.def("regular_polygon", &regular_polygon, "Gets a 2D regular polygon",
          "radius"_a, "n"_a);
    s.def("cuboid", &cuboid, "Gets a 3D cuboid mesh", "width"_a, "height"_a,
          "depth"_a, "center"_a = false);
    s.def("sphere", &sphere, "Gets a 3D sphere mesh", "radius"_a, "slices"_a,
          "stacks"_a);
}

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh
