#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

// Defines the hierarchical box tree structure to support 3D queries.
// The tree is represented as a vector of nodes, where each node is
// represented as a tuple of (triangle_id, left_child, right_child, box).
// The box is represented as a tuple of (min, max), where min and max are
// the minimum and maximum coordinates of the box, respectively.
// The triangle ID points to the triangle in the trimesh. If a ray
// doesn't intersect a box, then we don't need to check any of the
// triangles in the box.
typedef std::vector<std::tuple<size_t, int, int, bounding_box_3d_t>> tree_t;

struct bvh_3d_t {
    const std::shared_ptr<trimesh_3d_t> trimesh;
    tree_t tree;

    bvh_3d_t(const trimesh_3d_t &t);
    ~bvh_3d_t() = default;
    const std::shared_ptr<trimesh_3d_t> get_trimesh() const {
        return this->trimesh;
    }
    tree_t get_tree() const { return this->tree; }
    std::vector<std::tuple<size_t, face_t, point_3d_t>> intersections(
        const line_3d_t &l) const;
    std::string to_string() const;
};

void add_3d_bvh_modules(py::module &m);

}  // namespace trimesh
