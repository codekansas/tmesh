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

class Trimesh2D : public Trimesh<geometry::Point2D> {
   public:
    Trimesh2D() = default;
    ~Trimesh2D() = default;

    void validate() const;
    Trimesh2D &operator+=(const Trimesh2D &other);
    Trimesh2D operator+(const Trimesh2D &other) const;
};

class Trimesh3D : public Trimesh<geometry::Point3D> {
   public:
    Trimesh3D() = default;
    ~Trimesh3D() = default;

    geometry::Triangle3D get_triangle(int i) const;
    void validate() const;
    Trimesh3D &operator<<=(const AffineTransformation &tf);
    Trimesh3D operator<<(const AffineTransformation &tf) const;
    Trimesh3D &operator+=(const Trimesh3D &other);
    Trimesh3D operator+(const Trimesh3D &other) const;
};

Trimesh2D triangulate(const geometry::Polygon2D &polygon,
                      bool is_convex = false);

class AffineTransformation {
   protected:
    std::optional<geometry::Point3D> rotation;     // ZYX Euler angles
    std::optional<geometry::Point3D> translation;  // Translation vector
    std::optional<float> scale;                    // Scale factor

    friend class Trimesh3D;

   public:
    AffineTransformation(std::optional<geometry::Point3D> rotation,
                         std::optional<geometry::Point3D> translation,
                         std::optional<float> scale)
        : rotation(rotation), translation(translation), scale(scale) {
        // Checks that only one of rotation, translation, and scale is set.
        if (rotation.has_value() + translation.has_value() + scale.has_value() >
            1) {
            throw std::invalid_argument(
                "Only one of rotation, translation, and scale can be set");
        }
    }

    ~AffineTransformation() = default;

    std::optional<geometry::Point3D> get_rotation() const { return rotation; }
    std::optional<geometry::Point3D> get_translation() const {
        return translation;
    }
    std::optional<float> get_scale() const { return scale; }
    Trimesh3D operator>>(const Trimesh3D &t);
};

void add_modules(py::module &m);

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
