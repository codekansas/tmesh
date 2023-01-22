#include "bvh.h"

#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>

using namespace pybind11::literals;

namespace trimesh {

/* ---- *
 *  BVH *
 * ---- */

void sort_bounding_boxes(const std::vector<bounding_box_3d_t> &boxes,
                         std::vector<size_t> &indices, tree_t &tree, size_t lo,
                         size_t hi) {
    // If the number of boxes is less than 2, then there is nothing to sort.
    if (hi - lo < 2) {
        tree[lo] = {indices[lo], -1, -1, boxes[indices[lo]]};
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
        const auto &box = boxes[indices[i]];
        min_x = std::min(min_x, box.min.x);
        min_y = std::min(min_y, box.min.y);
        min_z = std::min(min_z, box.min.z);
        max_x = std::max(max_x, box.max.x);
        max_y = std::max(max_y, box.max.y);
        max_z = std::max(max_z, box.max.z);
    }

    // Gets the longest axis.
    float dx = max_x - min_x, dy = max_y - min_y, dz = max_z - min_z;
    size_t axis = 0;
    if (dy > dx) {
        axis = 1;
        dx = dy;
    }
    if (dz > dx) {
        axis = 2;
    }

    auto get_axis_vals = [&axis](const bounding_box_3d_t &box) {
        auto min = box.min, max = box.max;
        switch (axis) {
            case 0:
                return std::make_pair(min.x, max.x);
            case 1:
                return std::make_pair(min.y, max.y);
            case 2:
                return std::make_pair(min.z, max.z);
            default:
                throw std::runtime_error("Invalid axis.");
        }
    };

    auto get_sort_val = [&boxes, &get_axis_vals](const size_t &i) {
        auto [min, max] = get_axis_vals(boxes[i]);
        return (min + max) / 2;
    };

    // Sorts the bounding boxes along the longest axis.
    std::sort(indices.begin() + lo, indices.begin() + hi,
              [&get_sort_val](const size_t &a, const size_t &b) {
                  return get_sort_val(a) < get_sort_val(b);
              });

    // Gets the middle element, which will be the root of the subtree.
    size_t mid = (hi - lo + 1) / 2;
    std::swap(indices[lo], indices[lo + mid]);
    tree[lo] = {indices[lo],
                mid == 1 ? -1 : lo + 1,
                mid == (hi - lo) ? -1 : lo + mid,
                {{min_x, min_y, min_z}, {max_x, max_y, max_z}}};

    // Recursively sorts the left and right halves.
    sort_bounding_boxes(boxes, indices, tree, lo + 1, lo + mid);
    sort_bounding_boxes(boxes, indices, tree, lo + mid, hi);
}

bvh_3d_t::bvh_3d_t(const trimesh_3d_t &t)
    : trimesh(std::make_shared<trimesh_3d_t>(t)) {
    // Builds the boundaary volume hierachy tree.
    // First, we build a vector of boxes, where each box is represented as a
    // tuple of (min, max), where min and max are the minimum and maximum
    // coordinates of the box, respectively.
    std::vector<bounding_box_3d_t> boxes;
    for (auto &face : t.faces())
        boxes.push_back(bounding_box_3d_t({t.get_triangle(face)}));

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
    sort_bounding_boxes(boxes, indices, tree, 0, boxes.size());
}

void intersections_helper(
    const tree_t tree, const std::shared_ptr<trimesh_3d_t> &trimesh, int id,
    const line_3d_t &l,
    std::vector<std::tuple<size_t, face_t, point_3d_t>> &intrs) {
    if (id < 0 || id >= tree.size()) throw std::runtime_error("Invalid ID");

    // Gets the bounding box of the current node.
    auto box = std::get<3>(tree[id]);

    // Checks if the line intersects the bounding box.
    if (!l.intersects_bounding_box(box)) {
        return;
    }

    // Checks if the line intersects the current triangle.
    auto face_id = std::get<0>(tree[id]);
    auto face_indices = trimesh->faces()[face_id];
    triangle_3d_t face = {trimesh->vertices()[face_indices.a],
                          trimesh->vertices()[face_indices.b],
                          trimesh->vertices()[face_indices.c]};
    if (auto intr = l.triangle_intersection(face)) {
        intrs.push_back({face_id, face_indices, *intr});
    }

    // Recursively checks the left and right subtrees.
    auto lhs = std::get<1>(tree[id]), rhs = std::get<2>(tree[id]);
    if (lhs != -1) intersections_helper(tree, trimesh, lhs, l, intrs);
    if (rhs != -1) intersections_helper(tree, trimesh, rhs, l, intrs);
}

std::vector<std::tuple<size_t, face_t, point_3d_t>> bvh_3d_t::intersections(
    const line_3d_t &l) const {
    std::vector<std::tuple<size_t, face_t, point_3d_t>> intrs;
    intersections_helper(tree, trimesh, 0, l, intrs);
    return intrs;
}

std::string bvh_3d_t::to_string() const {
    std::stringstream ss;
    ss << "BVH3D(" << trimesh->to_string() << ")";
    return ss.str();
}

void add_3d_bvh_modules(py::module &m) {
    auto bvh_3d = py::class_<bvh_3d_t, std::shared_ptr<bvh_3d_t>>(m, "BVH3D");

    bvh_3d
        .def(py::init<trimesh_3d_t &>(), "Boundary volume hierarchy",
             "trimesh"_a)
        .def("__str__", &bvh_3d_t::to_string, "String representation",
             py::is_operator())
        .def("__repr__", &bvh_3d_t::to_string, "String representation",
             py::is_operator())
        .def("intersections", &bvh_3d_t::intersections, "Intersections",
             "line"_a)
        .def_property_readonly("trimesh", &bvh_3d_t::get_trimesh, "Trimesh")
        .def_property_readonly("tree", &bvh_3d_t::get_tree, "Tree");
}

}  // namespace trimesh
