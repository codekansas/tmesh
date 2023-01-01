#include "geometry.h"

#include <numeric>

#define EPSILON 1e-6

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace geometry {

Point2D operator+(const Point2D &p1, const Point2D &p2) {
    return {std::get<0>(p1) + std::get<0>(p2),
            std::get<1>(p1) + std::get<1>(p2)};
}

void operator+=(Point2D &p1, const Point2D &p2) {
    std::get<0>(p1) += std::get<0>(p2);
    std::get<1>(p1) += std::get<1>(p2);
}

Point2D operator-(const Point2D &p1, const Point2D &p2) {
    return {std::get<0>(p1) - std::get<0>(p2),
            std::get<1>(p1) - std::get<1>(p2)};
}

Point2D operator-(const Point2D &p) {
    return {-std::get<0>(p), -std::get<1>(p)};
}

Point2D operator*(const Point2D &p1, const Point2D &p2) {
    return {std::get<0>(p1) * std::get<0>(p2),
            std::get<1>(p1) * std::get<1>(p2)};
}

Point2D operator*(const Point2D &p, float s) {
    return {std::get<0>(p) * s, std::get<1>(p) * s};
}

Point2D operator/(const Point2D &p, float s) {
    return {std::get<0>(p) / s, std::get<1>(p) / s};
}

Point3D operator+(const Point3D &p1, const Point3D &p2) {
    return {std::get<0>(p1) + std::get<0>(p2),
            std::get<1>(p1) + std::get<1>(p2),
            std::get<2>(p1) + std::get<2>(p2)};
}

void operator+=(Point3D &p1, const Point3D &p2) {
    std::get<0>(p1) += std::get<0>(p2);
    std::get<1>(p1) += std::get<1>(p2);
    std::get<2>(p1) += std::get<2>(p2);
}

Point3D operator-(const Point3D &p1, const Point3D &p2) {
    return {std::get<0>(p1) - std::get<0>(p2),
            std::get<1>(p1) - std::get<1>(p2),
            std::get<2>(p1) - std::get<2>(p2)};
}

Point3D operator-(const Point3D &p) {
    return {-std::get<0>(p), -std::get<1>(p), -std::get<2>(p)};
}

Point3D operator*(const Point3D &p1, const Point3D &p2) {
    return {std::get<0>(p1) * std::get<0>(p2),
            std::get<1>(p1) * std::get<1>(p2),
            std::get<2>(p1) * std::get<2>(p2)};
}

Point3D operator*(const Point3D &p, float s) {
    return {std::get<0>(p) * s, std::get<1>(p) * s, std::get<2>(p) * s};
}

Point3D operator/(const Point3D &p, float s) {
    return {std::get<0>(p) / s, std::get<1>(p) / s, std::get<2>(p) / s};
}

Point2D scale(const Point2D &p, float s) {
    return {std::get<0>(p) * s, std::get<1>(p) * s};
}

Point3D scale(const Point3D &p, float s) {
    return {std::get<0>(p) * s, std::get<1>(p) * s, std::get<2>(p) * s};
}

Point2D translate(const Point2D &p, const Point2D &v) {
    return {std::get<0>(p) + std::get<0>(v), std::get<1>(p) + std::get<1>(v)};
}

Point3D translate(const Point3D &p, const Point3D &v) {
    return {std::get<0>(p) + std::get<0>(v), std::get<1>(p) + std::get<1>(v),
            std::get<2>(p) + std::get<2>(v)};
}

Point2D rotate(const Point2D &p, float angle) {
    float x = std::get<0>(p);
    float y = std::get<1>(p);
    float cos_a = std::cos(angle);
    float sin_a = std::sin(angle);
    return {x * cos_a - y * sin_a, x * sin_a + y * cos_a};
}

Point3D rotate(const Point3D &p, const Point3D &angle) {
    float x = std::get<0>(p);
    float y = std::get<1>(p);
    float z = std::get<2>(p);

    float cos_x = std::cos(std::get<0>(angle));
    float sin_x = std::sin(std::get<0>(angle));
    float cos_y = std::cos(std::get<1>(angle));
    float sin_y = std::sin(std::get<1>(angle));
    float cos_z = std::cos(std::get<2>(angle));
    float sin_z = std::sin(std::get<2>(angle));

    float xx = cos_y * cos_z, xy = sin_x * sin_y * cos_z - cos_x * sin_z,
          xz = cos_x * sin_y * cos_z + sin_x * sin_z;
    float yx = cos_y * sin_z, yy = sin_x * sin_y * sin_z + cos_x * cos_z,
          yz = cos_x * sin_y * sin_z - sin_x * cos_z;
    float zx = -sin_y, zy = sin_x * cos_y, zz = cos_x * cos_y;

    return {x * xx + y * xy + z * xz, x * yx + y * yy + z * yz,
            x * zx + y * zy + z * zz};
}

float dot_product(const Point2D &p1, const Point2D &p2) {
    return std::get<0>(p1) * std::get<0>(p2) +
           std::get<1>(p1) * std::get<1>(p2);
}

float dot_product(const Point3D &p1, const Point3D &p2) {
    return std::get<0>(p1) * std::get<0>(p2) +
           std::get<1>(p1) * std::get<1>(p2) +
           std::get<2>(p1) * std::get<2>(p2);
}

float cross_product(const Point2D &p1, const Point2D &p2) {
    return std::get<0>(p1) * std::get<1>(p2) -
           std::get<1>(p1) * std::get<0>(p2);
}

Point3D cross_product(const Point3D &p1, const Point3D &p2) {
    return {
        std::get<1>(p1) * std::get<2>(p2) - std::get<2>(p1) * std::get<1>(p2),
        std::get<2>(p1) * std::get<0>(p2) - std::get<0>(p1) * std::get<2>(p2),
        std::get<0>(p1) * std::get<1>(p2) - std::get<1>(p1) * std::get<0>(p2)};
}

float signed_angle(const Point2D &p1, const Point2D &p2, const Point2D &p3) {
    float angle = std::atan2(cross_product(p2 - p1, p2 - p3),
                             dot_product(p2 - p1, p2 - p3));
    return angle;
}

float angle(const Point2D &p1, const Point2D &p2, const Point2D &p3) {
    float cos_angle = dot_product(p2 - p1, p2 - p3) /
                      std::sqrt(dot_product(p2 - p1, p2 - p1) *
                                dot_product(p2 - p3, p2 - p3));
    return std::acos(cos_angle);
}

float angle(const Point3D &p1, const Point3D &p2, const Point3D &p3) {
    float cos_angle = dot_product(p2 - p1, p2 - p3) /
                      std::sqrt(dot_product(p2 - p1, p2 - p1) *
                                dot_product(p2 - p3, p2 - p3));
    return std::acos(cos_angle);
}

bool is_convex(const Point2D &p1, const Point2D &p2, const Point2D &p3) {
    // Equivalent to angle(p1, p2, p3) <= 0, meaning that a convex polygon
    // is traversed in counter-clockwise order.
    return determinant(p1, p2, p3) >= 0;
}

float signed_area(const Polygon2D &p) {
    int n = p.size();
    float area = 0;
    for (int j = 0; j < n; j++) {
        int i = (j + n - 1) % n;
        float x1 = std::get<0>(p[i]), y1 = std::get<1>(p[i]),
              x2 = std::get<0>(p[j]), y2 = std::get<1>(p[j]);
        area += (x2 - x1) * (y2 + y1);
    }
    return -area / 2;
}

bool is_clockwise(const Polygon2D &p) { return signed_area(p) < 0; }

float signed_volume(const Point3D &p1, const Point3D &p2, const Point3D &p3,
                    const Point3D &p4) {
    return (1.0 / 6.0) * dot_product(cross_product(p2 - p1, p3 - p1), p4 - p1);
}

Polygon2D convex_hull(const Polygon2D &p) {
    int n = p.size();
    if (n <= 3) return p;

    // Finds convex hull using Graham Scan algorithm.
    // https://en.wikipedia.org/wiki/Graham_scan

    // Find the lowest y-coordinate and leftmost point, called P0.
    int P0 = 0;
    for (int i = 1; i < n; i++) {
        auto &[x, y] = p[i];
        auto &[x0, y0] = p[P0];
        if (y < y0 || (y == y0 && x < x0)) P0 = i;
    }

    // Sort points by polar angle with P0, if several points have the same polar
    // angle then put the closer one first.
    std::vector<int> points(n);
    std::iota(points.begin(), points.end(), 0);
    std::sort(points.begin(), points.end(), [&](int i, int j) {
        if (i == P0) return false;
        float det = determinant(p[P0], p[i], p[j]);
        if (det == 0) return distance(p[i], p[P0]) < distance(p[j], p[P0]);
        return det < 0;
    });

    // Traverses the points, keeping points which are convex.
    Polygon2D stack;
    stack.push_back(p[P0]);
    stack.push_back(p[points[1]]);
    for (int i = 2; i < n; i++) {
        int point = points[i];
        while (stack.size() > 1 && determinant(stack[stack.size() - 2],
                                               stack.back(), p[point]) >= 0) {
            stack.pop_back();
        }
        stack.push_back(p[point]);
    }

    return stack;
}

BoundingBox2D bounding_box(const Polygon2D &p) {
    float min_x = std::numeric_limits<float>::max(),
          min_y = std::numeric_limits<float>::max(),
          max_x = std::numeric_limits<float>::lowest(),
          max_y = std::numeric_limits<float>::lowest();
    for (auto &[x, y] : p) {
        min_x = std::min(min_x, x);
        min_y = std::min(min_y, y);
        max_x = std::max(max_x, x);
        max_y = std::max(max_y, y);
    }
    return {{min_x, min_y}, {max_x, max_y}};
}

BoundingBox3D bounding_box(const std::vector<Point3D> &p) {
    float min_x = std::numeric_limits<float>::max(),
          min_y = std::numeric_limits<float>::max(),
          min_z = std::numeric_limits<float>::max(),
          max_x = std::numeric_limits<float>::lowest(),
          max_y = std::numeric_limits<float>::lowest(),
          max_z = std::numeric_limits<float>::lowest();
    for (auto &[x, y, z] : p) {
        min_x = std::min(min_x, x);
        min_y = std::min(min_y, y);
        min_z = std::min(min_z, z);
        max_x = std::max(max_x, x);
        max_y = std::max(max_y, y);
        max_z = std::max(max_z, z);
    }
    return {{min_x, min_y, min_z}, {max_x, max_y, max_z}};
}

float determinant(const Point2D &p1, const Point2D &p2) {
    return std::get<0>(p1) * std::get<1>(p2) -
           std::get<1>(p1) * std::get<0>(p2);
}

float determinant(const Point2D &p1, const Point2D &p2, const Point2D &p3) {
    return determinant(p2 - p1, p3 - p1);
}

float determinant(const Point3D &p1, const Point3D &p2, const Point3D &p3) {
    return std::get<0>(p1) * std::get<1>(p2) * std::get<2>(p3) +
           std::get<0>(p2) * std::get<1>(p3) * std::get<2>(p1) +
           std::get<0>(p3) * std::get<1>(p1) * std::get<2>(p2) -
           std::get<0>(p3) * std::get<1>(p2) * std::get<2>(p1) -
           std::get<0>(p2) * std::get<1>(p1) * std::get<2>(p3) -
           std::get<0>(p1) * std::get<1>(p3) * std::get<2>(p2);
}

float distance(const Point2D &p) {
    return std::sqrt(std::pow(std::get<0>(p), 2) + std::pow(std::get<1>(p), 2));
}

float distance(const Point2D &p1, const Point2D &p2) {
    return std::sqrt(std::pow(std::get<0>(p1) - std::get<0>(p2), 2) +
                     std::pow(std::get<1>(p1) - std::get<1>(p2), 2));
}

float distance(const Point3D &p) {
    return std::sqrt(std::pow(std::get<0>(p), 2) + std::pow(std::get<1>(p), 2) +
                     std::pow(std::get<2>(p), 2));
}

float distance(const Point3D &p1, const Point3D &p2) {
    return std::sqrt(std::pow(std::get<0>(p1) - std::get<0>(p2), 2) +
                     std::pow(std::get<1>(p1) - std::get<1>(p2), 2) +
                     std::pow(std::get<2>(p1) - std::get<2>(p2), 2));
}

float area(const Triangle2D &t) {
    Point2D p1, p2, p3;
    std::tie(p1, p2, p3) = t;
    return 0.5 * std::abs(std::get<0>(p1) * std::get<1>(p2) +
                          std::get<0>(p2) * std::get<1>(p3) +
                          std::get<0>(p3) * std::get<1>(p1) -
                          std::get<0>(p1) * std::get<1>(p3) -
                          std::get<0>(p2) * std::get<1>(p1) -
                          std::get<0>(p3) * std::get<1>(p2));
}

float area(const Triangle3D &t) {
    Point3D p1, p2, p3;
    std::tie(p1, p2, p3) = t;
    return 0.5 * distance(cross_product({std::get<0>(p2) - std::get<0>(p1),
                                         std::get<1>(p2) - std::get<1>(p1),
                                         std::get<2>(p2) - std::get<2>(p1)},
                                        {std::get<0>(p3) - std::get<0>(p1),
                                         std::get<1>(p3) - std::get<1>(p1),
                                         std::get<2>(p3) - std::get<2>(p1)}));
}

Point2D center(const std::vector<Point2D> &p) {
    Point2D c = {0, 0};
    if (p.size() == 0) return c;
    for (const auto &p : p) c += p;
    return c / p.size();
}

Point3D center(const std::vector<Point3D> &p) {
    Point3D c = {0, 0, 0};
    if (p.size() == 0) return c;
    for (const auto &p : p) c += p;
    return c / p.size();
}

Point3D barycentric_coordinates(const Point2D &p, const Triangle2D &t) {
    Point2D l1, l2, l3;
    std::tie(l1, l2, l3) = t;

    // Unpacks the points.
    float x0, y0, x1, y1, x2, y2, x3, y3;
    std::tie(x0, y0) = p;
    std::tie(x1, y1) = l1;
    std::tie(x2, y2) = l2;
    std::tie(x3, y3) = l3;

    // Computes the barycentric coordinates.
    float a = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    float a1 = ((x2 - x0) * (y3 - y0) - (x3 - x0) * (y2 - y0)) / a;
    float a2 = ((x3 - x0) * (y1 - y0) - (x1 - x0) * (y3 - y0)) / a;
    float a3 = ((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)) / a;

    return {a1, a2, a3};
}

Point3D barycentric_coordinates(const Point3D &p, const Triangle3D &t) {
    Point3D l1, l2, l3;
    std::tie(l1, l2, l3) = t;

    // Unpacks the points.
    float x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3;
    std::tie(x0, y0, z0) = p;
    std::tie(x1, y1, z1) = l1;
    std::tie(x2, y2, z2) = l2;
    std::tie(x3, y3, z3) = l3;

    // Gets the normal vector of the triangle.
    Point3D n =
        cross_product({x2 - x1, y2 - y1, z2 - z1}, {x3 - x1, y3 - y1, z3 - z1});
    float xn, yn, zn;
    std::tie(xn, yn, zn) = n;

    // Projects the point onto the plane of the triangle.
    float t1 = (xn * (x1 - x0) + yn * (y1 - y0) + zn * (z1 - z0)) /
               (xn * xn + yn * yn + zn * zn);
    Point3D tp = {x0 + t1 * xn, y0 + t1 * yn, z0 + t1 * zn};
    float xtp, ytp, ztp;
    std::tie(xtp, ytp, ztp) = tp;

    // Computes the barycentric coordinates.
    float a1 = dot_product(cross_product({x2 - x1, y2 - y1, z2 - z1},
                                         {xtp - x1, ytp - y1, ztp - z1}),
                           n),
          a2 = dot_product(cross_product({x3 - x1, y3 - y1, z3 - z1},
                                         {xtp - x2, ytp - y2, ztp - z2}),
                           n),
          a3 = dot_product(cross_product({x1 - x2, y1 - y2, z1 - z2},
                                         {xtp - x3, ytp - y3, ztp - z3}),
                           n);

    return {a1, a2, a3};
}

std::optional<Point2D> project(const Point2D &p, const Line2D &l) {
    // Unpacks the points.
    Point2D p1, p2;
    std::tie(p1, p2) = l;

    // Unpacks the line.
    float x0, y0, x1, y1, x2, y2;
    std::tie(x0, y0) = p;
    std::tie(x1, y1) = p1;
    std::tie(x2, y2) = p2;

    // Computes the point on the line that is closest to p.
    float dx = x2 - x1, dy = y2 - y1;
    float t = ((x0 - x1) * dx + (y0 - y1) * dy) / (dx * dx + dy * dy);

    // If the point is outside the line segment, return null.
    if (t < 0 || t > 1) return std::nullopt;

    // Otherwise, returns the point on the line.
    return std::make_tuple(x1 + t * dx, y1 + t * dy);
}

std::optional<Point3D> project(const Point3D &p, const Line3D &l) {
    // Unpacks the points.
    Point3D p1, p2;
    std::tie(p1, p2) = l;

    // Unpacks the line.
    float x0, y0, z0, x1, y1, z1, x2, y2, z2;
    std::tie(x0, y0, z0) = p;
    std::tie(x1, y1, z1) = p1;
    std::tie(x2, y2, z2) = p2;

    // Computes the point on the line that is closest to p.
    float dx = x2 - x1, dy = y2 - y1, dz = z2 - z1;
    float t = ((x0 - x1) * dx + (y0 - y1) * dy + (z0 - z1) * dz) /
              (dx * dx + dy * dy + dz * dz);

    // If the point is outside the line segment, return null.
    if (t < 0 || t > 1) return std::nullopt;

    // Otherwise, returns the point on the line.
    return std::make_tuple(x1 + t * dx, y1 + t * dy, z1 + t * dz);
}

std::optional<Point3D> project(const Point3D &p, const Triangle3D &t) {
    // Unpacks the points.
    Point3D p1, p2, p3;
    std::tie(p1, p2, p3) = t;

    // Unpacks the triangle.
    float x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3;
    std::tie(x0, y0, z0) = p;
    std::tie(x1, y1, z1) = p1;
    std::tie(x2, y2, z2) = p2;
    std::tie(x3, y3, z3) = p3;

    // Gets the normal vector of the triangle.
    Point3D n =
        cross_product({x2 - x1, y2 - y1, z2 - z1}, {x3 - x1, y3 - y1, z3 - z1});
    float xn, yn, zn;
    std::tie(xn, yn, zn) = n;

    // Computes the point on the plane of the triangle closest to the point.
    float t1 = (xn * (x1 - x0) + yn * (y1 - y0) + zn * (z1 - z0)) /
               (xn * xn + yn * yn + zn * zn);
    Point3D tp = {x0 + t1 * xn, y0 + t1 * yn, z0 + t1 * zn};
    float xtp, ytp, ztp;
    std::tie(xtp, ytp, ztp) = tp;

    // If the point is outside the triangle, return null.
    if (dot_product(cross_product({x2 - x1, y2 - y1, z2 - z1},
                                  {xtp - x1, ytp - y1, ztp - z1}),
                    n) < 0 ||
        dot_product(cross_product({x3 - x2, y3 - y2, z3 - z2},
                                  {xtp - x2, ytp - y2, ztp - z2}),
                    n) < 0 ||
        dot_product(cross_product({x1 - x3, y1 - y3, z1 - z3},
                                  {xtp - x3, ytp - y3, ztp - z3}),
                    n) < 0)
        return std::nullopt;

    // Otherwise, returns the point on the plane.
    return tp;
}

std::optional<Point2D> intersection(const Line2D &l1, const Line2D &l2) {
    // Unpacks the points.
    Point2D p1, p2, p3, p4;
    std::tie(p1, p2) = l1;
    std::tie(p3, p4) = l2;

    // Unpacks the lines.
    float x1, y1, x2, y2, x3, y3, x4, y4;
    std::tie(x1, y1) = p1;
    std::tie(x2, y2) = p2;
    std::tie(x3, y3) = p3;
    std::tie(x4, y4) = p4;

    // Checks if the lines intersect.
    float d = determinant({x1 - x2, y1 - y2}, {x3 - x4, y3 - y4});

    // If the lines are parallel, return null.
    if (d == 0) return std::nullopt;

    // Computes the intersection point.
    float t = ((x3 - x1) * (y4 - y3) - (y3 - y1) * (x4 - x3)) / d;
    float u = ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) / d;

    // If the intersection point is outside the line segments, return null.
    if (t < 0 || t > 1 || u < 0 || u > 1) return std::nullopt;

    // Otherwise, returns the intersection point.
    return std::make_tuple(x1 + t * (x2 - x1), y1 + t * (y2 - y1));
}

