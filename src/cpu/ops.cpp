#include "ops.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace ops {

types::Trimesh3D linear_extrude(const types::Polygon2D &polygon, float height) {
    std::function<float(float, float)> height_func =
        [height](float x, float y) -> float { return height; };
    return linear_extrude(polygon, height_func);
}

types::Trimesh3D linear_extrude(
    const types::Polygon2D &polygon,
    const std::function<float(float, float)> &height_func) {
    types::vertices3d_t vertices;
    types::face_set_t faces;

    // Ensure that polygon is counter-clockwise.
    types::Polygon2D poly = polygon;
    if (poly.is_clockwise()) {
        poly.reverse();
    }

    int p = poly.points.size();

    vertices.reserve(p * 2);
    faces.reserve(p * 2 + (p - 2) * 2);

    // Adds bottom face.
    for (int i = 0; i < p; i++) {
        vertices.push_back({poly.points[i].x, poly.points[i].y, 0.0f});
    }
    for (int i = 0; i < p - 1; i++) {
        int v0 = i, v1 = i + 1, v2 = 0;
        // Note that the order of the vertices is reversed, because the
        // bottom is face-down.
        faces.insert(types::face_t(v0, v2, v1));
    }

    // Adds top faces.
    for (int i = 0; i < p; i++) {
        float x = poly.points[i].x, y = poly.points[i].y;
        float height = height_func(x, y);
        if (height <= 0) {
            throw std::invalid_argument(
                "The height function must be positive.");
        }
        vertices.push_back({x, y, height});
    }
    for (int i = 0; i < p - 1; i++) {
        int v0 = i + p, v1 = i + 1 + p, v2 = p;
        faces.insert(types::face_t(v0, v1, v2));
    }

    // Adds side faces. Each side face is made up of two triangles.
    for (int i = 0; i < p; i++) {
        int v0 = i, v1 = (i + 1) % p, v2 = i + p, v3 = (i + 1) % p + p;
        faces.insert(types::face_t(v0, v1, v2));
        faces.insert(types::face_t(v1, v3, v2));
    }

    return {vertices, faces};
}

types::Trimesh3D rotate_extrude(const types::Polygon2D &polygon, float angle,
                                int n, int axis) {
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

    types::vertices3d_t vertices;
    types::face_list_t faces;

    // Ensure that polygon is counter-clockwise.
    types::Polygon2D poly = polygon;
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
        faces.push_back(types::face_t(v0, v2, v1));
    }

    // Adds side faces. Each side face is made up of two triangles.
    int offset = 0;
    for (int i = 0; i < n; i++) {
        float angle_i = (i + 1) * angle / n;
        std::tuple<float, float, float> rot{axis == 0 ? angle_i : 0.0,
                                            axis == 1 ? angle_i : 0.0f,
                                            axis == 2 ? angle_i : 0.0f};
        types::Affine3D tf{rot};

        // Adds next layer of vertices.
        for (int j = 0; j < p; j++) {
            types::Point3D v{poly.points[j].x, poly.points[j].y, 0.0f};
            v <<= tf;
            vertices.push_back(v);
        }

        // Adds side faces between adjacent layers of vertices.
        for (int j = 0; j < p; j++) {
            int v0 = j + offset, v1 = (j + 1) % p + offset, v2 = j + offset + p,
                v3 = (j + 1) % p + offset + p;
            faces.push_back(types::face_t(v0, v1, v2));
            faces.push_back(types::face_t(v1, v3, v2));
        }

        offset += p;
    }

    // Adds top face.
    for (int i = 1; i < p - 1; i++) {
        int v0 = i + offset, v1 = i + 1 + offset, v2 = offset;
        faces.push_back(types::face_t(v0, v1, v2));
    }

    types::Trimesh3D mesh3d = {vertices, faces};
    return mesh3d.signed_volume() < 0 ? mesh3d.flip_inside_out() : mesh3d;
}

types::Trimesh3D rotate_extrude(const types::Polygon2D &polygon, int n,
                                int axis) {
    // Checks that `n` is valid.
    if (n < 1) {
        throw std::invalid_argument("`n` must be at least 1.");
    }

    // Checks that `axis` is valid.
    if (axis < 0 || axis > 2) {
        throw std::invalid_argument("`axis` must be 0, 1, or 2.");
    }

    types::vertices3d_t vertices;
    types::face_list_t faces;

    // Ensure that polygon is counter-clockwise.
    types::Polygon2D poly = polygon;
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
        types::Affine3D tf{rot};
        int offset_next = offset + p;

        // Adds next layer of vertices.
        for (int j = 0; j < p; j++) {
            types::Point3D v{poly.points[j].x, poly.points[j].y, 0.0f};
            v <<= tf;
            vertices.push_back(v);
        }

        // Adds side faces between adjacent layers of vertices.
        for (int j = 0; j < p; j++) {
            int v0 = j + offset, v1 = (j + 1) % p + offset,
                v2 = j + offset_next, v3 = (j + 1) % p + offset_next;
            faces.push_back(types::face_t(v0, v1, v2));
            faces.push_back(types::face_t(v1, v3, v2));
        }

        offset = offset_next;
    }

    // Adds final faces connecting last layer of vertices to first layer.
    for (int j = 0; j < p; j++) {
        int v0 = j + offset, v1 = (j + 1) % p + offset, v2 = j,
            v3 = (j + 1) % p;
        faces.push_back(types::face_t(v0, v1, v2));
        faces.push_back(types::face_t(v1, v3, v2));
    }

    types::Trimesh3D mesh3d{vertices, faces};
    return mesh3d.signed_volume() < 0 ? mesh3d.flip_inside_out() : mesh3d;
}

void add_modules(py::module &m) {
    py::module o = m.def_submodule("ops");
    o.doc() = "Mesh operations.";

    o.def("linear_extrude",
          py::overload_cast<const types::Polygon2D &, float>(&linear_extrude),
          "Linearly extrudes a 2D mesh", "mesh"_a, "height"_a);
    o.def("linear_extrude",
          py::overload_cast<const types::Polygon2D &,
                            const std::function<float(float, float)> &>(
              &linear_extrude),
          "Linearly extrudes a 2D mesh", "mesh"_a, "height_func"_a);

    o.def("rotate_extrude",
          py::overload_cast<const types::Polygon2D &, float, int, int>(
              &rotate_extrude),
          "Rotates a 2D mesh", "mesh"_a, "angle"_a, "n"_a, "axis"_a = 0);
    o.def(
        "rotate_extrude",
        py::overload_cast<const types::Polygon2D &, int, int>(&rotate_extrude),
        "Rotates a 2D mesh", "mesh"_a, "n"_a, "axis"_a = 0);
}

}  // namespace ops
}  // namespace cpu
}  // namespace fast_trimesh
