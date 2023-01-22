#include "bvh.h"

#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>
#include <unordered_set>

#include "../options.h"

using namespace pybind11::literals;

namespace trimesh {

/* ------------------------ *
 * triangle_split_tree_2d_t *
 * ------------------------ */

triangle_split_tree_2d_t::triangle_split_tree_2d_t(
    const face_t &root, const std::vector<point_2d_t> &vertices)
    : root(root) {
    this->faces = {{0, 1, 2}};
    this->children = {{}};
    auto &[a, b, c] = root;
    this->vertices = {vertices[a], vertices[b], vertices[c]};
}

void triangle_split_tree_2d_t::add_triangle(const face_t &f,
                                            const size_t parent) {
    triangle_2d_t t{vertices[f.a], vertices[f.b], vertices[f.c]};
    if (t.area() < get_tolerance()) return;

    this->faces.push_back({f.a, f.b, f.c});
    this->children.push_back(std::vector<size_t>{});
    this->children[parent].push_back(this->children.size() - 1);
}

size_t triangle_split_tree_2d_t::add_point(const point_2d_t &p) {
    this->vertices.push_back(p);
    return this->vertices.size() - 1;
}

size_t triangle_split_tree_2d_t::maybe_add_point(const point_2d_t &p,
                                                 const size_t a,
                                                 const point_2d_t &pa,
                                                 const size_t b,
                                                 const point_2d_t &pb) {
    if (p == pa) return a;
    if (p == pb) return b;
    return add_point(p);
}

bool triangle_split_tree_2d_t::is_leaf(size_t i) const {
    return this->children[i].empty();
}

std::vector<size_t>
triangle_split_tree_2d_t::get_leaf_triangles_which_intersect_point(
    const point_2d_t &p) const {
    std::unordered_set<size_t> leaf_triangles;
    std::queue<size_t> q;
    q.push(0);
    while (!q.empty()) {
        size_t i = q.front();
        q.pop();
        auto t = get_triangle(i);
        if (t.contains_point(p)) {
            if (is_leaf(i)) {
                leaf_triangles.insert(i);
            } else {
                for (auto &child : this->children[i]) {
                    q.push(child);
                }
            }
        }
    }
    return std::vector<size_t>(leaf_triangles.begin(), leaf_triangles.end());
}

std::vector<size_t>
triangle_split_tree_2d_t::get_leaf_triangles_which_intersect_line(
    const line_2d_t &l) const {
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
    return std::vector<size_t>(leaf_triangles.begin(), leaf_triangles.end());
}

void triangle_split_tree_2d_t::split_triangle_at_point(const point_2d_t &p,
                                                       size_t i) {
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

void triangle_split_tree_2d_t::split_triangle_at_line(const line_2d_t &l,
                                                      size_t i) {
    const auto f = faces[i];
    const auto t = get_triangle(i);

    // Gets the intersection points the line and each edge of the triangle.
    line_2d_t l1{t.p1, t.p2}, l2{t.p2, t.p3}, l3{t.p3, t.p1};
    auto i1 = l1.line_intersection(l), i2 = l2.line_intersection(l),
         i3 = l3.line_intersection(l);

    // Cuts the triangle when it passes through two intersections.
    if (i1.has_value() && i2.has_value()) {
        auto new_point_1 = maybe_add_point(i1.value(), f.a, t.p1, f.b, t.p2),
             new_point_2 = maybe_add_point(i2.value(), f.b, t.p2, f.c, t.p3);
        add_triangle({f.a, new_point_1, new_point_2}, i);
        add_triangle({new_point_1, f.b, new_point_2}, i);
        add_triangle({new_point_2, f.c, f.a}, i);
        return;
    }
    if (i2.has_value() && i3.has_value()) {
        auto new_point_1 = maybe_add_point(i2.value(), f.b, t.p2, f.c, t.p3),
             new_point_2 = maybe_add_point(i3.value(), f.c, t.p3, f.a, t.p1);
        add_triangle({f.b, new_point_1, new_point_2}, i);
        add_triangle({new_point_1, f.c, new_point_2}, i);
        add_triangle({new_point_2, f.a, f.b}, i);
        return;
    }
    if (i3.has_value() && i1.has_value()) {
        auto new_point_1 = maybe_add_point(i3.value(), f.c, t.p3, f.a, t.p1),
             new_point_2 = maybe_add_point(i1.value(), f.a, t.p1, f.b, t.p2);
        add_triangle({f.c, new_point_1, new_point_2}, i);
        add_triangle({new_point_1, f.a, new_point_2}, i);
        add_triangle({new_point_2, f.b, f.c}, i);
        return;
    }

    // Cuts the triangle when it passes through a single intersection
    // (meaning that it just touches an edge).
    if (i1.has_value()) {
        auto new_point = maybe_add_point(i1.value(), f.a, t.p1, f.b, t.p2);
        add_triangle({f.a, new_point, f.c}, i);
        add_triangle({new_point, f.b, f.c}, i);
        return;
    }
    if (i2.has_value()) {
        auto new_point = maybe_add_point(i2.value(), f.b, t.p2, f.c, t.p3);
        add_triangle({f.b, new_point, f.a}, i);
        add_triangle({new_point, f.c, f.a}, i);
        return;
    }
    if (i3.has_value()) {
        auto new_point = maybe_add_point(i3.value(), f.c, t.p3, f.a, t.p1);
        add_triangle({f.c, new_point, f.b}, i);
        add_triangle({new_point, f.a, f.b}, i);
        return;
    }
}

triangle_2d_t triangle_split_tree_2d_t::get_triangle(size_t i) const {
    const auto &[p1, p2, p3] = faces[i];
    const auto v1 = vertices[p1], v2 = vertices[p2], v3 = vertices[p3];
    triangle_2d_t ret_val{v1, v2, v3};
    return ret_val;
}

const std::vector<size_t> triangle_split_tree_2d_t::get_children(
    size_t i) const {
    return children[i];
}

const std::vector<face_t> triangle_split_tree_2d_t::get_leaf_faces(
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

const std::vector<point_2d_t> triangle_split_tree_2d_t::get_vertices() const {
    std::vector<point_2d_t> v(vertices.begin() + 3, vertices.end());
    return v;
}

const size_t triangle_split_tree_2d_t::count_leaf_triangles() const {
    size_t count = 0;
    for (size_t i = 0; i < faces.size(); i++) {
        if (is_leaf(i)) {
            count++;
        }
    }
    return count;
}

/* -------- *
 * bvh_2d_t *
 * -------- */

void sort_bounding_boxes(const std::vector<bounding_box_2d_t> &boxes,
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

    auto get_axis_vals = [&axis](const bounding_box_2d_t &box) {
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

bvh_2d_t::bvh_2d_t(const trimesh_2d_t &t)
    : trimesh(std::make_shared<trimesh_2d_t>(t)) {
    std::vector<bounding_box_2d_t> boxes;
    for (const auto &face : t.faces())
        boxes.push_back(bounding_box_2d_t({t.get_triangle(face)}));

    std::vector<size_t> indices(boxes.size());
    std::iota(indices.begin(), indices.end(), 0);
    tree.resize(boxes.size());
    sort_bounding_boxes(boxes, indices, tree, 0, boxes.size());
}

void intersections_helper(const tree_t tree,
                          const std::shared_ptr<trimesh_2d_t> &trimesh, int id,
                          const triangle_2d_t &t, std::vector<face_t> &intrs) {
    if (id < 0 || id >= tree.size()) throw std::runtime_error("Invalid ID");

    auto &[face_id, lhs, rhs, box] = tree[id];

    // If the triangle doesn't intersect the current bounding box, then
    // there's no need to check child triangles.
    if (!box.intersects_triangle(t)) {
        return;
    }

    // Checks if the line intersects the current triangle.
    auto &face_indices = trimesh->faces()[face_id];
    triangle_2d_t face = {trimesh->vertices()[face_indices.a],
                          trimesh->vertices()[face_indices.b],
                          trimesh->vertices()[face_indices.c]};
    if (face.intersects_triangle(t)) {
        intrs.push_back(face_indices);
    }

    // Recursively checks the left and right subtrees.
    if (lhs != -1) intersections_helper(tree, trimesh, lhs, t, intrs);
    if (rhs != -1) intersections_helper(tree, trimesh, rhs, t, intrs);
}

std::vector<face_t> bvh_2d_t::intersections(const triangle_2d_t &t) const {
    std::vector<face_t> intrs;
    intersections_helper(tree, trimesh, 0, t, intrs);
    return intrs;
}

std::optional<face_t> get_containing_face_helper(
    const tree_t tree, const std::shared_ptr<trimesh_2d_t> &trimesh, int id,
    const triangle_2d_t &t) {
    if (id < 0 || id >= tree.size()) return std::nullopt;

    auto &[face_id, lhs, rhs, box] = tree[id];

    // If some part of the triangle is outside the current bounding box, then
    // the triangle is not inside the mesh.
    if (!box.contains_triangle(t)) {
        return std::nullopt;
    }

    // Checks if the triangle is inside the current triangle.
    auto &face_indices = trimesh->faces()[face_id];
    triangle_2d_t face = {trimesh->vertices()[face_indices.a],
                          trimesh->vertices()[face_indices.b],
                          trimesh->vertices()[face_indices.c]};
    if (face.contains_triangle(t)) {
        return face_indices;
    }

    // Recursively checks the left and right subtrees.
    if (auto face = get_containing_face_helper(tree, trimesh, lhs, t))
        return face;
    if (auto face = get_containing_face_helper(tree, trimesh, rhs, t))
        return face;
    return std::nullopt;
}

std::optional<face_t> bvh_2d_t::get_containing_face(
    const triangle_2d_t &t) const {
    return get_containing_face_helper(tree, trimesh, 0, t);
}

std::string bvh_2d_t::to_string() const {
    std::stringstream ss;
    ss << "BVH2D(" << trimesh->to_string() << ")";
    return ss.str();
}

void add_2d_bvh_modules(py::module &m) {
    auto ttree_2d = py::class_<triangle_split_tree_2d_t,
                               std::shared_ptr<triangle_split_tree_2d_t>>(
        m, "TriangleSplitTree2D");
    auto bvh_2d = py::class_<bvh_2d_t, std::shared_ptr<bvh_2d_t>>(m, "BVH2D");

    ttree_2d
        .def(py::init<const face_t &, const std::vector<point_2d_t> &>(),
             "face"_a, "vertices"_a,
             "Constructs a 2D triangle split tree from a face and a list "
             "of vertices.")
        .def("is_leaf", &triangle_split_tree_2d_t::is_leaf, "i"_a,
             "Returns true if the node is a leaf.")
        .def(
            "get_leaf_triangles_which_intersect_point",
            &triangle_split_tree_2d_t::get_leaf_triangles_which_intersect_point,
            "point"_a, "Returns the triangles which intersect the point.")
        .def("get_leaf_triangles_which_intersect_line",
             &triangle_split_tree_2d_t::get_leaf_triangles_which_intersect_line,
             "line"_a, "Returns the triangles which intersect the line.")
        .def("split_triangle_at_point",
             &triangle_split_tree_2d_t::split_triangle_at_point, "point"_a,
             "i"_a, "Splits a triangle at a point.")
        .def("split_triangle_at_line",
             &triangle_split_tree_2d_t::split_triangle_at_line, "line"_a, "i"_a,
             "Splits a triangle at a line.")
        .def("get_triangle", &triangle_split_tree_2d_t::get_triangle, "i"_a,
             "Returns the triangle associated with the node.")
        .def("get_children", &triangle_split_tree_2d_t::get_children, "i"_a,
             "Returns the children of a node")
        .def("get_vertices", &triangle_split_tree_2d_t::get_vertices,
             "Returns the vertices of the tree.")
        .def("__len__", &triangle_split_tree_2d_t::count_leaf_triangles,
             "Returns the number of leaf triangles", py::is_operator())
        .def("__getitem__", &triangle_split_tree_2d_t::get_triangle, "i"_a,
             "Get a node", py::is_operator());

    bvh_2d
        .def(py::init<trimesh_2d_t &>(), "Boundary volume hierarchy",
             "trimesh"_a)
        .def("__str__", &bvh_2d_t::to_string, "String representation",
             py::is_operator())
        .def("__repr__", &bvh_2d_t::to_string, "String representation",
             py::is_operator())
        .def("intersections", &bvh_2d_t::intersections, "Intersections",
             "triangle"_a)
        .def_property_readonly("trimesh", &bvh_2d_t::get_trimesh, "Trimesh")
        .def_property_readonly("tree", &bvh_2d_t::get_tree, "Tree");
}

}  // namespace trimesh
