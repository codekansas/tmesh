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

types::Trimesh3D icosphere(float radius, int n) {
    if (radius <= 0)
        throw std::runtime_error("Sphere radius must be positive.");
    if (n < 0) throw std::runtime_error("Sphere subdivision must be positive.");

    // Gets icosahedron vertices.
    float t = (1.0f + std::sqrt(5.0f)) / 2.0f;

    types::vertices3d_t vertices = {
        {-1.0f, t, 0.0f}, {1.0f, t, 0.0f}, {-1.0f, -t, 0.0f}, {1.0f, -t, 0.0f},
        {0.0f, -1.0f, t}, {0.0f, 1.0f, t}, {0.0f, -1.0f, -t}, {0.0f, 1.0f, -t},
        {t, 0.0f, -1.0f}, {t, 0.0f, 1.0f}, {-t, 0.0f, -1.0f}, {-t, 0.0f, 1.0f}};

    // Gets icosahedron faces.
    types::face_list_t faces = {
        {0, 11, 5}, {0, 5, 1},  {0, 1, 7},   {0, 7, 10}, {0, 10, 11},
        {1, 5, 9},  {5, 11, 4}, {11, 10, 2}, {10, 7, 6}, {7, 1, 8},
        {3, 9, 4},  {3, 4, 2},  {3, 2, 6},   {3, 6, 8},  {3, 8, 9},
        {4, 9, 5},  {2, 4, 11}, {6, 2, 10},  {8, 6, 7},  {9, 8, 1}};

    // Subdivides faces.
    for (int i = 0; i < n; i++) {
        types::face_list_t new_faces;
        for (auto &face : faces) {
            auto &[p0, p1, p2] = face;

            // Gets face vertices.
            types::Point3D v0 = vertices[p0];
            types::Point3D v1 = vertices[p1];
            types::Point3D v2 = vertices[p2];

            // Gets face midpoints.
            types::Point3D v01 = (v0 + v1) / 2.0f;
            types::Point3D v12 = (v1 + v2) / 2.0f;
            types::Point3D v20 = (v2 + v0) / 2.0f;

            // Adds new vertices.
            int v01_index = vertices.size();
            vertices.push_back(v01);
            int v12_index = vertices.size();
            vertices.push_back(v12);
            int v20_index = vertices.size();
            vertices.push_back(v20);

            // Adds new faces.
            new_faces.push_back({p0, v01_index, v20_index});
            new_faces.push_back({p1, v12_index, v01_index});
            new_faces.push_back({p2, v20_index, v12_index});
            new_faces.push_back({v01_index, v12_index, v20_index});
        }
        faces = new_faces;
    }

    // Normalizes vertices.
    for (auto &vertex : vertices) vertex = vertex.normalize() * radius;

    return {vertices, faces};
}

types::Trimesh3D uv_sphere(float radius, int n, int m) {
    if (radius <= 0)
        throw std::runtime_error("Sphere radius must be positive.");
    if (n < 0) throw std::runtime_error("Sphere subdivision must be positive.");
    if (m < 0) throw std::runtime_error("Sphere subdivision must be positive.");

    // Gets vertices.
    types::vertices3d_t vertices;
    for (int i = 0; i <= n; i++) {
        float theta = M_PI * i / n;
        for (int j = 0; j <= m; j++) {
            float phi = 2 * M_PI * j / m;
            float x = radius * std::sin(theta) * std::cos(phi);
            float y = radius * std::sin(theta) * std::sin(phi);
            float z = radius * std::cos(theta);
            vertices.push_back({x, y, z});
        }
    }

    // Gets faces.
    types::face_list_t faces;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p0 = i * (m + 1) + j;
            int p1 = p0 + 1;
            int p2 = p0 + m + 1;
            int p3 = p2 + 1;
            faces.push_back({p0, p2, p1});
            faces.push_back({p1, p2, p3});
        }
    }

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
    s.def("icosphere", &icosphere, "Gets a 3D sphere mesh", "radius"_a, "n"_a);
    s.def("uv_sphere", &uv_sphere, "Gets a 3D sphere mesh", "radius"_a, "n"_a,
          "m"_a);
}

}  // namespace shapes
}  // namespace cpu
}  // namespace fast_trimesh
