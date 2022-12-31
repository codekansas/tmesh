#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

namespace fast_trimesh {
namespace cpu {
namespace geometry {

// Define some common types.
using Point2D = std::tuple<float, float>;
using Line2D = std::tuple<Point2D, Point2D>;
using Triangle2D = std::tuple<Point2D, Point2D, Point2D>;
using Polygon2D = std::vector<Point2D>;
using Point3D = std::tuple<float, float, float>;
using Line3D = std::tuple<Point3D, Point3D>;
using Triangle3D = std::tuple<Point3D, Point3D, Point3D>;

// Vector operations.
Point2D operator+(const Point2D &p1, const Point2D &p2);
void operator+=(Point2D &p1, const Point2D &p2);
Point2D operator-(const Point2D &p1, const Point2D &p2);
Point2D operator-(const Point2D &p);
Point2D operator*(const Point2D &p1, const Point2D &p2);
Point2D operator*(const Point2D &p, float s);
Point2D operator/(const Point2D &p, float s);
Point3D operator+(const Point3D &p1, const Point3D &p2);
void operator+=(Point3D &p1, const Point3D &p2);
Point3D operator-(const Point3D &p1, const Point3D &p2);
Point3D operator-(const Point3D &p);
Point3D operator*(const Point3D &p1, const Point3D &p2);
Point3D operator*(const Point3D &p, float s);
Point3D operator/(const Point3D &p, float s);

// Scales a point from the origin by a scalar.
Point2D scale(const Point2D &p, float s);
Point3D scale(const Point3D &p, float s);

// Translates a point by a vector.
Point2D translate(const Point2D &p, const Point2D &v);
Point3D translate(const Point3D &p, const Point3D &v);

// Rotate a point by an angle.
Point2D rotate(const Point2D &p, const Point2D &angle);
Point3D rotate(const Point3D &p, const Point3D &angle);

// Vector products.
float dot_product(const Point2D &p1, const Point2D &p2);
float dot_product(const Point3D &p1, const Point3D &p2);
float cross_product(const Point2D &p1, const Point2D &p2);
Point3D cross_product(const Point3D &p1, const Point3D &p2);

// Orientation.
float signed_angle(const Point2D &p1, const Point2D &p2, const Point2D &p3);
float angle(const Point2D &p1, const Point2D &p2, const Point2D &p3);
float angle(const Point3D &p1, const Point3D &p2, const Point3D &p3);

// Angle convexity.
bool is_convex(const Point2D &p1, const Point2D &p2, const Point2D &p3);

// Signed area.
float signed_area(const Polygon2D &p);
bool is_clockwise(const Polygon2D &p);

// Signed volume.
float signed_volume(const Point3D &p1, const Point3D &p2, const Point3D &p3,
                    const Point3D &p4);

// Determinants.
float determinant(const Point2D &p1, const Point2D &p2);
float determinant(const Point3D &p1, const Point3D &p2, const Point3D &p3);

// Euclidean distances.
float distance(const Point2D &p);
float distance(const Point2D &p1, const Point2D &p2);
float distance(const Point3D &p);
float distance(const Point3D &p1, const Point3D &p2);

// Area functions.
float area(const Triangle2D &t);
float area(const Triangle3D &t);

// Get center point.
Point2D center(const std::vector<Point2D> &p);
Point3D center(const std::vector<Point3D> &p);

// Barycentric coordinate functions.
Point3D barycentric_coordinates(const Point2D &p, const Triangle2D &t);
Point3D barycentric_coordinates(const Point3D &p, const Triangle3D &t);

// Projection functions.
std::optional<Point2D> project(const Point2D &p, const Line2D &l);
std::optional<Point3D> project(const Point3D &p, const Line3D &l);
std::optional<Point3D> project(const Point3D &p, const Triangle3D &t);

// Intersection functions.
std::optional<Point2D> intersection(const Line2D &l1, const Line2D &l2);
std::optional<Point3D> intersection(const Line3D &l1, const Line3D &l2);
bool intersects(const Line3D &l, const Triangle3D &tr);
std::optional<Point3D> intersection(const Line3D &l, const Triangle3D &tr);

// Nearest intersection functions.
std::optional<std::tuple<Point3D, Point3D>> nearest_points(const Line3D &l1,
                                                           const Line3D &l2);

// Normal vector.
Point3D normal(const Triangle3D &t);

// Check if point is inside triangle.
bool is_inside(const Point2D &p, const Triangle2D &t);
bool is_inside(const Point3D &p, const Triangle3D &t);
bool is_coplanar(const Point3D &p, const Triangle3D &t);

// Minimum distances between geometric objects.
float min_distance(const Point2D &p, const Line2D &l);
float min_distance(const Line2D &l1, const Line2D &l2);
float min_distance(const Point2D &p, const Triangle2D &t);
float min_distance(const Line2D &l, const Triangle2D &t);
float min_distance(const Point3D &p, const Line3D &l);
float min_distance(const Line3D &l1, const Line3D &l2);
float min_distance(const Point3D &p, const Triangle3D &t);

void add_modules(py::module &m);

}  // namespace geometry
}  // namespace cpu
}  // namespace fast_trimesh
