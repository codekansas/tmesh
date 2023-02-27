#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

struct point_3d_set_t {
   private:
    std::vector<point_3d_t> points;
    std::map<point_3d_t, size_t> indices;

   public:
    point_3d_set_t() = default;
    point_3d_set_t(const std::initializer_list<point_3d_t> &points);
    ~point_3d_set_t() = default;

    point_3d_t operator[](size_t i) const;

    size_t add_point(const point_3d_t &p);
    size_t size() const;
    size_t get_point(const point_3d_t &p) const;
    point_3d_t get_point(size_t i) const;
    std::optional<size_t> point_id(const point_3d_t &p) const;
    const std::vector<point_3d_t> &get_points() const;
};

struct delaunay_split_tree_3d_t {
   private:
    const tetramesh_3d_t root;
    std::vector<volume_t> volumes;
    std::vector<std::vector<size_t>> children;
    face_map_t face_to_volume;
    point_3d_set_t vertices;

    void make_delaunay(const size_t &pi, const face_t &f, const size_t &ti);
    size_t add_volume(const volume_t &v, const std::vector<size_t> &parents);

   public:
    delaunay_split_tree_3d_t(const tetrahedron_3d_t &root);
    ~delaunay_split_tree_3d_t() = default;

    bool is_leaf(size_t i) const;
    size_t find_leaf_index(const point_3d_t &p) const;
    const volume_t &get_volume(size_t i) const;
    tetrahedron_3d_t get_tetrahedron(const volume_t &f) const;
    tetrahedron_3d_t get_tetrahedron(size_t i) const;
    std::vector<size_t> get_leaf_triangles() const;
    void split_triangle(const point_3d_t &p, size_t i);
    const point_3d_set_t &get_vertices() const;
};

// Defines the hierarchical box tree structure to support 3D queries.
// The tree is represented as a vector of nodes, where each node is
// represented as a tuple of (triangle_id, left_child, right_child, box).
// The box is represented as a tuple of (min, max), where min and max are
// the minimum and maximum coordinates of the box, respectively.
// The triangle ID points to the triangle in the trimesh. If a ray
// doesn't intersect a box, then we don't need to check any of the
// triangles in the box.
typedef std::vector<std::tuple<size_t, int, int, bounding_box_3d_t>> bvh_tree_t;

struct bvh_3d_t {
    const std::shared_ptr<trimesh_3d_t> trimesh;
    bvh_tree_t tree;

    bvh_3d_t(const trimesh_3d_t &t);
    ~bvh_3d_t() = default;
    const std::shared_ptr<trimesh_3d_t> get_trimesh() const {
        return this->trimesh;
    }
    bvh_tree_t get_tree() const { return this->tree; }
    std::vector<std::tuple<size_t, face_t, point_3d_t>> intersections(
        const line_3d_t &l) const;
    std::string to_string() const;
};

void add_3d_bvh_modules(py::module &m);

}  // namespace trimesh
