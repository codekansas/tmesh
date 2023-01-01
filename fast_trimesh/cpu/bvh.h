#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "geometry.h"
#include "trimesh.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace bvh {

class BoundaryVolumeHierarchy {
   private:
    std::shared_ptr<trimesh::Trimesh3D> trimesh;

    // Defines the hierarchical box tree structure to support 3D queries.
    // The tree is represented as a vector of nodes, where each node is
    // represented as a tuple of (left_child, right_child, box).
    // The root node is at index 0, and the left and right children of node i
    // are at indices 2i + 1 and 2i + 2, respectively.
    // The box is represented as a tuple of (min, max), where min and max are
    // the minimum and maximum coordinates of the box, respectively.
    // The box is represented as a tuple of (min, max), where min and max are
    // the minimum and maximum coordinates of the box, respectively.
    std::vector<std::tuple<size_t, size_t, size_t, geometry::BoundingBox3D>>
        tree;

   public:
    BoundaryVolumeHierarchy(trimesh::Trimesh3D &t);
    ~BoundaryVolumeHierarchy() = default;

    // Accessors.
    std::shared_ptr<trimesh::Trimesh3D> get_trimesh() const {
        return this->trimesh;
    }
    std::vector<std::tuple<size_t, size_t, size_t, geometry::BoundingBox3D>>
    get_tree() const {
        return this->tree;
    }

    // Functions for querying geometric intersections.
    // std::vector<geometry::Triangle3D> intersections(
    //     const geometry::Line3D &l) const;
    // std::vector<geometry::Triangle3D> intersections(
    //     const geometry::Triangle3D &t) const;
};

void add_modules(py::module &m);

}  // namespace bvh
}  // namespace cpu
}  // namespace fast_trimesh
