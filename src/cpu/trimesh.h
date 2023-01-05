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
    std::set<std::tuple<int, int, int>> faces;

   public:
    Trimesh() = default;
    ~Trimesh() = default;

    // Accessor methods
    size_t add_vertex(T vertex) {
        vertices.push_back(vertex);
        return vertices.size() - 1;
    }
    void set_vertices(std::vector<T> vertices) { this->vertices = vertices; }
    void remove_face(int i, int j, int k) { faces.erase({i, j, k}); }
    void add_face(int i, int j, int k) { faces.insert({i, j, k}); }
    void set_faces(std::vector<std::tuple<int, int, int>> faces) {
        this->faces.clear();
        this->faces.insert(faces.begin(), faces.end());
    }
    std::vector<T> get_vertices() const { return vertices; }
    const std::set<std::tuple<int, int, int>> &get_face_set() const {
        return faces;
    }
    std::vector<std::tuple<int, int, int>> get_faces() const {
        return std::vector<std::tuple<int, int, int>>(faces.begin(),
                                                      faces.end());
    }
    T get_vertex(int i) const { return vertices[i]; }
    size_t num_vertices() const { return vertices.size(); }
    size_t num_faces() const { return faces.size(); }
};

class Trimesh2D : public Trimesh<types::Point2D> {
   public:
    Trimesh2D() = default;
    ~Trimesh2D() = default;

    Trimesh2D(const types::Polygon2D &polygon, bool is_convex = false);

    void validate() const;
    Trimesh2D &operator<<=(const types::Affine2D &tf);
    Trimesh2D operator<<(const types::Affine2D &tf) const;

    types::Triangle2D get_triangle(const std::tuple<int, int, int> &face) const;

    std::string to_string() const;
};

class Trimesh3D : public Trimesh<types::Point3D> {
   public:
    Trimesh3D() = default;
    ~Trimesh3D() = default;

    types::Triangle3D get_triangle(const std::tuple<int, int, int> &face) const;
    std::vector<types::Triangle3D> get_triangles() const;
    void validate() const;
    Trimesh3D &operator<<=(const types::Affine3D &tf);
    Trimesh3D operator<<(const types::Affine3D &tf) const;
    Trimesh3D &operator|=(const Trimesh3D &other);
    Trimesh3D operator|(const Trimesh3D &other) const;
    Trimesh3D &operator&=(const Trimesh3D &other);
    Trimesh3D operator&(const Trimesh3D &other) const;
    Trimesh3D &operator-=(const Trimesh3D &other);
    Trimesh3D operator-(const Trimesh3D &other) const;

    float signed_volume() const;
    void flip_inside_out();

    std::string to_string() const;
};

void add_modules(py::module &m);

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
