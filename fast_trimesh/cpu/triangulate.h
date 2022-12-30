#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace triangulate {

class Polygon {
   private:
    std::vector<std::tuple<float, float>> vertices;

   public:
    Polygon() = default;
    ~Polygon() = default;

    void add_vertex(float x, float y) {
        vertices.push_back(std::make_tuple(x, y));
    }
    std::vector<std::tuple<float, float>> get_vertices() { return vertices; }
};

void add_modules(py::module &m);

}  // namespace triangulate
}  // namespace cpu
}  // namespace fast_trimesh