std::optional<Point3D> intersection(const Line3D &l1, const Line3D &l2) {
    // Gets the nearest intersection point.
    auto p = nearest_points(l1, l2);

    // If there is no intersection, return null.
    if (!p.has_value()) return std::nullopt;

    // Unpacks the nearest intersection points.
    Point3D p1, p2;
    std::tie(p1, p2) = p.value();

    // If the points are different by some epsilon, return null.
    if (distance(p1, p2) > EPSILON) return std::nullopt;

    // Otherwise, returns the intersection point.
    return p1 + (p2 - p1) / 2.0;
}

bool intersects(const Line3D &l, const Triangle3D &tr) {
    // Unpacks the triangle.
    Point3D p1, p2, p3;
    std::tie(p1, p2, p3) = tr;

    // Unpacks the line.
    Point3D q1, q2;
    std::tie(q1, q2) = l;

    bool s1 = signed_volume(q1, p1, p2, p3) > 0,
         s2 = signed_volume(q2, p1, p2, p3) > 0,
         s3 = signed_volume(q1, q2, p1, p2) > 0,
         s4 = signed_volume(q1, q2, p2, p3) > 0,
         s5 = signed_volume(q1, q2, p3, p1) > 0;

    return (s1 != s2) && (s3 == s4 && s4 == s5);
}

