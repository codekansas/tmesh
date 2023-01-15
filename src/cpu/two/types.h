#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <unordered_set>

#include "../types.h"

namespace py = pybind11;

namespace trimesh {

struct Point2D;
struct Line2D;
struct Triangle2D;
struct BoundingBox2D;
struct Polygon2D;
struct Affine2D;
struct Trimesh2D;

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
    std::optional<Point2D> line_intersection(const Line2D &l) const;
    bool intersects_triangle(const Triangle2D &t) const;
    std::vector<Point2D> triangle_intersection(const Triangle2D &t) const;
    bool intersects_bounding_box(const BoundingBox2D &b) const;

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
    std::vector<Point2D> vertices() const;
    std::vector<Line2D> edges() const;

    bool contains(const Point2D &p) const;
    bool intersects_bounding_box(const BoundingBox2D &bb) const;
    bool intersects_triangle(const Triangle2D &t) const;
    float distance_to_point(const Point2D &p) const;
    float distance_to_line(const Line2D &l) const;
    float distance_to_triangle(const Triangle2D &t) const;
    float distance_to_bounding_box(const BoundingBox2D &bb) const;
    Point2D point_from_barycentric_coords(
        const BarycentricCoordinates &b) const;

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

    float area() const;
    Point2D center() const;
    std::vector<Point2D> vertices() const;
    std::vector<Line2D> edges() const;

    bool intersects_triangle(const Triangle2D &t) const;
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
    Polygon2D operator+(const Polygon2D &p) const;
    Polygon2D operator+=(const Polygon2D &p);

    float signed_area() const;
    bool is_clockwise() const;
    void reverse();
    Polygon2D convex_hull() const;
    BoundingBox2D bounding_box() const;
    Point2D center() const;
    bool is_ear(int vi, int vj, int vk) const;
    Trimesh2D get_trimesh(bool is_convex = false) const;

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

struct Trimesh2D {
   private:
    const std::vector<Point2D> _vertices;
    const face_list_t _faces;
    void validate() const;

   public:
    Trimesh2D(const std::vector<Point2D> &vertices, const face_set_t &faces);
    Trimesh2D(const std::vector<Point2D> &vertices, const face_list_t &faces);

    const std::vector<Point2D> &vertices() const;
    const face_list_t &faces() const;
    const Triangle2D get_triangle(const face_t &face) const;
    const std::vector<Triangle2D> get_triangles() const;
    const std::vector<size_t> get_polygon_inds() const;
    const Polygon2D get_polygon() const;
    Trimesh2D subdivide(bool at_edges = true) const;
    std::string to_string() const;

    Trimesh2D operator<<(const Affine2D &tf) const;
    Trimesh2D operator|(const Trimesh2D &other) const;
    Trimesh2D operator&(const Trimesh2D &other) const;
    Trimesh2D operator-(const Trimesh2D &other) const;
};

void add_2d_types_modules(py::module &m);

}  // namespace trimesh
