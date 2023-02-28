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
    const tetrahedron_3d_t root;
    std::vector<volume_t> volumes;
    std::vector<std::vector<size_t>> children;
    std::unordered_map<edge_t, std::unordered_set<size_t>, __edge_hash_fn>
        edge_to_volumes;
    face_map_t face_to_volume;
    point_3d_set_t vertices;

    void make_delaunay(const size_t &pi, const face_t &f, const size_t &ti);
    std::optional<size_t> add_volume(const volume_t &v,
                                     const std::vector<size_t> &parents);
    std::vector<std::optional<size_t>> add_volumes(
        const std::vector<volume_t> &volumes,
        const std::vector<size_t> &parents);

   public:
    delaunay_split_tree_3d_t(const tetrahedron_3d_t &root);
    ~delaunay_split_tree_3d_t() = default;

    bool is_leaf(size_t i) const;
    size_t find_leaf_index(const point_3d_t &p) const;
    const volume_t &get_volume(size_t i) const;
    tetrahedron_3d_t get_tetrahedron_from_volume(const volume_t &f) const;
    tetrahedron_3d_t get_tetrahedron(size_t i) const;
    std::vector<size_t> get_leaf_indices() const;
    void split_tetrahedron(const point_3d_t &p, size_t i,
                           bool make_delaunay = true);
    const point_3d_set_t &get_vertices() const;
};

void add_3d_bvh_modules(py::module &m);

}  // namespace trimesh