std::optional<Point3D> intersection(const Line3D &l, const Triangle3D &tr) {
    // Unpacks the triangle.
    Point3D p1, p2, p3;
    std::tie(p1, p2, p3) = tr;

    // Unpacks the line.
    Point3D q1, q2;
    std::tie(q1, q2) = l;

    Point3D e1 = p2 - p1, e2 = p3 - p1;
    Point3D n = cross_product(e1, e2);

    float det = -dot_product(q2 - q1, n);

    Point3D ao = q1 - p1;
    Point3D dao = cross_product(ao, q2 - q1);

    float u = dot_product(e2, dao) / det;
    float v = -dot_product(e1, dao) / det;
    float t = dot_product(ao, n) / det;

    if (det < EPSILON || t < 0.0 || u < 0.0 || v < 0.0 || (u + v) > 1.0)
        return std::nullopt;

    return q1 + (q2 - q1) * t;
}

std::optional<std::tuple<Point3D, Point3D>> nearest_points(const Line3D &l1,
                                                           const Line3D &l2) {
    // Unpacks the points.
    Point3D p1, p2, p3, p4;
    std::tie(p1, p2) = l1;
    std::tie(p3, p4) = l2;

    // Unpacks the lines.
    float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    std::tie(x1, y1, z1) = p1;
    std::tie(x2, y2, z2) = p2;
    std::tie(x3, y3, z3) = p3;
    std::tie(x4, y4, z4) = p4;

    // Gets the deltas.
    float dx1 = x2 - x1, dy1 = y2 - y1, dz1 = z2 - z1, dx2 = x4 - x3,
          dy2 = y4 - y3, dz2 = z4 - z3;
    Point3D d1 = {dx1, dy1, dz1}, d2 = {dx2, dy2, dz2};

    // Cross product of the two direction vectors.
    Point3D n = cross_product(d1, d2);
    Point3D n1 = cross_product(d1, n), n2 = cross_product(d2, n);

    // If the lines are parallel, return null.
    float d2n1 = dot_product(d2, n1), d1n2 = dot_product(d1, n2);
    if (d2n1 == 0 || d1n2 == 0) return std::nullopt;

    // Computes the nearest intersection points.
    Point3D c1 = p1 + d1 * (dot_product(n2, p3 - p1) / d1n2),
            c2 = p3 + d2 * (dot_product(n1, p1 - p3) / d2n1);

    return std::make_tuple(c1, c2);
}

