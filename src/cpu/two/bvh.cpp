#include "bvh.h"

#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>

using namespace pybind11::literals;

namespace trimesh {

/* ------------------- *
 * TriangleSplitTree2D *
 * ------------------- */

TriangleSplitTree2D::TriangleSplitTree2D(const face_t &root,
                                         const std::vector<Point2D> &vertices)
    : root(root) {
    this->faces = {{0, 1, 2}};
    this->children = {{}};
    auto &[a, b, c] = root;
    this->vertices = {vertices[a], vertices[b], vertices[c]};
}

void TriangleSplitTree2D::add_triangle(const face_t &f, const size_t parent) {
    this->faces.push_back({f.a, f.b, f.c});
    this->children.push_back(std::vector<size_t>{});
    this->children[parent].push_back(this->children.size() - 1);
}

size_t TriangleSplitTree2D::add_point(const Point2D &p) {
    this->vertices.push_back(p);
    return this->vertices.size() - 1;
}

bool TriangleSplitTree2D::is_leaf(size_t i) const {
    return this->children[i].empty();
}

std::unordered_set<size_t>
TriangleSplitTree2D::get_leaf_triangles_which_intersect(
    const Point2D &p) const {
    std::unordered_set<size_t> leaf_triangles;
    std::queue<size_t> q;
    q.push(0);
    while (!q.empty()) {
        size_t i = q.front();
        q.pop();
        auto t = get_triangle(i);
        if (t.contains(p)) {
            if (is_leaf(i)) {
                leaf_triangles.insert(i);
            } else {
                for (auto &child : this->children[i]) {
                    q.push(child);
                }
            }
        }
    }
    return leaf_triangles;
}

std::unordered_set<size_t>
TriangleSplitTree2D::get_leaf_triangles_which_intersect(const Line2D &l) const {
    std::unordered_set<size_t> leaf_triangles;
    std::queue<size_t> q;
    q.push(0);
    while (!q.empty()) {
        size_t i = q.front();
        q.pop();
        auto t = get_triangle(i);
        if (l.intersects_triangle(t)) {
            if (is_leaf(i)) {
                leaf_triangles.insert(i);
            } else {
                for (auto &child : this->children[i]) {
                    q.push(child);
                }
            }
        }
    }
    return leaf_triangles;
}

void TriangleSplitTree2D::split_triangle(const Point2D &p, size_t i) {
    const auto f = faces[i];
    const auto t = get_triangle(i);

    // Ignore points which are close to vertices.
    if (t.p1 == p || t.p2 == p | t.p3 == p) return;

    // Adds a new point.
    size_t p4 = add_point(p);

    // Create three new triangles.
    add_triangle({p4, f.a, f.b}, i);
    add_triangle({p4, f.b, f.c}, i);
    add_triangle({f.c, p4, f.a}, i);
}

void TriangleSplitTree2D::split_triangle(const Line2D &l, size_t i) {
    const auto f = faces[i];
    const auto t = get_triangle(i);

    // Gets the intersection points the line and each edge of the triangle.
    Line2D l1{t.p1, t.p2}, l2{t.p2, t.p3}, l3{t.p3, t.p1};
    auto i1 = l1.line_intersection(l), i2 = l2.line_intersection(l),
         i3 = l3.line_intersection(l);

    // Does triangle cutting.
    if (i1 != std::nullopt && i2 != std::nullopt) {
        auto new_point_1 = add_point(*i1), new_point_2 = add_point(*i2);
        add_triangle({f.a, new_point_1, new_point_2}, i);
        add_triangle({f.b, f.c, new_point_2}, i);
        add_triangle({new_point_1, f.b, new_point_2}, i);
        return;
    }
    if (i2 != std::nullopt && i3 != std::nullopt) {
        auto new_point_1 = add_point(*i2), new_point_2 = add_point(*i3);
        add_triangle({f.b, new_point_1, new_point_2}, i);
        add_triangle({f.c, f.a, new_point_2}, i);
        add_triangle({new_point_1, f.c, new_point_2}, i);
        return;
    }
    if (i3 != std::nullopt && i1 != std::nullopt) {
        auto new_point_1 = add_point(*i3), new_point_2 = add_point(*i1);
        add_triangle({f.c, new_point_1, new_point_2}, i);
        add_triangle({f.a, f.b, new_point_2}, i);
        add_triangle({new_point_1, f.a, new_point_2}, i);
        return;
    }
}

Triangle2D TriangleSplitTree2D::get_triangle(size_t i) const {
    const auto &[p1, p2, p3] = faces[i];
    const auto v1 = vertices[p1], v2 = vertices[p2], v3 = vertices[p3];
    Triangle2D ret_val{v1, v2, v3};
    return ret_val;
}

const std::vector<face_t> TriangleSplitTree2D::get_leaf_faces(
    size_t offset) const {
    auto get_vertex = [&](const size_t v) {
        switch (v) {
            case 0:
                return this->root.a;
            case 1:
                return this->root.b;
            case 2:
                return this->root.c;
            default:
                return v - 3 + offset;
        }
    };
    std::vector<face_t> leaf_faces;
    for (size_t i = 0; i < faces.size(); i++) {
        if (is_leaf(i)) {
            auto &[a, b, c] = faces[i];
            leaf_faces.push_back({get_vertex(a), get_vertex(b), get_vertex(c)});
        }
    }
    return leaf_faces;
}

const std::vector<Point2D> TriangleSplitTree2D::get_vertices() const {
    std::vector<Point2D> v(vertices.begin() + 3, vertices.end());
    return v;
}

/* ----- *
 * BVH2D *
 * ----- */

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
    Triangle2D face = {trimesh->vertices()[face_indices.a],
                       trimesh->vertices()[face_indices.b],
                       trimesh->vertices()[face_indices.c]};
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

}  // namespace trimesh
