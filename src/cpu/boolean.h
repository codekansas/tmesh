#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

types::Trimesh3D triangulation(const types::Triangle3D &triangle,
                               const std::vector<types::Point3D> &points);

typedef std::tuple<size_t, size_t> edge_t;

struct __edge_hash_fn {
    std::size_t operator()(const edge_t &f) const {
        return std::get<0>(f) ^ std::get<1>(f);
    }
};

struct TrimeshAdjacency {
    std::vector<std::vector<size_t>> vertex_to_faces;
    std::vector<types::face_t> face_to_vertices;
    std::vector<types::face_t> face_to_faces;
    std::unordered_map<edge_t, size_t, __edge_hash_fn> edge_to_faces;

    TrimeshAdjacency(const types::Trimesh3D &mesh);

    void validate() const;
};

types::Trimesh3D mesh_union(const types::Trimesh3D &a,
                            const types::Trimesh3D &b);

types::Trimesh3D mesh_intersection(const types::Trimesh3D &a,
                                   const types::Trimesh3D &b);

types::Trimesh3D mesh_difference(const types::Trimesh3D &a,
                                 const types::Trimesh3D &b);

void add_modules(py::module &m);

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
