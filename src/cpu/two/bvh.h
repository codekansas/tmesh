#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace two {
namespace bvh {

typedef std::tuple<size_t, size_t> edge_t;

typedef std::vector<std::tuple<size_t, int, int, types::BoundingBox2D>> tree_t;

struct BVH {
    const std::shared_ptr<types::Trimesh2D> trimesh;
    tree_t tree;

    BVH(const types::Trimesh2D &t);
    ~BVH() = default;
    const std::shared_ptr<types::Trimesh2D> get_trimesh() const {
        return this->trimesh;
    }
    tree_t get_tree() const { return this->tree; }
    std::vector<std::tuple<size_t, types::face_t, types::Point2D>>
    intersections(const types::Line2D &l) const;
    std::string to_string() const;
};

void add_modules(py::module &m);

}  // namespace bvh
}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
