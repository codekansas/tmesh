#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <numeric>
#include <tuple>
#include <vector>

#include "geometry.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

class AffineTransformation;

template <typename T>
class Trimesh;

using Trimesh2D = Trimesh<geometry::Point2D>;
using Trimesh3D = Trimesh<geometry::Point3D>;

template <typename T>
class Trimesh {
   private:
    std::vector<T> vertices;
    std::vector<std::tuple<int, int, int>> faces;

    friend Trimesh3D &operator+=(Trimesh3D &t, const AffineTransformation &tf);

    template <typename Tf>
    friend Trimesh<Tf> &operator+=(Trimesh<Tf> &a, const Trimesh<Tf> &other);

   public:
    Trimesh() = default;
    ~Trimesh() = default;

    // Accessor methods
    void add_vertex(T vertex) { vertices.push_back(vertex); }
    void set_vertices(std::vector<T> vertices) { this->vertices = vertices; }
    void add_face(int i, int j, int k) {
        faces.push_back(std::make_tuple(i, j, k));
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
};

Trimesh2D triangulate(const geometry::Polygon2D &polygon,
                      bool is_convex = false);

class AffineTransformation {
   private:
    std::optional<geometry::Point3D> rotation;     // ZYX Euler angles
    std::optional<geometry::Point3D> translation;  // Translation vector
    std::optional<float> scale;                    // Scale factor

    friend Trimesh3D &operator+=(Trimesh3D &t, const AffineTransformation &tf);

   public:
    AffineTransformation(std::optional<geometry::Point3D> rotation,
                         std::optional<geometry::Point3D> translation,
                         std::optional<float> scale)
        : rotation(rotation), translation(translation), scale(scale) {}

    ~AffineTransformation() = default;

    std::optional<geometry::Point3D> get_rotation() const { return rotation; }
    std::optional<geometry::Point3D> get_translation() const {
        return translation;
    }
    std::optional<float> get_scale() const { return scale; }

    void operator*=(const AffineTransformation &other);
    AffineTransformation operator*(const AffineTransformation &other) const;
};

// Combine two 3D trimeshes.
template <typename T>
Trimesh<T> &operator+=(Trimesh<T> &a, const Trimesh<T> &other);
template <typename T>
Trimesh<T> operator+(const Trimesh<T> &a, const Trimesh<T> &b);

// Apply affine transformation to a 3D trimesh.
Trimesh3D &operator+=(Trimesh3D &t, const AffineTransformation &tf);
Trimesh3D operator+(const Trimesh3D &t, const AffineTransformation &tf);

void add_modules(py::module &m);

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
