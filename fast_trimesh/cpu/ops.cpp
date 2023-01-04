#include "ops.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace ops {

trimesh::Trimesh3D linear_extrude(const types::Polygon2D &polygon,
                                  float height) {
    // Checks that `height` is positive.
    if (height <= 0.0f) {
        throw std::invalid_argument("Height must be positive.");
    }

    trimesh::Trimesh3D mesh3d;

    // Ensure that polygon is counter-clockwise.
    types::Polygon2D poly = polygon;
    if (poly.is_clockwise()) {
        poly.reverse();
    }

    int p = poly.points.size();

    // Adds bottom face.
    for (int i = 0; i < p; i++) {
        mesh3d.add_vertex({poly.points[i].x, poly.points[i].y, 0.0f});
    }
    for (int i = 0; i < p - 1; i++) {
        int v0 = i, v1 = i + 1, v2 = 0;
        // Note that the order of the vertices is reversed, because the
        // bottom is face-down.
        mesh3d.add_face(v0, v2, v1);
    }

    // Adds top faces.
    for (int i = 0; i < p; i++) {
        mesh3d.add_vertex({poly.points[i].x, poly.points[i].y, height});
    }
    for (int i = 0; i < p - 1; i++) {
        int v0 = i + p, v1 = i + 1 + p, v2 = p;
        mesh3d.add_face(v0, v1, v2);
    }

    // Adds side faces. Each side face is made up of two triangles.
    for (int i = 0; i < p; i++) {
        int v0 = i, v1 = (i + 1) % p, v2 = i + p, v3 = (i + 1) % p + p;
        mesh3d.add_face(v0, v1, v2);
        mesh3d.add_face(v1, v3, v2);
    }

    return mesh3d;
}

trimesh::Trimesh3D rotate_extrude(const types::Polygon2D &polygon, float angle,
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

    trimesh::Trimesh3D mesh3d;

    // Ensure that polygon is counter-clockwise.
    types::Polygon2D poly = polygon;
    if (poly.is_clockwise()) {
        poly.reverse();
    }

    int p = poly.points.size();

    // Adds bottom face.
    for (int i = 0; i < n; i++) {
        mesh3d.add_vertex({poly.points[i].x, poly.points[i].y, 0.0f});
    }
    for (int i = 1; i < n - 1; i++) {
        int v0 = i, v1 = i + 1, v2 = 0;
        // Note that the order of the vertices is reversed, because the
        // bottom is face-down.
        mesh3d.add_face(v0, v2, v1);
    }

    // Adds side faces. Each side face is made up of two triangles.
    int offset = 0;
    for (int i = 0; i < n; i++) {
        float angle_i = (i + 1) * angle / n;
        std::tuple<float, float, float> rot{axis == 0 ? angle_i : 0.0,
                                            axis == 1 ? angle_i : 0.0f,
                                            axis == 2 ? angle_i : 0.0f};
        types::Affine3D tf{rot};
        int offset_next = offset + p;

        // Adds next layer of vertices.
        for (int j = 0; j < p; j++) {
            types::Point3D v{poly.points[j].x, poly.points[j].y, 0.0f};
            v <<= tf;
            mesh3d.add_vertex(v);
        }

        // Adds side faces between adjacent layers of vertices.
        for (int j = 0; j < p; j++) {
            int v0 = j + offset, v1 = (j + 1) % p + offset,
                v2 = j + offset_next, v3 = (j + 1) % p + offset_next;
            mesh3d.add_face(v0, v1, v2);
            mesh3d.add_face(v1, v3, v2);
        }

        offset = offset_next;
    }

    // Adds top face.
    for (int j = 1; j < p; j++) {
        int v0 = j + offset, v1 = (j + 1) % p + offset, v2 = offset;
        mesh3d.add_face(v0, v1, v2);
    }

    // Flips inside out if necessary.
    if (mesh3d.signed_volume() < 0) {
        mesh3d.flip_inside_out();
    }

    return mesh3d;
}

trimesh::Trimesh3D rotate_extrude(const types::Polygon2D &polygon, int n,
                                  int axis) {
    // Checks that `n` is valid.
    if (n < 1) {
        throw std::invalid_argument("`n` must be at least 1.");
    }

    // Checks that `axis` is valid.
    if (axis < 0 || axis > 2) {
        throw std::invalid_argument("`axis` must be 0, 1, or 2.");
    }

    trimesh::Trimesh3D mesh3d;

    // Ensure that polygon is counter-clockwise.
    types::Polygon2D poly = polygon;
    if (poly.is_clockwise()) {
        poly.reverse();
    }

    int p = poly.points.size();

    // Adds initial layer of vertices.
    for (int i = 0; i < p; i++) {
        mesh3d.add_vertex({poly.points[i].x, poly.points[i].y, 0.0f});
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
            mesh3d.add_vertex(v);
        }

        // Adds side faces between adjacent layers of vertices.
        for (int j = 0; j < p; j++) {
            int v0 = j + offset, v1 = (j + 1) % p + offset,
                v2 = j + offset_next, v3 = (j + 1) % p + offset_next;
            mesh3d.add_face(v0, v1, v2);
            mesh3d.add_face(v1, v3, v2);
        }

        offset = offset_next;
    }

    // Adds final faces connecting last layer of vertices to first layer.
    for (int j = 0; j < p; j++) {
        int v0 = j + offset, v1 = (j + 1) % p + offset, v2 = j,
            v3 = (j + 1) % p;
        mesh3d.add_face(v0, v1, v2);
        mesh3d.add_face(v1, v3, v2);
    }

    // Flips inside out if necessary.
    if (mesh3d.signed_volume() < 0) {
        mesh3d.flip_inside_out();
    }

    return mesh3d;
}

void add_modules(py::module &m) {
    py::module o = m.def_submodule("ops");
    o.doc() = "Mesh operations.";

    o.def("linear_extrude",
          py::overload_cast<const types::Polygon2D &, float>(&linear_extrude),
          "Linearly extrudes a 2D mesh", "mesh"_a, "height"_a);

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
