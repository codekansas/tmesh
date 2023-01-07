#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace bvh {

typedef std::tuple<size_t, size_t> edge_t;

struct IntersectionSet {
    std::vector<std::vector<size_t>> a_to_b;
    std::vector<std::vector<size_t>> b_to_a;
    std::vector<std::tuple<edge_t, types::Point3D>> points;

    void add(const size_t a, const size_t b, const types::Point3D &p);
    std::string to_string() const;
};

IntersectionSet intersections(const types::Trimesh3D &a,
                              const types::Trimesh3D &b);

typedef std::tuple<size_t, size_t> edge_t;

struct __edge_hash_fn {
    std::size_t operator()(const edge_t &f) const {
        return std::get<0>(f) ^ std::get<1>(f);
    }
};

struct TrimeshAdjacency {
    std::vector<std::vector<size_t>> vertex_to_faces;
    std::vector<std::vector<size_t>> vertex_to_vertices;
    std::vector<types::face_t> face_to_vertices;
    std::vector<types::face_t> face_to_faces;
    std::unordered_map<edge_t, size_t, __edge_hash_fn> edge_to_faces;

    TrimeshAdjacency(const types::Trimesh3D &mesh);

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
typedef std::vector<std::tuple<size_t, int, int, types::BoundingBox3D>> tree_t;

struct BVH3D {
    const std::shared_ptr<types::Trimesh3D> trimesh;
    tree_t tree;

    BVH3D(const types::Trimesh3D &t);
    ~BVH3D() = default;

    // Accessors.
    const std::shared_ptr<types::Trimesh3D> get_trimesh() const {
        return this->trimesh;
    }
    tree_t get_tree() const { return this->tree; }

    // Functions for computing the intersection of various geometric shapes
    // with the mesh represented by the BVH. Returns the face ID, the face,
    // and the intersection point.
    std::vector<std::tuple<size_t, types::face_t, types::Point3D>>
    intersections(const types::Line3D &l) const;

    std::string to_string() const;
};

void add_modules(py::module &m);

}  // namespace bvh
}  // namespace cpu
}  // namespace fast_trimesh
