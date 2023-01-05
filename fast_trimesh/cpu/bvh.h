#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "trimesh.h"
#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace bvh {

// Defines the hierarchical box tree structure to support 3D queries.
// The tree is represented as a vector of nodes, where each node is
// represented as a tuple of (triangle_id, left_child, right_child, box).
// The box is represented as a tuple of (min, max), where min and max are
// the minimum and maximum coordinates of the box, respectively.
// The triangle ID points to the triangle in the trimesh. If a ray
// doesn't intersect a box, then we don't need to check any of the
// triangles in the box.
typedef std::tuple<int, int, int> face_t;
typedef std::vector<std::tuple<face_t, int, int, types::BoundingBox3D>> tree_t;

class BoundaryVolumeHierarchy {
   private:
    const std::shared_ptr<trimesh::Trimesh3D> trimesh;

    tree_t tree;

   public:
    BoundaryVolumeHierarchy(const trimesh::Trimesh3D &t);
    ~BoundaryVolumeHierarchy() = default;

    // Accessors.
    const std::shared_ptr<trimesh::Trimesh3D> get_trimesh() const {
        return this->trimesh;
    }
    tree_t get_tree() const { return this->tree; }

    // Returns the intersected faces and the intersection points for a line.
    std::vector<std::tuple<face_t, types::Point3D>> intersections(
        const types::Line3D &l) const;
};

void add_modules(py::module &m);

}  // namespace bvh
}  // namespace cpu
}  // namespace fast_trimesh
