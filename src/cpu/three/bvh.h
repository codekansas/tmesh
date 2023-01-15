#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <unordered_map>

#include "../types.h"
#include "types.h"

namespace py = pybind11;

namespace trimesh {

typedef std::tuple<size_t, size_t> edge_t;

struct __edge_hash_fn {
    std::size_t operator()(const edge_t &f) const {
        auto hf = std::hash<size_t>();
        return hf(std::get<0>(f)) ^ hf(std::get<1>(f));
    }
};

struct TrimeshAdjacency3D {
    std::vector<std::vector<size_t>> vertex_to_faces;
    std::vector<std::vector<size_t>> vertex_to_vertices;
    std::vector<face_t> face_to_vertices;
    std::vector<face_t> face_to_faces;
    std::unordered_map<edge_t, size_t, __edge_hash_fn> edge_to_faces;

    TrimeshAdjacency3D(const Trimesh3D &mesh);

    void validate() const;
};

// Defines the hierarchical box tree structure to support 3D queries.
// The tree is represented as a vector of nodes, where each node is
// represented as a tuple of (triangle_id, left_child, right_child, box).
// The box is represented as a tuple of (min, max), where min and max are
// the minimum and maximum coordinates of the box, respectively.
// The triangle ID points to the triangle in the trimesh. If a ray
// doesn't intersect a box, then we don't need to check any of the
// triangles in the box.
typedef std::vector<std::tuple<size_t, int, int, BoundingBox3D>> tree_t;

struct BVH3D {
    const std::shared_ptr<Trimesh3D> trimesh;
    tree_t tree;

    BVH3D(const Trimesh3D &t);
    ~BVH3D() = default;
    const std::shared_ptr<Trimesh3D> get_trimesh() const {
        return this->trimesh;
    }
    tree_t get_tree() const { return this->tree; }
    std::vector<std::tuple<size_t, face_t, Point3D>> intersections(
        const Line3D &l) const;
    std::string to_string() const;
};

void add_3d_bvh_modules(py::module &m);

}  // namespace trimesh
