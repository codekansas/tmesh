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
    if (auto it = point_id(p); it) return *it;
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

size_t delaunay_split_tree_3d_t::add_volume(
    const volume_t &v, const std::vector<size_t> &parents) {
    tetrahedron_3d_t t{this->vertices[v.a], this->vertices[v.b],
                       this->vertices[v.c], this->vertices[v.d]};
    if (t.signed_volume() < 0) {
        throw std::runtime_error(
            "Tetrahedron is not oriented correctly (signed volume is "
            "negative).");
    }

    const size_t i = this->volumes.size();
    for (const auto &parent : parents) {
        this->children[parent].push_back(i);
    }
    this->volumes.push_back(v);
    for (const auto &face : v.get_faces()) {
        this->face_to_volume[face] = i;
        for (const auto &edge : face.get_edges(false)) {
            this->edge_to_faces[edge].insert(face);
        }
    }
    this->children.push_back({});
    return i;
}

std::vector<size_t> delaunay_split_tree_3d_t::add_volumes(
    const std::vector<volume_t> &volumes, const std::vector<size_t> &parents) {
    std::vector<size_t> indices;

    // Checks that the total volume of the new volumes matches parents.
    double child_volume = 0, parent_volume = 0;
    for (size_t i = 0; i < volumes.size(); i++) {
        const auto sv =
            this->get_tetrahedron_from_volume(volumes[i]).signed_volume();
        if (sv < 0) {
            throw std::runtime_error(
                "Tetrahedron is not oriented correctly (volume is negative).");
        }
        child_volume += sv;
    }
    for (size_t i = 0; i < parents.size(); i++) {
        const auto &pv = this->volumes[parents[i]];
        tetrahedron_3d_t t{this->vertices[pv.a], this->vertices[pv.b],
                           this->vertices[pv.c], this->vertices[pv.d]};
        const auto sv = t.signed_volume();
        if (sv < 0) {
            throw std::runtime_error("Parent tetrahedron " + std::to_string(i) +
                                     " volume is negative.");
        }
        parent_volume += sv;
    }
    if (std::abs(child_volume - parent_volume) > get_tolerance()) {
        throw std::runtime_error("The total volume of the new volumes " +
                                 std::to_string(child_volume) +
                                 " does not match the parent volume " +
                                 std::to_string(parent_volume));
    }

    for (size_t i = 0; i < volumes.size(); ++i) {
        if (this->get_tetrahedron_from_volume(volumes[i]).signed_volume() <
            get_tolerance())
            continue;
        indices.push_back(this->add_volume(volumes[i], parents));
    }
    return indices;
}

