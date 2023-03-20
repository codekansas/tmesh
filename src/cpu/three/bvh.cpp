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

void delaunay_split_tree_3d_t::make_delaunay(const size_t &pi, const face_t &f,
                                             const size_t &ti) {
    const auto f_rev = f.flip();

    // This means that the face is not an interior face.
    if (this->face_to_volume.find(f_rev) == this->face_to_volume.end()) return;

    size_t tj = this->face_to_volume[f_rev];
    const auto &ti_vol = this->volumes[ti];
    const auto &tj_vol = this->volumes[tj];
    const auto &pj = tj_vol.get_other_vertex(f_rev);
    const auto &ti_tetr = this->get_tetrahedron_from_volume(ti_vol);
    const auto &tj_tetr = this->get_tetrahedron_from_volume(tj_vol);

    // Checks for 2-3 flips.
    if (tj_tetr.circumsphere_contains(this->vertices[pi])) {
        const auto &pj = tj_vol.get_other_vertex(f_rev);

        const auto ts = this->add_volumes(
            {{pi, f.a, f.b, pj}, {pi, f.b, f.c, pj}, {pi, f.c, f.a, pj}},
            {ti, tj});

        this->make_delaunay(pi, {f.a, f.b, pj}, ts[0]);
        this->make_delaunay(pi, {f.b, f.c, pj}, ts[1]);
        this->make_delaunay(pi, {f.c, f.a, pj}, ts[2]);
        return;
    }

    // auto get_common_face = [](const volume_t &va,
    //                           const volume_t &vb) -> std::optional<face_t> {
    //     for (const auto &fa : va.get_faces()) {
    //         for (const auto &fb : vb.get_faces()) {
    //             if (fa == fb.flip()) return fa;
    //         }
    //     }
    //     return std::nullopt;
    // };

    // auto get_common_edge = [](const face_t &fa, const face_t &fb,
    //                           const face_t &fc) -> edge_t {
    //     for (const auto &ea : fa.get_edges(false)) {
    //         for (const auto &eb : fb.get_edges(false)) {
    //             if (ea == eb) {
    //                 for (const auto &ec : fc.get_edges(false)) {
    //                     if (ea == ec) return ea;
    //                 }
    //             }
    //         }
    //     }
    //     throw std::runtime_error("No common edge found");
    // };

    // // Checks for 3-2 flips.
    // const auto pc = this->volumes[ti].get_other_vertex(f);
    // for (const auto &fo : this->volumes[ti].get_faces()) {
    //     if (fo == f) continue;
    //     const auto &fo_rev = fo.flip();
    //     if (this->face_to_volume.find(fo_rev) == this->face_to_volume.end())
    //         continue;

    //     const auto &tk = this->face_to_volume[fo_rev];
    //     const auto &tk_vol = this->volumes[tk];
    //     const auto &tk_tetr = this->get_tetrahedron_from_volume(tk_vol);
    //     const auto fc = get_common_face(tj_vol, tk_vol);
    //     if (!fc) continue;
    //     const auto ec = get_common_edge(f, fo, *fc);

    //     // The three points around the edge.
    //     const size_t pk_opp = tj_vol.get_other_vertex(*fc),
    //                  pj_opp = tk_vol.get_other_vertex((*fc).flip()),
    //                  pi_opp = tk_vol.get_other_vertex(fo_rev);

    //     if (ti_tetr.circumsphere_contains(this->vertices[pi_opp]) ||
    //         tj_tetr.circumsphere_contains(this->vertices[pj_opp]) ||
    //         tk_tetr.circumsphere_contains(this->vertices[pk_opp])) {
    //         const auto ts = this->add_volumes({{ec.a, pi_opp, pj_opp, pk_opp},
    //                                            {pi_opp, pj_opp, pk_opp, ec.b}},
    //                                           {ti, tj, tk});

    //         this->make_delaunay(pi, {ec.a, pi_opp, pj_opp}, ts[0]);
    //         this->make_delaunay(pi, {pi_opp, pj_opp, pk_opp}, ts[0]);
    //         this->make_delaunay(pi, {pi_opp, pj_opp, pk_opp}, ts[1]);
    //         this->make_delaunay(pi, {pi_opp, pk_opp, ec.b}, ts[1]);
    //         return;
    //     }
    // }
}

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
        const auto &v = volumes[i];
        tetrahedron_3d_t t{this->vertices[v.a], this->vertices[v.b],
                           this->vertices[v.c], this->vertices[v.d]};
        const auto sv = t.signed_volume();
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

