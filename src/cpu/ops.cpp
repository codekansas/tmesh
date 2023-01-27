#include "ops.h"

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

    // Gets the polygons for each connected component.
    auto polygons = mesh.get_polygons();

    // Adds bottom and top vertices.
    for (auto &vertex : mesh.vertices())
        vertices.push_back({vertex.x, vertex.y, 0});
    for (auto &vertex : mesh.vertices())
        vertices.push_back(
            {vertex.x, vertex.y, height_func(vertex.x, vertex.y)});
    size_t top_offset = mesh.vertices().size();

    // Adds bottom and top faces.
    edge_set_t edges;
    for (auto &face : mesh.faces()) {
        auto &[a, b, c] = face;
        edge_t ab{a, b}, bc{b, c}, ca{c, a};
        edges.insert(ab);
        edges.insert(bc);
        edges.insert(ca);
        faces.insert({a, c, b});
        faces.insert({a + top_offset, b + top_offset, c + top_offset});
    }

    // Adds side faces.
    for (auto &[poly, poly_inds] : polygons) {
        for (size_t i = 0; i < poly_inds.size(); i++) {
            auto &a = poly_inds[i];
            auto &b = poly_inds[(i + 1) % poly_inds.size()];
            edge_t edge{a, b};
            bool has_edge = edges.find(edge) == edges.end();
            if (has_edge) {
                faces.insert({a, b + top_offset, b});
                faces.insert({a, a + top_offset, b + top_offset});
            } else {
                faces.insert({a, b, b + top_offset});
                faces.insert({a, b + top_offset, a + top_offset});
            }
        }
    }

    return {vertices, faces};
}

void add_ops_modules(py::module &m) {
    m.def("linear_extrude",
          py::overload_cast<const polygon_2d_t &, float>(&linear_extrude),
          "Linearly extrudes a 2D mesh from a polygon, with a specific height",
          "mesh"_a, "height"_a);
    m.def("linear_extrude",
          py::overload_cast<const polygon_2d_t &,
                            const std::function<float(float, float)> &>(
              &linear_extrude),
          "Linearly extrudes a 2D mesh from a polygon, with a function "
          "specifying the height of each XY coordinate",
          "mesh"_a, "height_func"_a);
    m.def("linear_extrude",
          py::overload_cast<const trimesh_2d_t &, float>(&linear_extrude),
          "Linearly extrudes a 2D mesh, with a particular height", "mesh"_a,
          "height"_a);
    m.def("linear_extrude",
          py::overload_cast<const trimesh_2d_t &,
                            const std::function<float(float, float)> &>(
              &linear_extrude),
          "Linearly extrudes a 2D mesh, with a function specifying the height "
          "of each XY coordinate",
          "mesh"_a, "height_func"_a);
}

}  // namespace trimesh
