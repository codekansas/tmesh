#include "types.h"

#include <iostream>
#include <numeric>
#include <sstream>

using namespace pybind11::literals;

#define TOLERANCE 1e-6

namespace fast_trimesh {
namespace cpu {
namespace types {

/* ------- *
 * Point2D *
 * ------- */

Point2D Point2D::operator+=(const Point2D &p) {
    x += p.x;
    y += p.y;
    return *this;
}

Point2D Point2D::operator-=(const Point2D &p) {
    x -= p.x;
    y -= p.y;
    return *this;
}

Point2D Point2D::operator*=(const Point2D &p) {
    x *= p.x;
    y *= p.y;
    return *this;
}

Point2D Point2D::operator*=(float s) {
    x *= s;
    y *= s;
    return *this;
}

Point2D Point2D::operator/=(const Point2D &p) {
    x /= p.x;
    y /= p.y;
    return *this;
}

Point2D Point2D::operator/=(float s) {
    x /= s;
    y /= s;
    return *this;
}

bool Point2D::operator==(const Point2D &p) const {
    return std::abs(x - p.x) < TOLERANCE && std::abs(y - p.y) < TOLERANCE;
}

bool Point2D::operator!=(const Point2D &p) const { return !(*this == p); }

bool Point2D::operator<(const Point2D &p) const {
    return x < p.x || (x == p.x && y < p.y);
}

Point2D Point2D::operator<<=(const Affine2D &a) {
    Point2D p = *this << a;
    x = p.x;
    y = p.y;
    return *this;
}

Point2D Point2D::normalize() const {
    float l = length();
    return Point2D{x / l, y / l};
}

Point2D Point2D::rotate(float angle) const {
    float c = std::cos(angle);
    float s = std::sin(angle);
    return Point2D{x * c - y * s, x * s + y * c};
}

float Point2D::determinant(const Point2D &other) const {
    return x * other.y - y * other.x;
}

float Point2D::length() const { return std::sqrt(x * x + y * y); }

float Point2D::dot(const Point2D &other) const {
    return x * other.x + y * other.y;
}

float Point2D::cross(const Point2D &other) const {
    return x * other.y - y * other.x;
}

BarycentricCoordinates Point2D::barycentric_coordinates(
    const Triangle2D &t) const {
    Point2D v0 = t.p2 - t.p1;
    Point2D v1 = t.p3 - t.p1;
    Point2D v2 = *this - t.p1;

    float d00 = v0.dot(v0);
    float d01 = v0.dot(v1);
    float d11 = v1.dot(v1);
    float d20 = v2.dot(v0);
    float d21 = v2.dot(v1);
    float denom = d00 * d11 - d01 * d01;

    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;

    return {u, v, w};
}

bool Point2D::is_inside_triangle(const Triangle2D &t) const {
    BarycentricCoordinates bary = barycentric_coordinates(t);
    return bary.u >= 0.0f && bary.v >= 0.0f && bary.w >= 0.0f;
}

bool Point2D::is_inside_bounding_box(const BoundingBox2D &bb) const {
    return x >= bb.min.x && x <= bb.max.x && y >= bb.min.y && y <= bb.max.y;
}

float Point2D::distance_to_point(const Point2D &p) const {
    return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

float Point2D::distance_to_line(const Line2D &l) const {
    return l.distance_to_point(*this);
}

float Point2D::distance_to_triangle(const Triangle2D &t) const {
    return t.distance_to_point(*this);
}

float Point2D::distance_to_bounding_box(const BoundingBox2D &bb) const {
    return bb.distance_to_point(*this);
}

std::optional<Point2D> Point2D::project_to_line(const Line2D &l) const {
    float dx = l.p2.x - l.p1.x, dy = l.p2.y - l.p1.y;
    float t = ((x - l.p1.x) * dx + (y - l.p1.y) * dy) / (dx * dx + dy * dy);
    if (t < 0.0f || t > 1.0f) return std::nullopt;
    return Point2D{l.p1.x + t * dx, l.p1.y + t * dy};
}

std::string Point2D::to_string() const {
    std::ostringstream ss;
    ss << "Point2D(" << x << ", " << y << ")";
    return ss.str();
}

Point2D operator+(const Point2D &p1, const Point2D &p2) {
    return {p1.x + p2.x, p1.y + p2.y};
}

Point2D operator-(const Point2D &p1, const Point2D &p2) {
    return {p1.x - p2.x, p1.y - p2.y};
}

Point2D operator*(const Point2D &p1, const Point2D &p2) {
    return {p1.x * p2.x, p1.y * p2.y};
}

Point2D operator*(const Point2D &p, float s) { return {p.x * s, p.y * s}; }

Point2D operator*(float s, const Point2D &p) { return {p.x * s, p.y * s}; }

Point2D operator/(const Point2D &p1, const Point2D &p2) {
    return {p1.x / p2.x, p1.y / p2.y};
}

Point2D operator/(const Point2D &p, float s) { return {p.x / s, p.y / s}; }

bool is_convex(const Point2D &a, const Point2D &b, const Point2D &c) {
    // Equivalent to angle(a, b, c) <= 0, meaning that a convex polygon
    // is traversed in a counter-clockwise direction.
    return (b - a).determinant(c - a) >= 0;
}

/* ------- *
 * Line2D *
 * ------- */

bool Line2D::operator==(const Line2D &other) const {
    return p1 == other.p1 && p2 == other.p2;
}

bool Line2D::operator!=(const Line2D &other) const { return !(*this == other); }

Line2D Line2D::operator<<=(const Affine2D &a) {
    p1 <<= a;
    p2 <<= a;
    return *this;
}

Point2D Line2D::closest_point(const Point2D &p) const {
    Point2D v = p2 - p1;
    Point2D w = p - p1;

    float c1 = w.dot(v);
    if (c1 <= 0.0f) return p1;

    float c2 = v.dot(v);
    if (c2 <= c1) return p2;

    float b = c1 / c2;
    return p1 + v * b;
}

std::optional<Point2D> Line2D::intersection(const Line2D &l) const {
    Point2D r = p2 - p1;
    Point2D s = l.p2 - l.p1;

    float rxs = r.cross(s);
    if (std::abs(rxs) < TOLERANCE) return std::nullopt;

    Point2D qmp1 = l.p1 - p1;
    float t = qmp1.cross(s) / rxs;
    float u = qmp1.cross(r) / rxs;

    if (t < 0.0f || t > 1.0f || u < 0.0f || u > 1.0f) return std::nullopt;

    return p1 + r * t;
}

float Line2D::distance_to_point(const Point2D &p) const {
    Point2D pb = closest_point(p);
    return p.distance_to_point(pb);
}

float Line2D::distance_to_line(const Line2D &l) const {
    std::optional<Point2D> p = intersection(l);

    if (p) return 0.0f;

    return std::min({distance_to_point(l.p1), distance_to_point(l.p2),
                     l.distance_to_point(p1), l.distance_to_point(p2)});
}

float Line2D::distance_to_triangle(const Triangle2D &t) const {
    return t.distance_to_line(*this);
}

float Line2D::distance_to_bounding_box(const BoundingBox2D &bb) const {
    return bb.distance_to_line(*this);
}

std::string Line2D::to_string() const {
    std::ostringstream ss;
    ss << "Line2D(" << p1.to_string() << ", " << p2.to_string() << ")";
    return ss.str();
}

/* --------- *
 * Triangle2D *
 * --------- */

bool Triangle2D::operator==(const Triangle2D &other) const {
    return (p1 == other.p1 && p2 == other.p2 && p3 == other.p3) ||
           (p1 == other.p2 && p2 == other.p3 && p3 == other.p1) ||
           (p1 == other.p3 && p2 == other.p1 && p3 == other.p2);
}

bool Triangle2D::operator!=(const Triangle2D &other) const {
    return !(*this == other);
}

Triangle2D Triangle2D::operator<<=(const Affine2D &a) {
    p1 <<= a;
    p2 <<= a;
    p3 <<= a;
    return *this;
}

float Triangle2D::area() const {
    return std::abs((p1.x - p3.x) * (p2.y - p1.y) -
                    (p1.x - p2.x) * (p3.y - p1.y)) /
           2.0f;
}

Point2D Triangle2D::center() const { return (p1 + p2 + p3) / 3.0f; }

float Triangle2D::distance_to_point(const Point2D &p) const {
    if (p.is_inside_triangle(*this)) return 0.0f;
    Line2D l1 = {p1, p2}, l2 = {p2, p3}, l3 = {p3, p1};
    return std::min({l1.distance_to_point(p), l2.distance_to_point(p),
                     l3.distance_to_point(p)});
}

float Triangle2D::distance_to_line(const Line2D &l) const {
    if (l.p1.is_inside_triangle(*this) || l.p2.is_inside_triangle(*this))
        return 0.0f;
    Line2D l1 = {p1, p2}, l2 = {p2, p3}, l3 = {p3, p1};
    return std::min({l1.distance_to_line(l), l2.distance_to_line(l),
                     l3.distance_to_line(l)});
}

float Triangle2D::distance_to_triangle(const Triangle2D &t) const {
    Line2D l1 = {p1, p2}, l2 = {p2, p3}, l3 = {p3, p1};
    Line2D l4 = {t.p1, t.p2}, l5 = {t.p2, t.p3}, l6 = {t.p3, t.p1};
    return std::min({l1.distance_to_line(l4), l1.distance_to_line(l5),
                     l1.distance_to_line(l6), l2.distance_to_line(l4),
                     l2.distance_to_line(l5), l2.distance_to_line(l6),
                     l3.distance_to_line(l4), l3.distance_to_line(l5),
                     l3.distance_to_line(l6)});
}

float Triangle2D::distance_to_bounding_box(const BoundingBox2D &b) const {
    return b.distance_to_triangle(*this);
}

std::string Triangle2D::to_string() const {
    std::ostringstream ss;
    ss << "Triangle2D(" << p1.to_string() << ", " << p2.to_string() << ", "
       << p3.to_string() << ")";
    return ss.str();
}

/* ------------- *
 * BoundingBox2D *
 * ------------- */

BoundingBox2D::BoundingBox2D() {
    min = {std::numeric_limits<float>::max(),
           std::numeric_limits<float>::max()};
    max = {std::numeric_limits<float>::lowest(),
           std::numeric_limits<float>::lowest()};
}

BoundingBox2D::BoundingBox2D(const Point2D &p1, const Point2D &p2) {
    min = {std::min(p1.x, p2.x), std::min(p1.y, p2.y)};
    max = {std::max(p1.x, p2.x), std::max(p1.y, p2.y)};
}

BoundingBox2D::BoundingBox2D(const std::vector<Point2D> &points) {
    if (points.empty()) throw std::runtime_error("Empty point list");

    float min_x = points[0].x, min_y = points[0].y;
    float max_x = points[0].x, max_y = points[0].y;

    for (size_t i = 1; i < points.size(); ++i) {
        min_x = std::min(min_x, points[i].x);
        min_y = std::min(min_y, points[i].y);
        max_x = std::max(max_x, points[i].x);
        max_y = std::max(max_y, points[i].y);
    }

    min = {min_x, min_y};
    max = {max_x, max_y};
}

BoundingBox2D::BoundingBox2D(const std::vector<Line2D> &lines) {
    if (lines.empty()) throw std::runtime_error("Empty line list");

    float min_x = lines[0].p1.x, min_y = lines[0].p1.y;
    float max_x = lines[0].p1.x, max_y = lines[0].p1.y;

    for (size_t i = 0; i < lines.size(); ++i) {
        min_x = std::min(min_x, lines[i].p1.x);
        min_y = std::min(min_y, lines[i].p1.y);
        max_x = std::max(max_x, lines[i].p1.x);
        max_y = std::max(max_y, lines[i].p1.y);

        min_x = std::min(min_x, lines[i].p2.x);
        min_y = std::min(min_y, lines[i].p2.y);
        max_x = std::max(max_x, lines[i].p2.x);
        max_y = std::max(max_y, lines[i].p2.y);
    }

    min = {min_x, min_y};
    max = {max_x, max_y};
}

BoundingBox2D::BoundingBox2D(const std::vector<Triangle2D> &triangles) {
    if (triangles.empty()) throw std::runtime_error("Empty triangle list");

    float min_x = triangles[0].p1.x, min_y = triangles[0].p1.y;
    float max_x = triangles[0].p1.x, max_y = triangles[0].p1.y;

    for (size_t i = 0; i < triangles.size(); ++i) {
        min_x = std::min(min_x, triangles[i].p1.x);
        min_y = std::min(min_y, triangles[i].p1.y);
        max_x = std::max(max_x, triangles[i].p1.x);
        max_y = std::max(max_y, triangles[i].p1.y);

        min_x = std::min(min_x, triangles[i].p2.x);
        min_y = std::min(min_y, triangles[i].p2.y);
        max_x = std::max(max_x, triangles[i].p2.x);
        max_y = std::max(max_y, triangles[i].p2.y);

        min_x = std::min(min_x, triangles[i].p3.x);
        min_y = std::min(min_y, triangles[i].p3.y);
        max_x = std::max(max_x, triangles[i].p3.x);
        max_y = std::max(max_y, triangles[i].p3.y);
    }

    min = {min_x, min_y};
    max = {max_x, max_y};
}

BoundingBox2D::BoundingBox2D(const std::vector<BoundingBox2D> &bboxes) {
    if (bboxes.empty()) throw std::runtime_error("Empty bounding box list");

    float min_x = bboxes[0].min.x, min_y = bboxes[0].min.y;
    float max_x = bboxes[0].max.x, max_y = bboxes[0].max.y;

    for (size_t i = 1; i < bboxes.size(); ++i) {
        min_x = std::min(min_x, bboxes[i].min.x);
        min_y = std::min(min_y, bboxes[i].min.y);
        max_x = std::max(max_x, bboxes[i].max.x);
        max_y = std::max(max_y, bboxes[i].max.y);
    }

    min = {min_x, min_y};
    max = {max_x, max_y};
}

bool BoundingBox2D::operator==(const BoundingBox2D &b) const {
    return min == b.min && max == b.max;
}

bool BoundingBox2D::operator!=(const BoundingBox2D &b) const {
    return min != b.min || max != b.max;
}

BoundingBox2D BoundingBox2D::operator<<=(const Affine2D &a) {
    min <<= a;
    max <<= a;
    return *this;
}

float BoundingBox2D::distance_to_point(const Point2D &p) const {
    if (p.is_inside_bounding_box(*this)) return 0.0f;
    return std::min({p.distance_to_line({min, {max.x, min.y}}),
                     p.distance_to_line({{max.x, min.y}, max}),
                     p.distance_to_line({max, {min.x, max.y}}),
                     p.distance_to_line({{min.x, max.y}, min})});
}

float BoundingBox2D::distance_to_line(const Line2D &l) const {
    if (l.p1.is_inside_bounding_box(*this) ||
        l.p2.is_inside_bounding_box(*this))
        return 0.0f;
    return std::min({l.distance_to_line({min, {max.x, min.y}}),
                     l.distance_to_line({{max.x, min.y}, max}),
                     l.distance_to_line({max, {min.x, max.y}}),
                     l.distance_to_line({{min.x, max.y}, min})});
}

float BoundingBox2D::distance_to_triangle(const Triangle2D &t) const {
    if (t.p1.is_inside_bounding_box(*this) ||
        t.p2.is_inside_bounding_box(*this) ||
        t.p3.is_inside_bounding_box(*this))
        return 0.0f;
    return std::min({t.distance_to_line({min, {max.x, min.y}}),
                     t.distance_to_line({{max.x, min.y}, max}),
                     t.distance_to_line({max, {min.x, max.y}}),
                     t.distance_to_line({{min.x, max.y}, min})});
}

float BoundingBox2D::distance_to_bounding_box(const BoundingBox2D &b) const {
    Point2D p1 = min, p2 = {max.x, min.y}, p3 = max, p4 = {min.x, max.y};
    if (p1.is_inside_bounding_box(b) || p2.is_inside_bounding_box(b) ||
        p3.is_inside_bounding_box(b) || p4.is_inside_bounding_box(b))
        return 0.0f;
    return std::min({b.distance_to_line({p1, p2}), b.distance_to_line({p2, p3}),
                     b.distance_to_line({p3, p4}),
                     b.distance_to_line({p4, p1})});
}

std::string BoundingBox2D::to_string() const {
    std::ostringstream ss;
    ss << "BoundingBox2D(" << min.to_string() << ", " << max.to_string() << ")";
    return ss.str();
}

/* --------- *
 * Polygon2D *
 * --------- */

Polygon2D::Polygon2D(const std::vector<Point2D> &ps) : points(ps) {
    if (points.size() < 3)
        throw std::runtime_error("Polygon2D must have at least 3 points");
}

bool Polygon2D::operator==(const Polygon2D &p) const {
    return points == p.points;
}

bool Polygon2D::operator!=(const Polygon2D &p) const {
    return points != p.points;
}

Polygon2D Polygon2D::operator<<=(const Affine2D &a) {
    for (auto &p : points) p <<= a;
    return *this;
}

float Polygon2D::signed_area() const {
    float area = 0.0f;
    for (size_t i = 0; i < points.size(); ++i) {
        const Point2D &p1 = points[i];
        const Point2D &p2 = points[(i + 1) % points.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return area * 0.5f;
}

bool Polygon2D::is_clockwise() const { return signed_area() < 0.0f; }

void Polygon2D::reverse() { std::reverse(points.begin(), points.end()); }

Polygon2D Polygon2D::convex_hull() const {
    int n = points.size();
    if (n <= 3) return *this;

    // Finds convex hull using Graham Scan algorithm.
    // https://en.wikipedia.org/wiki/Graham_scan

    // Find the lowest y-coordinate and leftmost point, called P0.
    int P0 = 0;
    for (int i = 1; i < n; i++) {
        auto &[x, y] = points[i];
        auto &[x0, y0] = points[P0];
        if (y < y0 || (y == y0 && x < x0)) P0 = i;
    }

    // Sort points by polar angle with P0, if several points have the same
    // polar angle then put the closer one first.
    std::vector<int> hull_points(n);
    std::iota(hull_points.begin(), hull_points.end(), 0);
    std::sort(hull_points.begin(), hull_points.end(), [&](int i, int j) {
        if (i == P0) return false;
        float det =
            (points[i] - points[P0]).determinant(points[j] - points[P0]);
        if (det == 0)
            return points[i].distance_to_point(points[P0]) <
                   points[j].distance_to_point(points[P0]);
        return det < 0;
    });

    // Traverses the points, keeping points which are convex.
    std::vector<Point2D> stack;
    stack.push_back(points[P0]);
    stack.push_back(points[hull_points[1]]);
    for (int i = 2; i < n; i++) {
        int point = hull_points[i];
        while (stack.size() > 1 &&
               (stack[stack.size() - 2] - points[point])
                       .determinant(stack.back() - points[point]) >= 0) {
            stack.pop_back();
        }
        stack.push_back(points[point]);
    }

    return {stack};
}

BoundingBox2D Polygon2D::bounding_box() const {
    float min_x = points[0].x, min_y = points[0].y;
    float max_x = points[0].x, max_y = points[0].y;
    for (const auto &p : points) {
        min_x = std::min(min_x, p.x);
        min_y = std::min(min_y, p.y);
        max_x = std::max(max_x, p.x);
        max_y = std::max(max_y, p.y);
    }
    return {{min_x, min_y}, {max_x, max_y}};
}

Point2D Polygon2D::center() const {
    Point2D center;
    for (const auto &p : points) center += p;
    center /= points.size();
    return center;
}

std::string Polygon2D::to_string() const {
    std::ostringstream ss;
    ss << "Polygon2D(" << points.size() << " vertices)";
    return ss.str();
}

/* -------- *
 * Affine2D *
 * -------- */

Affine2D::Affine2D(std::optional<float> rot,
                   std::optional<std::tuple<float, float>> trans,
                   std::optional<float> scale) {
    if (rot) {
        float c = std::cos(*rot);
        float s = std::sin(*rot);
        r00 = c;
        r01 = -s;
        r10 = s;
        r11 = c;
    } else {
        r00 = 1.0;
        r01 = 0.0;
        r10 = 0.0;
        r11 = 1.0;
    }

    if (trans) {
        auto [x, y] = *trans;
        tx = x;
        ty = y;
    } else {
        tx = 0.0;
        ty = 0.0;
    }

    if (scale) {
        r00 *= *scale;
        r01 *= *scale;
        r10 *= *scale;
        r11 *= *scale;
    }
}

Affine2D::Affine2D(float r00, float r01, float r10, float r11, float tx,
                   float ty)
    : r00(r00), r01(r01), r10(r10), r11(r11), tx(tx), ty(ty) {}

Affine2D Affine2D::operator*=(const Affine2D &a) {
    float r00_ = r00 * a.r00 + r01 * a.r10;
    float r01_ = r00 * a.r01 + r01 * a.r11;
    float r10_ = r10 * a.r00 + r11 * a.r10;
    float r11_ = r10 * a.r01 + r11 * a.r11;
    float tx_ = tx * a.r00 + ty * a.r10 + a.tx;
    float ty_ = tx * a.r01 + ty * a.r11 + a.ty;
    r00 = r00_;
    r01 = r01_;
    r10 = r10_;
    r11 = r11_;
    tx = tx_;
    ty = ty_;
    return *this;
}

Affine2D Affine2D::inverse() const {
    float det = r00 * r11 - r01 * r10;
    float r00_ = r11 / det;
    float r01_ = -r01 / det;
    float r10_ = -r10 / det;
    float r11_ = r00 / det;
    float tx_ = (r10 * ty - r11 * tx) / det;
    float ty_ = (r01 * tx - r00 * ty) / det;
    return {r00_, r01_, r10_, r11_, tx_, ty_};
}

std::string Affine2D::to_string() const {
    std::ostringstream ss;
    ss << "Affine2D([[" << r00 << ", " << r01 << "], [" << r10 << ", " << r11
       << "]], [" << tx << ", " << ty << "])";
    return ss.str();
}

Affine2D operator*(const Affine2D &a1, const Affine2D &a2) {
    Affine2D a = a1;
    a *= a2;
    return a;
}

Point2D operator>>(const Affine2D &a, const Point2D &p) {
    return {a.r00 * p.x + a.r01 * p.y + a.tx, a.r10 * p.x + a.r11 * p.y + a.ty};
}

Point2D operator<<(const Point2D &p, const Affine2D &a) {
    return {a.r00 * p.x + a.r01 * p.y + a.tx, a.r10 * p.x + a.r11 * p.y + a.ty};
}

Line2D operator>>(const Affine2D &a, const Line2D &l) {
    return {a >> l.p1, a >> l.p2};
}

Line2D operator<<(const Line2D &l, const Affine2D &a) { return a >> l; }

Triangle2D operator>>(const Affine2D &a, const Triangle2D &t) {
    return {a >> t.p1, a >> t.p2, a >> t.p3};
}

Triangle2D operator<<(const Triangle2D &t, const Affine2D &a) { return a >> t; }

BoundingBox2D operator>>(const Affine2D &a, const BoundingBox2D &bb) {
    return {a >> bb.min, a >> bb.max};
}

BoundingBox2D operator<<(const BoundingBox2D &bb, const Affine2D &a) {
    return a >> bb;
}

Polygon2D operator>>(const Affine2D &a, const Polygon2D &p) {
    std::vector<Point2D> points;
    for (const auto &p1 : p.points) points.push_back(a >> p1);
    return {points};
}

Polygon2D operator<<(const Polygon2D &p, const Affine2D &a) { return a >> p; }

/* ------- *
 * Point3D *
 * ------- */

Point3D Point3D::operator+=(const Point3D &p) {
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}

Point3D Point3D::operator-=(const Point3D &p) {
    x -= p.x;
    y -= p.y;
    z -= p.z;
    return *this;
}

Point3D Point3D::operator*=(const Point3D &p) {
    x *= p.x;
    y *= p.y;
    z *= p.z;
    return *this;
}

Point3D Point3D::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

Point3D Point3D::operator/=(const Point3D &p) {
    x /= p.x;
    y /= p.y;
    z /= p.z;
    return *this;
}

Point3D Point3D::operator/=(float s) {
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

bool Point3D::operator==(const Point3D &p) const {
    return std::abs(x - p.x) < TOLERANCE && std::abs(y - p.y) < TOLERANCE &&
           std::abs(z - p.z) < TOLERANCE;
}

bool Point3D::operator!=(const Point3D &p) const { return !(*this == p); }

bool Point3D::operator<(const Point3D &p) const {
    return x < p.x || (x == p.x && (y < p.y || (y == p.y && z < p.z)));
}

Point3D Point3D::operator<<=(const Affine3D &a) {
    float x1 = a.r00 * x + a.r01 * y + a.r02 * z + a.tx;
    float y1 = a.r10 * x + a.r11 * y + a.r12 * z + a.ty;
    float z1 = a.r20 * x + a.r21 * y + a.r22 * z + a.tz;
    x = x1;
    y = y1;
    z = z1;
    return *this;
}

Point3D Point3D::normalize() const {
    float inv_length = 1.0f / length();
    return {x * inv_length, y * inv_length, z * inv_length};
}

float Point3D::determinant(const Point3D &a, const Point3D &b) const {
    return x * a.y * b.z + y * a.z * b.x + z * a.x * b.y - z * a.y * b.x -
           y * a.x * b.z - x * a.z * b.y;
}

float Point3D::length() const { return std::sqrt(x * x + y * y + z * z); }

float Point3D::dot(const Point3D &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Point3D Point3D::cross(const Point3D &other) const {
    return {y * other.z - z * other.y, z * other.x - x * other.z,
            x * other.y - y * other.x};
}

BarycentricCoordinates Point3D::barycentric_coordinates(
    const Triangle3D &t) const {
    Point3D v0 = t.p2 - t.p1;
    Point3D v1 = t.p3 - t.p1;
    Point3D v2 = *this - t.p1;
    float d00 = v0.dot(v0);
    float d01 = v0.dot(v1);
    float d11 = v1.dot(v1);
    float d20 = v2.dot(v0);
    float d21 = v2.dot(v1);
    float denom = d00 * d11 - d01 * d01;
    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;
    return {u, v, w};
}

bool Point3D::is_inside_bounding_box(const BoundingBox3D &bb) const {
    return x >= bb.min.x && x <= bb.max.x && y >= bb.min.y && y <= bb.max.y &&
           z >= bb.min.z && z <= bb.max.z;
}

float Point3D::distance_to_point(const Point3D &other) const {
    return std::sqrt((x - other.x) * (x - other.x) +
                     (y - other.y) * (y - other.y) +
                     (z - other.z) * (z - other.z));
}

float Point3D::distance_to_line(const Line3D &l) const {
    return l.distance_to_point(*this);
}

float Point3D::distance_to_triangle(const Triangle3D &t) const {
    return t.distance_to_point(*this);
}

bool Point3D::is_coplanar(const Triangle3D &t) const {
    return std::abs((*this - t.p1).dot((t.p2 - t.p1).cross(t.p3 - t.p1))) <
           TOLERANCE;
}

std::optional<Point3D> Point3D::project_to_line(const Line3D &l) const {
    float dx = l.p2.x - l.p1.x, dy = l.p2.y - l.p1.y, dz = l.p2.z - l.p1.z;
    float t = ((x - l.p1.x) * dx + (y - l.p1.y) * dy + (z - l.p1.z) * dz) /
              (dx * dx + dy * dy + dz * dz);
    if (t < 0 || t > 1) return std::nullopt;
    return Point3D{l.p1.x + t * dx, l.p1.y + t * dy, l.p1.z + t * dz};
}

std::optional<Point3D> Point3D::project_to_triangle(const Triangle3D &t) const {
    BarycentricCoordinates bc = barycentric_coordinates(t);
    if (bc.u < 0 || bc.v < 0 || bc.w < 0) return std::nullopt;
    return bc.get_point_3d(t);
}

bool Point3D::projects_to_triangle(const Triangle3D &t) const {
    return project_to_triangle(t).has_value();
}

std::string Point3D::to_string() const {
    std::ostringstream ss;
    ss << "Point3D(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

Point3D operator+(const Point3D &p1, const Point3D &p2) {
    return {p1.x + p2.x, p1.y + p2.y, p1.z + p2.z};
}

Point3D operator-(const Point3D &p1, const Point3D &p2) {
    return {p1.x - p2.x, p1.y - p2.y, p1.z - p2.z};
}

Point3D operator*(const Point3D &p1, const Point3D &p2) {
    return {p1.x * p2.x, p1.y * p2.y, p1.z * p2.z};
}

Point3D operator*(float s, const Point3D &p) {
    return {s * p.x, s * p.y, s * p.z};
}

Point3D operator*(const Point3D &p, float s) {
    return {s * p.x, s * p.y, s * p.z};
}

Point3D operator/(const Point3D &p1, const Point3D &p2) {
    return {p1.x / p2.x, p1.y / p2.y, p1.z / p2.z};
}

Point3D operator/(const Point3D &p, float s) {
    return {p.x / s, p.y / s, p.z / s};
}

float signed_volume(const Point3D &a, const Point3D &b, const Point3D &c,
                    const Point3D &d) {
    return (1.0 / 6.0) * (b - a).cross(c - a).dot(d - a);
}

/* ------ *
 * Line3D *
 * ------ */

bool Line3D::operator==(const Line3D &other) const {
    return p1 == other.p1 && p2 == other.p2;
}

bool Line3D::operator!=(const Line3D &other) const { return !(*this == other); }

Line3D Line3D::operator<<=(const Affine3D &a) {
    p1 <<= a;
    p2 <<= a;
    return *this;
}

std::optional<std::tuple<Point3D, Point3D>> Line3D::closest_points(
    const Line3D &l) const {
    Point3D d1 = p2 - p1, d2 = l.p2 - l.p1;
    Point3D n = d1.cross(d2);
    Point3D n1 = d1.cross(n), n2 = d2.cross(n);
    float d2n1 = d2.dot(n1), d1n2 = d1.dot(n2);
    if (std::abs(d2n1) < TOLERANCE && std::abs(d1n2) < TOLERANCE) {
        return std::nullopt;
    }
    Point3D c1 = p1 + d1 * (n2.dot(l.p1 - p1) / d1n2),
            c2 = l.p1 + d2 * (n1.dot(p1 - l.p1) / d2n1);
    return std::make_tuple(c1, c2);
}

std::optional<Point3D> Line3D::line_intersection(const Line3D &l) const {
    auto p = closest_points(l);
    if (!p) {
        return std::nullopt;
    }
    auto a = std::get<0>(*p), b = std::get<1>(*p);
    if (a.distance_to_point(b) > TOLERANCE) {
        return std::nullopt;
    }
    return a;
}

bool Line3D::intersects_triangle(const Triangle3D &t) const {
    bool s1 = signed_volume(p1, t.p1, t.p2, t.p3) > 0,
         s2 = signed_volume(p2, t.p1, t.p2, t.p3) > 0,
         s3 = signed_volume(p1, p2, t.p1, t.p2) > 0,
         s4 = signed_volume(p1, p2, t.p2, t.p3) > 0,
         s5 = signed_volume(p1, p2, t.p3, t.p1) > 0;

    return (s1 != s2) && (s3 == s4 && s4 == s5);
}

std::optional<Point3D> Line3D::triangle_intersection(
    const Triangle3D &t) const {
    Point3D e1 = t.p2 - t.p1, e2 = t.p3 - t.p1, d21 = p2 - p1;
    Point3D n = e1.cross(e2);
    float det = -n.dot(d21);

    // Lines are parallel.
    if (std::abs(det) < TOLERANCE) {
        return std::nullopt;
    }

    Point3D ao = p1 - t.p1;
    Point3D dao = ao.cross(d21);

    float u = e2.dot(dao) / det;
    float v = -e1.dot(dao) / det;
    float w = ao.dot(n) / det;

    if (w < 0.0 || u < 0.0 || v < 0.0 || (u + v) > 1.0 || w > 1.0) {
        return std::nullopt;
    }

    return p1 + d21 * w;
}

bool Line3D::intersects_bounding_box(const BoundingBox3D &b) const {
    if (p1.is_inside_bounding_box(b) || p2.is_inside_bounding_box(b)) {
        return true;
    }
    for (auto &t : b.triangles()) {
        if (intersects_triangle(t)) {
            return true;
        }
    }
    return false;
}

float Line3D::distance_to_point(const Point3D &p) const {
    Point3D d = p2 - p1;
    float t = d.dot(p - p1) / d.dot(d);
    if (t < 0.0f) {
        return p.distance_to_point(p1);
    } else if (t > 1.0f) {
        return p.distance_to_point(p2);
    }
    return p.distance_to_point(p1 + t * d);
}

float Line3D::distance_to_line(const Line3D &l) const {
    auto p = closest_points(l);
    if (p) {
        auto a = std::get<0>(*p), b = std::get<1>(*p);
        return a.distance_to_point(b);
    }
    return std::min({p1.distance_to_point(l.p1), p1.distance_to_point(l.p2),
                     p2.distance_to_point(l.p1), p2.distance_to_point(l.p2)});
}

std::string Line3D::to_string() const {
    std::ostringstream ss;
    ss << "Line3D(" << p1.to_string() << ", " << p2.to_string() << ")";
    return ss.str();
}

/* -------------- *
 * Circumcircle3D *
 * -------------- */

bool Circumcircle3D::operator==(const Circumcircle3D &c) const {
    return center == c.center && std::abs(radius - c.radius) < TOLERANCE;
}

bool Circumcircle3D::operator!=(const Circumcircle3D &c) const {
    return !(*this == c);
}

bool Circumcircle3D::contains_point(const Point3D &p) const {
    return center.distance_to_point(p) < radius + TOLERANCE;
}

std::string Circumcircle3D::to_string() const {
    std::ostringstream ss;
    ss << "Circumcircle3D(" << center.to_string() << ", " << radius << ")";
    return ss.str();
}

/* ---------- *
 * Triangle3D *
 * ---------- */

bool Triangle3D::operator==(const Triangle3D &t) const {
    return (p1 == t.p1 && p2 == t.p2 && p3 == t.p3) ||
           (p1 == t.p2 && p2 == t.p3 && p3 == t.p1) ||
           (p1 == t.p3 && p2 == t.p1 && p3 == t.p2);
}

bool Triangle3D::operator!=(const Triangle3D &t) const { return !(*this == t); }

Triangle3D Triangle3D::operator<<=(const Affine3D &a) {
    p1 <<= a;
    p2 <<= a;
    p3 <<= a;
    return *this;
}

float Triangle3D::area() const {
    Point3D v1 = p2 - p1;
    Point3D v2 = p3 - p1;
    return 0.5f * v1.cross(v2).length();
}

Point3D Triangle3D::center() const { return (p1 + p2 + p3) / 3.0f; }

Point3D Triangle3D::normal() const {
    Point3D v1 = p2 - p1;
    Point3D v2 = p3 - p1;
    return v1.cross(v2).normalize();
}

std::vector<Point3D> Triangle3D::vertices() const { return {p1, p2, p3}; }

std::vector<Line3D> Triangle3D::edges() const {
    return {{p1, p2}, {p2, p3}, {p3, p1}};
}

float Triangle3D::distance_to_point(const Point3D &p) const {
    std::optional<Point3D> tp = p.project_to_triangle(*this);
    if (tp) {
        return p.distance_to_point(*tp);
    }
    return std::min({p.distance_to_line({p1, p2}), p.distance_to_line({p2, p3}),
                     p.distance_to_line({p3, p1})});
}

Circumcircle3D Triangle3D::circumcircle() const {
    Point3D v1 = p2 - p1;
    Point3D v2 = p3 - p1;
    Point3D v3 = p3 - p2;
    float a = v1.length();
    float b = v2.length();
    float c = v3.length();
    float s = 0.5f * (a + b + c);
    float area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    float r = a * b * c / (4.0f * area);
    Point3D center = (p1 * a + p2 * b + p3 * c) / (a + b + c);
    return {center, r};
}

bool Triangle3D::contains(const Point3D &p) const {
    std::optional<Point3D> tp = p.project_to_triangle(*this);
    if (!tp) return false;
    return p.distance_to_point(*tp) < TOLERANCE;
}

bool Triangle3D::is_coplanar(const Triangle3D &t) const {
    Point3D n = normal();
    return std::abs(n.dot(t.p1 - p1)) < TOLERANCE &&
           std::abs(n.dot(t.p2 - p1)) < TOLERANCE &&
           std::abs(n.dot(t.p3 - p1)) < TOLERANCE;
}

std::string Triangle3D::to_string() const {
    std::ostringstream ss;
    ss << "Triangle3D(" << p1.to_string() << ", " << p2.to_string() << ", "
       << p3.to_string() << ")";
    return ss.str();
}

/* ------------- *
 * BoundingBox3D *
 * ------------- */

BoundingBox3D::BoundingBox3D() {
    min = {std::numeric_limits<float>::max(), std::numeric_limits<float>::max(),
           std::numeric_limits<float>::max()};
    max = {std::numeric_limits<float>::lowest(),
           std::numeric_limits<float>::lowest(),
           std::numeric_limits<float>::lowest()};
}

BoundingBox3D::BoundingBox3D(const Point3D &min, const Point3D &max)
    : min(min), max(max) {}

BoundingBox3D::BoundingBox3D(const std::vector<Point3D> &points) {
    if (points.empty()) throw std::runtime_error("Empty point list");

    float min_x = points[0].x, min_y = points[0].y, min_z = points[0].z;
    float max_x = points[0].x, max_y = points[0].y, max_z = points[0].z;

    for (size_t i = 1; i < points.size(); ++i) {
        min_x = std::min(min_x, points[i].x);
        min_y = std::min(min_y, points[i].y);
        min_z = std::min(min_z, points[i].z);
        max_x = std::max(max_x, points[i].x);
        max_y = std::max(max_y, points[i].y);
        max_z = std::max(max_z, points[i].z);
    }

    min = {min_x, min_y, min_z};
    max = {max_x, max_y, max_z};
}

BoundingBox3D::BoundingBox3D(const std::vector<Line3D> &lines) {
    if (lines.empty()) throw std::runtime_error("Empty line list");

    float min_x = lines[0].p1.x, min_y = lines[0].p1.y, min_z = lines[0].p1.z;
    float max_x = lines[0].p1.x, max_y = lines[0].p1.y, max_z = lines[0].p1.z;

    for (size_t i = 0; i < lines.size(); ++i) {
        min_x = std::min(min_x, lines[i].p1.x);
        min_y = std::min(min_y, lines[i].p1.y);
        min_z = std::min(min_z, lines[i].p1.z);
        max_x = std::max(max_x, lines[i].p1.x);
        max_y = std::max(max_y, lines[i].p1.y);
        max_z = std::max(max_z, lines[i].p1.z);
        min_x = std::min(min_x, lines[i].p2.x);
        min_y = std::min(min_y, lines[i].p2.y);
        min_z = std::min(min_z, lines[i].p2.z);
        max_x = std::max(max_x, lines[i].p2.x);
        max_y = std::max(max_y, lines[i].p2.y);
        max_z = std::max(max_z, lines[i].p2.z);
    }

    min = {min_x, min_y, min_z};
    max = {max_x, max_y, max_z};
}

BoundingBox3D::BoundingBox3D(const std::vector<Triangle3D> &triangles) {
    if (triangles.empty()) throw std::runtime_error("Empty triangle list");

    float min_x = triangles[0].p1.x, min_y = triangles[0].p1.y,
          min_z = triangles[0].p1.z;
    float max_x = triangles[0].p1.x, max_y = triangles[0].p1.y,
          max_z = triangles[0].p1.z;

    for (size_t i = 0; i < triangles.size(); ++i) {
        min_x = std::min(min_x, triangles[i].p1.x);
        min_y = std::min(min_y, triangles[i].p1.y);
        min_z = std::min(min_z, triangles[i].p1.z);
        max_x = std::max(max_x, triangles[i].p1.x);
        max_y = std::max(max_y, triangles[i].p1.y);
        max_z = std::max(max_z, triangles[i].p1.z);
        min_x = std::min(min_x, triangles[i].p2.x);
        min_y = std::min(min_y, triangles[i].p2.y);
        min_z = std::min(min_z, triangles[i].p2.z);
        max_x = std::max(max_x, triangles[i].p2.x);
        max_y = std::max(max_y, triangles[i].p2.y);
        max_z = std::max(max_z, triangles[i].p2.z);
        min_x = std::min(min_x, triangles[i].p3.x);
        min_y = std::min(min_y, triangles[i].p3.y);
        min_z = std::min(min_z, triangles[i].p3.z);
        max_x = std::max(max_x, triangles[i].p3.x);
        max_y = std::max(max_y, triangles[i].p3.y);
        max_z = std::max(max_z, triangles[i].p3.z);
    }

    min = {min_x, min_y, min_z};
    max = {max_x, max_y, max_z};
}

BoundingBox3D::BoundingBox3D(const std::vector<BoundingBox3D> &bboxes) {
    if (bboxes.empty()) throw std::runtime_error("Empty bounding box list");

    float min_x = bboxes[0].min.x, min_y = bboxes[0].min.y,
          min_z = bboxes[0].min.z;
    float max_x = bboxes[0].max.x, max_y = bboxes[0].max.y,
          max_z = bboxes[0].max.z;

    for (size_t i = 0; i < bboxes.size(); ++i) {
        min_x = std::min(min_x, bboxes[i].min.x);
        min_y = std::min(min_y, bboxes[i].min.y);
        min_z = std::min(min_z, bboxes[i].min.z);
        max_x = std::max(max_x, bboxes[i].max.x);
        max_y = std::max(max_y, bboxes[i].max.y);
        max_z = std::max(max_z, bboxes[i].max.z);
    }

    min = {min_x, min_y, min_z};
    max = {max_x, max_y, max_z};
}

bool BoundingBox3D::operator==(const BoundingBox3D &b) const {
    return min == b.min && max == b.max;
}

bool BoundingBox3D::operator!=(const BoundingBox3D &b) const {
    return min != b.min || max != b.max;
}

BoundingBox3D BoundingBox3D::operator<<=(const Affine3D &a) {
    min <<= a;
    max <<= a;
    return *this;
}

std::vector<std::tuple<int, int, int>> BoundingBox3D::triangle_indices() const {
    return {{0, 2, 1}, {0, 3, 2}, {0, 5, 4}, {0, 1, 5}, {1, 6, 5}, {1, 2, 6},
            {2, 7, 6}, {2, 3, 7}, {3, 4, 7}, {3, 0, 4}, {4, 6, 7}, {4, 5, 6}};
}

std::vector<Point3D> BoundingBox3D::corners() const {
    return {{min.x, min.x, min.x}, {max.x, min.y, min.z}, {max.x, max.y, min.z},
            {min.x, max.y, min.z}, {min.x, min.y, max.z}, {max.x, min.y, max.z},
            {max.x, max.y, max.z}, {min.x, max.y, max.z}};
}

std::vector<Triangle3D> BoundingBox3D::triangles() const {
    std::vector<Triangle3D> triangles;
    auto indices = this->triangle_indices();
    auto corners = this->corners();
    for (auto &index : indices) {
        triangles.push_back({corners[std::get<0>(index)],
                             corners[std::get<1>(index)],
                             corners[std::get<2>(index)]});
    }
    return triangles;
}

Point3D BoundingBox3D::center() const { return (min + max) / 2.0f; }

float BoundingBox3D::volume() const {
    return (max.x - min.x) * (max.y - min.y) * (max.z - min.z);
}

std::string BoundingBox3D::to_string() const {
    std::ostringstream ss;
    ss << "BoundingBox3D(" << min.to_string() << ", " << max.to_string() << ")";
    return ss.str();
}

/* --------- *
 * Polygon3D *
 * --------- */

Polygon3D::Polygon3D(const std::vector<Point3D> &points) : points(points) {}

bool Polygon3D::operator==(const Polygon3D &p) const {
    return points == p.points;
}

bool Polygon3D::operator!=(const Polygon3D &p) const { return !(*this == p); }

Polygon3D Polygon3D::operator<<=(const Affine3D &a) {
    for (auto &p : points) p <<= a;
    return *this;
}

float Polygon3D::area() const {
    if (points.size() < 3) return 0.0f;
    float area = 0.0f;
    Point3D p1 = points[0];
    for (size_t i = 1; i < points.size(); ++i) {
        size_t j = (i + 1) % points.size();
        Point3D v1 = points[i] - p1;
        Point3D v2 = points[j] - p1;
        area += v1.cross(v2).length();
    }
    return std::abs(area) / 2.0f;
}

Point3D Polygon3D::center() const {
    if (points.empty()) throw std::runtime_error("Empty polygon");
    Point3D center;
    for (auto &p : points) center += p;
    return center / points.size();
}

Point3D Polygon3D::normal() const {
    if (points.size() < 3) throw std::runtime_error("Not enough points");
    Point3D v1 = points[1] - points[0];
    Point3D v2 = points[2] - points[0];
    return v1.cross(v2).normalize();
}

BoundingBox3D Polygon3D::bounding_box() const {
    if (points.empty()) throw std::runtime_error("Empty polygon");

    float min_x = points[0].x, min_y = points[0].y, min_z = points[0].z;
    float max_x = points[0].x, max_y = points[0].y, max_z = points[0].z;

    for (size_t i = 0; i < points.size(); ++i) {
        min_x = std::min(min_x, points[i].x);
        min_y = std::min(min_y, points[i].y);
        min_z = std::min(min_z, points[i].z);
        max_x = std::max(max_x, points[i].x);
        max_y = std::max(max_y, points[i].y);
        max_z = std::max(max_z, points[i].z);
    }

    return BoundingBox3D({min_x, min_y, min_z}, {max_x, max_y, max_z});
}

std::string Polygon3D::to_string() const {
    std::ostringstream ss;
    ss << "Polygon3D(" << points.size() << " vertices)";
    return ss.str();
}

/* -------- *
 * Affine3D *
 * -------- */

Affine3D::Affine3D(float r00, float r01, float r02, float r10, float r11,
                   float r12, float r20, float r21, float r22, float tx,
                   float ty, float tz)
    : r00(r00),
      r01(r01),
      r02(r02),
      r10(r10),
      r11(r11),
      r12(r12),
      r20(r20),
      r21(r21),
      r22(r22),
      tx(tx),
      ty(ty),
      tz(tz) {}

Affine3D::Affine3D(std::optional<std::tuple<float, float, float>> rot,
                   std::optional<std::tuple<float, float, float>> trans,
                   std::optional<float> scale) {
    if (rot) {
        float x = std::get<0>(*rot);
        float y = std::get<1>(*rot);
        float z = std::get<2>(*rot);
        float cx = std::cos(x);
        float sx = std::sin(x);
        float cy = std::cos(y);
        float sy = std::sin(y);
        float cz = std::cos(z);
        float sz = std::sin(z);
        r00 = cy * cz;
        r01 = -cy * sz;
        r02 = sy;
        r10 = sx * sy * cz + cx * sz;
        r11 = -sx * sy * sz + cx * cz;
        r12 = -sx * cy;
        r20 = -cx * sy * cz + sx * sz;
        r21 = cx * sy * sz + sx * cz;
        r22 = cx * cy;
    } else {
        r00 = 1.0;
        r01 = 0.0;
        r02 = 0.0;
        r10 = 0.0;
        r11 = 1.0;
        r12 = 0.0;
        r20 = 0.0;
        r21 = 0.0;
        r22 = 1.0;
    }

    if (trans) {
        tx = std::get<0>(*trans);
        ty = std::get<1>(*trans);
        tz = std::get<2>(*trans);
    } else {
        tx = 0.0;
        ty = 0.0;
        tz = 0.0;
    }

    if (scale) {
        r00 *= *scale;
        r01 *= *scale;
        r02 *= *scale;
        r10 *= *scale;
        r11 *= *scale;
        r12 *= *scale;
        r20 *= *scale;
        r21 *= *scale;
        r22 *= *scale;
    }
}

Affine3D Affine3D::operator*=(const Affine3D &a) {
    float r00_ = r00 * a.r00 + r01 * a.r10 + r02 * a.r20;
    float r01_ = r00 * a.r01 + r01 * a.r11 + r02 * a.r21;
    float r02_ = r00 * a.r02 + r01 * a.r12 + r02 * a.r22;
    float r10_ = r10 * a.r00 + r11 * a.r10 + r12 * a.r20;
    float r11_ = r10 * a.r01 + r11 * a.r11 + r12 * a.r21;
    float r12_ = r10 * a.r02 + r11 * a.r12 + r12 * a.r22;
    float r20_ = r20 * a.r00 + r21 * a.r10 + r22 * a.r20;
    float r21_ = r20 * a.r01 + r21 * a.r11 + r22 * a.r21;
    float r22_ = r20 * a.r02 + r21 * a.r12 + r22 * a.r22;
    float tx_ = tx * a.r00 + ty * a.r10 + tz * a.r20 + a.tx;
    float ty_ = tx * a.r01 + ty * a.r11 + tz * a.r21 + a.ty;
    float tz_ = tx * a.r02 + ty * a.r12 + tz * a.r22 + a.tz;
    r00 = r00_;
    r01 = r01_;
    r02 = r02_;
    r10 = r10_;
    r11 = r11_;
    r12 = r12_;
    r20 = r20_;
    r21 = r21_;
    r22 = r22_;
    tx = tx_;
    ty = ty_;
    tz = tz_;
    return *this;
}

Affine3D Affine3D::inverse() const {
    float det = r00 * (r11 * r22 - r12 * r21) - r01 * (r10 * r22 - r12 * r20) +
                r02 * (r10 * r21 - r11 * r20);
    float r00_ = (r11 * r22 - r12 * r21) / det;
    float r01_ = (r02 * r21 - r01 * r22) / det;
    float r02_ = (r01 * r12 - r02 * r11) / det;
    float r10_ = (r12 * r20 - r10 * r22) / det;
    float r11_ = (r00 * r22 - r02 * r20) / det;
    float r12_ = (r02 * r10 - r00 * r12) / det;
    float r20_ = (r10 * r21 - r11 * r20) / det;
    float r21_ = (r01 * r20 - r00 * r21) / det;
    float r22_ = (r00 * r11 - r01 * r10) / det;
    float tx_ = -(r00 * tx + r01 * ty + r02 * tz);
    float ty_ = -(r10 * tx + r11 * ty + r12 * tz);
    float tz_ = -(r20 * tx + r21 * ty + r22 * tz);
    return {r00_, r01_, r02_, r10_, r11_, r12_,
            r20_, r21_, r22_, tx_,  ty_,  tz_};
}

std::string Affine3D::to_string() const {
    std::stringstream ss;
    ss << "Affine3D([[" << r00 << ", " << r01 << ", " << r02 << "], [" << r10
       << ", " << r11 << ", " << r12 << "], [" << r20 << ", " << r21 << ", "
       << r22 << "]], [" << tx << ", " << ty << ", " << tz << "])";
    return ss.str();
}

Affine3D operator*(const Affine3D &a1, const Affine3D &a2) {
    Affine3D a = a1;
    a *= a2;
    return a;
}

Point3D operator>>(const Affine3D &a, const Point3D &p) {
    float x = a.r00 * p.x + a.r01 * p.y + a.r02 * p.z + a.tx;
    float y = a.r10 * p.x + a.r11 * p.y + a.r12 * p.z + a.ty;
    float z = a.r20 * p.x + a.r21 * p.y + a.r22 * p.z + a.tz;
    return {x, y, z};
}

Point3D operator<<(const Point3D &p, const Affine3D &a) { return a >> p; }

Line3D operator>>(const Affine3D &a, const Line3D &l) {
    Point3D p1 = a >> l.p1;
    Point3D p2 = a >> l.p2;
    return {p1, p2};
}

Line3D operator<<(const Line3D &l, const Affine3D &a) { return a >> l; }

Triangle3D operator>>(const Affine3D &a, const Triangle3D &p) {
    return {a >> p.p1, a >> p.p2, a >> p.p3};
}

Triangle3D operator<<(const Triangle3D &p, const Affine3D &a) { return a >> p; }

BoundingBox3D operator>>(const Affine3D &a, const BoundingBox3D &b) {
    return {a >> b.min, a >> b.max};
}

BoundingBox3D operator<<(const BoundingBox3D &b, const Affine3D &a) {
    return a >> b;
}

Polygon3D operator>>(const Affine3D &a, const Polygon3D &p) {
    std::vector<Point3D> points;
    for (const auto &v : p.points) {
        points.push_back(a >> v);
    }
    return {points};
}

Polygon3D operator<<(const Polygon3D &p, const Affine3D &a) { return a >> p; }

/* ----- *
 * Angle *
 * ----- */

Angle::Angle(float value) : value(value) {}

Angle::Angle(const Point2D &p1, const Point2D &p2, const Point2D &p3) {
    Point2D v1 = p1 - p2;
    Point2D v2 = p3 - p2;
    value = std::atan2(v1.cross(v2), v1.dot(v2));
}

Angle::Angle(const Point3D &p1, const Point3D &p2, const Point3D &p3) {
    Point3D v1 = p1 - p2;
    Point3D v2 = p3 - p2;
    value = std::atan2(v1.cross(v2).length(), v1.dot(v2));
}

Angle Angle::operator+=(const Angle &a) {
    value += a.value;
    return *this;
}

Angle Angle::operator-=(const Angle &a) {
    value -= a.value;
    return *this;
}

Angle Angle::operator*=(const Angle &a) {
    value *= a.value;
    return *this;
}

Angle Angle::operator*=(float s) {
    value *= s;
    return *this;
}

Angle Angle::operator/=(const Angle &a) {
    value /= a.value;
    return *this;
}

Angle Angle::operator/=(float s) {
    value /= s;
    return *this;
}

float Angle::cos() const { return std::cos(value); }

float Angle::sin() const { return std::sin(value); }

float Angle::tan() const { return std::tan(value); }

float Angle::acos() const { return std::acos(value); }

float Angle::asin() const { return std::asin(value); }

float Angle::atan() const { return std::atan(value); }

float Angle::to_degrees() const { return value * 180.0f / M_PI; }

std::string Angle::to_string() const {
    std::ostringstream ss;
    ss << "Angle(" << value << ")";
    return ss.str();
}

Angle operator+(const Angle &a1, const Angle &a2) {
    return {a1.value + a2.value};
}

Angle operator-(const Angle &a1, const Angle &a2) {
    return {a1.value - a2.value};
}

Angle operator*(const Angle &a1, const Angle &a2) {
    return {a1.value * a2.value};
}

Angle operator*(float s, const Angle &a) { return {s * a.value}; }

Angle operator*(const Angle &a, float s) { return {s * a.value}; }

Angle operator/(float s, const Angle &a) { return {s / a.value}; }

Angle operator/(const Angle &a, float s) { return {a.value / s}; }

/* ---------------------- *
 * BarycentricCoordinates *
 * ---------------------- */

BarycentricCoordinates::BarycentricCoordinates(float u, float v, float w)
    : u(u), v(v), w(w) {}

bool BarycentricCoordinates::operator==(const BarycentricCoordinates &b) const {
    return std::abs(u - b.u) < TOLERANCE && std::abs(v - b.v) < TOLERANCE &&
           std::abs(w - b.w) < TOLERANCE;
}

bool BarycentricCoordinates::operator!=(const BarycentricCoordinates &b) const {
    return !(*this == b);
}

Point2D BarycentricCoordinates::get_point_2d(const Triangle2D &t) const {
    return u * t.p1 + v * t.p2 + w * t.p3;
}

Point3D BarycentricCoordinates::get_point_3d(const Triangle3D &t) const {
    return u * t.p1 + v * t.p2 + w * t.p3;
}

std::string BarycentricCoordinates::to_string() const {
    std::ostringstream ss;
    ss << "BarycentricCoordinates(" << u << ", " << v << ", " << w << ")";
    return ss.str();
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("types");
    s.doc() = "Types";

    // Defines the classes first, so that methods can resolve types correctly.
    auto point2d = py::class_<Point2D>(s, "Point2D");
    auto line2d = py::class_<Line2D>(s, "Line2D");
    auto triangle2d = py::class_<Triangle2D>(s, "Triangle2D");
    auto bbox2d = py::class_<BoundingBox2D>(s, "BoundingBox2D");
    auto polygon2d = py::class_<Polygon2D>(s, "Polygon2D");
    auto affine2d = py::class_<Affine2D>(s, "Affine2D");
    auto point3d = py::class_<Point3D>(s, "Point3D");
    auto line3d = py::class_<Line3D>(s, "Line3D");
    auto circumcircle3d = py::class_<Circumcircle3D>(s, "Circumcircle3D");
    auto triangle3d = py::class_<Triangle3D>(s, "Triangle3D");
    auto bbox3d = py::class_<BoundingBox3D>(s, "BoundingBox3D");
    auto polygon3d = py::class_<Polygon3D>(s, "Polygon3D");
    auto affine3d = py::class_<Affine3D>(s, "Affine3D");
    auto angle = py::class_<Angle>(s, "Angle");
    auto barycentric_coordinates =
        py::class_<BarycentricCoordinates>(s, "BarycentricCoordinates");

    // Defines Point2D methods.
    point2d.def(py::init<float, float>(), "A point in 2D space", "x"_a, "y"_a)
        .def_readwrite("x", &Point2D::x, "The point's x coordinate")
        .def_readwrite("y", &Point2D::y, "The point's y coordinate")
        .def("__str__", &Point2D::to_string, py::is_operator())
        .def("__repr__", &Point2D::to_string, py::is_operator())
        .def("__add__",
             py::overload_cast<const Point2D &, const Point2D &>(&operator+),
             "Vector addition with another point", "other"_a, py::is_operator())
        .def("__iadd__", &Point2D::operator+=,
             "Vector addition with another point", "other"_a, py::is_operator())
        .def("__sub__",
             py::overload_cast<const Point2D &, const Point2D &>(&operator-),
             "Vector subtraction with another point", "other"_a,
             py::is_operator())
        .def("__isub__", &Point2D::operator-=,
             "Vector subtraction with another point", "other"_a,
             py::is_operator())
        .def("__mul__",
             py::overload_cast<const Point2D &, const Point2D &>(&operator*),
             "Vector dot product with another point", "other"_a,
             py::is_operator())
        .def("__mul__", py::overload_cast<float, const Point2D &>(&operator*),
             "Scalar multiplication with a float", "other"_a, py::is_operator())
        .def("__mul__", py::overload_cast<const Point2D &, float>(&operator*),
             "Scalar multiplication with a float", "other"_a, py::is_operator())
        .def("__imul__",
             py::overload_cast<const Point2D &>(&Point2D::operator*=),
             "Vector dot product with another point", "other"_a,
             py::is_operator())
        .def("__imul__", py::overload_cast<float>(&Point2D::operator*=),
             "Scalar multiplication with a float", "other"_a, py::is_operator())
        .def("__truediv__",
             py::overload_cast<const Point2D &, const Point2D &>(&operator/),
             "Vector division with another point", "other"_a, py::is_operator())
        .def("__truediv__",
             py::overload_cast<const Point2D &, float>(&operator/),
             "Scalar division with a float", "other"_a, py::is_operator())
        .def("__itruediv__",
             py::overload_cast<const Point2D &>(&Point2D::operator/=),
             "Vector division with another point", "other"_a, py::is_operator())
        .def("__itruediv__", py::overload_cast<float>(&Point2D::operator/=),
             "Scalar division with a float", "other"_a, py::is_operator())
        .def("__eq__", &Point2D::operator==, "Equality with another point",
             "other"_a, py::is_operator())
        .def("__ne__", &Point2D::operator!=, "Inequality with another point",
             "other"_a, py::is_operator())
        .def("__lt__", &Point2D::operator<, "Less than another point",
             "other"_a, py::is_operator())
        .def("__lshift__",
             py::overload_cast<const Point2D &, const Affine2D &>(&operator<<),
             "Stream insertion operator for a point", "other"_a,
             py::is_operator())
        .def("__ilshift__", &Point2D::operator<<=,
             "Stream insertion operator for a point", "other"_a,
             py::is_operator())
        .def("normalize", &Point2D::normalize, "Normalize by length")
        .def("rotate", &Point2D::rotate, "Rotate around (0, 0) by some angle",
             "angle"_a)
        .def("determinant", &Point2D::determinant,
             "Determinant of a 2x2 matrix with another point", "other"_a)
        .def("length", &Point2D::length, "Vector length")
        .def("dot", &Point2D::dot, "Dot product with another point", "other"_a)
        .def("cross", &Point2D::cross, "Cross product with another point",
             "other"_a)
        .def("barycentric_coordinates", &Point2D::barycentric_coordinates,
             "Barycentric coordinates of a point in a triangle", "t"_a)
        .def("is_inside_triangle", &Point2D::is_inside_triangle,
             "Is inside a triangle", "t"_a)
        .def("is_inside_bounding_box", &Point2D::is_inside_bounding_box,
             "Is inside a bounding box", "bb"_a)
        .def("distance_to_point", &Point2D::distance_to_point,
             "Distance to another point", "p"_a)
        .def("distance_to_line", &Point2D::distance_to_line,
             "Distance to a line", "l"_a)
        .def("distance_to_triangle", &Point2D::distance_to_triangle,
             "Distance to a triangle", "t"_a)
        .def("distance_to_bounding_box", &Point2D::distance_to_bounding_box,
             "Distance to a bounding box", "bb"_a)
        .def("project_to_line", &Point2D::project_to_line,
             "Project onto a line", "other"_a);

    // Defines Line2D methods.
    line2d
        .def(py::init<const Point2D &, const Point2D &>(), "A line in 2D space",
             "p1"_a, "p2"_a)
        .def_readwrite("p1", &Line2D::p1, "The line's first point")
        .def_readwrite("p2", &Line2D::p2, "The line's second point")
        .def("__str__", &Line2D::to_string, py::is_operator())
        .def("__repr__", &Line2D::to_string, py::is_operator())
        .def("__eq__", &Line2D::operator==, "Equality with another line",
             "other"_a, py::is_operator())
        .def("__ne__", &Line2D::operator!=, "Inequality with another line",
             "other"_a, py::is_operator())
        .def("__lshift__",
             py::overload_cast<const Line2D &, const Affine2D &>(&operator<<),
             "Applies a affine transformation to the line", "other"_a,
             py::is_operator())
        .def("__ilshift__", &Line2D::operator<<=,
             "Applies a affine transformation to the line", "other"_a,
             py::is_operator())
        .def("closest_point", &Line2D::closest_point,
             "The closest point on the line to another point", "p"_a)
        .def("intersection", &Line2D::intersection,
             "The intersection point of two lines (None if they don't "
             "intersect)",
             "l"_a)
        .def("distance_to_point", &Line2D::distance_to_point,
             "Distance to a point", "p"_a)
        .def("distance_to_line", &Line2D::distance_to_line,
             "Distance to another line", "l"_a)
        .def("distance_to_triangle", &Line2D::distance_to_triangle,
             "Distance to a triangle", "t"_a)
        .def("distance_to_bounding_box", &Line2D::distance_to_bounding_box,
             "Distance to a bounding box", "bb"_a);

    // Defines Triangle2D methods.
    triangle2d
        .def(py::init<const Point2D &, const Point2D &, const Point2D &>(),
             "A triangle in 2D space", "p1"_a, "p2"_a, "p3"_a)
        .def_readwrite("p1", &Triangle2D::p1, "The triangle's first point")
        .def_readwrite("p2", &Triangle2D::p2, "The triangle's second point")
        .def_readwrite("p3", &Triangle2D::p3, "The triangle's third point")
        .def("__str__", &Triangle2D::to_string, py::is_operator())
        .def("__repr__", &Triangle2D::to_string, py::is_operator())
        .def("__eq__", &Triangle2D::operator==,
             "Equality with another triangle", "other"_a, py::is_operator())
        .def("__ne__", &Triangle2D::operator!=,
             "Inequality with another triangle", "other"_a, py::is_operator())
        .def("__lshift__",
             py::overload_cast<const Triangle2D &, const Affine2D &>(
                 &operator<<),
             "Applies a affine transformation to the triangle", "other"_a,
             py::is_operator())
        .def("__ilshift__", &Triangle2D::operator<<=,
             "Applies a affine transformation to the triangle", "other"_a,
             py::is_operator())
        .def("area", &Triangle2D::area, "The triangle's area")
        .def("center", &Triangle2D::center, "The triangle's center")
        .def("distance_to_point", &Triangle2D::distance_to_point,
             "Distance to a point", "p"_a)
        .def("distance_to_line", &Triangle2D::distance_to_line,
             "Distance to a line", "l"_a)
        .def("distance_to_triangle", &Triangle2D::distance_to_triangle,
             "Distance to another triangle", "t"_a)
        .def("distance_to_bounding_box", &Triangle2D::distance_to_bounding_box,
             "Distance to a bounding box", "bb"_a);

    // Defines BoundingBox2D methods.
    bbox2d
        .def(py::init<const Point2D &, const Point2D &>(),
             "Creates a bounding box from two points", "min"_a, "max"_a)
        .def(py::init<const std::vector<Point2D> &>(),
             "Creates a bounding box from a list of points", "points"_a)
        .def(py::init<const std::vector<Line2D> &>(),
             "Creates a bounding box from a list of lines", "lines"_a)
        .def(py::init<const std::vector<Triangle2D> &>(),
             "Creates a bounding box from a list of triangles", "triangles"_a)
        .def(py::init<const std::vector<BoundingBox2D> &>(),
             "Creates a bounding box from a list of other bounding boxes",
             "bboxes"_a)
        .def_readwrite("min", &BoundingBox2D::min,
                       "The bounding box's minimum point")
        .def_readwrite("max", &BoundingBox2D::max,
                       "The bounding box's maximum point")
        .def("__str__", &BoundingBox2D::to_string, py::is_operator())
        .def("__repr__", &BoundingBox2D::to_string, py::is_operator())
        .def("__eq__", &BoundingBox2D::operator==,
             "Equality with another bounding box", "other"_a, py::is_operator())
        .def("__ne__", &BoundingBox2D::operator!=,
             "Inequality with another bounding box", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const BoundingBox2D &, const Affine2D &>(
                 &operator<<),
             "Applies a affine transformation to the bounding box", "other"_a,
             py::is_operator())
        .def("__ilshift__", &BoundingBox2D::operator<<=,
             "Applies a affine transformation to the bounding box", "other"_a,
             py::is_operator())
        .def("distance_to_point", &BoundingBox2D::distance_to_point,
             "Distance to a point", "p"_a)
        .def("distance_to_line", &BoundingBox2D::distance_to_line,
             "Distance to a line", "l"_a)
        .def("distance_to_triangle", &BoundingBox2D::distance_to_triangle,
             "Distance to a triangle", "t"_a)
        .def("distance_to_bounding_box",
             &BoundingBox2D::distance_to_bounding_box,
             "Distance to another bounding box", "bb"_a);

    // Defines Polygon2D methods.
    polygon2d
        .def(py::init<const std::vector<Point2D> &>(),
             "Creates a polygon from a list of points", "points"_a)
        .def_readwrite("points", &Polygon2D::points,
                       "The polygon's list of points")
        .def("__str__", &Polygon2D::to_string, py::is_operator())
        .def("__repr__", &Polygon2D::to_string, py::is_operator())
        .def("__eq__", &Polygon2D::operator==, "Equality with another polygon",
             "other"_a, py::is_operator())
        .def("__ne__", &Polygon2D::operator!=,
             "Inequality with another polygon", "other"_a, py::is_operator())
        .def(
            "__lshift__",
            py::overload_cast<const Polygon2D &, const Affine2D &>(&operator<<),
            "Applies a affine transformation to the polygon", "other"_a,
            py::is_operator())
        .def("__ilshift__", &Polygon2D::operator<<=,
             "Applies a affine transformation to the polygon", "other"_a,
             py::is_operator())
        .def("signed_area", &Polygon2D::signed_area,
             "The polygon's signed area (positive if counterclockwise)")
        .def("is_clockwise", &Polygon2D::is_clockwise,
             "Returns true if the polygon is clockwise")
        .def("reverse", &Polygon2D::reverse, "Reverses the polygon's points")
        .def("convex_hull", &Polygon2D::convex_hull,
             "Returns the polygon's convex hull")
        .def("bounding_box", &Polygon2D::bounding_box,
             "Returns the polygon's bounding box")
        .def("center", &Polygon2D::center, "Returns the polygon's center");

    // Defines Affine2D methods.
    affine2d
        .def(py::init<std::optional<float>,
                      std::optional<std::tuple<float, float>>,
                      std::optional<float>>(),
             "Initialize affine transformation from rotation and translation "
             "vectors",
             "rot"_a = std::nullopt, "trans"_a = std::nullopt,
             "scale"_a = std::nullopt)
        .def("__str__", &Affine2D::to_string, py::is_operator())
        .def("__repr__", &Affine2D::to_string, py::is_operator())
        .def("__matmul__",
             py::overload_cast<const Affine2D &, const Affine2D &>(&operator*),
             "Combine two affine transformations", "other"_a, py::is_operator())
        .def("__imatmul__", &Affine2D::operator*=,
             "Applies an affine transformation to a point", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine2D &, const Point2D &>(&operator>>),
             "Applies an affine transformation to a point", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine2D &, const Line2D &>(&operator>>),
             "Applies an affine transformation to a line", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine2D &, const Triangle2D &>(
                 &operator>>),
             "Applies an affine transformation to a triangle", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine2D &, const BoundingBox2D &>(
                 &operator>>),
             "Applies an affine transformation to a bounding box", "other"_a,
             py::is_operator())
        .def(
            "__rshift__",
            py::overload_cast<const Affine2D &, const Polygon2D &>(&operator>>),
            "Applies an affine transformation to a polygon", "other"_a,
            py::is_operator())
        .def("inverse", &Affine2D::inverse,
             "The inverse of the affine transformation");

    // Defines Point3D methods.
    point3d
        .def(py::init<float, float, float>(), "A point in 3D space", "x"_a,
             "y"_a, "z"_a)
        .def_readwrite("x", &Point3D::x, "The point's x coordinate")
        .def_readwrite("y", &Point3D::y, "The point's y coordinate")
        .def_readwrite("z", &Point3D::z, "The point's z coordinate")
        .def("__str__", &Point3D::to_string, py::is_operator())
        .def("__repr__", &Point3D::to_string, py::is_operator())
        .def("__add__",
             py::overload_cast<const Point3D &, const Point3D &>(&operator+),
             "Adds two points together", "other"_a, py::is_operator())
        .def("__iadd__", &Point3D::operator+=, "Adds a point to this point",
             "other"_a, py::is_operator())
        .def("__sub__",
             py::overload_cast<const Point3D &, const Point3D &>(&operator-),
             "Subtracts two points", "other"_a, py::is_operator())
        .def("__isub__", &Point3D::operator-=,
             "Subtracts a point from this point", "other"_a, py::is_operator())
        .def("__mul__",
             py::overload_cast<const Point3D &, const Point3D &>(&operator*),
             "Vector multiplication", "other"_a, py::is_operator())
        .def("__mul__", py::overload_cast<const Point3D &, float>(&operator*),
             "Multiplies a point by a scalar", "other"_a, py::is_operator())
        .def("__mul__", py::overload_cast<float, const Point3D &>(&operator*),
             "Multiplies a point by a scalar", "other"_a, py::is_operator())
        .def("__imul__",
             py::overload_cast<const Point3D &>(&Point3D::operator*=),
             "Vector multiplication", "other"_a, py::is_operator())
        .def("__imul__", py::overload_cast<float>(&Point3D::operator*=),
             "Multiplies this point by a scalar", "other"_a, py::is_operator())
        .def("__truediv__",
             py::overload_cast<const Point3D &, const Point3D &>(&operator/),
             "Vector division", "other"_a, py::is_operator())
        .def("__truediv__",
             py::overload_cast<const Point3D &, float>(&operator/),
             "Divides a point by a scalar", "other"_a, py::is_operator())
        .def("__itruediv__",
             py::overload_cast<const Point3D &>(&Point3D::operator/=),
             "Vector division", "other"_a, py::is_operator())
        .def("__itruediv__", py::overload_cast<float>(&Point3D::operator/=),
             "Divides this point by a scalar", "other"_a, py::is_operator())
        .def("__eq__", &Point3D::operator==, "Checks if two points are equal",
             "other"_a, py::is_operator())
        .def("__ne__", &Point3D::operator!=,
             "Checks if two points are not equal", "other"_a, py::is_operator())
        .def("__lt__", &Point3D::operator<,
             "Checks if this point is less than another", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const Point3D &, const Affine3D &>(operator<<),
             "Applies a affine transformation to the point", "other"_a,
             py::is_operator())
        .def("__ilshift__", &Point3D::operator<<=,
             "Applies a affine transformation to the point", "other"_a,
             py::is_operator())
        .def("determinant", &Point3D::determinant,
             "The determinant of a 3x3 matrix with two other points", "a"_a,
             "b"_a)
        .def("length", &Point3D::length, "The point's length")
        .def("dot", &Point3D::dot, "The dot product of the point", "other"_a)
        .def("cross", &Point3D::cross, "The cross product of the point",
             "other"_a)
        .def("barycentric_coordinates", &Point3D::barycentric_coordinates,
             "The barycentric coordinates of the point relative to a triangle",
             "t"_a)
        .def("is_inside_bounding_box", &Point3D::is_inside_bounding_box,
             "Checks if the point is inside a bounding box", "bb"_a)
        .def("distance_to_point", &Point3D::distance_to_point,
             "The distance to another point", "other"_a)
        .def("distance_to_line", &Point3D::distance_to_line,
             "The distance to a line", "line"_a)
        .def("distance_to_triangle", &Point3D::distance_to_triangle,
             "The distance to a triangle", "triangle"_a)
        .def("is_coplanar", &Point3D::is_coplanar,
             "Checks if the point is coplanar with a triangle", "t"_a)
        .def("project_to_line", &Point3D::project_to_line,
             "Projects the point onto a line", "l"_a)
        .def("project_to_triangle", &Point3D::project_to_triangle,
             "Projects the point onto a triangle", "t"_a);

    // Defines Line3D methods.
    line3d
        .def(py::init<const Point3D &, const Point3D &>(), "A line in 3D space",
             "p1"_a, "p2"_a)
        .def_readwrite("p1", &Line3D::p1, "The line's first point")
        .def_readwrite("p2", &Line3D::p2, "The line's second point")
        .def("__str__", &Line3D::to_string, py::is_operator())
        .def("__repr__", &Line3D::to_string, py::is_operator())
        .def("__eq__", &Line3D::operator==, "Checks if two lines are equal",
             "other"_a, py::is_operator())
        .def("__ne__", &Line3D::operator!=, "Checks if two lines are not equal",
             "other"_a, py::is_operator())
        .def("__lshift__",
             py::overload_cast<const Line3D &, const Affine3D &>(&operator<<),
             "Applies a affine transformation to the line", "other"_a,
             py::is_operator())
        .def("__ilshift__", &Line3D::operator<<=,
             "Applies a affine transformation to the line", "other"_a,
             py::is_operator())
        .def("distance_to_point", &Line3D::distance_to_point,
             "The distance to another point", "other"_a)
        .def("distance_to_line", &Line3D::distance_to_line,
             "The distance to another line", "other"_a)
        .def("closest_points", &Line3D::closest_points,
             "The closest points between two lines; returns None if the lines "
             "are parallel",
             "other"_a)
        .def("line_intersection", &Line3D::line_intersection,
             "The intersection point between two lines; returns None if the "
             "lines don't intersect",
             "other"_a)
        .def("intersects_triangle", &Line3D::intersects_triangle,
             "Checks if the line intersects a triangle", "t"_a)
        .def("triangle_intersection", &Line3D::triangle_intersection,
             "The intersection point between a line and a triangle; returns "
             "None if the line doesn't intersect the triangle",
             "t"_a)
        .def("intersects_bounding_box", &Line3D::intersects_bounding_box,
             "Checks if the line intersects a bounding box", "bb"_a);

    // Defines Circumcircle3D methods.
    circumcircle3d
        .def(py::init<const Point3D &, float>(),
             "A circumcircle with a given center and radius", "center"_a,
             "radius"_a)
        .def_readwrite("center", &Circumcircle3D::center,
                       "The circumcircle's center")
        .def_readwrite("radius", &Circumcircle3D::radius,
                       "The circumcircle's radius")
        .def("__str__", &Circumcircle3D::to_string, py::is_operator())
        .def("__repr__", &Circumcircle3D::to_string, py::is_operator())
        .def("__eq__", &Circumcircle3D::operator==,
             "Checks if two circumcircles are equal", "other"_a,
             py::is_operator())
        .def("__ne__", &Circumcircle3D::operator!=,
             "Checks if two circumcircles are not equal", "other"_a,
             py::is_operator())
        .def("contains_point", &Circumcircle3D::contains_point,
             "Checks if the circumcircle contains a point", "p"_a);

    // Defines Triangle3D methods.
    triangle3d
        .def(py::init<const Point3D &, const Point3D &, const Point3D &>(),
             "A triangle in 3D space", "p1"_a, "p2"_a, "p3"_a)
        .def_readwrite("p1", &Triangle3D::p1, "The triangle's first point")
        .def_readwrite("p2", &Triangle3D::p2, "The triangle's second point")
        .def_readwrite("p3", &Triangle3D::p3, "The triangle's third point")
        .def("__str__", &Triangle3D::to_string, py::is_operator())
        .def("__repr__", &Triangle3D::to_string, py::is_operator())
        .def("__eq__", &Triangle3D::operator==,
             "Checks if two triangles are equal", "other"_a, py::is_operator())
        .def("__ne__", &Triangle3D::operator!=,
             "Checks if two triangles are not equal", "other"_a,
             py::is_operator())
        .def(
            "__lshift__",
            py::overload_cast<const Triangle3D &, const Affine3D &>(operator<<),
            "Applies a affine transformation to the triangle", "other"_a,
            py::is_operator())
        .def("__ilshift__", &Triangle3D::operator<<=,
             "Applies a affine transformation to the triangle", "other"_a,
             py::is_operator())
        .def("area", &Triangle3D::area, "The triangle's area")
        .def("normal", &Triangle3D::normal, "The triangle's normal")
        .def("center", &Triangle3D::center, "The triangle's center")
        .def("vertices", &Triangle3D::vertices, "The triangle's vertices")
        .def("edges", &Triangle3D::edges, "The triangle's edges")
        .def("distance_to_point", &Triangle3D::distance_to_point,
             "The distance to another point", "other"_a)
        .def("is_coplanar", &Triangle3D::is_coplanar,
             "Checks if the triangle is coplanar with another triangle",
             "other"_a)
        .def("circumcircle", &Triangle3D::circumcircle,
             "The triangle's circumcircle");

    // Defines BoundingBox3D methods.
    bbox3d
        .def(py::init<const Point3D &, const Point3D &>(),
             "Creates a bounding box from two points", "min"_a, "max"_a)
        .def(py::init<const std::vector<Point3D> &>(),
             "Creates a bounding box from a set of points", "points"_a)
        .def(py::init<const std::vector<Line3D> &>(),
             "Creates a bounding box from a set of lines", "lines"_a)
        .def(py::init<const std::vector<Triangle3D> &>(),
             "Creates a bounding box from a set of triangles", "triangles"_a)
        .def(py::init<const std::vector<BoundingBox3D> &>(),
             "Creates a bounding box from a set of bounding boxes", "boxes"_a)
        .def_readwrite("min", &BoundingBox3D::min,
                       "The bounding box's minimum point")
        .def_readwrite("max", &BoundingBox3D::max,
                       "The bounding box's maximum point")
        .def("__str__", &BoundingBox3D::to_string, py::is_operator())
        .def("__repr__", &BoundingBox3D::to_string, py::is_operator())
        .def("__eq__", &BoundingBox3D::operator==,
             "Checks if two bounding boxes are equal", "other"_a,
             py::is_operator())
        .def("__ne__", &BoundingBox3D::operator!=,
             "Checks if two bounding boxes are not equal", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const BoundingBox3D &, const Affine3D &>(
                 &operator<<),
             "Applies a affine transformation to the bounding box", "other"_a,
             py::is_operator())
        .def("__ilshift__", &BoundingBox3D::operator<<=,
             "Applies a affine transformation to the bounding box", "other"_a,
             py::is_operator())
        .def("triangle_indices", &BoundingBox3D::triangle_indices,
             "The indices of the triangles that make up the bounding box")
        .def("corners", &BoundingBox3D::corners, "The bounding box's corners")
        .def("triangles", &BoundingBox3D::triangles,
             "The bounding box's triangles")
        .def("center", &BoundingBox3D::center, "The bounding box's center")
        .def("volume", &BoundingBox3D::volume, "The bounding box's volume");

    // Defines Polygon3D methods.
    polygon3d
        .def(py::init<const std::vector<Point3D> &>(),
             "Creates a polygon from a set of points", "points"_a)
        .def_readwrite("points", &Polygon3D::points, "The polygon's points")
        .def("__str__", &Polygon3D::to_string, py::is_operator())
        .def("__repr__", &Polygon3D::to_string, py::is_operator())
        .def("__eq__", &Polygon3D::operator==,
             "Checks if two polygons are equal", "other"_a, py::is_operator())
        .def("__ne__", &Polygon3D::operator!=,
             "Checks if two polygons are not equal", "other"_a,
             py::is_operator())
        .def(
            "__lshift__",
            py::overload_cast<const Polygon3D &, const Affine3D &>(&operator<<),
            "Applies a affine transformation to the polygon", "other"_a,
            py::is_operator())
        .def("__ilshift__", &Polygon3D::operator<<=,
             "Applies a affine transformation to the polygon", "other"_a,
             py::is_operator())
        .def("area", &Polygon3D::area, "The polygon's area")
        .def("normal", &Polygon3D::normal, "The polygon's normal")
        .def("center", &Polygon3D::center, "The polygon's center")
        .def("bounding_box", &Polygon3D::bounding_box,
             "The polygon's bounding box");

    // Defines Affine3D methods.
    affine3d
        .def(py::init<std::optional<std::tuple<float, float, float>>,
                      std::optional<std::tuple<float, float, float>>,
                      std::optional<float>>(),
             "Initialize affine transformation from rotation and translation "
             "vectors",
             "rot"_a = std::nullopt, "trans"_a = std::nullopt,
             "scale"_a = std::nullopt)
        .def("__str__", &Affine3D::to_string, py::is_operator())
        .def("__repr__", &Affine3D::to_string, py::is_operator())
        .def("__matmul__",
             py::overload_cast<const Affine3D &, const Affine3D &>(&operator*),
             "Combine two affine transformations", "other"_a, py::is_operator())
        .def("__imatmul__", &Affine3D::operator*=,
             "Applies an affine transformation to a point", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine3D &, const Point3D &>(&operator>>),
             "Applies an affine transformation to a point", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine3D &, const Line3D &>(&operator>>),
             "Applies an affine transformation to a line", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine3D &, const Triangle3D &>(
                 &operator>>),
             "Applies an affine transformation to a triangle", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const Affine3D &, const BoundingBox3D &>(
                 &operator>>),
             "Applies an affine transformation to a bounding box", "other"_a,
             py::is_operator())
        .def(
            "__rshift__",
            py::overload_cast<const Affine3D &, const Polygon3D &>(&operator>>),
            "Applies an affine transformation to a polygon", "other"_a,
            py::is_operator())
        .def("inverse", &Affine3D::inverse,
             "The inverse of the affine transformation");

    // Defines Angle methods.
    angle.def(py::init<float>(), "An angle in 2D space", "value"_a)
        .def(py::init<const Point2D &, const Point2D &, const Point2D &>(),
             "An angle in 2D space", "p1"_a, "p2"_a, "p3"_a)
        .def(py::init<const Point3D &, const Point3D &, const Point3D &>(),
             "An angle in 3D space", "p1"_a, "p2"_a, "p3"_a)
        .def_readwrite("value", &Angle::value, "The angle's value")
        .def("__str__", &Angle::to_string, py::is_operator())
        .def("__repr__", &Angle::to_string, py::is_operator())
        .def("cos", &Angle::cos, "The angle's cosine")
        .def("sin", &Angle::sin, "The angle's sine")
        .def("tan", &Angle::tan, "The angle's tangent")
        .def("acos", &Angle::acos, "The angle's arc cosine")
        .def("asin", &Angle::asin, "The angle's arc sine")
        .def("atan", &Angle::atan, "The angle's arc tangent")
        .def("to_degress", &Angle::to_degrees, "The angle's value in degrees");

    // Defines BarycentricCoordinates methods.
    barycentric_coordinates
        .def(py::init<float, float, float>(), "Barycentric coordinates", "u"_a,
             "v"_a, "w"_a)
        .def_readwrite("u", &BarycentricCoordinates::u,
                       "The first barycentric coordinate")
        .def_readwrite("v", &BarycentricCoordinates::v,
                       "The second barycentric coordinate")
        .def_readwrite("w", &BarycentricCoordinates::w,
                       "The third barycentric coordinate")
        .def("__str__", &BarycentricCoordinates::to_string, py::is_operator())
        .def("__repr__", &BarycentricCoordinates::to_string, py::is_operator())
        .def("__eq__", &BarycentricCoordinates::operator==,
             "Checks if two barycentric coordinates are equal", "other"_a,
             py::is_operator())
        .def("__ne__", &BarycentricCoordinates::operator!=,
             "Checks if two barycentric coordinates are not equal", "other"_a,
             py::is_operator())
        .def("get_point_2d", &BarycentricCoordinates::get_point_2d,
             "The point corresponding to the barycentric coordinates within a "
             "2D triangle",
             "t"_a)
        .def("get_point_3d", &BarycentricCoordinates::get_point_3d,
             "The point corresponding to the barycentric coordinates within a "
             "3D triangle",
             "t"_a);
}

}  // namespace types
}  // namespace cpu
}  // namespace fast_trimesh
