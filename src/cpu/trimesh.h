#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <numeric>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {

namespace types {

struct Angle;
struct BarycentricCoordinates;
struct Point2D;
struct Line2D;
struct Triangle2D;
struct BoundingBox2D;
struct Polygon2D;
struct Affine2D;
struct Point3D;
struct Line3D;
struct Circumcircle3D;
struct Triangle3D;
struct BoundingBox3D;
struct Polygon3D;
struct Affine3D;

}  // namespace types

namespace trimesh {

typedef std::tuple<int, int, int> face_t;

struct __face_hash_fn {
    std::size_t operator()(const face_t &f) const {
        return std::get<0>(f) ^ std::get<1>(f) ^ std::get<2>(f);
    }
};

typedef std::vector<types::Point2D> vertices2d_t;
typedef std::vector<types::Point3D> vertices3d_t;
typedef std::unordered_set<face_t, __face_hash_fn> face_set_t;

class Trimesh2D {
   private:
    vertices2d_t _vertices;
    face_set_t _faces;

   public:
    Trimesh2D(vertices2d_t &vertices, face_set_t &faces);

    const vertices2d_t &vertices() const;
    const face_set_t &faces() const;
    const types::Triangle2D get_triangle(
        const std::tuple<int, int, int> &face) const;
    const std::vector<types::Triangle2D> get_triangles() const;
    std::string to_string() const;

    Trimesh2D operator<<(const types::Affine2D &tf) const;
};

struct Trimesh3D {
   private:
    vertices3d_t _vertices;
    face_set_t _faces;

   public:
    Trimesh3D(vertices3d_t &vertices, face_set_t &faces);

    const vertices3d_t &vertices() const;
    const face_set_t &faces() const;
    types::Triangle3D get_triangle(const std::tuple<int, int, int> &face) const;
    std::vector<types::Triangle3D> get_triangles() const;
    float signed_volume() const;
    Trimesh3D flip_inside_out() const;
    std::string to_string() const;

    Trimesh3D operator<<(const types::Affine3D &tf) const;
    Trimesh3D operator|(const Trimesh3D &other) const;
    Trimesh3D operator&(const Trimesh3D &other) const;
    Trimesh3D operator-(const Trimesh3D &other) const;
};

void add_modules(py::module &m);

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
