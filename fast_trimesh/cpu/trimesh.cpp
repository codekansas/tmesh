#include "trimesh.h"

namespace fast_trimesh {
namespace cpu {

void Trimesh::add_vertex(float x, float y, float z) {
    vertices.push_back(std::make_tuple(x, y, z));
}

void Trimesh::add_face(int i, int j, int k) {
    faces.push_back(std::make_tuple(i, j, k));
}

std::vector<std::tuple<float, float, float>> Trimesh::get_vertices() {
    return vertices;
}

std::vector<std::tuple<int, int, int>> Trimesh::get_faces() { return faces; }

Trimesh Trimesh::operator+(const Trimesh &other) {
    Trimesh result;

    // Add vertices from current mesh.
    result.vertices = vertices;
    result.faces = faces;

    // Add faces from other mesh, adding the offset of the current face index.
    auto offset = vertices.size();
    for (auto &face : other.faces) {
        result.faces.push_back(std::make_tuple(std::get<0>(face) + offset,
                                               std::get<1>(face) + offset,
                                               std::get<2>(face) + offset));
    }

    // Add vertices from other mesh.
    result.vertices.insert(result.vertices.end(), other.vertices.begin(),
                           other.vertices.end());

    return result;
}

Trimesh Trimesh::operator+=(const Trimesh &other) {
    // Add faces from other mesh, adding the offset of the current face index.
    auto offset = vertices.size();
    for (auto &face : other.faces) {
        faces.push_back(std::make_tuple(std::get<0>(face) + offset,
                                        std::get<1>(face) + offset,
                                        std::get<2>(face) + offset));
    }

    // Add vertices from other mesh.
    vertices.insert(vertices.end(), other.vertices.begin(),
                    other.vertices.end());

    return *this;
}

}  // namespace cpu
}  // namespace fast_trimesh
