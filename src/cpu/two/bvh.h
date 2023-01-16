#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

struct TriangleSplitTree2D {
    std::vector<std::vector<size_t>> children;
    std::vector<Triangle2D> triangles;

    TriangleSplitTree2D(const Triangle2D &root);
    ~TriangleSplitTree2D() = default;

    void add_triangle(const Triangle2D &t, size_t parent);
    bool is_leaf(size_t i);
    std::vector<std::tuple<const Triangle2D &, const std::vector<size_t> &>>
    get_children(size_t i);
    const std::tuple<const Triangle2D &, const std::vector<size_t> &> get(
        size_t i) const;
    size_t size() const;
    std::string to_string() const;
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

}  // namespace trimesh