Point3D normal(const Triangle3D &t) {
    Point3D p1, p2, p3;
    std::tie(p1, p2, p3) = t;
    return cross_product(p2 - p1, p3 - p1);
}

bool is_inside(const Point2D &p, const Triangle2D &t) {
    float a1, a2, a3;
    std::tie(a1, a2, a3) = barycentric_coordinates(p, t);
    return (a1 >= 0 && a2 >= 0 && a3 >= 0);
}

bool is_inside(const Point3D &p, const Triangle3D &t) {
    float a1, a2, a3;
    std::tie(a1, a2, a3) = barycentric_coordinates(p, t);
    return (a1 >= 0 && a2 >= 0 && a3 >= 0);
}

bool is_coplanar(const Point3D &p, const Triangle3D &t) {
    float a1, a2, a3;
    std::tie(a1, a2, a3) = barycentric_coordinates(p, t);
    return (a1 == 0 || a2 == 0 || a3 == 0);
}

float min_distance(const Point2D &p, const Line2D &l) {
    // Unpacks the points.
    Point2D p1, p2;
    std::tie(p1, p2) = l;

    // Unpacks the line.
    float x0, y0, x1, y1, x2, y2;
    std::tie(x0, y0) = p;
    std::tie(x1, y1) = p1;
    std::tie(x2, y2) = p2;

    // Computes the point on the line that is closest to p.
    float dx = x2 - x1, dy = y2 - y1;
    float t = ((x0 - x1) * dx + (y0 - y1) * dy) / (dx * dx + dy * dy);

    // If the point is outside the line segment, returns the distance to the
    // closest endpoint.
    if (t < 0) return distance(p, p1);
    if (t > 1) return distance(p, p2);

    // Otherwise, returns the distance to the point on the line.
    return distance(p, {x1 + t * dx, y1 + t * dy});
}

