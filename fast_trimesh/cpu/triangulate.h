#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"
#include "util.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace triangulate {

class Polygon {
   private:
    std::vector<util::Point2D> vertices;

   public:
    Polygon() = default;
    ~Polygon() = default;

    void add_vertex(float x, float y) {
        vertices.push_back(std::make_tuple(x, y));
    }
    std::vector<util::Point2D> get_vertices() { return vertices; }
    trimesh::Trimesh<util::Point2D> triangulate();
};

void add_modules(py::module &m);

}  // namespace triangulate
}  // namespace cpu
}  // namespace fast_trimesh
