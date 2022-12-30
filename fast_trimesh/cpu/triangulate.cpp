#include "triangulate.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace triangulate {

trimesh::Trimesh<util::Point2D> Polygon::triangulate() {
    trimesh::Trimesh<util::Point2D> t;

    std::vector<util::Point2D> vertices = get_vertices();
    for (auto v : vertices) t.add_vertex(v);

    // Ear clipping algorithm.
    // https://en.wikipedia.org/wiki/Polygon_triangulation#Ear_clipping_method
    while (vertices.size() > 3) {
        for (int i = 0; i < vertices.size(); i++) {
            // Get the previous, current, and next vertices.
            int j = (i + 1) % vertices.size();
            int k = (i + 2) % vertices.size();
            util::Point2D a = vertices[i];
            util::Point2D b = vertices[j];
            util::Point2D c = vertices[k];

            // Check if any other vertices are inside the triangle.
            bool is_ear = true;
            for (int l = 0; l < vertices.size(); l++) {
                if (l == i || l == j || l == k) {
                    continue;
                }
                util::Point2D p = vertices[l];
                if (util::is_inside(p, {a, b, c})) {
                    is_ear = false;
                    break;
                }
            }

            // If no other vertices are inside the triangle, it's an ear.
            if (is_ear) {
                t.add_face(i, j, k);
                vertices.erase(vertices.begin() + j);
                break;
            }
        }
    }

    return t;
}

void add_modules(py::module &m) {
    py::class_<Polygon>(m, "Polygon")
        .def(py::init<>())
        .def("add_vertex", &Polygon::add_vertex, "x"_a, "y"_a)
        .def_property_readonly("vertices", &Polygon::get_vertices);
}

}  // namespace triangulate
}  // namespace cpu
}  // namespace fast_trimesh
