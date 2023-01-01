#include "bvh.h"

namespace fast_trimesh {
namespace cpu {
namespace bvh {

void sort_bounding_boxes(
    const std::vector<geometry::BoundingBox3D> &boxes,
    std::vector<size_t> &indices,
    std::vector<std::tuple<size_t, size_t, size_t, geometry::BoundingBox3D>>
        &tree,
    size_t lo, size_t hi) {
    // If the number of boxes is less than 2, then there is nothing to sort.
    if (hi - lo < 2) {
        tree[lo] = {indices[lo], lo, lo, boxes[indices[lo]]};
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
        auto min = std::get<0>(boxes[indices[i]]);
        auto max = std::get<1>(boxes[indices[i]]);
        min_x = std::min(min_x, std::get<0>(min));
        min_y = std::min(min_y, std::get<1>(min));
        min_z = std::min(min_z, std::get<2>(min));
        max_x = std::max(max_x, std::get<0>(max));
        max_y = std::max(max_y, std::get<1>(max));
        max_z = std::max(max_z, std::get<2>(max));
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

    auto get_axis_vals = [axis](const geometry::BoundingBox3D &box) {
        auto min = std::get<0>(box);
        auto max = std::get<1>(box);
        std::tuple<float, float> vals;
        switch (axis) {
            case 0:
                vals = std::make_tuple(std::get<0>(min), std::get<0>(max));
                break;
            case 1:
                vals = std::make_tuple(std::get<1>(min), std::get<1>(max));
                break;
            case 2:
                vals = std::make_tuple(std::get<2>(min), std::get<2>(max));
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
    size_t mid = (hi - lo) / 2;
    size_t root = indices[lo + mid];
    std::swap(indices[lo], indices[lo + mid]);
    tree[lo] = {indices[lo],
                lo + 1,
                lo + mid,
                {{min_x, min_y, min_z}, {max_x, max_y, max_z}}};

    // Recursively sorts the left and right halves.
    sort_bounding_boxes(boxes, indices, tree, lo + 1, lo + mid);
    sort_bounding_boxes(boxes, indices, tree, lo + mid, hi);
}

BoundaryVolumeHierarchy::BoundaryVolumeHierarchy(trimesh::Trimesh3D &t) {
    // Sets shared pointer to the trimesh.
    trimesh = std::make_shared<trimesh::Trimesh3D>(t);

    // Builds the boundaary volume hierachy tree.
    // First, we build a vector of boxes, where each box is represented as a
    // tuple of (min, max), where min and max are the minimum and maximum
    // coordinates of the box, respectively.
    std::vector<geometry::BoundingBox3D> boxes;
    for (int i = 0; i < t.num_faces(); i++) {
        auto face = t.get_face(i);
        auto v1 = t.get_vertex(std::get<0>(face));
        auto v2 = t.get_vertex(std::get<1>(face));
        auto v3 = t.get_vertex(std::get<2>(face));
        auto box = geometry::bounding_box({v1, v2, v3});
        boxes.push_back(box);
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
    sort_bounding_boxes(boxes, indices, tree, 0, boxes.size());
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("bvh");
    s.doc() = "Bounding volume hierarchy module";

    py::class_<BoundaryVolumeHierarchy,
               std::shared_ptr<BoundaryVolumeHierarchy>>(
        s, "BoundaryVolumeHierarchy")
        .def(py::init<trimesh::Trimesh3D &>(), "Boundary volume hierarchy",
             py::arg("trimesh"))
        .def_property_readonly("trimesh", &BoundaryVolumeHierarchy::get_trimesh,
                               "Trimesh")
        .def_property_readonly("tree", &BoundaryVolumeHierarchy::get_tree,
                               "Tree");
}

}  // namespace bvh
}  // namespace cpu
}  // namespace fast_trimesh
