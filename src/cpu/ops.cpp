#include "ops.h"

#include <iostream>

#include "three/types.h"
#include "two/types.h"

using namespace pybind11::literals;

namespace trimesh {

tetramesh_3d_t linear_extrude(const polygon_2d_t &polygon, double height,
                              bool delaunay) {
    std::function<double(double, double)> height_func =
        [height](double x, double y) -> double { return height; };
    return linear_extrude(polygon, height_func, delaunay);
}

tetramesh_3d_t linear_extrude(
    const polygon_2d_t &polygon,
    const std::function<double(double, double)> &height_func, bool delaunay) {
    return linear_extrude(polygon.get_trimesh(delaunay), height_func);
}

tetramesh_3d_t linear_extrude(const trimesh_2d_t &polygon, double height) {
    std::function<double(double, double)> height_func =
        [height](double x, double y) -> double { return height; };
    return linear_extrude(polygon, height_func);
}

tetramesh_3d_t linear_extrude(
    const trimesh_2d_t &mesh,
    const std::function<double(double, double)> &height_func) {
    std::vector<point_3d_t> vertices;
    volume_set_t volumes;

    // Adds bottom and top vertices.
    for (auto &vertex : mesh.vertices())
        vertices.push_back({vertex.x, vertex.y, 0});
    for (auto &vertex : mesh.vertices())
        vertices.push_back(
            {vertex.x, vertex.y, height_func(vertex.x, vertex.y)});
    size_t top_offset = mesh.vertices().size();

    // Checks the orientation of the triangles in the mesh.
    bool is_cw = false, is_ccw = false;

    // Adds bottom and top faces.
    for (auto &face : mesh.faces()) {
        bool tri_is_cw = mesh.get_triangle(face).is_clockwise();
        is_cw |= tri_is_cw;
        is_ccw |= !tri_is_cw;
        if (is_cw && is_ccw) {
            throw std::runtime_error(
                "linear_extrude: mesh must be either clockwise or "
                "counter-clockwise, conflicting triangles found");
        }

        auto [a, b, c] = face;
        if (is_cw) std::swap(b, c);

        // Indices of bottom and top faces.
        const size_t ba = a, bb = b, bc = c, ta = a + top_offset,
                     tb = b + top_offset, tc = c + top_offset;

        volumes.insert({ba, bc, bb, ta});
        volumes.insert({ta, tb, tc, bb});
        volumes.insert({ta, tc, bc, bb});
    }

    return {vertices, volumes};
}

void add_ops_modules(py::module &m) {
    m.def(
        "linear_extrude",
        py::overload_cast<const polygon_2d_t &, double, bool>(&linear_extrude),
        "Linearly extrudes a 2D mesh from a polygon, with a specific height",
        "mesh"_a, "height"_a, "delaunay"_a = false);
    m.def(
        "linear_extrude",
        py::overload_cast<const polygon_2d_t &,
                          const std::function<double(double, double)> &, bool>(
            &linear_extrude),
        "Linearly extrudes a 2D mesh from a polygon, with a function "
        "specifying the height of each XY coordinate",
        "mesh"_a, "height_func"_a, "delaunay"_a = false);
    m.def("linear_extrude",
          py::overload_cast<const trimesh_2d_t &, double>(&linear_extrude),
          "Linearly extrudes a 2D mesh, with a particular height", "mesh"_a,
          "height"_a);
    m.def("linear_extrude",
          py::overload_cast<const trimesh_2d_t &,
                            const std::function<double(double, double)> &>(
              &linear_extrude),
          "Linearly extrudes a 2D mesh, with a function specifying the height "
          "of each XY coordinate",
          "mesh"_a, "height_func"_a);
}

}  // namespace trimesh
