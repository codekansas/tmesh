#include "bvh.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace bvh {

void sort_bounding_boxes(const std::vector<types::BoundingBox3D> &boxes,
                         const std::vector<std::tuple<int, int, int>> &faces,
                         std::vector<size_t> &indices, tree_t &tree, size_t lo,
                         size_t hi) {
    // If the number of boxes is less than 2, then there is nothing to sort.
    if (hi - lo < 2) {
        tree[lo] = {faces[indices[lo]], -1, -1, boxes[indices[lo]]};
        return;
    }

    // Gets the bounding box for the bounding boxes.
    float min_x = std::numeric_limits<float>::max(),
          min_y = std::numeric_limits<float>::max(),
          min_z = std::numeric_limits<float>::max(),
          max_x = std::numeric_limits<float>::lowest(),
          max_y = std::numeric_limits<float>::lowest(),
          max_z = std::numeric_limits<float>::lowest();
    for (size_t i = lo; i < hi; i++) {
        auto min = boxes[indices[i]].min;
        auto max = boxes[indices[i]].max;
        min_x = std::min(min_x, min.x);
        min_y = std::min(min_y, min.y);
        min_z = std::min(min_z, min.z);
        max_x = std::max(max_x, max.x);
        max_y = std::max(max_y, max.y);
        max_z = std::max(max_z, max.z);
    }

    // Gets the longest axis.
    float dx = max_x - min_x;
    float dy = max_y - min_y;
    float dz = max_z - min_z;
    size_t axis = 0;
    if (dy > dx) {
        axis = 1;
        dx = dy;
    }
    if (dz > dx) {
        axis = 2;
    }

    auto get_axis_vals = [axis](const types::BoundingBox3D &box) {
        auto min = box.min, max = box.max;
        std::tuple<float, float> vals;
        switch (axis) {
            case 0:
                vals = std::make_tuple(min.x, max.x);
                break;
            case 1:
                vals = std::make_tuple(min.y, max.y);
                break;
            case 2:
                vals = std::make_tuple(min.z, max.z);
                break;
        }
        return vals;
    };

    auto get_sort_val = [boxes, get_axis_vals](const size_t &i) {
        auto min_max = get_axis_vals(boxes[i]);
        return (std::get<0>(min_max) + std::get<1>(min_max)) / 2;
    };

    // Sorts the bounding boxes along the longest axis.
    std::sort(indices.begin() + lo, indices.begin() + hi,
              [get_sort_val](const size_t &a, const size_t &b) {
                  return get_sort_val(a) < get_sort_val(b);
              });

    // Gets the middle element, which will be the root of the subtree.
    size_t mid = (hi - lo + 1) / 2;
    std::swap(indices[lo], indices[lo + mid]);
    tree[lo] = {faces[indices[lo]],
                mid == 1 ? -1 : lo + 1,
                mid == (hi - lo) ? -1 : lo + mid,
                {{min_x, min_y, min_z}, {max_x, max_y, max_z}}};

    // Recursively sorts the left and right halves.
    sort_bounding_boxes(boxes, faces, indices, tree, lo + 1, lo + mid);
    sort_bounding_boxes(boxes, faces, indices, tree, lo + mid, hi);
}

BoundaryVolumeHierarchy::BoundaryVolumeHierarchy(const trimesh::Trimesh3D &t)
    : trimesh(std::make_shared<trimesh::Trimesh3D>(t)) {
    // Builds the boundaary volume hierachy tree.
    // First, we build a vector of boxes, where each box is represented as a
    // tuple of (min, max), where min and max are the minimum and maximum
    // coordinates of the box, respectively.
    std::vector<types::BoundingBox3D> boxes;
    for (auto &triangle : t.get_triangles()) {
        boxes.push_back(types::BoundingBox3D({triangle}));
    }

    // Insert the boxes into the tree.
    //
    //         4
    //        / \
    //       /   \
    //      3     5
    //     / \   / \
    //    0   2 6   7
    //     \         \
    //      1         8
    //
    // Indices:
    // 0  1  2  3  4  5  6  7  8
    // As a vector:
    // 4  3  5  0  2  6  7  1  8
    // LHS pointer:
    // 1  3  5 -1 -1 -1 -1 -1 -1
    // RHS pointer:
    // 2  4  6  7 -1 -1  8 -1 -1
    std::vector<size_t> indices(boxes.size());
    std::iota(indices.begin(), indices.end(), 0);
    tree.resize(boxes.size());
    sort_bounding_boxes(boxes, t.get_faces(), indices, tree, 0, boxes.size());
}

void intersections_helper(
    tree_t tree, const std::vector<types::Point3D> &vertices, int id,
    const types::Line3D &l,
    std::vector<std::tuple<face_t, types::Point3D>> &intersections) {
    if (id < 0 || id >= tree.size()) throw std::runtime_error("Invalid ID");

    // Gets the bounding box of the current node.
    auto box = std::get<3>(tree[id]);

    // Checks if the line intersects the bounding box.
    if (!l.intersects_bounding_box(box)) {
        return;
    }

    // Checks if the line intersects the current triangle.
    auto face_indices = std::get<0>(tree[id]);
    types::Triangle3D face = {vertices[std::get<0>(face_indices)],
                              vertices[std::get<1>(face_indices)],
                              vertices[std::get<2>(face_indices)]};
    if (auto intr = l.triangle_intersection(face)) {
        intersections.push_back({face_indices, *intr});
    }

    // Recursively checks the left and right subtrees.
    auto lhs = std::get<1>(tree[id]), rhs = std::get<2>(tree[id]);
    if (lhs != -1) intersections_helper(tree, vertices, lhs, l, intersections);
    if (rhs != -1) intersections_helper(tree, vertices, rhs, l, intersections);
}

std::vector<std::tuple<face_t, types::Point3D>>
BoundaryVolumeHierarchy::intersections(const types::Line3D &l) const {
    std::vector<std::tuple<face_t, types::Point3D>> intersections;
    intersections_helper(tree, trimesh->get_vertices(), 0, l, intersections);
    return intersections;
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("bvh");
    s.doc() = "Bounding volume hierarchy module";

    py::class_<BoundaryVolumeHierarchy,
               std::shared_ptr<BoundaryVolumeHierarchy>>(
        s, "BoundaryVolumeHierarchy")
        .def(py::init<trimesh::Trimesh3D &>(), "Boundary volume hierarchy",
             "trimesh"_a)
        .def("intersections", &BoundaryVolumeHierarchy::intersections,
             "Intersections", "line"_a)
        .def_property_readonly("trimesh", &BoundaryVolumeHierarchy::get_trimesh,
                               "Trimesh")
        .def_property_readonly("tree", &BoundaryVolumeHierarchy::get_tree,
                               "Tree");
}

}  // namespace bvh
}  // namespace cpu
}  // namespace fast_trimesh