delaunay_split_tree_3d_t::delaunay_split_tree_3d_t(const tetrahedron_3d_t &root)
    : root(root) {
    this->volumes = {{0, 1, 2, 3}};
    this->face_to_volume = {};
    this->edge_to_faces = {};
    for (const auto &f : this->volumes[0].get_faces()) {
        this->face_to_volume[f] = 0;
        for (const auto &e : f.get_edges(false)) {
            this->edge_to_faces[e].insert(f);
        }
    }
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

tetrahedron_3d_t delaunay_split_tree_3d_t::get_tetrahedron_from_volume(
    const volume_t &f) const {
    return {this->vertices[f.a], this->vertices[f.b], this->vertices[f.c],
            this->vertices[f.d]};
}

tetrahedron_3d_t delaunay_split_tree_3d_t::get_tetrahedron(size_t i) const {
    const auto &v = this->get_volume(i);
    return this->get_tetrahedron_from_volume(v);
}

std::vector<size_t> delaunay_split_tree_3d_t::get_leaf_indices() const {
    std::vector<size_t> leaf_indices;
    for (size_t i = 0; i < this->children.size(); i++) {
        if (is_leaf(i)) {
            leaf_indices.push_back(i);
        }
    }
    return leaf_indices;
}

void delaunay_split_tree_3d_t::make_delaunay(const size_t &pi,
                                             const size_t &ti) {
    const auto &p = this->vertices.get_point(pi);

    // Flood fill to find volumes which need to be removed.
    std::queue<size_t> volumes{{ti}};
    std::unordered_set<size_t> volumes_to_remove{ti};

    auto not_delaunay = [&](const volume_t &v) -> bool {
        return this->get_tetrahedron_from_volume(v).circumsphere_contains(
            p, get_tolerance());
    };

    while (!volumes.empty()) {
        size_t volume_id = volumes.front();
        volumes.pop();
        const auto &volume = this->get_volume(volume_id);
        for (const auto &face : volume.get_faces()) {
            const auto &rev_face = face.flip();
            if (this->face_to_volume.find(rev_face) ==
                this->face_to_volume.end())
                continue;
            const auto &neighbor_id = this->face_to_volume[rev_face];
            if (volumes_to_remove.find(neighbor_id) != volumes_to_remove.end())
                continue;
            const auto &neighbor = this->get_volume(neighbor_id);
            if (not_delaunay(neighbor)) {
                volumes.push(neighbor_id);
                volumes_to_remove.insert(neighbor_id);
            }
        }
    }

    // Finds boundary faces.
    face_set_t boundary_faces;
    for (const auto &volume_id : volumes_to_remove) {
        const auto &volume = this->get_volume(volume_id);
        for (const auto &face : volume.get_faces()) {
            const auto &rev_face = face.flip();
            if (this->face_to_volume.find(rev_face) ==
                this->face_to_volume.end()) {
                boundary_faces.insert(face);
                continue;
            }
            const auto &neighbor_id = this->face_to_volume[rev_face];
            if (volumes_to_remove.find(neighbor_id) ==
                volumes_to_remove.end()) {
                boundary_faces.insert(face);
            }
        }
    }

    // For each boundary face, create a new tetrahedron with the point.
    std::vector<volume_t> new_volumes;
    for (const auto &face : boundary_faces) {
        new_volumes.push_back({pi, face.a, face.b, face.c});
    }

    const std::vector<size_t> parents{volumes_to_remove.begin(),
                                      volumes_to_remove.end()};
    this->add_volumes(new_volumes, parents);
}

void delaunay_split_tree_3d_t::split_tetrahedron(const point_3d_t &p,
                                                 size_t i) {
    // if (!this->get_tetrahedron(i).point_is_inside(p)) {
    //     std::ostringstream ss;
    //     ss << "Point " << p.to_string() << " is not inside tetrahedron "
    //        << this->get_tetrahedron(i).to_string();
    //     throw std::runtime_error(ss.str());
    // }

    make_delaunay(this->vertices.add_point(p), i);
}

const point_3d_set_t &delaunay_split_tree_3d_t::get_vertices() const {
    return this->vertices;
}

void add_3d_bvh_modules(py::module &m) {
    auto dtree_3d =
        py::class_<delaunay_split_tree_3d_t>(m, "DelaunaySplitTree3D");

    dtree_3d
        .def(py::init<const tetrahedron_3d_t &>(), "root"_a,
             "Constructs a 3D Delaunay split tree from a "
             "tetrahedron")
        .def("is_leaf", &delaunay_split_tree_3d_t::is_leaf, "i"_a,
             "Returns whether the node is a leaf")
        .def("find_leaf_index", &delaunay_split_tree_3d_t::find_leaf_index,
             "p"_a,
             "Returns the index of the leaf containing the "
             "point")
        .def("get_volume", &delaunay_split_tree_3d_t::get_volume, "i"_a,
             "Returns the volume at the given index")
        .def("get_tetrahedron",
             &delaunay_split_tree_3d_t::get_tetrahedron_from_volume, "v"_a,
             "Returns the tetrahedron corresponding to the "
             "volume")
        .def("get_tetrahedron", &delaunay_split_tree_3d_t::get_tetrahedron,
             "i"_a, "Returns the tetrahedron at the given index")
        .def("get_leaf_indices", &delaunay_split_tree_3d_t::get_leaf_indices,
             "Returns all the leaf triangles")
        .def("split_tetrahedron",
             py::overload_cast<const point_3d_t &, size_t>(
                 &delaunay_split_tree_3d_t::split_tetrahedron),
             "p"_a, "i"_a, "Splits the tetrahedron at the given index");
}

}  // namespace trimesh