float min_distance(const Line2D &l1, const Line2D &l2) {
    // Unpacks the points.
    Point2D p1, p2, p3, p4;
    std::tie(p1, p2) = l1;
    std::tie(p3, p4) = l2;

    // Checks if the lines intersect.
    std::optional<Point2D> p = intersection(l1, l2);

    // If the lines intersect, returns zero.
    if (p) return 0.0;

    // Otherwise, returns the minimum distance from each endpoint to the
    // opposite line.
    return std::min({min_distance(p1, l2), min_distance(p2, l2),
                     min_distance(p3, l1), min_distance(p4, l1)});
}

float min_distance(const Point2D &p, const Triangle2D &t) {
    if (is_inside(p, t)) return 0.0;

    // Unpacks the triangle.
    Point2D l1, l2, l3;
    std::tie(l1, l2, l3) = t;

    // Unpacks the points.
    float x0, y0, x1, y1, x2, y2, x3, y3;
    std::tie(x0, y0) = p;
    std::tie(x1, y1) = l1;
    std::tie(x2, y2) = l2;
    std::tie(x3, y3) = l3;

    // Computes the distances from the point to each edge.
    float d1 = distance(p, l1), d2 = distance(p, l2), d3 = distance(p, l3);

    return std::min({d1, d2, d3});
}

