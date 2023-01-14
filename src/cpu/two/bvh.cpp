#include "bvh.h"

#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace two {
namespace bvh {

void sort_bounding_boxes(const std::vector<types::BoundingBox2D> &boxes,
                         std::vector<size_t> &indices, tree_t &tree, size_t lo,
                         size_t hi) {
    if (hi - lo < 2) {
        tree[lo] = {indices[lo], -1, -1, boxes[indices[lo]]};
        return;
    }

    float min_x = std::numeric_limits<float>::max(),
          min_y = std::numeric_limits<float>::max(),
          max_x = std::numeric_limits<float>::lowest(),
          max_y = std::numeric_limits<float>::lowest();
    for (size_t i = lo; i < hi; i++) {
        const auto &box = boxes[indices[i]];
        min_x = std::min(min_x, box.min.x);
        min_y = std::min(min_y, box.min.y);
        max_x = std::max(max_x, box.max.x);
        max_y = std::max(max_y, box.max.y);
    }

    float dx = max_x - min_x, dy = max_y - min_y;
    size_t axis = 0;
    if (dx < dy) axis = 1;

    auto get_axis_vals = [&axis](const types::BoundingBox2D &box) {
        auto min = box.min, max = box.max;
        switch (axis) {
            case 0:
                return std::make_pair(min.x, max.x);
            case 1:
                return std::make_pair(min.y, max.y);
            default:
                throw std::runtime_error("Invalid axis.");
        }
    };

    auto get_sort_val = [&boxes, &get_axis_vals](size_t i) {
        auto [min, max] = get_axis_vals(boxes[i]);
        return (min + max) / 2;
    };

    std::sort(indices.begin() + lo, indices.begin() + hi,
              [&get_sort_val](const size_t &a, const size_t &b) {
                  return get_sort_val(a) < get_sort_val(b);
              });

    size_t mid = (hi - lo + 1) / 2;
    std::swap(indices[lo], indices[lo + mid]);
    tree[lo] = {indices[lo],
                mid == 1 ? -1 : lo + 1,
                mid == (hi - lo) ? -1 : lo + mid,
                {{min_x, min_y}, {max_x, max_y}}};

    sort_bounding_boxes(boxes, indices, tree, lo + 1, lo + mid);
    sort_bounding_boxes(boxes, indices, tree, lo + mid, hi);
}

BVH::BVH(const types::Trimesh2D &t)
    : trimesh(std::make_shared<types::Trimesh2D>(t)) {
    std::vector<types::BoundingBox2D> boxes;
    for (const auto &face : t.faces())
        boxes.push_back(types::BoundingBox2D({t.get_triangle(face)}));

    std::vector<size_t> indices;
    std::iota(indices.begin(), indices.end(), 0);
    tree.resize(boxes.size());
    sort_bounding_boxes(boxes, indices, tree, 0, boxes.size());
}

void intersections_helper(
    const tree_t tree, const std::shared_ptr<types::Trimesh2D> &trimesh, int id,
    const types::Line2D &l,
    std::vector<std::tuple<size_t, types::face_t, types::Point2D>> &intrs) {
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
    types::Triangle2D face = {trimesh->vertices()[std::get<0>(face_indices)],
                              trimesh->vertices()[std::get<1>(face_indices)],
                              trimesh->vertices()[std::get<2>(face_indices)]};
    for (auto intr : l.triangle_intersection(face)) {
        intrs.push_back({face_id, face_indices, intr});
    }

    // Recursively checks the left and right subtrees.
    auto lhs = std::get<1>(tree[id]), rhs = std::get<2>(tree[id]);
    if (lhs != -1) intersections_helper(tree, trimesh, lhs, l, intrs);
    if (rhs != -1) intersections_helper(tree, trimesh, rhs, l, intrs);
}

std::vector<std::tuple<size_t, types::face_t, types::Point2D>>
BVH::intersections(const types::Line2D &l) const {
    std::vector<std::tuple<size_t, types::face_t, types::Point2D>> intrs;
    intersections_helper(tree, trimesh, 0, l, intrs);
    return intrs;
}

std::string BVH::to_string() const {
    std::stringstream ss;
    ss << "BVH(" << trimesh->to_string() << ")";
    return ss.str();
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("bvh");
    s.doc() = "Bounding volume hierarchy module";

    py::class_<BVH, std::shared_ptr<BVH>>(s, "BVH")
        .def(py::init<types::Trimesh2D &>(), "Boundary volume hierarchy",
             "trimesh"_a)
        .def("__str__", &BVH::to_string, "String representation",
             py::is_operator())
        .def("__repr__", &BVH::to_string, "String representation",
             py::is_operator())
        .def("intersections", &BVH::intersections, "Intersections", "line"_a)
        .def_property_readonly("trimesh", &BVH::get_trimesh, "Trimesh")
        .def_property_readonly("tree", &BVH::get_tree, "Tree");
}

}  // namespace bvh
}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
