#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <unordered_set>

#include "../types.h"

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace three {
namespace types {

using namespace fast_trimesh::cpu::types;

struct Point3D;
struct Line3D;
struct Circumcircle3D;
struct Triangle3D;
struct BoundingBox3D;
struct Polygon3D;
struct Affine3D;
struct Trimesh3D;

struct Point3D {
    float x, y, z;

    Point3D operator+=(const Point3D &p);
    Point3D operator-=(const Point3D &p);
    Point3D operator*=(const Point3D &p);
    Point3D operator*=(float s);
    Point3D operator/=(const Point3D &p);
    Point3D operator/=(float s);
    bool operator==(const Point3D &p) const;
    bool operator!=(const Point3D &p) const;
    bool operator<(const Point3D &p) const;
    Point3D operator<<=(const Affine3D &q);

    Point3D normalize() const;
    float determinant(const Point3D &a, const Point3D &b) const;
    float length() const;
    float dot(const Point3D &other) const;
    Point3D cross(const Point3D &other) const;

    BarycentricCoordinates barycentric_coordinates(const Triangle3D &t) const;
    bool is_inside_bounding_box(const BoundingBox3D &bb) const;

    float distance_to_point(const Point3D &other) const;
    float distance_to_line(const Line3D &l) const;
    float distance_to_triangle(const Triangle3D &t) const;
    bool is_coplanar(const Triangle3D &t) const;

    std::optional<Point3D> project_to_line(const Line3D &l) const;
    std::optional<Point3D> project_to_triangle(const Triangle3D &t) const;
    bool projects_to_triangle(const Triangle3D &t) const;

    std::string to_string() const;
};

Point3D operator+(const Point3D &p1, const Point3D &p2);
Point3D operator-(const Point3D &p1, const Point3D &p2);
Point3D operator*(const Point3D &p1, const Point3D &p2);
Point3D operator*(float s, const Point3D &p);
Point3D operator*(const Point3D &p, float s);
Point3D operator/(const Point3D &p1, const Point3D &p2);
Point3D operator/(const Point3D &p, float s);
Point3D operator<<(const Point3D &p, const Affine3D &q);

float triangle_signed_volume(const Point3D &a, const Point3D &b,
                             const Point3D &c, const Point3D &d);

struct Line3D {
    Point3D p1, p2;

    bool operator==(const Line3D &l) const;
    bool operator!=(const Line3D &l) const;
    Line3D operator<<=(const Affine3D &q);

    std::optional<std::tuple<Point3D, Point3D>> closest_points(
        const Line3D &p) const;
    std::optional<Point3D> line_intersection(const Line3D &l) const;
    bool intersects_triangle(const Triangle3D &t) const;
    std::optional<Point3D> triangle_intersection(const Triangle3D &t) const;
    bool intersects_bounding_box(const BoundingBox3D &b) const;

    float distance_to_point(const Point3D &p) const;
    float distance_to_line(const Line3D &l) const;

    std::string to_string() const;
};

struct Circumcircle3D {
    Point3D center;
    float radius;

    bool operator==(const Circumcircle3D &c) const;
    bool operator!=(const Circumcircle3D &c) const;

    bool contains_point(const Point3D &p) const;

    std::string to_string() const;
};

struct Triangle3D {
    Point3D p1, p2, p3;

    bool operator==(const Triangle3D &t) const;
    bool operator!=(const Triangle3D &t) const;
    Triangle3D operator<<=(const Affine3D &q);

    float area() const;
    Point3D center() const;
    Point3D normal() const;
    std::vector<Point3D> vertices() const;
    std::vector<Line3D> edges() const;

    float distance_to_point(const Point3D &p) const;
    bool contains(const Point3D &p) const;
    bool is_coplanar(const Triangle3D &t) const;
    Circumcircle3D circumcircle() const;
    Point3D point_from_barycentric_coords(
        const BarycentricCoordinates &b) const;

    std::string to_string() const;
};

struct BoundingBox3D {
    Point3D min, max;

    BoundingBox3D();
    BoundingBox3D(const Point3D &min, const Point3D &max);
    BoundingBox3D(const std::vector<Point3D> &ps);
    BoundingBox3D(const std::vector<Line3D> &lines);
    BoundingBox3D(const std::vector<Triangle3D> &triangles);
    BoundingBox3D(const std::vector<BoundingBox3D> &bboxes);

    bool operator==(const BoundingBox3D &bb) const;
    bool operator!=(const BoundingBox3D &bb) const;
    BoundingBox3D operator<<=(const Affine3D &q);

    std::vector<face_t> triangle_indices() const;
    std::vector<Point3D> corners() const;
    std::vector<Line3D> edges() const;
    std::vector<Triangle3D> triangles() const;

    Point3D center() const;
    float volume() const;

    std::string to_string() const;
};

struct Polygon3D {
    std::vector<Point3D> points;

    Polygon3D(const std::vector<Point3D> &points);

    bool operator==(const Polygon3D &p) const;
    bool operator!=(const Polygon3D &p) const;
    Polygon3D operator<<=(const Affine3D &q);

    float area() const;
    Point3D normal() const;
    Point3D center() const;
    BoundingBox3D bounding_box() const;

    std::string to_string() const;
};

struct Affine3D {
    // Represents the affine transformation:
    // r00 r01 r02 tx
    // r10 r11 r12 ty
    // r20 r21 r22 tz
    // 0   0   0   1

    float r00, r01, r02, r10, r11, r12, r20, r21, r22, tx, ty, tz;

    Affine3D(float r00, float r01, float r02, float r10, float r11, float r12,
             float r20, float r21, float r22, float tx, float ty, float tz);
    Affine3D(
        std::optional<std::tuple<float, float, float>> rot = std::nullopt,
        std::optional<std::tuple<float, float, float>> trans = std::nullopt,
        std::optional<float> scale = std::nullopt);

    Affine3D operator*=(const Affine3D &a);

    Affine3D inverse() const;

    std::string to_string() const;
};

Affine3D operator*(const Affine3D &a1, const Affine3D &a2);
Point3D operator>>(const Affine3D &a, const Point3D &p);
Point3D operator<<(const Point3D &p, const Affine3D &a);
Line3D operator>>(const Affine3D &a, const Line3D &l);
Line3D operator<<(const Line3D &l, const Affine3D &a);
Triangle3D operator>>(const Affine3D &a, const Triangle3D &t);
Triangle3D operator<<(const Triangle3D &t, const Affine3D &a);
BoundingBox3D operator>>(const Affine3D &a, const BoundingBox3D &bb);
BoundingBox3D operator<<(const BoundingBox3D &bb, const Affine3D &a);
Polygon3D operator>>(const Affine3D &a, const Polygon3D &p);
Polygon3D operator<<(const Polygon3D &p, const Affine3D &a);

struct Trimesh3D {
   private:
    const std::vector<Point3D> _vertices;
    const face_list_t _faces;
    void validate() const;

   public:
    Trimesh3D(const std::vector<Point3D> &vertices, const face_set_t &faces);
    Trimesh3D(const std::vector<Point3D> &vertices, const face_list_t &faces);

    const std::vector<Point3D> &vertices() const;
    const face_list_t &faces() const;
    Triangle3D get_triangle(const face_t &face) const;
    std::vector<Triangle3D> get_triangles() const;
    float signed_volume() const;
    Trimesh3D flip_inside_out() const;
    Trimesh3D subdivide(bool at_edges = true) const;
    std::string to_string() const;

    Trimesh3D operator<<(const Affine3D &tf) const;
    Trimesh3D operator|(const Trimesh3D &other) const;
    Trimesh3D operator&(const Trimesh3D &other) const;
    Trimesh3D operator-(const Trimesh3D &other) const;
};

void add_3d_types_modules(py::module &m);

}  // namespace types
}  // namespace three
}  // namespace cpu
}  // namespace fast_trimesh
