#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

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

struct Point2D {
    float x, y;

    Point2D operator+=(const Point2D &p);
    Point2D operator-=(const Point2D &p);
    Point2D operator*=(const Point2D &p);
    Point2D operator*=(float s);
    Point2D operator/=(const Point2D &p);
    Point2D operator/=(float s);
    bool operator==(const Point2D &p) const;
    bool operator!=(const Point2D &p) const;
    bool operator<(const Point2D &p) const;
    Point2D operator<<=(const Affine2D &a);

    Point2D normalize() const;
    Point2D rotate(float angle) const;
    float determinant(const Point2D &other) const;
    float length() const;
    float dot(const Point2D &other) const;
    float cross(const Point2D &other) const;

    BarycentricCoordinates barycentric_coordinates(const Triangle2D &t) const;
    bool is_inside_triangle(const Triangle2D &t) const;
    bool is_inside_bounding_box(const BoundingBox2D &bb) const;

    float distance_to_point(const Point2D &other) const;
    float distance_to_line(const Line2D &l) const;
    float distance_to_triangle(const Triangle2D &t) const;
    float distance_to_bounding_box(const BoundingBox2D &bb) const;

    std::optional<Point2D> project_to_line(const Line2D &l) const;

    std::string to_string() const;
};

Point2D operator+(const Point2D &p1, const Point2D &p2);
Point2D operator-(const Point2D &p1, const Point2D &p2);
Point2D operator*(const Point2D &p1, const Point2D &p2);
Point2D operator*(float s, const Point2D &p);
Point2D operator*(const Point2D &p, float s);
Point2D operator/(const Point2D &p1, const Point2D &p2);
Point2D operator/(const Point2D &p, float s);

bool is_convex(const Point2D &a, const Point2D &b, const Point2D &c);

struct Line2D {
    Point2D p1, p2;

    bool operator==(const Line2D &l) const;
    bool operator!=(const Line2D &l) const;
    Line2D operator<<=(const Affine2D &a);

    Point2D closest_point(const Point2D &p) const;
    std::optional<Point2D> intersection(const Line2D &l) const;

    float distance_to_point(const Point2D &p) const;
    float distance_to_line(const Line2D &l) const;
    float distance_to_triangle(const Triangle2D &t) const;
    float distance_to_bounding_box(const BoundingBox2D &bb) const;

    std::string to_string() const;
};

struct Triangle2D {
    Point2D p1, p2, p3;

    bool operator==(const Triangle2D &t) const;
    bool operator!=(const Triangle2D &t) const;
    Triangle2D operator<<=(const Affine2D &a);

    float area() const;
    Point2D center() const;

    float distance_to_point(const Point2D &p) const;
    float distance_to_line(const Line2D &l) const;
    float distance_to_triangle(const Triangle2D &t) const;
    float distance_to_bounding_box(const BoundingBox2D &bb) const;

    std::string to_string() const;
};

struct BoundingBox2D {
    Point2D min, max;

    BoundingBox2D();
    BoundingBox2D(const Point2D &min, const Point2D &max);
    BoundingBox2D(const std::vector<Point2D> &points);
    BoundingBox2D(const std::vector<Line2D> &lines);
    BoundingBox2D(const std::vector<Triangle2D> &triangles);
    BoundingBox2D(const std::vector<BoundingBox2D> &bboxes);

    bool operator==(const BoundingBox2D &bb) const;
    bool operator!=(const BoundingBox2D &bb) const;
    BoundingBox2D operator<<=(const Affine2D &a);

    float distance_to_point(const Point2D &p) const;
    float distance_to_line(const Line2D &l) const;
    float distance_to_triangle(const Triangle2D &t) const;
    float distance_to_bounding_box(const BoundingBox2D &bb) const;

    std::string to_string() const;
};

struct Polygon2D {
    std::vector<Point2D> points;

    Polygon2D(const std::vector<Point2D> &points);

    bool operator==(const Polygon2D &p) const;
    bool operator!=(const Polygon2D &p) const;
    Polygon2D operator<<=(const Affine2D &a);

    float signed_area() const;
    bool is_clockwise() const;
    void reverse();
    Polygon2D convex_hull() const;
    BoundingBox2D bounding_box() const;
    Point2D center() const;

    std::string to_string() const;
};

struct Affine2D {
    // Represents the affine transformation:
    // r00 r01 tx
    // r10 r11 ty
    // 0   0   1

    float r00, r01, r10, r11, tx, ty;

    Affine2D(float r00, float r01, float r10, float r11, float tx, float ty);
    Affine2D(std::optional<float> rot = std::nullopt,
             std::optional<std::tuple<float, float>> trans = std::nullopt,
             std::optional<float> scale = std::nullopt);

    Affine2D operator*=(const Affine2D &a);

    Affine2D inverse() const;

    std::string to_string() const;
};

Affine2D operator*(const Affine2D &a1, const Affine2D &a2);
Point2D operator>>(const Affine2D &a, const Point2D &p);
Point2D operator<<(const Point2D &p, const Affine2D &a);
Line2D operator>>(const Affine2D &a, const Line2D &l);
Line2D operator<<(const Line2D &l, const Affine2D &a);
Triangle2D operator>>(const Affine2D &a, const Triangle2D &t);
Triangle2D operator<<(const Triangle2D &t, const Affine2D &a);
BoundingBox2D operator>>(const Affine2D &a, const BoundingBox2D &bb);
BoundingBox2D operator<<(const BoundingBox2D &bb, const Affine2D &a);
Polygon2D operator>>(const Affine2D &a, const Polygon2D &p);
Polygon2D operator<<(const Polygon2D &p, const Affine2D &a);

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

float signed_volume(const Point3D &a, const Point3D &b, const Point3D &c,
                    const Point3D &d);

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
    bool intersects_bounding_box(const BoundingBox3D &bb) const;

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

    std::vector<std::tuple<int, int, int>> triangle_indices() const;
    std::vector<Point3D> corners() const;
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

struct Angle {
    float value;

    Angle(float angle);
    Angle(const Point2D &p1, const Point2D &p2, const Point2D &p3);
    Angle(const Point3D &p1, const Point3D &p2, const Point3D &p3);

    Angle operator+=(const Angle &a);
    Angle operator-=(const Angle &a);
    Angle operator*=(const Angle &a);
    Angle operator*=(float s);
    Angle operator/=(const Angle &a);
    Angle operator/=(float s);

    float cos() const;
    float sin() const;
    float tan() const;
    float acos() const;
    float asin() const;
    float atan() const;

    float to_degrees() const;

    std::string to_string() const;
};

Angle operator+(const Angle &a1, const Angle &a2);
Angle operator-(const Angle &a1, const Angle &a2);
Angle operator*(const Angle &a1, const Angle &a2);
Angle operator*(float s, const Angle &a);
Angle operator*(const Angle &a, float s);
Angle operator/(const Angle &a1, const Angle &a2);
Angle operator/(const Angle &a, float s);

struct BarycentricCoordinates {
    float u, v, w;

    BarycentricCoordinates(float u, float v, float w);

    bool operator==(const BarycentricCoordinates &bc) const;
    bool operator!=(const BarycentricCoordinates &bc) const;

    Point2D get_point_2d(const Triangle2D &t) const;
    Point3D get_point_3d(const Triangle3D &t) const;

    std::string to_string() const;
};

void add_modules(py::module &m);

}  // namespace types
}  // namespace cpu
}  // namespace fast_trimesh
