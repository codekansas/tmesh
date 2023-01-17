#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <unordered_set>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

struct TriangleSplitTree2D {
   private:
    const face_t root;
    std::vector<face_t> faces;
    std::vector<std::vector<size_t>> children;
    std::vector<Point2D> vertices;

   public:
    TriangleSplitTree2D(const face_t &root,
                        const std::vector<Point2D> &vertices);
    ~TriangleSplitTree2D() = default;

    void add_triangle(const face_t &f, size_t parent);
    size_t add_point(const Point2D &p);
    bool is_leaf(size_t i) const;
    std::unordered_set<size_t> get_leaf_triangles_which_intersect(
        const Point2D &p) const;
    std::unordered_set<size_t> get_leaf_triangles_which_intersect(
        const Line2D &l) const;
    void split_triangle(const Point2D &p, size_t i);
    void split_triangle(const Line2D &l, size_t i);
    Triangle2D get_triangle(size_t i) const;
    const std::vector<face_t> get_leaf_faces(size_t offset) const;
    const std::vector<Point2D> get_vertices() const;
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
