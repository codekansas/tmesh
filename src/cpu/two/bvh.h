#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace two {
namespace bvh {

using namespace fast_trimesh::cpu::types;
using namespace fast_trimesh::cpu::two::types;

typedef std::tuple<size_t, size_t> edge_t;

struct IntersectionSet {
    // Points from the first mesh which intersect lines of
    std::vector<std::tuple<size_t, edge_t>> point_to_edge;
};

// Defines the hierarchical box tree structure to support 2D queries.
// Each element in the vector is (triangle_id, left_child, right_child, box)
// where triangle_id is the index of the triangle in the trimesh, left_child
// and right_child are the indices of the left and right children in the tree
// (-1 if there is no child), and box is the bounding box for the current
// node.
typedef std::vector<std::tuple<size_t, int, int, BoundingBox2D>> tree_t;

struct BVH2D {
    const std::shared_ptr<Trimesh2D> trimesh;
    tree_t tree;

    BVH2D(const Trimesh2D &t);
    ~BVH2D() = default;
    const std::shared_ptr<Trimesh2D> get_trimesh() const {
        return this->trimesh;
    }
    tree_t get_tree() const { return this->tree; }
    std::vector<face_t> intersections(const Triangle2D &t) const;
    std::string to_string() const;
};

void add_2d_bvh_modules(py::module &m);

}  // namespace bvh
}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
