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

void sort_bounding_boxes(const std::vector<BoundingBox2D> &boxes,
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

    auto get_axis_vals = [&axis](const BoundingBox2D &box) {
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

BVH2D::BVH2D(const Trimesh2D &t) : trimesh(std::make_shared<Trimesh2D>(t)) {
    std::vector<BoundingBox2D> boxes;
    for (const auto &face : t.faces())
        boxes.push_back(BoundingBox2D({t.get_triangle(face)}));

    std::vector<size_t> indices(boxes.size());
    std::iota(indices.begin(), indices.end(), 0);
    tree.resize(boxes.size());
    sort_bounding_boxes(boxes, indices, tree, 0, boxes.size());
}

void intersections_helper(const tree_t tree,
                          const std::shared_ptr<Trimesh2D> &trimesh, int id,
                          const Triangle2D &t, std::vector<face_t> &intrs) {
    if (id < 0 || id >= tree.size()) throw std::runtime_error("Invalid ID");

    auto &[face_id, lhs, rhs, box] = tree[id];

    // If the triangle doesn't intersect the current bounding box, then
    // there's no need to check child triangles.
    if (!box.intersects_triangle(t)) {
        return;
    }

    // Checks if the line intersects the current triangle.
    auto &face_indices = trimesh->faces()[face_id];
    Triangle2D face = {trimesh->vertices()[std::get<0>(face_indices)],
                       trimesh->vertices()[std::get<1>(face_indices)],
                       trimesh->vertices()[std::get<2>(face_indices)]};
    if (face.intersects_triangle(t)) {
        intrs.push_back(face_indices);
    }

    // Recursively checks the left and right subtrees.
    if (lhs != -1) intersections_helper(tree, trimesh, lhs, t, intrs);
    if (rhs != -1) intersections_helper(tree, trimesh, rhs, t, intrs);
}

std::vector<face_t> BVH2D::intersections(const Triangle2D &t) const {
    std::vector<face_t> intrs;
    intersections_helper(tree, trimesh, 0, t, intrs);
    return intrs;
}

std::string BVH2D::to_string() const {
    std::stringstream ss;
    ss << "BVH2D(" << trimesh->to_string() << ")";
    return ss.str();
}

void add_2d_bvh_modules(py::module &m) {
    py::class_<BVH2D, std::shared_ptr<BVH2D>>(m, "BVH2D")
        .def(py::init<Trimesh2D &>(), "Boundary volume hierarchy", "trimesh"_a)
        .def("__str__", &BVH2D::to_string, "String representation",
             py::is_operator())
        .def("__repr__", &BVH2D::to_string, "String representation",
             py::is_operator())
        .def("intersections", &BVH2D::intersections, "Intersections",
             "triangle"_a)
        .def_property_readonly("trimesh", &BVH2D::get_trimesh, "Trimesh")
        .def_property_readonly("tree", &BVH2D::get_tree, "Tree");
}

}  // namespace bvh
}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
