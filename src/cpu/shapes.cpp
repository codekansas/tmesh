#include "shapes.h"

#include "three/types.h"
#include "two/types.h"

using namespace pybind11::literals;

namespace trimesh {

polygon_2d_t rectangle(float width, float height, bool center) {
    if (center) {
        std::vector<point_2d_t> vertices = {{-width / 2, -height / 2},
                                            {width / 2, -height / 2},
                                            {width / 2, height / 2},
                                            {-width / 2, height / 2}};
        return {vertices};
    } else {
        std::vector<point_2d_t> vertices = {
            {0, 0}, {width, 0}, {width, height}, {0, height}};
        return {vertices};
    }
}

polygon_2d_t regular_polygon(float radius, size_t n) {
    if (radius < 0)
        throw std::runtime_error("Polygon radius must be positive.");
    if (n < 3) throw std::runtime_error("Polygon must have at least 3 sides.");
    std::vector<point_2d_t> vertices;
    for (size_t i = 0; i < n; i++) {
        float theta = 2 * M_PI * i / n;
        vertices.push_back({radius * cos(theta), radius * sin(theta)});
    }
    return {vertices};
}

trimesh_2d_t regular_polygon_mesh(float radius, size_t n) {
    if (radius < 0)
        throw std::runtime_error("Polygon radius must be positive.");
    if (n < 3) throw std::runtime_error("Polygon must have at least 3 sides.");
    std::vector<point_2d_t> vertices;
    face_list_t faces;
    vertices.push_back({0, 0});
    for (size_t i = 0; i < n; i++) {
        float theta = 2 * M_PI * i / n;
        vertices.push_back({radius * cos(theta), radius * sin(theta)});
        faces.push_back({0, i + 1, (i + 1) % n + 1});
    }
    return {vertices, faces};
}

trimesh_3d_t cuboid(float width, float height, float depth, bool center) {
    if (width < 0 || height < 0 || depth < 0)
        throw std::runtime_error("Cuboid dimensions must be positive.");

    // Gets cuboid bounding box.
    bounding_box_3d_t bbox;
    if (center) {
        bbox = {{-width / 2, -height / 2, -depth / 2},
                {width / 2, height / 2, depth / 2}};
    } else {
        bbox = {{0, 0, 0}, {width, height, depth}};
    }

    std::vector<point_3d_t> vertices = bbox.corners();
    face_set_t faces;
    for (auto &face : bbox.triangle_indices()) faces.insert(face);

    return {vertices, faces};
}

trimesh_3d_t tetrahedron(float radius) {
    if (radius <= 0)
        throw std::runtime_error("Tetrahedron radius must be positive.");

    std::vector<point_3d_t> vertices = {
        {std::sqrt(8.0f / 9.0f), 0.0f, -1.0f / 3.0f},
        {-std::sqrt(2.0f / 9.0f), std::sqrt(2.0f / 3.0f), -1.0f / 3.0f},
        {-std::sqrt(2.0f / 9.0f), -std::sqrt(2.0f / 3.0f), -1.0f / 3.0f},
        {0.0f, 0.0f, 1.0f}};
    face_set_t faces = {{0, 2, 1}, {0, 1, 3}, {1, 2, 3}, {2, 0, 3}};

    return {vertices, faces};
}

trimesh_3d_t icosphere(float radius, size_t n) {
    if (radius <= 0)
        throw std::runtime_error("Sphere radius must be positive.");

    // Gets icosahedron vertices.
    float t = (1.0f + std::sqrt(5.0f)) / 2.0f;

    std::vector<point_3d_t> vertices = {
        {-1.0f, t, 0.0f}, {1.0f, t, 0.0f}, {-1.0f, -t, 0.0f}, {1.0f, -t, 0.0f},
        {0.0f, -1.0f, t}, {0.0f, 1.0f, t}, {0.0f, -1.0f, -t}, {0.0f, 1.0f, -t},
        {t, 0.0f, -1.0f}, {t, 0.0f, 1.0f}, {-t, 0.0f, -1.0f}, {-t, 0.0f, 1.0f}};

    // Gets icosahedron faces.
    face_list_t faces = {{0, 11, 5},  {0, 5, 1},  {0, 1, 7},  {0, 7, 10},
                         {0, 10, 11}, {1, 5, 9},  {5, 11, 4}, {11, 10, 2},
                         {10, 7, 6},  {7, 1, 8},  {3, 9, 4},  {3, 4, 2},
                         {3, 2, 6},   {3, 6, 8},  {3, 8, 9},  {4, 9, 5},
                         {2, 4, 11},  {6, 2, 10}, {8, 6, 7},  {9, 8, 1}};

    // Subdivides faces.
    for (size_t i = 0; i < n; i++) {
        face_list_t new_faces;
        for (auto &face : faces) {
            auto &[p0, p1, p2] = face;

            // Gets face vertices.
            point_3d_t v0 = vertices[p0];
            point_3d_t v1 = vertices[p1];
            point_3d_t v2 = vertices[p2];

            // Gets face midpoints.
            point_3d_t v01 = (v0 + v1) / 2.0f;
            point_3d_t v12 = (v1 + v2) / 2.0f;
            point_3d_t v20 = (v2 + v0) / 2.0f;

            // Adds new vertices.
            size_t v01_index = vertices.size();
            vertices.push_back(v01);
            size_t v12_index = vertices.size();
            vertices.push_back(v12);
            size_t v20_index = vertices.size();
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

trimesh_3d_t uv_sphere(float radius, size_t n, size_t m) {
    if (radius <= 0)
        throw std::runtime_error("Sphere radius must be positive.");
    if (n < 0) throw std::runtime_error("Sphere subdivision must be positive.");
    if (m < 0) throw std::runtime_error("Sphere subdivision must be positive.");

    // Gets vertices.
    std::vector<point_3d_t> vertices;
    for (size_t i = 0; i <= n; i++) {
        float theta = M_PI * i / n;
        for (size_t j = 0; j <= m; j++) {
            float phi = 2 * M_PI * j / m;
            float x = radius * std::sin(theta) * std::cos(phi);
            float y = radius * std::sin(theta) * std::sin(phi);
            float z = radius * std::cos(theta);
            vertices.push_back({x, y, z});
        }
    }

    // Gets faces.
    face_list_t faces;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            size_t p0 = i * (m + 1) + j;
            size_t p1 = p0 + 1;
            size_t p2 = p0 + m + 1;
            size_t p3 = p2 + 1;
            faces.push_back({p0, p2, p1});
            faces.push_back({p1, p2, p3});
        }
    }

    return {vertices, faces};
}

void add_shapes_modules(py::module &m) {
    m.def("rectangle", &rectangle, "Gets a 2D rectangle", "width"_a, "height"_a,
          "center"_a = false);
    m.def("regular_polygon", &regular_polygon, "Gets a 2D regular polygon",
          "radius"_a, "n"_a);
    m.def("regular_polygon_mesh", &regular_polygon_mesh,
          "Gets a 2D regular polygon mesh", "radius"_a, "n"_a);
    m.def("cuboid", &cuboid, "Gets a 3D cuboid mesh", "width"_a, "height"_a,
          "depth"_a, "center"_a = false);
    m.def("tetrahedron", &tetrahedron, "Gets a 3D tetrahedron mesh",
          "radius"_a);
    m.def("icosphere", &icosphere, "Gets a 3D sphere mesh", "radius"_a, "n"_a);
    m.def("uv_sphere", &uv_sphere, "Gets a 3D sphere mesh", "radius"_a, "n"_a,
          "m"_a);
}

}  // namespace trimesh
