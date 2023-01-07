#include "bvh.h"

#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace bvh {

/* --------------- *
 * IntersectionSet *
 * --------------- */

void IntersectionSet::add(const size_t a, const size_t b,
                          const types::Point3D &p) {
    size_t pid = points.size();
    points.push_back({{a, b}, p});
    a_to_b[a].push_back(pid);
    b_to_a[b].push_back(pid);
}

std::string IntersectionSet::to_string() const {
    std::stringstream ss;
    ss << "IntersectionSet(" << points.size() << " intersections)";
    return ss.str();
}

void add_all_intersections(const BVH3D &bvh, const TrimeshAdjacency &adj,
                           const types::Trimesh3D &a, IntersectionSet &intrs,
                           bool a_to_b) {
    for (size_t i = 0; i < adj.face_to_faces.size(); i++) {
        auto &[fa, fb, fc] = adj.face_to_faces[i];
        edge_t e1{fa, fb}, e2{fb, fc}, e3{fc, fa};
        for (auto &[v1, v2] : {e1, e2, e3}) {
            const types::Line3D line{a.vertices()[v1], a.vertices()[v2]};
            for (const auto &[k, face, pt] : bvh.intersections(line)) {
                if (a_to_b)
                    intrs.add(i, k, pt);
                else
                    intrs.add(k, i, pt);
            }
        }
    }
}

IntersectionSet intersections(const types::Trimesh3D &a,
                              const types::Trimesh3D &b) {
    IntersectionSet intrs;
    intrs.a_to_b.resize(a.faces().size());
    intrs.b_to_a.resize(b.faces().size());

    BVH3D bvh_a{a}, bvh_b{b};
    TrimeshAdjacency adj_a{a}, adj_b{b};

    add_all_intersections(bvh_b, adj_a, a, intrs, true);
    add_all_intersections(bvh_a, adj_b, b, intrs, false);

    return intrs;
}

/* ---------------- *
 * TrimeshAdjacency *
 * ---------------- */

TrimeshAdjacency::TrimeshAdjacency(const types::Trimesh3D &mesh) {
    // Initializes adjacency lists.
    vertex_to_faces.resize(mesh.vertices().size());
    vertex_to_vertices.resize(mesh.vertices().size());
    face_to_vertices.resize(mesh.faces().size());
    face_to_faces.resize(mesh.faces().size());

    // Populates adjacency lists.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        vertex_to_faces[a].push_back(i);
        vertex_to_faces[b].push_back(i);
        vertex_to_faces[c].push_back(i);
        vertex_to_vertices[a].push_back(b);
        vertex_to_vertices[b].push_back(c);
        vertex_to_vertices[c].push_back(a);
        face_to_vertices[i] = {a, b, c};
    }

    // Populates edge-to-face map.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        edge_to_faces[{a, b}] = i;
        edge_to_faces[{b, c}] = i;
        edge_to_faces[{c, a}] = i;
    }

    // Populates face-to-face adjacency list.
    for (size_t i = 0; i < mesh.faces().size(); i++) {
        auto &[a, b, c] = mesh.faces()[i];
        edge_t ba = {b, a}, cb = {c, b}, ac = {a, c};
        for (const edge_t &e : {ba, cb, ac}) {
            if (edge_to_faces.find(e) == edge_to_faces.end()) {
                throw std::runtime_error("Mesh is not manifold; edge " +
                                         std::to_string(std::get<0>(e)) + ", " +
                                         std::to_string(std::get<1>(e)) +
                                         " is not shared.");
            }
        }
        face_to_faces[i] = {edge_to_faces[ba], edge_to_faces[cb],
                            edge_to_faces[ac]};
    }
}

void TrimeshAdjacency::validate() const {
    // Checks that all vertices are connected.
    std::vector<bool> visited(vertex_to_vertices.size(), false);
    std::queue<size_t> queue;
    queue.push(0);
    while (!queue.empty()) {
        auto &i = queue.front();
        queue.pop();
        for (auto &j : vertex_to_vertices[i]) {
            if (!visited[j]) queue.push(j);
            visited[j] = true;
        }
    }
    size_t num_invalid = 0;
    for (const auto &v : visited)
        if (!v) {
            num_invalid++;
            std::cout << "Vertex " << std::to_string(&v - &visited[0])
                      << " is not connected." << std::endl;
        }
    if (num_invalid > 0)
        throw std::runtime_error("Mesh is not connected; found " +
                                 std::to_string(num_invalid) +
                                 " unconnected vertices.");
}

/* ------ *
 *  BVH3D *
 * ------ */