void delaunay_split_tree_3d_t::split_tetrahedron(const point_3d_t &p, size_t i,
                                                 bool make_delaunay) {
    // if (!this->get_tetrahedron(i).point_is_inside(p)) {
    //     std::ostringstream ss;
    //     ss << "Point " << p.to_string() << " is not inside tetrahedron "
    //        << this->get_tetrahedron(i).to_string();
    //     throw std::runtime_error(ss.str());
    // }

    const auto [fa, fb, fc, fd] = this->volumes[i];
    const auto &va = this->vertices[fa], &vb = this->vertices[fb],
               &vc = this->vertices[fc], &vd = this->vertices[fd];
    if (p == va || p == vb || p == vc) return;
    const auto pi = this->vertices.add_point(p);

    for (const auto face : this->volumes[i].get_faces()) {
        // Checks if the point intersects an edge.
        for (const auto edge : face.get_edges(false)) {
            const line_3d_t l{this->vertices[edge.a], this->vertices[edge.b]};
            if (l.closest_point(p) == p) {
                for (const auto &face : this->edge_to_faces[edge]) {
                    const size_t vi = this->face_to_volume[face];
                    if (this->is_leaf(vi)) continue;

                    const auto &v = this->volumes[vi];
                    const auto &[fa, fb] = v.get_faces_with_edge(edge);

                    const size_t j = this->face_to_volume[fa];
                    const size_t pa = fa.get_other_vertex(edge),
                                 pc = v.get_other_vertex(fa);

                    // Splits each tetrahedron.
                    if (fa.has_directed_edge(edge)) {
                        const auto ts = this->add_volumes(
                            {{pi, edge.a, pa, pc}, {pi, edge.b, pc, pa}}, {vi});
                        if (make_delaunay) {
                            this->make_delaunay(pi, {edge.a, pa, pc}, ts[0]);
                            this->make_delaunay(pi, {edge.b, pc, pa}, ts[1]);
                        }
                    } else {
                        const auto ts = this->add_volumes(
                            {{pi, edge.b, pa, pc}, {pi, edge.a, pc, pa}}, {vi});
                        if (make_delaunay) {
                            this->make_delaunay(pi, {edge.a, pc, pa}, ts[0]);
                            this->make_delaunay(pi, {edge.b, pa, pc}, ts[1]);
                        }
                    }
                }

                return;
            }
        }
    }

    for (const auto face : this->volumes[i].get_faces()) {
        // Checks if the point intersects a face.
        const auto &v1 = this->vertices[face.a], &v2 = this->vertices[face.b],
                   &v3 = this->vertices[face.c];
        const triangle_3d_t t{v1, v2, v3};
        if (t.distance_to_point(p) < get_tolerance()) {
            const size_t pc = this->volumes[i].get_other_vertex(face);

            // Splits each tetrahedron.
            const auto ts = this->add_volumes({{face.a, face.b, pc, pi},
                                               {face.b, face.c, pc, pi},
                                               {face.c, face.a, pc, pi}},
                                              {i});

            // Makes the new tetrahedra Delaunay.
            if (make_delaunay) {
                this->make_delaunay(pi, {face.a, pc, face.b}, ts[0]);
                this->make_delaunay(pi, {face.b, pc, face.c}, ts[1]);
                this->make_delaunay(pi, {face.c, pc, face.a}, ts[2]);
            }

            const face_t face_rev = face.flip();
            if (this->face_to_volume.find(face_rev) !=
                this->face_to_volume.end()) {
                const size_t j = this->face_to_volume[face_rev];
                const size_t pn = this->volumes[j].get_other_vertex(face_rev);

                const auto ts = this->add_volumes({{face.a, face.b, pi, pn},
                                                   {face.b, face.c, pi, pn},
                                                   {face.c, face.a, pi, pn}},
                                                  {j});

                if (make_delaunay) {
                    this->make_delaunay(pi, {face.a, face.b, pn}, ts[0]);
                    this->make_delaunay(pi, {face.b, face.c, pn}, ts[1]);
                    this->make_delaunay(pi, {face.c, face.a, pn}, ts[2]);
                }
            }

            return;
        }
    }

    // Splits the current tetrahedrons.
    const auto ts = this->add_volumes({{fa, fb, fc, pi},
                                       {fa, fb, pi, fd},
                                       {fa, pi, fc, fd},
                                       {pi, fb, fc, fd}},
                                      {i});

    // Makes the new tetrahedra Delaunay.
    if (make_delaunay) {
        this->make_delaunay(pi, {fa, fc, fb}, ts[0]);
        this->make_delaunay(pi, {fa, fb, fd}, ts[1]);
        this->make_delaunay(pi, {fa, fd, fc}, ts[2]);
        this->make_delaunay(pi, {fb, fc, fd}, ts[3]);
    }
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
        .def_property_readonly("vertices",
                               &delaunay_split_tree_3d_t::get_vertices,
                               "Returns the vertices of the tree")
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
             py::overload_cast<const point_3d_t &, size_t, bool>(
                 &delaunay_split_tree_3d_t::split_tetrahedron),
             "p"_a, "i"_a, "make_delaunay"_a = false,
             "Splits the tetrahedron at the given index");
}

}  // namespace trimesh
