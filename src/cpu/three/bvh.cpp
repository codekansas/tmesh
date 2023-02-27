#include "bvh.h"

#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>

#include "../options.h"

using namespace pybind11::literals;

namespace trimesh {

/* -------------- *
 * point_3d_set_t *
 * -------------- */

point_3d_set_t::point_3d_set_t(const std::initializer_list<point_3d_t> &points)
    : points(points) {
    for (size_t i = 0; i < this->points.size(); ++i)
        this->indices[this->points[i]] = i;
}

point_3d_t point_3d_set_t::operator[](size_t i) const { return points[i]; }

size_t point_3d_set_t::add_point(const point_3d_t &p) {
    if (auto it = point_id(p); it.has_value()) return it.value();
    points.push_back(p);
    indices[p] = points.size() - 1;
    return points.size() - 1;
}

size_t point_3d_set_t::size() const { return points.size(); }

size_t point_3d_set_t::get_point(const point_3d_t &p) const {
    return indices.at(p);
}

point_3d_t point_3d_set_t::get_point(size_t i) const { return points[i]; }

std::optional<size_t> point_3d_set_t::point_id(const point_3d_t &p) const {
    if (auto it = indices.find(p); it != indices.end()) return it->second;
    return std::nullopt;
}

const std::vector<point_3d_t> &point_3d_set_t::get_points() const {
    return points;
}

/* ------------------------ *
 * delaunay_split_tree_3d_t *
 * ------------------------ */

void delaunay_split_tree_3d_t::make_delaunay(const size_t &pi, const face_t &f,
                                             const size_t &ti) {
    const auto f_rev = f.flip();

    if (this->face_to_volume.find(f_rev) == this->face_to_volume.end()) {
        return;
    }

    size_t tj = this->face_to_volume[f_rev];
    const auto &tj_vol = this->volumes[tj];
    const auto &tj_tetr = this->get_tetrahedron(tj_vol);

    if (tj_tetr.circumsphere_contains(this->vertices[pi])) {
        const auto &pj = tj_vol.get_other_vertex(f_rev);
        // TODO: This is not working.
        // const auto tk = this->add_volume({pi, pj, e.b}, {ti, tj}),
        //            tl = this->add_volume({pj, pi, e.a}, {ti, tj});

        // this->make_delaunay(pi, {e.a, pj, true}, tl);
        // this->make_delaunay(pi, {pj, e.b, true}, tk);
    }
}

size_t delaunay_split_tree_3d_t::add_volume(
    const volume_t &v, const std::vector<size_t> &parents) {
    const size_t i = this->volumes.size();
    for (const auto &parent : parents) {
        this->children[parent].push_back(i);
    }
    this->volumes.push_back(v);
    for (const auto &volume : v.get_faces()) {
        this->face_to_volume[volume] = i;
    }
    this->children.push_back({});
    return i;
}

delaunay_split_tree_3d_t::delaunay_split_tree_3d_t(const tetrahedron_3d_t &root)
    : root(root) {
    this->volumes = {{0, 1, 2, 3}};
    this->face_to_volume = {};
    for (const auto &f : this->volumes[0].get_faces())
        this->face_to_volume[f] = 0;
    this->children = {{}};
    this->vertices = {root.p1, root.p2, root.p3, root.p4};
}

bool delaunay_split_tree_3d_t::is_leaf(size_t i) const {
    return this->children[i].empty();
}

size_t delaunay_split_tree_3d_t::find_leaf_index(const point_3d_t &p) const {
    size_t i = 0;
    while (!is_leaf(i)) {
        // Gets the closest triangle to the point.
        double min_dist = std::numeric_limits<double>::max();
        size_t min_index = 0;
        for (const auto &child_id : this->children[i]) {
            const auto &child = this->volumes[child_id];
            const tetrahedron_3d_t t{
                this->vertices[child.a], this->vertices[child.b],
                this->vertices[child.c], this->vertices[child.d]};
            double t_dist = p.distance_to_tetrahedron(t);
            if (t_dist < min_dist) {
                min_dist = t_dist;
                min_index = child_id;
            }
        }

        if (min_dist > get_tolerance()) {
            std::ostringstream ss;
            ss << "Could not find leaf triangle for point " << p.to_string()
               << " in tetrahedron " << this->get_tetrahedron(i).to_string()
               << " with " << this->children[i].size()
               << " children:" << std::endl;
            for (const auto &child_id : this->children[i]) {
                ss << " - " << this->get_tetrahedron(child_id).to_string()
                   << " (dist: "
                   << p.distance_to_tetrahedron(this->get_tetrahedron(child_id))
                   << ")" << std::endl;
            }
            throw std::runtime_error(ss.str());
        }

        i = min_index;
    }
    return i;
}

const volume_t &delaunay_split_tree_3d_t::get_volume(size_t i) const {
    return this->volumes[i];
}

tetrahedron_3d_t delaunay_split_tree_3d_t::get_tetrahedron(
    const volume_t &f) const {
    return {this->vertices[f.a], this->vertices[f.b], this->vertices[f.c]};
}

tetrahedron_3d_t delaunay_split_tree_3d_t::get_tetrahedron(size_t i) const {
    const auto &v = this->get_volume(i);
    return this->get_tetrahedron(v);
}

std::vector<size_t> delaunay_split_tree_3d_t::get_leaf_triangles() const {
    std::vector<size_t> leaf_triangles;
    for (size_t i = 0; i < this->children.size(); i++) {
        if (is_leaf(i)) {
            leaf_triangles.push_back(i);
        }
    }
    return leaf_triangles;
}

void delaunay_split_tree_3d_t::split_triangle(const point_3d_t &p, size_t i) {
    const auto pi = this->vertices.add_point(p);
    const auto [fa, fb, fc, fd] = this->volumes[i];
    const auto &va = this->vertices[fa], &vb = this->vertices[fb],
               &vc = this->vertices[fc], &vd = this->vertices[fd];

    // Checks if the point is at the same location as one of the vertices.
    if (p == va || p == vb || p == vc) {
        return;
    }

    // Checks if the point intersects an edge.
    for (const auto [ea, eb, ec] : this->volumes[i].get_faces()) {
        const auto &v1 = this->vertices[ea], &v2 = this->vertices[eb];
        const line_3d_t l{v1, v2};
        if (l.closest_point(p) == p) {
            const face_t e{ea, eb, true}, e_rev{eb, ea, true};
            const size_t j = this->face_to_volume[e_rev];
            const size_t pc = this->volumes[i].get_other_vertex(e),
                         pn = this->volumes[j].get_other_vertex(e_rev);

            // TODO: This is not working.

            // Splits each triangle.
            // const auto t1 = this->add_volume({pi, pc, ea}, {i}),
            //            t2 = this->add_volume({pi, eb, pc}, {i}),
            //            t3 = this->add_volume({pi, ea, pn}, {j}),
            //            t4 = this->add_volume({pi, pn, eb}, {j});

            // Makes the new triangles Delaunay.
            // this->make_delaunay(pi, {pc, ea, true}, t1);
            // this->make_delaunay(pi, {eb, pc, true}, t2);
            // this->make_delaunay(pi, {ea, pn, true}, t3);
            // this->make_delaunay(pi, {pn, eb, true}, t4);

            return;
        }
    }

    // Splits the current triangle.
    // const auto t1 = this->add_volume({fa, fb, pi}, {i});
    // const auto t2 = this->add_volume({fb, fc, pi}, {i});
    // const auto t3 = this->add_volume({fc, fa, pi}, {i});

    // Makes the new triangles Delaunay.
    // this->make_delaunay(pi, {fa, fb, true}, t1);
    // this->make_delaunay(pi, {fb, fc, true}, t2);
    // this->make_delaunay(pi, {fc, fa, true}, t3);
}

const point_3d_set_t &delaunay_split_tree_3d_t::get_vertices() const {
    return this->vertices;
}

/* -------- *
 * bvh_3d_t *
 * -------- */

void sort_bounding_boxes(const std::vector<bounding_box_3d_t> &boxes,
                         std::vector<size_t> &indices, bvh_tree_t &tree,
                         size_t lo, size_t hi) {
    // If the number of boxes is less than 2, then there is nothing to sort.
    if (hi - lo < 2) {
        tree[lo] = {indices[lo], -1, -1, boxes[indices[lo]]};
        return;
    }

    // Gets the bounding box for the bounding boxes.
    double min_x = std::numeric_limits<double>::max(),
           min_y = std::numeric_limits<double>::max(),
           min_z = std::numeric_limits<double>::max(),
           max_x = std::numeric_limits<double>::lowest(),
           max_y = std::numeric_limits<double>::lowest(),
           max_z = std::numeric_limits<double>::lowest();
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
    double dx = max_x - min_x, dy = max_y - min_y, dz = max_z - min_z;
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
                mid == 1 ? -1 : (int)(lo + 1),
                mid == (hi - lo) ? -1 : (int)(lo + mid),
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
    for (auto &face : t.get_faces())
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
    const bvh_tree_t tree, const std::shared_ptr<trimesh_3d_t> &trimesh, int id,
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
    auto face_indices = trimesh->get_faces()[face_id];
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
        .def("__str__", &bvh_3d_t::to_string, py::is_operator())
        .def("__repr__", &bvh_3d_t::to_string, py::is_operator())
        .def("intersections", &bvh_3d_t::intersections, "Intersections",
             "line"_a)
        .def_property_readonly("trimesh", &bvh_3d_t::get_trimesh, "Trimesh")
        .def_property_readonly("tree", &bvh_3d_t::get_tree, "Tree");
}

}  // namespace trimesh
