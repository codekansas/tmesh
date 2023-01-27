#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

struct point_2d_set_t {
   private:
    std::vector<point_2d_t> points;
    std::map<point_2d_t, size_t> indices;

   public:
    point_2d_set_t() = default;
    point_2d_set_t(const std::initializer_list<point_2d_t> &points);
    ~point_2d_set_t() = default;

    point_2d_t operator[](size_t i) const;

    size_t add_point(const point_2d_t &p);
    size_t size() const;
    point_2d_t get_point(size_t i) const;
    std::optional<size_t> point_id(const point_2d_t &p) const;
    const std::vector<point_2d_t> &get_points() const;
};

struct triangle_split_tree_2d_t {
   private:
    const face_t root;
    std::vector<face_t> faces;
    std::vector<std::vector<size_t>> children;
    point_2d_set_t vertices;

    void add_triangle(const face_t &f, size_t parent);
    void add_triangles(const std::vector<face_t> &fs, size_t parent);
    size_t add_point(const point_2d_t &p);

   public:
    triangle_split_tree_2d_t(const face_t &root,
                             const std::vector<point_2d_t> &vertices);
    ~triangle_split_tree_2d_t() = default;

    bool is_leaf(size_t i) const;
    std::vector<size_t> get_leaf_triangles() const;
    std::vector<size_t> get_leaf_triangles_which_intersect(
        const line_2d_t &l) const;
    void split_triangle(const line_2d_t &l, size_t i);
    triangle_2d_t get_triangle(size_t i) const;
    triangle_2d_t get_triangle_from_face(const face_t &f) const;
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
   private:
    const face_list_t &faces;
    const std::vector<point_2d_t> &vertices;
    tree_t tree;

   public:
    bvh_2d_t(const trimesh_2d_t &t);
    bvh_2d_t(const face_list_t &faces, const std::vector<point_2d_t> &vertices);
    ~bvh_2d_t() = default;
    const face_list_t &get_faces() const { return this->faces; }
    const std::vector<point_2d_t> &get_vertices() const {
        return this->vertices;
    }
    const tree_t get_tree() const { return this->tree; }

    std::vector<face_t> line_intersections(
        const line_2d_t &l,
        const std::optional<size_t> max_intersections = std::nullopt) const;
    std::vector<face_t> triangle_intersections(
        const triangle_2d_t &l,
        const std::optional<size_t> max_intersections = std::nullopt) const;
    std::optional<face_t> get_containing_face(const triangle_2d_t &t) const;
    std::string to_string() const;
};

void add_2d_bvh_modules(py::module &m);

}  // namespace trimesh
