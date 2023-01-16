#include "types.h"

#include <numeric>
#include <sstream>

#include "boolean.h"

using namespace pybind11::literals;

namespace trimesh {

#define TOLERANCE 1e-6

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
    return distance_to_point(p) < TOLERANCE;
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
    return bary.u >= -TOLERANCE && bary.v >= -TOLERANCE && bary.w >= -TOLERANCE;
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

std::optional<Point2D> Line2D::line_intersection(const Line2D &l) const {
    Point2D r = p2 - p1;
    Point2D s = l.p2 - l.p1;

    float rxs = r.cross(s);
    if (std::abs(rxs) < TOLERANCE) return std::nullopt;

    Point2D qmp1 = l.p1 - p1;
    float t = qmp1.cross(s) / rxs;
    float u = qmp1.cross(r) / rxs;

    if (t < -TOLERANCE || t > 1.0f + TOLERANCE || u < -TOLERANCE ||
        u > 1.0f + TOLERANCE)
        return std::nullopt;

    return p1 + r * t;
}

bool Line2D::intersects_triangle(const Triangle2D &t) const {
    if (p1.is_inside_triangle(t) || p2.is_inside_triangle(t)) {
        return true;
    }
    for (auto &l : t.edges()) {
        if (line_intersection(l)) return true;
    }
    return false;
}

std::vector<Point2D> Line2D::triangle_intersection(const Triangle2D &t) const {
    std::vector<Point2D> points;
    if (p1.is_inside_triangle(t)) points.push_back(p1);
    if (p2.is_inside_triangle(t)) points.push_back(p2);
    for (auto &l : t.edges()) {
        std::optional<Point2D> p = line_intersection(l);
        if (p) points.push_back(*p);
    }
    return points;
}

bool Line2D::intersects_bounding_box(const BoundingBox2D &b) const {
    if (p1.is_inside_bounding_box(b) || p2.is_inside_bounding_box(b)) {
        return true;
    }
    for (auto &l : b.edges()) {
        if (line_intersection(l)) return true;
    }
    return false;
}

float Line2D::distance_to_point(const Point2D &p) const {
    Point2D pb = closest_point(p);
    return p.distance_to_point(pb);
}

float Line2D::distance_to_line(const Line2D &l) const {
    std::optional<Point2D> p = line_intersection(l);

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

std::vector<Point2D> Triangle2D::vertices() const { return {p1, p2, p3}; }

std::vector<Line2D> Triangle2D::edges() const {
    return {{p1, p2}, {p2, p3}, {p3, p1}};
}

bool Triangle2D::contains(const Point2D &p) const {
    return p.is_inside_triangle(*this);
}

bool Triangle2D::intersects_bounding_box(const BoundingBox2D &bb) const {
    return bb.intersects_triangle(*this);
}

bool Triangle2D::intersects_triangle(const Triangle2D &t) const {
    if (t.contains(p1) || t.contains(p2) || t.contains(p3)) return true;
    if (contains(t.p1) || contains(t.p2) || contains(t.p3)) return true;
    for (auto &l : edges()) {
        if (l.intersects_triangle(t)) return true;
    }
    return false;
}

std::vector<Point2D> Triangle2D::triangle_intersection(
    const Triangle2D &t) const {
    std::vector<Point2D> points;
    for (auto &l : edges()) {
        std::vector<Point2D> p = l.triangle_intersection(t);
        points.insert(points.end(), p.begin(), p.end());
    }
    return points;
}

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

Point2D Triangle2D::point_from_barycentric_coords(
    const BarycentricCoordinates &b) const {
    return p1 * b.u + p2 * b.v + p3 * b.w;
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

float BoundingBox2D::area() const { return (max.x - min.x) * (max.y - min.y); }

Point2D BoundingBox2D::center() const {
    return {(min.x + max.x) / 2.0f, (min.y + max.y) / 2.0f};
}

std::vector<Point2D> BoundingBox2D::vertices() const {
    return {min, {max.x, min.y}, max, {min.x, max.y}};
}

std::vector<Line2D> BoundingBox2D::edges() const {
    return {{min, {max.x, min.y}},
            {{max.x, min.y}, max},
            {max, {min.x, max.y}},
            {{min.x, max.y}, min}};
}

bool BoundingBox2D::intersects_triangle(const Triangle2D &t) const {
    for (const auto &l : edges())
        if (l.intersects_triangle(t)) return true;
    return false;
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

Polygon2D Polygon2D::operator+(const Polygon2D &p) const {
    Polygon2D result = *this;
    result += p;
    return result;
}

Polygon2D Polygon2D::operator+=(const Polygon2D &p) {
    points.insert(points.end(), p.points.begin(), p.points.end());
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

    // Sort points by polar angle with P0, in clockwise order.
    std::vector<int> hull_points(n);
    std::iota(hull_points.begin(), hull_points.end(), 0);
    std::sort(hull_points.begin(), hull_points.end(), [&](int i, int j) {
        if (i == P0) return true;  // First element.
        float det =
            (points[i] - points[P0]).determinant(points[j] - points[P0]);
        if (det == 0)
            return points[i].distance_to_point(points[P0]) <
                   points[j].distance_to_point(points[P0]);
        return det > 0;
    });

    // Traverses the points, keeping points which are convex.
    std::vector<Point2D> stack;
    for (int i = 0; i < n; i++) {
        int point = hull_points[i];
        while (stack.size() > 1 &&
               (stack[stack.size() - 2] - stack.back())
                       .determinant(points[point] - stack.back()) >= 0) {
            stack.pop_back();
        }
        stack.push_back(points[point]);
    }

    // Ensures that the last point is also convex.
    while (stack.size() > 2 &&
           (stack[stack.size() - 2] - stack.back())
                   .determinant(stack[0] - stack.back()) >= 0) {
        stack.pop_back();
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

bool Polygon2D::is_ear(int vi, int vj, int vk) const {
    Point2D pi = points[vi], pj = points[vj], pk = points[vk];

    // Checks if the triangle is convex.
    if (!is_convex(pi, pj, pk)) return false;

    // Checks if the triangle contains any other points.
    for (int l = 0; l < points.size(); l++) {
        if (l == vi || l == vj || l == vk) continue;
        Triangle2D triangle = {pi, pj, pk};
        if (points[l].is_inside_triangle(triangle)) return false;
    }

    return true;
}

Trimesh2D Polygon2D::get_trimesh(bool is_convex) const {
    if (points.size() < 3) throw std::runtime_error("Invalid polygon.");

    // Gets the vertex indices from 0 to n - 1.
    std::vector<size_t> indices(points.size());
    std::iota(indices.begin(), indices.end(), 0);

    // Ensures that the polygon is counter-clockwise.
    if (is_clockwise()) {
        std::reverse(indices.begin(), indices.end());
    }

    std::vector<Point2D> vertices(points);
    face_list_t faces;

    // Runs ear clipping algorithm.
    while (indices.size() > 3) {
        bool found = false;
        size_t n = indices.size();
        for (size_t i = 0; i < n; i++) {
            size_t j = (i + 1) % n;
            size_t k = (i + 2) % n;
            size_t vi = indices[i], vj = indices[j], vk = indices[k];
            Point2D pi = points[vi], pj = points[vj], pk = points[vk];
            if (is_convex || is_ear(vi, vj, vk)) {
                faces.push_back({vi, vj, vk});
                indices.erase(indices.begin() + j);
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Unable to triangulate polygon.");
        }
    }
    faces.push_back({indices[0], indices[1], indices[2]});

    return {vertices, faces};
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

/* --------- *
 * Trimesh2D *
 * --------- */

Trimesh2D::Trimesh2D(const std::vector<Point2D> &vertices,
                     const face_set_t &faces)
    : _vertices(vertices), _faces(faces.begin(), faces.end()) {
    validate();
}

Trimesh2D::Trimesh2D(const std::vector<Point2D> &vertices,
                     const face_list_t &faces)
    : _vertices(vertices), _faces(faces) {
    validate();
}

void Trimesh2D::validate() const {
    // Checks that there is at least one face.
    if (_faces.empty()) {
        throw std::invalid_argument("No faces");
    }

    // Checks that all face vertices are valid.
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        if (vi >= _vertices.size() || vj >= _vertices.size() ||
            vk >= _vertices.size()) {
            throw std::invalid_argument("Invalid face");
        }
    }

    // Checks that all vertices are used.
    std::vector<bool> used(_vertices.size(), false);
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        used[vi] = true;
        used[vj] = true;
        used[vk] = true;
    }
    for (size_t i = 0; i < used.size(); i++) {
        if (!used[i]) {
            throw std::invalid_argument("Unused vertex: " + std::to_string(i));
        }
    }

    // Checks that all faces are triangles.
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        if (vi == vj || vi == vk || vj == vk) {
            throw std::invalid_argument("Face is not a triangle");
        }
    }

    // Checks that all 2D faces are oriented the same direction.
    auto &face = _faces[0];
    auto &[vi, vj, vk] = face;
    const Point2D &p1 = _vertices[vi], &p2 = _vertices[vj], &p3 = _vertices[vk];
    const Point2D v1 = p2 - p1, v2 = p3 - p1;
    float normal = v1.cross(v2);
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        const Point2D &p1 = _vertices[vi], &p2 = _vertices[vj],
                      &p3 = _vertices[vk];
        const Point2D v1 = p2 - p1, v2 = p3 - p1;
        float normal1 = v1.cross(v2);
        if (normal * normal1 < 0) {
            throw std::invalid_argument("Face is not oriented the same way");
        }
    }
}

const std::vector<Point2D> &Trimesh2D::vertices() const { return _vertices; }

const face_list_t &Trimesh2D::faces() const { return _faces; }

const Triangle2D Trimesh2D::get_triangle(const face_t &face) const {
    auto &[vi, vj, vk] = face;
    return {_vertices[vi], _vertices[vj], _vertices[vk]};
}

const std::vector<Triangle2D> Trimesh2D::get_triangles() const {
    std::vector<Triangle2D> result;
    for (auto &face : _faces) {
        result.push_back(get_triangle(face));
    }
    return result;
}

float angle(const Point2D &p1, const Point2D &p2, const Point2D &p3) {
    auto v1 = p2 - p1;
    auto v2 = p3 - p1;
    auto angle = std::atan2(v2.y, v2.x) - std::atan2(v1.y, v1.x);
    if (angle < 0.0f) angle += 2.0f * M_PI;
    return angle;
}

const std::vector<size_t> Trimesh2D::get_polygon_inds() const {
    // First, counts the number of faces that each edge is part of.
    std::map<const std::tuple<size_t, size_t>, size_t> edge_counts;
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        edge_counts[{vi, vj}]++;
        edge_counts[{vj, vi}]++;
        edge_counts[{vj, vk}]++;
        edge_counts[{vk, vj}]++;
        edge_counts[{vk, vi}]++;
        edge_counts[{vi, vk}]++;
    }

    // Checks that each edge is part of exactly one or two faces.
    for (auto &[edge, count] : edge_counts) {
        if (count != 1 && count != 2) {
            throw std::invalid_argument("Edge is part of more than two faces");
        }
    }

    // Next, get the adjacencies of each vertex for the endpoints of the
    // edges that are part of only one face.
    std::map<size_t, std::set<size_t>> adjacencies;
    for (auto &[edge, count] : edge_counts) {
        if (count == 1) {
            auto &[vi, vj] = edge;
            adjacencies[vi].insert(vj);
            adjacencies[vj].insert(vi);
        }
    }

    // Finally, find the starting vertex and walk around the polygon.
    auto current = adjacencies.begin()->first;
    std::vector<size_t> polygon_inds;
    while (true) {
        polygon_inds.push_back(current);
        auto next = adjacencies[current].begin();
        adjacencies[current].erase(next);
        adjacencies[*next].erase(current);
        current = *next;
        if (current == polygon_inds[0]) {
            break;
        }
    }

    // If the polygon is oriented clockwise, reverse it.
    auto &p1 = _vertices[polygon_inds[0]], &p2 = _vertices[polygon_inds[1]],
         &p3 = _vertices[polygon_inds[2]];
    if (angle(p1, p2, p3) < M_PI) {
        std::reverse(polygon_inds.begin(), polygon_inds.end());
    }

    // Check that the polygon indices are unique.
    std::set<size_t> unique_inds;
    for (auto &ind : polygon_inds) {
        unique_inds.insert(ind);
    }
    if (unique_inds.size() != polygon_inds.size()) {
        throw std::invalid_argument("Polygon indices are not unique");
    }

    return polygon_inds;
}

const Polygon2D Trimesh2D::get_polygon() const {
    auto polygon_inds = get_polygon_inds();
    std::vector<Point2D> polygon;
    for (auto &ind : polygon_inds) {
        polygon.push_back(_vertices[ind]);
    }
    return {polygon};
}

Trimesh2D Trimesh2D::subdivide(bool at_edges) const {
    std::vector<Point2D> vertices = _vertices;
    face_list_t faces;

    if (at_edges) {
        // Add center points of each edge as new vertices.
        std::map<const std::tuple<size_t, size_t>, size_t> edge_map;
        auto add_edge = [&](const size_t &p1, const size_t &p2) {
            std::tuple<size_t, size_t> edge1 = {p1, p2}, edge2 = {p2, p1};
            if (edge_map.find(edge1) == edge_map.end() &&
                edge_map.find(edge2) == edge_map.end()) {
                edge_map[edge1] = vertices.size();
                edge_map[edge2] = vertices.size();
                const auto &v1 = _vertices[p1], &v2 = _vertices[p2];
                vertices.push_back(v1 + (v2 - v1) / 2.0f);
            }
        };
        for (auto &face : _faces) {
            add_edge(face.a, face.b);
            add_edge(face.b, face.c);
            add_edge(face.c, face.a);
        }

        // Add new faces.
        for (auto &face : _faces) {
            auto &[vi, vj, vk] = face;
            auto e1 = edge_map[{vi, vj}];
            auto e2 = edge_map[{vj, vk}];
            auto e3 = edge_map[{vk, vi}];
            faces.push_back({vi, e1, e3});
            faces.push_back({vj, e2, e1});
            faces.push_back({vk, e3, e2});
            faces.push_back({e1, e2, e3});
        }
    } else {
        // Add center point of each face as an additional vertex.
        for (auto &face : _faces) {
            auto &[vi, vj, vk] = face;
            auto center =
                (_vertices[vi] + _vertices[vj] + _vertices[vk]) / 3.0f;
            vertices.push_back(center);
        }

        // Add new faces.
        size_t i = 0;
        for (auto &face : _faces) {
            auto &[vi, vj, vk] = face;
            auto center = _vertices.size() + i++;
            faces.push_back({vi, center, vk});
            faces.push_back({vj, center, vi});
            faces.push_back({vk, center, vj});
        }
    }

    return {vertices, faces};
}

std::string Trimesh2D::to_string() const {
    std::stringstream ss;
    ss << "Trimesh2D(" << std::endl;
    ss << "  " << _vertices.size() << " vertices = [" << std::endl;
    size_t i = 0;
    for (auto &vertex : _vertices) {
        ss << "    " << vertex.to_string() << "," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]," << std::endl;
    ss << "  " << _faces.size() << " faces = [" << std::endl;
    i = 0;
    for (auto &face : _faces) {
        ss << "    " << face.to_string() << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]" << std::endl;
    ss << ")" << std::endl;
    return ss.str();
}

Trimesh2D Trimesh2D::operator<<(const Affine2D &tf) const {
    std::vector<Point2D> vertices;
    face_list_t faces = this->_faces;
    std::transform(this->_vertices.begin(), this->_vertices.end(),
                   std::back_inserter(vertices),
                   [&tf](const Point2D &vertex) { return vertex << tf; });
    return {vertices, faces};
}

Trimesh2D Trimesh2D::operator|(const Trimesh2D &other) const {
    return mesh_intersection(*this, other);
}

Trimesh2D Trimesh2D::operator&(const Trimesh2D &other) const {
    return mesh_union(*this, other);
}

Trimesh2D Trimesh2D::operator-(const Trimesh2D &other) const {
    return mesh_difference(*this, other);
}

void add_2d_types_modules(py::module &m) {
    // Defines the classes first, so that methods can resolve types
    // correctly.
    auto point2d = py::class_<Point2D>(m, "Point2D");
    auto line2d = py::class_<Line2D>(m, "Line2D");
    auto triangle2d = py::class_<Triangle2D>(m, "Triangle2D");
    auto bbox2d = py::class_<BoundingBox2D>(m, "BoundingBox2D");
    auto polygon2d = py::class_<Polygon2D>(m, "Polygon2D");
    auto affine2d = py::class_<Affine2D>(m, "Affine2D");
    auto trimesh2d =
        py::class_<Trimesh2D, std::shared_ptr<Trimesh2D>>(m, "Trimesh2D");

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
        .def("line_intersection", &Line2D::line_intersection,
             "The intersection point of two lines (None if they don't "
             "intersect)",
             "l"_a)
        .def("intersects_triangle", &Line2D::intersects_triangle,
             "Does the line intersect a triangle", "t"_a)
        .def("intersects_bounding_box", &Line2D::intersects_bounding_box,
             "Does the line intersect a bounding box", "bb"_a)
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
        .def("contains", &Triangle2D::contains,
             "Does the triangle contain a point", "p"_a)
        .def("intersects_bounding_box", &Triangle2D::intersects_bounding_box,
             "Does the triangle intersect a bounding box", "bb"_a)
        .def("intersects_triangle", &Triangle2D::intersects_triangle,
             "Does the triangle intersect another triangle", "t"_a)
        .def("distance_to_point", &Triangle2D::distance_to_point,
             "Distance to a point", "p"_a)
        .def("distance_to_line", &Triangle2D::distance_to_line,
             "Distance to a line", "l"_a)
        .def("distance_to_triangle", &Triangle2D::distance_to_triangle,
             "Distance to another triangle", "t"_a)
        .def("distance_to_bounding_box", &Triangle2D::distance_to_bounding_box,
             "Distance to a bounding box", "bb"_a)
        .def("point_from_barycentric_coords",
             &Triangle2D::point_from_barycentric_coords,
             "Returns a point from barycentric coordinates", "b"_a);

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
        .def("area", &BoundingBox2D::area, "The bounding box's area")
        .def("center", &BoundingBox2D::center, "The bounding box's center")
        .def("vertices", &BoundingBox2D::vertices,
             "The bounding box's vertices")
        .def("edges", &BoundingBox2D::edges, "The bounding box's edges")
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
        .def("__add__", &Polygon2D::operator+, "Concatenates two polygons",
             "other"_a, py::is_operator())
        .def("__iadd__", &Polygon2D::operator+=, "Concatenates two polygons",
             "other"_a, py::is_operator())
        .def("signed_area", &Polygon2D::signed_area,
             "The polygon's signed area (positive if counterclockwise)")
        .def("is_clockwise", &Polygon2D::is_clockwise,
             "Returns true if the polygon is clockwise")
        .def("reverse", &Polygon2D::reverse, "Reverses the polygon's points")
        .def("convex_hull", &Polygon2D::convex_hull,
             "Returns the polygon's convex hull")
        .def("bounding_box", &Polygon2D::bounding_box,
             "Returns the polygon's bounding box")
        .def("center", &Polygon2D::center, "Returns the polygon's center")
        .def("is_ear", &Polygon2D::is_ear,
             "Returns true if the polygon's point "
             "is an ear (for triangulation)",
             "vi"_a, "vj"_a, "vk"_a)
        .def("get_trimesh", &Polygon2D::get_trimesh,
             "Returns a triangle mesh representation of the polygon",
             "is_convex"_a = false);

    // Defines Affine2D methods.
    affine2d
        .def(py::init<std::optional<float>,
                      std::optional<std::tuple<float, float>>,
                      std::optional<float>>(),
             "Initialize affine transformation from rotation and "
             "translation "
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

    // Defines Trimesh2D methods.
    trimesh2d
        // .def(py::init<vertices2d_t &, face_set_t &>(),
        //      "Creates a trimesh from vertices and faces", "vertices"_a,
        //      "faces"_a)
        .def_property_readonly("vertices", &Trimesh2D::vertices,
                               "The mesh vertices")
        .def_property_readonly("faces", &Trimesh2D::faces, "The mesh faces")
        .def("get_triangle", &Trimesh2D::get_triangle,
             "Returns the triangle for a given face", "face"_a)
        .def("get_triangles", &Trimesh2D::get_triangles,
             "Returns all the triangles in the trimesh")
        .def("get_polygon_inds", &Trimesh2D::get_polygon_inds,
             "Returns the indices of the polygon inscribing the trimesh")
        .def("get_polygon", &Trimesh2D::get_polygon,
             "Returns the polygon inscribing the trimesh")
        .def("subdivide", &Trimesh2D::subdivide,
             "Splits each triangle into four smaller triangles",
             "at_edges"_a = true)
        .def("__str__", &Trimesh2D::to_string, "Converts the mesh to a string",
             py::is_operator())
        .def("__repr__", &Trimesh2D::to_string, "Converts the mesh to a string",
             py::is_operator())
        .def("__or__", &Trimesh2D::operator|,
             "Computes the union of two 2D meshes", "other"_a,
             py::is_operator())
        .def("__and__", &Trimesh2D::operator&,
             "Computes the intersection of two 2D meshes", "other"_a,
             py::is_operator())
        .def("__sub__", &Trimesh2D::operator-,
             "Computes the difference of two 2D meshes", "other"_a,
             py::is_operator())
        .def("__lshift__", &Trimesh2D::operator<<,
             "Applies affine transformation to the mesh", "affine"_a,
             py::is_operator());
}

}  // namespace trimesh
