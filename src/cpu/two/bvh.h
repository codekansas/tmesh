#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

struct triangle_split_tree_2d_t {
   private:
    const face_t root;
    std::vector<face_t> faces;
    std::vector<std::vector<size_t>> children;
    std::vector<point_2d_t> vertices;

    void add_triangle(const face_t &f, size_t parent);
    size_t add_point(const point_2d_t &p);
    size_t maybe_add_point(const point_2d_t &p, const size_t a,
                           const point_2d_t &pa, const size_t b,
                           const point_2d_t &pb);

   public:
    triangle_split_tree_2d_t(const face_t &root,
                             const std::vector<point_2d_t> &vertices);
    ~triangle_split_tree_2d_t() = default;

    bool is_leaf(size_t i) const;
    std::vector<size_t> get_leaf_triangles_which_intersect_point(
        const point_2d_t &p) const;
    std::vector<size_t> get_leaf_triangles_which_intersect_line(
        const line_2d_t &l) const;
    void split_triangle_at_point(const point_2d_t &p, size_t i);
    void split_triangle_at_line(const line_2d_t &l, size_t i);
    triangle_2d_t get_triangle(size_t i) const;
    const std::vector<size_t> get_children(size_t i) const;
    const std::vector<face_t> get_leaf_faces(size_t offset) const;
    const std::vector<point_2d_t> get_vertices() const;
    const size_t count_leaf_triangles() const;
};

// Defines the hierarchical box tree structure to support 2D queries.
// Each element in the vector is (triangle_id, left_child, right_child, box)
// where triangle_id is the index of the triangle in the trimesh, left_child
// and right_child are the indices of the left and right children in the tree
// (-1 if there is no child), and box is the bounding box for the current
// node.
typedef std::vector<std::tuple<size_t, int, int, bounding_box_2d_t>> tree_t;

struct bvh_2d_t {
    const std::shared_ptr<trimesh_2d_t> trimesh;
    tree_t tree;

    bvh_2d_t(const trimesh_2d_t &t);
    ~bvh_2d_t() = default;
    const std::shared_ptr<trimesh_2d_t> get_trimesh() const {
        return this->trimesh;
    }
    tree_t get_tree() const { return this->tree; }
    std::vector<face_t> intersections(const triangle_2d_t &t) const;
    std::optional<face_t> get_containing_face(const triangle_2d_t &t) const;
    std::string to_string() const;
};

void add_2d_bvh_modules(py::module &m);

}  // namespace trimesh