void sort_bounding_boxes(const std::vector<types::BoundingBox3D> &boxes,
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
    tree[lo] = {indices[lo],
                mid == 1 ? -1 : lo + 1,
                mid == (hi - lo) ? -1 : lo + mid,
                {{min_x, min_y, min_z}, {max_x, max_y, max_z}}};

    // Recursively sorts the left and right halves.
    sort_bounding_boxes(boxes, indices, tree, lo + 1, lo + mid);
    sort_bounding_boxes(boxes, indices, tree, lo + mid, hi);
}

BVH3D::BVH3D(const types::Trimesh3D &t)
    : trimesh(std::make_shared<types::Trimesh3D>(t)) {
    // Builds the boundaary volume hierachy tree.
    // First, we build a vector of boxes, where each box is represented as a
    // tuple of (min, max), where min and max are the minimum and maximum
    // coordinates of the box, respectively.
    std::vector<types::BoundingBox3D> boxes;
    for (auto &face : t.faces())
        boxes.push_back(types::BoundingBox3D({t.get_triangle(face)}));

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
    const tree_t tree, const std::shared_ptr<types::Trimesh3D> &trimesh, int id,
    const types::Line3D &l,
    std::vector<std::tuple<size_t, types::face_t, types::Point3D>> &intrs) {
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
    types::Triangle3D face = {trimesh->vertices()[std::get<0>(face_indices)],
                              trimesh->vertices()[std::get<1>(face_indices)],
                              trimesh->vertices()[std::get<2>(face_indices)]};
    if (auto intr = l.triangle_intersection(face)) {
        intrs.push_back({face_id, face_indices, *intr});
    }

    // Recursively checks the left and right subtrees.
    auto lhs = std::get<1>(tree[id]), rhs = std::get<2>(tree[id]);
    if (lhs != -1) intersections_helper(tree, trimesh, lhs, l, intrs);
    if (rhs != -1) intersections_helper(tree, trimesh, rhs, l, intrs);
}

std::vector<std::tuple<size_t, types::face_t, types::Point3D>>
BVH3D::intersections(const types::Line3D &l) const {
    std::vector<std::tuple<size_t, types::face_t, types::Point3D>> intrs;
    intersections_helper(tree, trimesh, 0, l, intrs);
    std::cout << "BVH3D::intersections: " << intrs.size() << " intersections"
              << std::endl;
    std::cout << "  Line: " << l.to_string() << std::endl;
    for (auto &intr : intrs) {
        std::cout << "  Face: "
                  << trimesh->get_triangles()[std::get<0>(intr)].to_string()
                  << std::endl;
        std::cout << "  Point: " << std::get<2>(intr).to_string() << std::endl;
    }
    return intrs;
}

std::string BVH3D::to_string() const {
    std::stringstream ss;
    ss << "BVH3D(" << trimesh->to_string() << ")";
    return ss.str();
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("bvh");
    s.doc() = "Bounding volume hierarchy module";

    py::class_<BVH3D, std::shared_ptr<BVH3D>>(s, "BVH3D")
        .def(py::init<types::Trimesh3D &>(), "Boundary volume hierarchy",
             "trimesh"_a)
        .def("__str__", &BVH3D::to_string, "String representation",
             py::is_operator())
        .def("__repr__", &BVH3D::to_string, "String representation",
             py::is_operator())
        .def("intersections", &BVH3D::intersections, "Intersections", "line"_a)
        .def_property_readonly("trimesh", &BVH3D::get_trimesh, "Trimesh")
        .def_property_readonly("tree", &BVH3D::get_tree, "Tree");

    py::class_<IntersectionSet, std::shared_ptr<IntersectionSet>>(
        s, "IntersectionSet")
        .def(py::init<>(), "Intersection set")
        .def("__str__", &IntersectionSet::to_string, "String representation",
             py::is_operator())
        .def("__repr__", &IntersectionSet::to_string, "String representation",
             py::is_operator())
        .def_readonly("a_to_b", &IntersectionSet::a_to_b, "A to B")
        .def_readonly("b_to_a", &IntersectionSet::b_to_a, "B to A")
        .def_readonly("points", &IntersectionSet::points,
                      "Vector of all points");

    py::class_<TrimeshAdjacency>(s, "TrimeshAdjacency")
        .def(py::init<const types::Trimesh3D &>())
        .def_readonly("vertex_to_faces", &TrimeshAdjacency::vertex_to_faces)
        .def_readonly("vertex_to_vertices",
                      &TrimeshAdjacency::vertex_to_vertices)
        .def_readonly("face_to_vertices", &TrimeshAdjacency::face_to_vertices)
        .def_readonly("face_to_faces", &TrimeshAdjacency::face_to_faces)
        .def_readonly("edge_to_faces", &TrimeshAdjacency::edge_to_faces)
        .def("validate", &TrimeshAdjacency::validate);

    s.def("intersections", &intersections, "Intersections", "a"_a, "b"_a);
}

}  // namespace bvh
}  // namespace cpu
}  // namespace fast_trimesh