float min_distance(const Line2D &l, const Triangle2D &t) {
    // Unpacks the line.
    Point2D p1, p2;
    std::tie(p1, p2) = l;

    // Unpacks the triangle.
    Point2D p3, p4, p5;
    std::tie(p3, p4, p5) = t;

    // If any of the line's endpoints are inside the triangle, returns zero.
    if (is_inside(p1, t) || is_inside(p2, t)) return 0.0;

    // Minimum distance from the line to the triangle is the minimum
    // distance from the line to any of the triangle's edges, or the
    // minimum distance from any of the triangle's vertices to the line.
    return std::min({
        min_distance(l, {p3, p4}),
        min_distance(l, {p4, p5}),
        min_distance(l, {p5, p3}),
        min_distance(p3, l),
        min_distance(p4, l),
        min_distance(p5, l),
    });
}

float min_distance(const Point3D &p, const Line3D &l) {
    // Unpacks the line.
    Point3D p1, p2;
    std::tie(p1, p2) = l;

    // Unpacks the points.
    float x0, y0, z0, x1, y1, z1, x2, y2, z2;
    std::tie(x0, y0, z0) = p;
    std::tie(x1, y1, z1) = p1;
    std::tie(x2, y2, z2) = p2;

    // Computes the point on the line closest to the point.
    float dx = x2 - x1, dy = y2 - y1, dz = z2 - z1;
    float t = ((x0 - x1) * dx + (y0 - y1) * dy + (z0 - z1) * dz) /
              (dx * dx + dy * dy + dz * dz);

    // If the point is outside the line segment, returns the minimum
    // distance from the point to the line segment's endpoints.
    if (t < 0) return distance(p, p1);
    if (t > 1) return distance(p, p2);

    // Returns the distance from the point to the line.
    return distance(p, {x1 + t * dx, y1 + t * dy, z1 + t * dz});
}

float min_distance(const Line3D &l1, const Line3D &l2) {
    // Unpacks the lines.
    Point3D p1, p2, p3, p4;
    std::tie(p1, p2) = l1;
    std::tie(p3, p4) = l2;

    // Checks if the lines intersect.
    std::optional<std::tuple<Point3D, Point3D>> p = nearest_points(l1, l2);

    // If nearest intersection points were found, return their distance.
    if (p) return distance(std::get<0>(p.value()), std::get<1>(p.value()));

    // Otherwise, returns the minimum distance from each endpoint to the
    // opposite line.
    return std::min({min_distance(p1, l2), min_distance(p2, l2),
                     min_distance(p3, l1), min_distance(p4, l1)});
}

