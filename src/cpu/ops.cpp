#include "ops.h"

#include <iostream>

#include "three/types.h"
#include "two/types.h"

using namespace pybind11::literals;

namespace trimesh {

trimesh_3d_t linear_extrude(const polygon_2d_t &polygon, float height) {
    std::function<float(float, float)> height_func =
        [height](float x, float y) -> float { return height; };
    return linear_extrude(polygon, height_func);
}

trimesh_3d_t linear_extrude(
    const polygon_2d_t &polygon,
    const std::function<float(float, float)> &height_func) {
    return linear_extrude(polygon.get_trimesh(), height_func);
}

trimesh_3d_t linear_extrude(const trimesh_2d_t &polygon, float height) {
    std::function<float(float, float)> height_func =
        [height](float x, float y) -> float { return height; };
    return linear_extrude(polygon, height_func);
}

trimesh_3d_t linear_extrude(
    const trimesh_2d_t &mesh,
    const std::function<float(float, float)> &height_func) {
    std::vector<point_3d_t> vertices;
    face_set_t faces;

    // Ensure that polygon is counter-clockwise.
    std::vector<size_t> poly_inds = mesh.get_polygon_inds();

    size_t tv = mesh.vertices().size();
    size_t tf = mesh.faces().size();
    size_t p = poly_inds.size();

    vertices.reserve(2 * tv);
    faces.reserve(2 * tf + 2 * p);

    // Adds bottom vertices.
    for (size_t i = 0; i < tv; i++) {
        float x = mesh.vertices()[i].x;
        float y = mesh.vertices()[i].y;
        float z = height_func(x, y);
        vertices.push_back({x, y, 0});
    }

    // Adds top vertices.
    for (size_t i = 0; i < tv; i++) {
        float x = mesh.vertices()[i].x;
        float y = mesh.vertices()[i].y;
        float z = height_func(x, y);
        vertices.push_back({x, y, z});
    }

    // Adds top and bottom faces.
    for (size_t i = 0; i < tf; i++) {
        size_t v0 = mesh.faces()[i].a;
        size_t v1 = mesh.faces()[i].b;
        size_t v2 = mesh.faces()[i].c;
        faces.insert({v0, v2, v1});
        faces.insert({v0 + tv, v1 + tv, v2 + tv});
    }

    // Adds side faces. Each side face is made up of two triangles.
    for (size_t i = 0; i < p; i++) {
        size_t v0 = poly_inds[i];
        size_t v1 = poly_inds[(i + 1) % p];
        faces.insert({v0, v1 + tv, v1});
        faces.insert({v0, v0 + tv, v1 + tv});
    }

    return {vertices, faces};
}

trimesh_3d_t rotate_extrude(const polygon_2d_t &polygon, float angle, int n,
                            int axis) {
    // Checks that `angle` is less than a full circle.
    if (angle < 0 || angle > 2 * M_PI - 1e-6) {
        throw std::invalid_argument(
            "`angle` must be between 0 and 2 * pi. To extrude a full circle, "
            "use `rotate_extrude` without providing an `angle` argument.");
    }

    // Checks that `n` is valid.
    if (n < 1) {
        throw std::invalid_argument("`n` must be at least 1.");
    }

    // Checks that `axis` is valid.
    if (axis < 0 || axis > 2) {
        throw std::invalid_argument("`axis` must be 0, 1, or 2.");
    }

    std::vector<point_3d_t> vertices;
    face_list_t faces;

    // Ensure that polygon is counter-clockwise.
    polygon_2d_t poly = polygon;
    if (poly.is_clockwise()) {
        poly.reverse();
    }

    int p = poly.points.size();

    vertices.reserve(n * p);
    faces.reserve(n * p + (p - 2) * 2);

    // Adds bottom face.
    for (int i = 0; i < p; i++) {
        vertices.push_back({poly.points[i].x, poly.points[i].y, 0.0f});
    }
    for (int i = 1; i < p - 1; i++) {
        int v0 = i, v1 = i + 1, v2 = 0;
        // Note that the order of the vertices is reversed, because the
        // bottom is face-down.
        faces.push_back(face_t(v0, v2, v1));
    }

    // Adds side faces. Each side face is made up of two triangles.
    int offset = 0;
    for (int i = 0; i < n; i++) {
        float angle_i = (i + 1) * angle / n;
        std::tuple<float, float, float> rot{axis == 0 ? angle_i : 0.0,
                                            axis == 1 ? angle_i : 0.0f,
                                            axis == 2 ? angle_i : 0.0f};
        affine_3d_t tf{rot};

        // Adds next layer of vertices.
        for (int j = 0; j < p; j++) {
            point_3d_t v{poly.points[j].x, poly.points[j].y, 0.0f};
            v <<= tf;
            vertices.push_back(v);
        }

        // Adds side faces between adjacent layers of vertices.
        for (int j = 0; j < p; j++) {
            int v0 = j + offset, v1 = (j + 1) % p + offset, v2 = j + offset + p,
                v3 = (j + 1) % p + offset + p;
            faces.push_back(face_t(v0, v1, v2));
            faces.push_back(face_t(v1, v3, v2));
        }

        offset += p;
    }

    // Adds top face.
    for (int i = 1; i < p - 1; i++) {
        int v0 = i + offset, v1 = i + 1 + offset, v2 = offset;
        faces.push_back(face_t(v0, v1, v2));
    }

    trimesh_3d_t mesh3d = {vertices, faces};
    return mesh3d.signed_volume() < 0 ? mesh3d.flip_inside_out() : mesh3d;
}

trimesh_3d_t rotate_extrude(const polygon_2d_t &polygon, int n, int axis) {
    // Checks that `n` is valid.
    if (n < 1) {
        throw std::invalid_argument("`n` must be at least 1.");
    }

    // Checks that `axis` is valid.
    if (axis < 0 || axis > 2) {
        throw std::invalid_argument("`axis` must be 0, 1, or 2.");
    }

    std::vector<point_3d_t> vertices;
    face_list_t faces;

    // Ensure that polygon is counter-clockwise.
    polygon_2d_t poly = polygon;
    if (poly.is_clockwise()) {
        poly.reverse();
    }

    int p = poly.points.size();

    vertices.reserve(n * p);
    faces.reserve((n - 1) * p * 2 + (n - 2) * (p - 2) * 2);

    // Adds initial layer of vertices.
    for (int i = 0; i < p; i++) {
        vertices.push_back({poly.points[i].x, poly.points[i].y, 0.0f});
    }

    // Adds side faces. Each side face is made up of two triangles.
    int offset = 0;
    for (int i = 0; i < n; i++) {
        float angle_i = (i + 1) * 2 * M_PI / n;
        std::tuple<float, float, float> rot{axis == 0 ? angle_i : 0.0,
                                            axis == 1 ? angle_i : 0.0f,
                                            axis == 2 ? angle_i : 0.0f};
        affine_3d_t tf{rot};
        int offset_next = offset + p;

        // Adds next layer of vertices.
        for (int j = 0; j < p; j++) {
            point_3d_t v{poly.points[j].x, poly.points[j].y, 0.0f};
            v <<= tf;
            vertices.push_back(v);
        }

        // Adds side faces between adjacent layers of vertices.
        for (int j = 0; j < p; j++) {
            int v0 = j + offset, v1 = (j + 1) % p + offset,
                v2 = j + offset_next, v3 = (j + 1) % p + offset_next;
            faces.push_back(face_t(v0, v1, v2));
            faces.push_back(face_t(v1, v3, v2));
        }

        offset = offset_next;
    }

    // Adds final faces connecting last layer of vertices to first layer.
    for (int j = 0; j < p; j++) {
        int v0 = j + offset, v1 = (j + 1) % p + offset, v2 = j,
            v3 = (j + 1) % p;
        faces.push_back(face_t(v0, v1, v2));
        faces.push_back(face_t(v1, v3, v2));
    }

    trimesh_3d_t mesh3d{vertices, faces};
    return mesh3d.signed_volume() < 0 ? mesh3d.flip_inside_out() : mesh3d;
}

void add_ops_modules(py::module &m) {
    m.def("linear_extrude",
          py::overload_cast<const polygon_2d_t &, float>(&linear_extrude),
          "Linearly extrudes a 2D mesh", "mesh"_a, "height"_a);
    m.def("linear_extrude",
          py::overload_cast<const polygon_2d_t &,
                            const std::function<float(float, float)> &>(
              &linear_extrude),
          "Linearly extrudes a 2D mesh", "mesh"_a, "height_func"_a);
    m.def("linear_extrude",
          py::overload_cast<const trimesh_2d_t &, float>(&linear_extrude),
          "Linearly extrudes a 2D mesh", "mesh"_a, "height"_a);
    m.def("linear_extrude",
          py::overload_cast<const trimesh_2d_t &,
                            const std::function<float(float, float)> &>(
              &linear_extrude),
          "Linearly extrudes a 2D mesh", "mesh"_a, "height_func"_a);

    m.def("rotate_extrude",
          py::overload_cast<const polygon_2d_t &, float, int, int>(
              &rotate_extrude),
          "Rotates a 2D mesh", "mesh"_a, "angle"_a, "n"_a, "axis"_a = 0);
    m.def("rotate_extrude",
          py::overload_cast<const polygon_2d_t &, int, int>(&rotate_extrude),
          "Rotates a 2D mesh", "mesh"_a, "n"_a, "axis"_a = 0);
}

}  // namespace trimesh
