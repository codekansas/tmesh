#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <numeric>
#include <tuple>
#include <vector>

#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

template <typename T>
class Trimesh;

class Trimesh2D;
class Trimesh3D;

template <typename T>
class Trimesh {
   protected:
    std::vector<T> vertices;
    std::vector<std::tuple<int, int, int>> faces;

   public:
    Trimesh() = default;
    ~Trimesh() = default;

    // Accessor methods
    size_t add_vertex(T vertex) {
        vertices.push_back(vertex);
        return vertices.size() - 1;
    }
    void set_vertices(std::vector<T> vertices) { this->vertices = vertices; }
    size_t add_face(int i, int j, int k) {
        faces.push_back(std::make_tuple(i, j, k));
        return faces.size() - 1;
    }
    void set_faces(std::vector<std::tuple<int, int, int>> faces) {
        this->faces = faces;
    }
    std::vector<T> get_vertices() const { return vertices; }
    std::vector<std::tuple<int, int, int>> get_faces() const { return faces; }
    T get_vertex(int i) const { return vertices[i]; }
    std::tuple<int, int, int> get_face(int i) const { return faces[i]; }
    size_t num_vertices() const { return vertices.size(); }
    size_t num_faces() const { return faces.size(); }

    Trimesh<T> &operator+=(const Trimesh<T> &other);
    Trimesh<T> operator+(const Trimesh<T> &other) const;
};

class Trimesh2D : public Trimesh<types::Point2D> {
   public:
    Trimesh2D() = default;
    ~Trimesh2D() = default;

    Trimesh2D(const types::Polygon2D &polygon, bool is_convex = false);

    void validate() const;
    Trimesh2D &operator+=(const Trimesh2D &other);
    Trimesh2D operator+(const Trimesh2D &other) const;

    std::string to_string() const;
};

class Trimesh3D : public Trimesh<types::Point3D> {
   public:
    Trimesh3D() = default;
    ~Trimesh3D() = default;

    types::Triangle3D get_triangle(int i) const;
    void validate() const;
    Trimesh3D &operator<<=(const types::Affine3D &tf);
    Trimesh3D operator<<(const types::Affine3D &tf) const;
    Trimesh3D &operator+=(const Trimesh3D &other);
    Trimesh3D operator+(const Trimesh3D &other) const;

    std::string to_string() const;
};

void add_modules(py::module &m);

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