float min_distance(const Point3D &p, const Triangle3D &t) {
    // Unpacks the triangle.
    Point3D p1, p2, p3;
    std::tie(p1, p2, p3) = t;

    // Projects the point onto the triangle's plane.
    std::optional<Point3D> tp = project(p, t);

    // If the projected point is inside the triangle, returns the distance
    // from the point to the projected point.
    if (tp.has_value()) return distance(p, tp.value());

    // Otherwise, returns the minimum distance from the point to each of the
    // triangle's edges.
    return std::min({min_distance(p, {p1, p2}), min_distance(p, {p2, p3}),
                     min_distance(p, {p3, p1})});
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("geometry");
    s.doc() = "Geometry helper functions.";

    // Scales a point from the origin by a scalar.
    s.def("scale", py::overload_cast<const Point2D &, float>(&scale),
          "Scales a 2D point from the origin by a scalar", "p"_a, "s"_a);
    s.def("scale", py::overload_cast<const Point3D &, float>(&scale),
          "Scales a 3D point from the origin by a scalar", "p"_a, "s"_a);

    // Translates a point by a vector.
    s.def("translate",
          py::overload_cast<const Point2D &, const Point2D &>(&translate),
          "Translates a 2D point by a vector", "p"_a, "v"_a);
    s.def("translate",
          py::overload_cast<const Point3D &, const Point3D &>(&translate),
          "Translates a 3D point by a vector", "p"_a, "v"_a);

    // Rotate a point by an angle.
    s.def("rotate", py::overload_cast<const Point2D &, float>(&rotate),
          "Rotates a 2D point by a rotation vector", "p"_a, "angle"_a);
    s.def("rotate",
          py::overload_cast<const Point3D &, const Point3D &>(&rotate),
          "Rotates a 3D point by a rotation vector", "p"_a, "angle"_a);

    // Vector products.
    s.def("dot_product",
          py::overload_cast<const Point2D &, const Point2D &>(&dot_product),
          "Dot product of two 2D vectors", "p1"_a, "p2"_a);
    s.def("dot_product",
          py::overload_cast<const Point3D &, const Point3D &>(&dot_product),
          "Dot product of two 3D vectors", "p1"_a, "p2"_a);
    s.def("cross_product",
          py::overload_cast<const Point2D &, const Point2D &>(&cross_product),
          "Cross product of two 2D vectors", "p1"_a, "p2"_a);
    s.def("cross_product",
          py::overload_cast<const Point3D &, const Point3D &>(&cross_product),
          "Cross product of two 3D vectors", "p1"_a, "p2"_a);

    // Orientation.
    s.def("signed_angle",
          py::overload_cast<const Point2D &, const Point2D &, const Point2D &>(
              &signed_angle),
          "Signed angle between two 2D vectors", "p1"_a, "p2"_a, "p3"_a);
    s.def("angle",
          py::overload_cast<const Point2D &, const Point2D &, const Point2D &>(
              &angle),
          "Angle between two 2D vectors", "p1"_a, "p2"_a, "p3"_a);
    s.def("angle",
          py::overload_cast<const Point3D &, const Point3D &, const Point3D &>(
              &angle),
          "Angle between two 3D vectors", "p1"_a, "p2"_a, "p3"_a);

    // Angle convexity.
    s.def("is_convex",
          py::overload_cast<const Point2D &, const Point2D &, const Point2D &>(
              &is_convex),
          "Equivalent to `angle(p1, p2, p3) < 0`; convex polygon is "
          "traversed "
          "in counter-clockwise order",
          "p1"_a, "p2"_a, "p3"_a);

    // Signed area.
    s.def("signed_area", &signed_area,
          "Signed area of a 2D polygon (positive if counter-clockwise, "
          "negative if clockwise)",
          "p"_a);
    s.def("is_clockwise", &is_clockwise,
          "Checks if points in a 2D polygon are in clockwise or "
          "counter-clockwise order",
          "p"_a);

    // Signed volume.
    s.def("signed_volume",
          py::overload_cast<const Point3D &, const Point3D &, const Point3D &,
                            const Point3D &>(&signed_volume),
          "Signed volume of a 3D tetrahedron (positive if p1, p2, p3 are "
          "counterclockwise when viewed from p4, negative if clockwise)",
          "p1"_a, "p2"_a, "p3"_a, "p4"_a);

    // Convex hull.
    s.def("convex_hull", &convex_hull,
          "Computes the convex hull of a set of 2D points", "p"_a);

    // Determinants.
    s.def("determinant",
          py::overload_cast<const Point2D &, const Point2D &>(&determinant),
          "Determinant of a 2x2 matrix", "p1"_a, "p2"_a);
    s.def("determinant",
          py::overload_cast<const Point3D &, const Point3D &, const Point3D &>(
              &determinant),
          "Determinant of a 3x3 matrix", "p1"_a, "p2"_a, "p3"_a);

    // Euclidean distances.
    s.def("distance", py::overload_cast<const Point2D &>(&distance),
          "Magnitude of a 2D vector", "p"_a);
    s.def("distance",
          py::overload_cast<const Point2D &, const Point2D &>(&distance),
          "Distance between two 2D points", "p1"_a, "p2"_a);
    s.def("distance", py::overload_cast<const Point3D &>(&distance),
          "Magnitude of a 3D vector", "p"_a);
    s.def("distance",
          py::overload_cast<const Point3D &, const Point3D &>(&distance),
          "Distance between two 3D points", "p1"_a, "p2"_a);

    // Area functions.
    s.def("area", py::overload_cast<const Triangle2D &>(&area),
          "Area of a 2D triangle", "t"_a);
    s.def("area", py::overload_cast<const Triangle3D &>(&area),
          "Area of a 3D triangle", "t"_a);

    // Get center point.
    s.def("center", py::overload_cast<const std::vector<Point2D> &>(&center),
          "Center of a 2D polygon", "p"_a);
    s.def("center", py::overload_cast<const std::vector<Point3D> &>(&center),
          "Center of a 3D polygon", "p"_a);

    // Barycentric coordinate functions.
    s.def("barycentric_coordinates",
          py::overload_cast<const Point2D &, const Triangle2D &>(
              &barycentric_coordinates),
          "Barycentric coordinates of a 2D point with respect to a 2D "
          "triangle",
          "p"_a, "t"_a);
    s.def("barycentric_coordinates",
          py::overload_cast<const Point3D &, const Triangle3D &>(
              &barycentric_coordinates),
          "Barycentric coordinates of a 3D point with respect to a 3D "
          "triangle",
          "p"_a, "t"_a);

    // Projection functions.
    s.def("project",
          py::overload_cast<const Point2D &, const Line2D &>(&project),
          "Project a 2D point onto a 2D line segment, returning None if the "
          "projected point is outside the line segment",
          "p"_a, "l"_a);
    s.def("project",
          py::overload_cast<const Point3D &, const Line3D &>(&project),
          "Project a 3D point onto a 3D line, returning None if the "
          "projected "
          "point is outside the line segment",
          "p"_a, "l"_a);
    s.def("project",
          py::overload_cast<const Point3D &, const Triangle3D &>(&project),
          "Project a 3D point onto a 3D triangle, returning None if the "
          "projected point is outside the triangle",
          "p"_a, "t"_a);

    // Intersection functions.
    s.def("intersection",
          py::overload_cast<const Line2D &, const Line2D &>(&intersection),
          "Gets the intersection of two line segments, returning None if "
          "they "
          "do not intersect",
          "l1"_a, "l2"_a);
    s.def("intersection",
          py::overload_cast<const Line3D &, const Line3D &>(&intersection),
          "Gets the intersection of two lines, returning None if they do not "
          "intersect",
          "l1"_a, "l2"_a);
    s.def("intersects",
          py::overload_cast<const Line3D &, const Triangle3D &>(&intersects),
          "Checks if a 3D line intersects a 3D triangle", "l1"_a, "l2"_a);
    s.def("intersection",
          py::overload_cast<const Line3D &, const Triangle3D &>(&intersection),
          "Gets the intersection of a 3D line and a 3D triangle, returning "
          "None "
          "if they do not intersect",
          "l"_a, "t"_a);

    // Nearest intersection functions.
    s.def("nearest_points",
          py::overload_cast<const Line3D &, const Line3D &>(&nearest_points),
          "Gets the nearest points between two lines", "p"_a, "l"_a);

    // Normal vector.
    s.def("normal", py::overload_cast<const Triangle3D &>(&normal),
          "Normal vector of a 3D triangle", "t"_a);

    // Check if point is inside triangle.
    s.def("is_inside",
          py::overload_cast<const Point2D &, const Triangle2D &>(&is_inside),
          "Checks if a 2D point is inside a 2D triangle", "p"_a, "t"_a);
    s.def("is_inside",
          py::overload_cast<const Point3D &, const Triangle3D &>(&is_inside),
          "Checks if a 3D point is inside a 3D triangle", "p"_a, "t"_a);
    s.def("is_coplanar",
          py::overload_cast<const Point3D &, const Triangle3D &>(&is_coplanar),
          "Checks if a 3D point is coplanar with a 3D triangle", "p"_a, "t"_a);

    // Geometric utility functions.
    s.def("min_distance",
          py::overload_cast<const Point2D &, const Line2D &>(&min_distance),
          "Gets the minimum distance between a 2D point and a 2D line "
          "segment",
          "p"_a, "l"_a);
    s.def("min_distance",
          py::overload_cast<const Line2D &, const Line2D &>(&min_distance),
          "Gets the minimum distance between two 2D line segments", "l1"_a,
          "l2"_a);
    s.def("min_distance",
          py::overload_cast<const Point2D &, const Triangle2D &>(&min_distance),
          "Gets the minimum distance between a 2D point and a 2D triangle",
          "p"_a, "t"_a);
    s.def("min_distance",
          py::overload_cast<const Line2D &, const Triangle2D &>(&min_distance),
          "Gets the minimum distance between a 2D line segment and a 2D "
          "triangle",
          "l"_a, "t"_a);
    s.def("min_distance",
          py::overload_cast<const Point3D &, const Line3D &>(&min_distance),
          "Gets the minimum distance between a 3D point and a 3D line "
          "segment",
          "p"_a, "l"_a);
    s.def("min_distance",
          py::overload_cast<const Line3D &, const Line3D &>(&min_distance),
          "Gets the minimum distance between two 3D line segments", "l1"_a,
          "l2"_a);
    s.def("min_distance",
          py::overload_cast<const Point3D &, const Triangle3D &>(&min_distance),
          "Gets the minimum distance between a 3D point and a 3D triangle",
          "p"_a, "t"_a);
}

}  // namespace geometry
}  // namespace cpu
}  // namespace fast_trimesh
