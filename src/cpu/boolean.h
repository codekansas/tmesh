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

struct TrimeshAdjacency {
    std::vector<std::vector<size_t>> vertex_to_faces;
    std::vector<std::vector<size_t>> face_to_vertices;
    std::vector<std::vector<size_t>> face_to_faces;
};

TrimeshAdjacency compute_adjacency(const types::Trimesh3D &mesh);

// types::Trimesh3D split_intersecting_faces(const types::Trimesh3D &a,
//                                           const types::Trimesh3D &b);

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
