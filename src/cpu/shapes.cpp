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

types::Trimesh3D cuboid(float width, float height, float depth, bool center) {
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

    types::vertices3d_t vertices = bbox.corners();
    types::face_set_t faces;
    for (auto &face : bbox.triangle_indices()) faces.insert(face);

    return {vertices, faces};
}

types::Trimesh3D tetrahedron(float radius) {
    if (radius <= 0)
        throw std::runtime_error("Tetrahedron radius must be positive.");

    types::vertices3d_t vertices = {
        {std::sqrt(8.0f / 9.0f), 0.0f, -1.0f / 3.0f},
        {-std::sqrt(2.0f / 9.0f), std::sqrt(2.0f / 3.0f), -1.0f / 3.0f},
        {-std::sqrt(2.0f / 9.0f), -std::sqrt(2.0f / 3.0f), -1.0f / 3.0f},
        {0.0f, 0.0f, 1.0f}};
    types::face_set_t faces = {{0, 2, 1}, {0, 1, 3}, {1, 2, 3}, {2, 0, 3}};

    return {vertices, faces};
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
    s.def("tetrahedron", &tetrahedron, "Gets a 3D tetrahedron mesh",
          "radius"_a);
}

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh
