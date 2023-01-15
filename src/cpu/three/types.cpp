#include "types.h"

#include <numeric>
#include <sstream>

#include "boolean.h"

using namespace pybind11::literals;

#define TOLERANCE 1e-6

namespace fast_trimesh {
namespace cpu {
namespace three {
namespace types {

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
    return distance_to_point(p) < TOLERANCE;
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
    return x >= bb.min.x - TOLERANCE && x <= bb.max.x + TOLERANCE &&
           y >= bb.min.y - TOLERANCE && y <= bb.max.y + TOLERANCE &&
           z >= bb.min.z - TOLERANCE && z <= bb.max.z + TOLERANCE;
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
    return t.point_from_barycentric_coords(bc);
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

float triangle_signed_volume(const Point3D &a, const Point3D &b,
                             const Point3D &c, const Point3D &d) {
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
    // bool s1 = signed_volume(p1, t.p1, t.p2, t.p3) > 0,
    //      s2 = signed_volume(p2, t.p1, t.p2, t.p3) > 0,
    //      s3 = signed_volume(p1, p2, t.p1, t.p2) > 0,
    //      s4 = signed_volume(p1, p2, t.p2, t.p3) > 0,
    //      s5 = signed_volume(p1, p2, t.p3, t.p1) > 0;
    // return (s1 != s2) && (s3 == s4 && s4 == s5);

    return triangle_intersection(t).has_value();
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

    if (w < -TOLERANCE || u < -TOLERANCE || v < -TOLERANCE ||
        (u + v) > 1.0 + TOLERANCE || w > 1.0 + TOLERANCE) {
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

Point3D Triangle3D::point_from_barycentric_coords(
    const BarycentricCoordinates &b) const {
    return p1 * b.u + p2 * b.v + p3 * b.w;
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

std::vector<face_t> BoundingBox3D::triangle_indices() const {
    return {{0, 2, 1}, {0, 3, 2}, {0, 5, 4}, {0, 1, 5}, {1, 6, 5}, {1, 2, 6},
            {2, 7, 6}, {2, 3, 7}, {3, 4, 7}, {3, 0, 4}, {4, 6, 7}, {4, 5, 6}};
}

std::vector<Point3D> BoundingBox3D::corners() const {
    return {{min.x, min.x, min.x}, {max.x, min.y, min.z}, {max.x, max.y, min.z},
            {min.x, max.y, min.z}, {min.x, min.y, max.z}, {max.x, min.y, max.z},
            {max.x, max.y, max.z}, {min.x, max.y, max.z}};
}

std::vector<Line3D> BoundingBox3D::edges() const {
    return {
        {min, {max.x, min.y, min.z}},
        {min, {min.x, max.y, min.z}},
        {min, {min.x, min.y, max.z}},
        {max, {min.x, max.y, max.z}},
        {max, {max.x, min.y, max.z}},
        {max, {max.x, max.y, min.z}},
        {{min.x, max.y, min.z}, {max.x, max.y, min.z}},
        {{min.x, max.y, min.z}, {min.x, max.y, max.z}},
        {{max.x, min.y, min.z}, {max.x, max.y, min.z}},
        {{max.x, min.y, min.z}, {max.x, min.y, max.z}},
        {{min.x, min.y, max.z}, {max.x, min.y, max.z}},
        {{min.x, min.y, max.z}, {min.x, max.y, max.z}},
    };
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

/* --------- *
 * Trimesh3D *
 * --------- */

Trimesh3D::Trimesh3D(const std::vector<Point3D> &vertices,
                     const face_set_t &faces)
    : _vertices(vertices), _faces(faces.begin(), faces.end()) {
    validate();
}

Trimesh3D::Trimesh3D(const std::vector<Point3D> &vertices,
                     const face_list_t &faces)
    : _vertices(vertices), _faces(faces) {
    validate();
}

void Trimesh3D::validate() const {
    // Checks that there is at least one face.
    if (_faces.empty()) {
        throw std::runtime_error("No faces");
    }

    // Check that all vertices are valid.
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        if (vi >= _vertices.size() || vj >= _vertices.size() ||
            vk >= _vertices.size()) {
            throw std::runtime_error("Invalid face");
        }
    }

    // Check that all vertices are used.
    std::vector<bool> used(_vertices.size(), false);
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        used[vi] = true;
        used[vj] = true;
        used[vk] = true;
    }
    for (bool b : used) {
        if (!b) {
            throw std::runtime_error("Unused vertex");
        }
    }

    // Check that all faces are triangles.
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        if (vi == vj || vi == vk || vj == vk) {
            throw std::runtime_error("Degenerate face");
        }
    }
}

const std::vector<Point3D> &Trimesh3D::vertices() const { return _vertices; }

const face_list_t &Trimesh3D::faces() const { return _faces; }

Triangle3D Trimesh3D::get_triangle(const face_t &face) const {
    auto &[vi, vj, vk] = face;
    return {_vertices[vi], _vertices[vj], _vertices[vk]};
}

std::vector<Triangle3D> Trimesh3D::get_triangles() const {
    std::vector<Triangle3D> result;
    for (auto &face : _faces) {
        result.push_back(get_triangle(face));
    }
    return result;
}

float Trimesh3D::signed_volume() const {
    Point3D center = {0, 0, 0};
    float volume = 0;
    for (auto &triangle : get_triangles()) {
        volume += triangle_signed_volume(center, triangle.p1, triangle.p2,
                                         triangle.p3);
    }
    return volume;
}

Trimesh3D Trimesh3D::flip_inside_out() const {
    std::vector<Point3D> vertices = this->_vertices;
    face_list_t faces;
    std::transform(this->_faces.begin(), this->_faces.end(),
                   std::inserter(faces, faces.begin()), [](const face_t &face) {
                       return std::make_tuple(std::get<0>(face),
                                              std::get<2>(face),
                                              std::get<1>(face));
                   });
    return {vertices, faces};
}

Trimesh3D Trimesh3D::subdivide(bool at_edges) const {
    std::vector<Point3D> vertices = _vertices;
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
            add_edge(std::get<0>(face), std::get<1>(face));
            add_edge(std::get<1>(face), std::get<2>(face));
            add_edge(std::get<2>(face), std::get<0>(face));
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

std::string Trimesh3D::to_string() const {
    std::stringstream ss;
    ss << "Trimesh3D(" << std::endl;
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
        ss << "    (" << std::get<0>(face) << ", " << std::get<1>(face) << ", "
           << std::get<2>(face) << ")," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]" << std::endl;
    ss << ")" << std::endl;
    return ss.str();
}

Trimesh3D Trimesh3D::operator<<(const Affine3D &tf) const {
    std::vector<Point3D> vertices;
    face_list_t faces = this->_faces;
    std::transform(this->_vertices.begin(), this->_vertices.end(),
                   std::back_inserter(vertices),
                   [&tf](const Point3D &vertex) { return vertex << tf; });
    return {vertices, faces};
}

Trimesh3D Trimesh3D::operator|(const Trimesh3D &other) const {
    return three::boolean::mesh_intersection(*this, other);
}

Trimesh3D Trimesh3D::operator&(const Trimesh3D &other) const {
    return three::boolean::mesh_union(*this, other);
}

Trimesh3D Trimesh3D::operator-(const Trimesh3D &other) const {
    return three::boolean::mesh_difference(*this, other);
}

void add_3d_types_modules(py::module &m) {
    // Defines the classes first, so that methods can resolve types
    // correctly.
    auto point3d = py::class_<Point3D>(m, "Point3D");
    auto line3d = py::class_<Line3D>(m, "Line3D");
    auto circumcircle3d = py::class_<Circumcircle3D>(m, "Circumcircle3D");
    auto triangle3d = py::class_<Triangle3D>(m, "Triangle3D");
    auto bbox3d = py::class_<BoundingBox3D>(m, "BoundingBox3D");
    auto polygon3d = py::class_<Polygon3D>(m, "Polygon3D");
    auto affine3d = py::class_<Affine3D>(m, "Affine3D");
    auto trimesh3d =
        py::class_<Trimesh3D, std::shared_ptr<Trimesh3D>>(m, "Trimesh3D");

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
             "The barycentric coordinates of the point relative to a "
             "triangle",
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
             "The closest points between two lines; returns None if the "
             "lines "
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
             "The triangle's circumcircle")
        .def("point_from_barycentric_coords",
             &Triangle3D::point_from_barycentric_coords,
             "The point from barycentric coordinates", "b"_a);

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
             "Initialize affine transformation from rotation and "
             "translation "
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

    // Defines Trimesh3D methods.
    trimesh3d
        // .def(py::init<vertices3d_t &, face_set_t &>(),
        //      "Creates a trimesh from vertices and faces", "vertices"_a,
        //      "faces"_a)
        .def_property_readonly("vertices", &Trimesh3D::vertices,
                               "The mesh vertices")
        .def_property_readonly("faces", &Trimesh3D::faces, "The mesh faces")
        .def("get_triangle", &Trimesh3D::get_triangle,
             "Gets a mesh triangle from a face", "face"_a)
        .def("get_triangles", &Trimesh3D::get_triangles,
             "Gets all mesh triangles")
        .def("signed_volume", &Trimesh3D::signed_volume,
             "Computes the signed volume of the mesh")
        .def("flip_inside_out", &Trimesh3D::flip_inside_out,
             "Flips the mesh inside out")
        .def("subdivide", &Trimesh3D::subdivide,
             "Subdivides the mesh into smaller triangles", "at_edges"_a = true)
        .def("__str__", &Trimesh3D::to_string, "Converts the mesh to a string",
             py::is_operator())
        .def("__repr__", &Trimesh3D::to_string, "Converts the mesh to a string",
             py::is_operator())
        .def("__or__", &Trimesh3D::operator|,
             "Computes the union of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__and__", &Trimesh3D::operator&,
             "Computes the intersection of two "
             "3D meshes",
             "other"_a, py::is_operator())
        .def("__sub__", &Trimesh3D::operator-,
             "Computes the difference of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__lshift__", &Trimesh3D::operator<<,
             "Applies affine transformation to 3D mesh", "affine"_a,
             py::is_operator());
}

}  // namespace types
}  // namespace three
}  // namespace cpu
}  // namespace fast_trimesh
