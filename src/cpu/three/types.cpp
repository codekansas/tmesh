#include "types.h"

#include <numeric>
#include <sstream>

#include "../options.h"
#include "boolean.h"

using namespace pybind11::literals;

namespace trimesh {

/* ---------- *
 * point_3d_t *
 * ---------- */

point_3d_t point_3d_t::operator+=(const point_3d_t &p) {
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}

point_3d_t point_3d_t::operator-=(const point_3d_t &p) {
    x -= p.x;
    y -= p.y;
    z -= p.z;
    return *this;
}

point_3d_t point_3d_t::operator*=(const point_3d_t &p) {
    x *= p.x;
    y *= p.y;
    z *= p.z;
    return *this;
}

point_3d_t point_3d_t::operator*=(double s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

point_3d_t point_3d_t::operator/=(const point_3d_t &p) {
    x /= p.x;
    y /= p.y;
    z /= p.z;
    return *this;
}

point_3d_t point_3d_t::operator/=(double s) {
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

bool point_3d_t::operator==(const point_3d_t &p) const {
    return distance_to_point(p) < get_tolerance();
}

bool point_3d_t::operator!=(const point_3d_t &p) const { return !(*this == p); }

bool point_3d_t::operator<(const point_3d_t &p) const {
    return *this != p &&
           (x < p.x || (x == p.x && (y < p.y || (y == p.y && z < p.z))));
}

point_3d_t point_3d_t::operator<<=(const affine_3d_t &a) {
    double x1 = a.r00 * x + a.r01 * y + a.r02 * z + a.tx;
    double y1 = a.r10 * x + a.r11 * y + a.r12 * z + a.ty;
    double z1 = a.r20 * x + a.r21 * y + a.r22 * z + a.tz;
    x = x1;
    y = y1;
    z = z1;
    return *this;
}

point_3d_t point_3d_t::normalize() const {
    double inv_length = 1.0 / length();
    return {x * inv_length, y * inv_length, z * inv_length};
}

double point_3d_t::determinant(const point_3d_t &a, const point_3d_t &b) const {
    return x * a.y * b.z + y * a.z * b.x + z * a.x * b.y - z * a.y * b.x -
           y * a.x * b.z - x * a.z * b.y;
}

double point_3d_t::length() const { return std::sqrt(x * x + y * y + z * z); }

double point_3d_t::dot(const point_3d_t &other) const {
    return x * other.x + y * other.y + z * other.z;
}

point_3d_t point_3d_t::cross(const point_3d_t &other) const {
    return {y * other.z - z * other.y, z * other.x - x * other.z,
            x * other.y - y * other.x};
}

barycentric_coordinates_t point_3d_t::barycentric_coordinates(
    const triangle_3d_t &t) const {
    point_3d_t v0 = t.p2 - t.p1;
    point_3d_t v1 = t.p3 - t.p1;
    point_3d_t v2 = *this - t.p1;
    double d00 = v0.dot(v0);
    double d01 = v0.dot(v1);
    double d11 = v1.dot(v1);
    double d20 = v2.dot(v0);
    double d21 = v2.dot(v1);
    double denom = d00 * d11 - d01 * d01;
    double v = (d11 * d20 - d01 * d21) / denom;
    double w = (d00 * d21 - d01 * d20) / denom;
    double u = 1.0 - v - w;
    return {u, v, w};
}

bool point_3d_t::is_inside_bounding_box(const bounding_box_3d_t &bb) const {
    return x >= bb.min.x - get_tolerance() && x <= bb.max.x + get_tolerance() &&
           y >= bb.min.y - get_tolerance() && y <= bb.max.y + get_tolerance() &&
           z >= bb.min.z - get_tolerance() && z <= bb.max.z + get_tolerance();
}

double point_3d_t::distance_to_point(const point_3d_t &other) const {
    return std::sqrt((x - other.x) * (x - other.x) +
                     (y - other.y) * (y - other.y) +
                     (z - other.z) * (z - other.z));
}

double point_3d_t::distance_to_line(const line_3d_t &l) const {
    return l.distance_to_point(*this);
}

double point_3d_t::distance_to_triangle(const triangle_3d_t &t) const {
    return t.distance_to_point(*this);
}

bool point_3d_t::is_coplanar(const triangle_3d_t &t) const {
    return std::abs((*this - t.p1).dot((t.p2 - t.p1).cross(t.p3 - t.p1))) <
           get_tolerance();
}

std::optional<point_3d_t> point_3d_t::project_to_line(
    const line_3d_t &l) const {
    double dx = l.p2.x - l.p1.x, dy = l.p2.y - l.p1.y, dz = l.p2.z - l.p1.z;
    double t = ((x - l.p1.x) * dx + (y - l.p1.y) * dy + (z - l.p1.z) * dz) /
               (dx * dx + dy * dy + dz * dz);
    if (t < 0 || t > 1) return std::nullopt;
    return point_3d_t{l.p1.x + t * dx, l.p1.y + t * dy, l.p1.z + t * dz};
}

std::optional<point_3d_t> point_3d_t::project_to_triangle(
    const triangle_3d_t &t) const {
    barycentric_coordinates_t bc = barycentric_coordinates(t);
    if (bc.u < 0 || bc.v < 0 || bc.w < 0) return std::nullopt;
    return t.point_from_barycentric_coords(bc);
}

bool point_3d_t::projects_to_triangle(const triangle_3d_t &t) const {
    return project_to_triangle(t).has_value();
}

std::string point_3d_t::to_string() const {
    std::ostringstream ss;
    ss << "Point3D(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

size_t point_3d_hash_fn(const point_3d_t &p) {
    auto hf = std::hash<double>();
    return hf(p.x) ^ hf(p.y) ^ hf(p.z);
}

size_t __point_3d_hash_fn::operator()(const point_3d_t &p) const {
    return point_3d_hash_fn(p);
}

point_3d_t operator+(const point_3d_t &p1, const point_3d_t &p2) {
    return {p1.x + p2.x, p1.y + p2.y, p1.z + p2.z};
}

point_3d_t operator-(const point_3d_t &p1, const point_3d_t &p2) {
    return {p1.x - p2.x, p1.y - p2.y, p1.z - p2.z};
}

point_3d_t operator*(const point_3d_t &p1, const point_3d_t &p2) {
    return {p1.x * p2.x, p1.y * p2.y, p1.z * p2.z};
}

point_3d_t operator*(double s, const point_3d_t &p) {
    return {s * p.x, s * p.y, s * p.z};
}

point_3d_t operator*(const point_3d_t &p, double s) {
    return {s * p.x, s * p.y, s * p.z};
}

point_3d_t operator/(const point_3d_t &p1, const point_3d_t &p2) {
    return {p1.x / p2.x, p1.y / p2.y, p1.z / p2.z};
}

point_3d_t operator/(const point_3d_t &p, double s) {
    return {p.x / s, p.y / s, p.z / s};
}

/* --------- *
 * line_3d_t *
 * --------- */

bool line_3d_t::operator==(const line_3d_t &other) const {
    return p1 == other.p1 && p2 == other.p2;
}

bool line_3d_t::operator!=(const line_3d_t &other) const {
    return !(*this == other);
}

line_3d_t line_3d_t::operator<<=(const affine_3d_t &a) {
    p1 <<= a;
    p2 <<= a;
    return *this;
}

std::optional<std::tuple<point_3d_t, point_3d_t>> line_3d_t::closest_points(
    const line_3d_t &l) const {
    point_3d_t d1 = p2 - p1, d2 = l.p2 - l.p1;
    point_3d_t n = d1.cross(d2);
    point_3d_t n1 = d1.cross(n), n2 = d2.cross(n);
    double d2n1 = d2.dot(n1), d1n2 = d1.dot(n2);
    if (std::abs(d2n1) < get_tolerance() && std::abs(d1n2) < get_tolerance()) {
        return std::nullopt;
    }
    point_3d_t c1 = p1 + d1 * (n2.dot(l.p1 - p1) / d1n2),
               c2 = l.p1 + d2 * (n1.dot(p1 - l.p1) / d2n1);
    return std::make_tuple(c1, c2);
}

std::optional<point_3d_t> line_3d_t::line_intersection(
    const line_3d_t &l) const {
    auto p = closest_points(l);
    if (!p) {
        return std::nullopt;
    }
    auto a = std::get<0>(*p), b = std::get<1>(*p);
    if (a.distance_to_point(b) > get_tolerance()) {
        return std::nullopt;
    }
    return a;
}

bool line_3d_t::intersects_triangle(const triangle_3d_t &t) const {
    // bool s1 = signed_volume(p1, t.p1, t.p2, t.p3) > 0,
    //      s2 = signed_volume(p2, t.p1, t.p2, t.p3) > 0,
    //      s3 = signed_volume(p1, p2, t.p1, t.p2) > 0,
    //      s4 = signed_volume(p1, p2, t.p2, t.p3) > 0,
    //      s5 = signed_volume(p1, p2, t.p3, t.p1) > 0;
    // return (s1 != s2) && (s3 == s4 && s4 == s5);

    return triangle_intersection(t).has_value();
}

std::optional<point_3d_t> line_3d_t::triangle_intersection(
    const triangle_3d_t &t) const {
    point_3d_t e1 = t.p2 - t.p1, e2 = t.p3 - t.p1, d21 = p2 - p1;
    point_3d_t n = e1.cross(e2);
    double det = -n.dot(d21);

    // Lines are parallel.
    if (std::abs(det) < get_tolerance()) {
        return std::nullopt;
    }

    point_3d_t ao = p1 - t.p1;
    point_3d_t dao = ao.cross(d21);

    double u = e2.dot(dao) / det;
    double v = -e1.dot(dao) / det;
    double w = ao.dot(n) / det;

    if (w < -get_tolerance() || u < -get_tolerance() || v < -get_tolerance() ||
        (u + v) > 1.0 + get_tolerance() || w > 1.0 + get_tolerance()) {
        return std::nullopt;
    }

    return p1 + d21 * w;
}

bool line_3d_t::intersects_bounding_box(const bounding_box_3d_t &b) const {
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

double line_3d_t::distance_to_point(const point_3d_t &p) const {
    point_3d_t d = p2 - p1;
    double t = d.dot(p - p1) / d.dot(d);
    if (t < 0.0) {
        return p.distance_to_point(p1);
    } else if (t > 1.0) {
        return p.distance_to_point(p2);
    }
    return p.distance_to_point(p1 + t * d);
}

double line_3d_t::distance_to_line(const line_3d_t &l) const {
    auto p = closest_points(l);
    if (p) {
        auto a = std::get<0>(*p), b = std::get<1>(*p);
        return a.distance_to_point(b);
    }
    return std::min({p1.distance_to_point(l.p1), p1.distance_to_point(l.p2),
                     p2.distance_to_point(l.p1), p2.distance_to_point(l.p2)});
}

std::string line_3d_t::to_string() const {
    std::ostringstream ss;
    ss << "Line3D(" << p1.to_string() << ", " << p2.to_string() << ")";
    return ss.str();
}

/* ----------- *
 * sphere_3d_t *
 * ----------- */

sphere_3d_t::sphere_3d_t() : center({0.0, 0.0, 0.0}), radius(0.0) {}

sphere_3d_t::sphere_3d_t(const point_3d_t &c, double r)
    : center(c), radius(r) {}

sphere_3d_t::sphere_3d_t(const tetrahedron_3d_t &t) {
    center = t.circumcenter();
    radius = center.distance_to_point(t.p1);
}

bool sphere_3d_t::operator==(const sphere_3d_t &c) const {
    return center == c.center && std::abs(radius - c.radius) < get_tolerance();
}

bool sphere_3d_t::operator!=(const sphere_3d_t &c) const {
    return !(*this == c);
}

double sphere_3d_t::volume() const {
    return 4.0 / 3.0 * M_PI * radius * radius * radius;
}

bool sphere_3d_t::contains_point(const point_3d_t &p) const {
    return center.distance_to_point(p) < radius + get_tolerance();
}

std::string sphere_3d_t::to_string() const {
    std::ostringstream ss;
    ss << "Sphere3D(" << center.to_string() << ", " << radius << ")";
    return ss.str();
}

/* ------------- *
 * triangle_3d_t *
 * ------------- */

bool triangle_3d_t::operator==(const triangle_3d_t &t) const {
    return (p1 == t.p1 && p2 == t.p2 && p3 == t.p3) ||
           (p1 == t.p2 && p2 == t.p3 && p3 == t.p1) ||
           (p1 == t.p3 && p2 == t.p1 && p3 == t.p2);
}

bool triangle_3d_t::operator!=(const triangle_3d_t &t) const {
    return !(*this == t);
}

triangle_3d_t triangle_3d_t::operator<<=(const affine_3d_t &a) {
    p1 <<= a;
    p2 <<= a;
    p3 <<= a;
    return *this;
}

double triangle_3d_t::area() const {
    point_3d_t v1 = p2 - p1;
    point_3d_t v2 = p3 - p1;
    return 0.5f * v1.cross(v2).length();
}

point_3d_t triangle_3d_t::center() const { return (p1 + p2 + p3) / 3.0; }

point_3d_t triangle_3d_t::normal() const {
    point_3d_t v1 = p2 - p1;
    point_3d_t v2 = p3 - p1;
    return v1.cross(v2).normalize();
}

std::vector<point_3d_t> triangle_3d_t::vertices() const { return {p1, p2, p3}; }

std::vector<line_3d_t> triangle_3d_t::edges() const {
    return {{p1, p2}, {p2, p3}, {p3, p1}};
}

double triangle_3d_t::distance_to_point(const point_3d_t &p) const {
    std::optional<point_3d_t> tp = p.project_to_triangle(*this);
    if (tp) {
        return p.distance_to_point(*tp);
    }
    return std::min({p.distance_to_line({p1, p2}), p.distance_to_line({p2, p3}),
                     p.distance_to_line({p3, p1})});
}

bool triangle_3d_t::contains_point(const point_3d_t &p) const {
    std::optional<point_3d_t> tp = p.project_to_triangle(*this);
    if (!tp) return false;
    return p.distance_to_point(*tp) < get_tolerance();
}

bool triangle_3d_t::is_coplanar(const triangle_3d_t &t) const {
    point_3d_t n = normal();
    return std::abs(n.dot(t.p1 - p1)) < get_tolerance() &&
           std::abs(n.dot(t.p2 - p1)) < get_tolerance() &&
           std::abs(n.dot(t.p3 - p1)) < get_tolerance();
}

point_3d_t triangle_3d_t::point_from_barycentric_coords(
    const barycentric_coordinates_t &b) const {
    return p1 * b.u + p2 * b.v + p3 * b.w;
}

std::vector<point_3d_t> triangle_3d_t::triangle_intersection(
    const triangle_3d_t &t) const {
    std::vector<point_3d_t> points;
    if (is_coplanar(t)) {
        for (const point_3d_t &p : t.vertices()) {
            if (contains_point(p)) points.push_back(p);
        }
        for (const point_3d_t &p : vertices()) {
            if (t.contains_point(p)) points.push_back(p);
        }
        for (const line_3d_t &e : edges()) {
            for (const line_3d_t &f : t.edges()) {
                std::optional<point_3d_t> p = e.line_intersection(f);
                if (p) points.push_back(*p);
            }
        }
    } else {
        for (const point_3d_t &p : t.vertices()) {
            if (contains_point(p)) points.push_back(p);
        }
        for (const point_3d_t &p : vertices()) {
            if (t.contains_point(p)) points.push_back(p);
        }
    }
    return points;
}

point_3d_t triangle_3d_t::orthocenter() const {
    point_3d_t v1 = p2 - p1;
    point_3d_t v2 = p3 - p1;
    point_3d_t v3 = p3 - p2;
    double a = v1.length();
    double b = v2.length();
    double c = v3.length();
    double s = 0.5f * (a + b + c);
    double area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    double r = 2.0 * area / (a + b + c);
    point_3d_t center = (p1 * a + p2 * b + p3 * c) / (a + b + c);
    return center;
}

std::string triangle_3d_t::to_string() const {
    std::ostringstream ss;
    ss << "Triangle3D(" << p1.to_string() << ", " << p2.to_string() << ", "
       << p3.to_string() << ")";
    return ss.str();
}

/* ---------------- *
 * tetrahedron_3d_t *
 * ---------------- */

bool tetrahedron_3d_t::operator==(const tetrahedron_3d_t &t) const {
    return p1 == t.p1 && p2 == t.p2 && p3 == t.p3 && p4 == t.p4;
}

bool tetrahedron_3d_t::operator!=(const tetrahedron_3d_t &t) const {
    return !(*this == t);
}

tetrahedron_3d_t tetrahedron_3d_t::operator<<=(const affine_3d_t &a) {
    p1 <<= a;
    p2 <<= a;
    p3 <<= a;
    p4 <<= a;
    return *this;
}

double tetrahedron_3d_t::signed_volume() const {
    point_3d_t v1 = p2 - p1;
    point_3d_t v2 = p3 - p1;
    point_3d_t v3 = p4 - p1;
    return v1.dot(v2.cross(v3)) / 6.0;
}

std::vector<triangle_3d_t> tetrahedron_3d_t::faces() const {
    volume_t v{0, 1, 2, 3};
    std::vector<point_3d_t> points{p1, p2, p3, p4};
    const auto get_face = [&points](const face_t &f) {
        return triangle_3d_t{points[f.a], points[f.b], points[f.c]};
    };
    face_list_t faces = v.faces();
    return {get_face(faces[0]), get_face(faces[1]), get_face(faces[2]),
            get_face(faces[3])};
}

double tetrahedron_3d_t::surface_area() const {
    double area = 0.0;
    for (const triangle_3d_t &t : faces()) {
        area += t.area();
    }
    return area;
}

point_3d_t tetrahedron_3d_t::circumcenter() const {
    point_3d_t e1 = p2 - p1, e2 = p3 - p1, e3 = p4 - p1;
    point_3d_t a = e2.cross(e3) * e1.dot(e1), b = e3.cross(e1) * e2.dot(e2),
               c = e1.cross(e2) * e3.dot(e3);
    double alpha = 2.0 * e1.determinant(e2, e3);
    return (a + b + c) / alpha + p1;
}

point_3d_t tetrahedron_3d_t::incenter() const {
    double a = (p2 - p3).length();
    double b = (p3 - p4).length();
    double c = (p4 - p2).length();
    double d = (p1 - p3).length();
    double e = (p1 - p4).length();
    double f = (p1 - p2).length();
    double s = 0.5 * (a + b + c);
    double t = 0.5 * (d + e + f);
    double area1 = std::sqrt(s * (s - a) * (s - b) * (s - c));
    double area2 = std::sqrt(t * (t - d) * (t - e) * (t - f));
    double r = 3.0 * (area1 + area2) / (a + b + c + d + e + f);
    return (p1 * a + p2 * b + p3 * c + p4 * d) / (a + b + c + d);
}

point_3d_t tetrahedron_3d_t::centroid() const {
    return (p1 + p2 + p3 + p4) / 4.0;
}

sphere_3d_t tetrahedron_3d_t::circumsphere() const { return {*this}; }

std::string tetrahedron_3d_t::to_string() const {
    return "Tetrahedron3D(" + p1.to_string() + ", " + p2.to_string() + ", " +
           p3.to_string() + ", " + p4.to_string() + ")";
}

/* ----------------- *
 * bounding_box_3d_t *
 * ----------------- */

bounding_box_3d_t::bounding_box_3d_t() {
    min = {std::numeric_limits<double>::max(),
           std::numeric_limits<double>::max(),
           std::numeric_limits<double>::max()};
    max = {std::numeric_limits<double>::lowest(),
           std::numeric_limits<double>::lowest(),
           std::numeric_limits<double>::lowest()};
}

bounding_box_3d_t::bounding_box_3d_t(const point_3d_t &min,
                                     const point_3d_t &max)
    : min(min), max(max) {}

bounding_box_3d_t::bounding_box_3d_t(const std::vector<point_3d_t> &points) {
    if (points.empty()) throw std::runtime_error("Empty point list");

    double min_x = points[0].x, min_y = points[0].y, min_z = points[0].z;
    double max_x = points[0].x, max_y = points[0].y, max_z = points[0].z;

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

bounding_box_3d_t::bounding_box_3d_t(const std::vector<line_3d_t> &lines) {
    if (lines.empty()) throw std::runtime_error("Empty line list");

    double min_x = lines[0].p1.x, min_y = lines[0].p1.y, min_z = lines[0].p1.z;
    double max_x = lines[0].p1.x, max_y = lines[0].p1.y, max_z = lines[0].p1.z;

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

bounding_box_3d_t::bounding_box_3d_t(
    const std::vector<triangle_3d_t> &triangles) {
    if (triangles.empty()) throw std::runtime_error("Empty triangle list");

    double min_x = triangles[0].p1.x, min_y = triangles[0].p1.y,
           min_z = triangles[0].p1.z;
    double max_x = triangles[0].p1.x, max_y = triangles[0].p1.y,
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

bounding_box_3d_t::bounding_box_3d_t(
    const std::vector<bounding_box_3d_t> &bboxes) {
    if (bboxes.empty()) throw std::runtime_error("Empty bounding box list");

    double min_x = bboxes[0].min.x, min_y = bboxes[0].min.y,
           min_z = bboxes[0].min.z;
    double max_x = bboxes[0].max.x, max_y = bboxes[0].max.y,
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

bool bounding_box_3d_t::operator==(const bounding_box_3d_t &b) const {
    return min == b.min && max == b.max;
}

bool bounding_box_3d_t::operator!=(const bounding_box_3d_t &b) const {
    return !(*this == b);
}

bounding_box_3d_t bounding_box_3d_t::operator<<=(const affine_3d_t &a) {
    min <<= a;
    max <<= a;
    return *this;
}

std::vector<face_t> bounding_box_3d_t::triangle_faces() const {
    return {{0, 2, 1}, {0, 3, 2}, {0, 5, 4}, {0, 1, 5}, {1, 6, 5}, {1, 2, 6},
            {2, 7, 6}, {2, 3, 7}, {3, 4, 7}, {3, 0, 4}, {4, 6, 7}, {4, 5, 6}};
}

std::vector<volume_t> bounding_box_3d_t::tetrahedron_volumes() const {
    // TODO: Need to check if this is actually correct...
    return {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 1, 5, 4},
            {1, 2, 6, 5}, {2, 3, 7, 6}, {3, 0, 4, 7}};
}

std::vector<point_3d_t> bounding_box_3d_t::corners() const {
    return {{min.x, min.x, min.x}, {max.x, min.y, min.z}, {max.x, max.y, min.z},
            {min.x, max.y, min.z}, {min.x, min.y, max.z}, {max.x, min.y, max.z},
            {max.x, max.y, max.z}, {min.x, max.y, max.z}};
}

std::vector<line_3d_t> bounding_box_3d_t::edges() const {
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

std::vector<triangle_3d_t> bounding_box_3d_t::triangles() const {
    std::vector<triangle_3d_t> triangles;
    auto faces = this->triangle_faces();
    auto corners = this->corners();
    for (auto &index : faces) {
        triangles.push_back(
            {corners[index.a], corners[index.b], corners[index.c]});
    }
    return triangles;
}

std::vector<tetrahedron_3d_t> bounding_box_3d_t::tetrahedrons() const {
    std::vector<tetrahedron_3d_t> tetrahedrons;
    auto face = this->tetrahedron_volumes();
    auto corners = this->corners();
    for (auto &index : face) {
        tetrahedrons.push_back({corners[index.a], corners[index.b],
                                corners[index.c], corners[index.d]});
    }
    return tetrahedrons;
}

point_3d_t bounding_box_3d_t::center() const { return (min + max) / 2.0; }

double bounding_box_3d_t::volume() const {
    return (max.x - min.x) * (max.y - min.y) * (max.z - min.z);
}

std::string bounding_box_3d_t::to_string() const {
    return "BoundingBox3D(" + min.to_string() + ", " + max.to_string() + ")";
}

/* ------------ *
 * polygon_3d_t *
 * ------------ */

polygon_3d_t::polygon_3d_t(const std::vector<point_3d_t> &points)
    : points(points) {}

bool polygon_3d_t::operator==(const polygon_3d_t &p) const {
    return points == p.points;
}

bool polygon_3d_t::operator!=(const polygon_3d_t &p) const {
    return !(*this == p);
}

polygon_3d_t polygon_3d_t::operator<<=(const affine_3d_t &a) {
    for (auto &p : points) p <<= a;
    return *this;
}

double polygon_3d_t::area() const {
    if (points.size() < 3) return 0.0;
    double area = 0.0;
    point_3d_t p1 = points[0];
    for (size_t i = 1; i < points.size(); ++i) {
        size_t j = (i + 1) % points.size();
        point_3d_t v1 = points[i] - p1;
        point_3d_t v2 = points[j] - p1;
        area += v1.cross(v2).length();
    }
    return std::abs(area) / 2.0;
}

point_3d_t polygon_3d_t::center() const {
    if (points.empty()) throw std::runtime_error("Empty polygon");
    point_3d_t center;
    for (auto &p : points) center += p;
    return center / points.size();
}

point_3d_t polygon_3d_t::normal() const {
    if (points.size() < 3) throw std::runtime_error("Not enough points");
    point_3d_t v1 = points[1] - points[0];
    point_3d_t v2 = points[2] - points[0];
    return v1.cross(v2).normalize();
}

bounding_box_3d_t polygon_3d_t::bounding_box() const {
    if (points.empty()) throw std::runtime_error("Empty polygon");

    double min_x = points[0].x, min_y = points[0].y, min_z = points[0].z;
    double max_x = points[0].x, max_y = points[0].y, max_z = points[0].z;

    for (size_t i = 0; i < points.size(); ++i) {
        min_x = std::min(min_x, points[i].x);
        min_y = std::min(min_y, points[i].y);
        min_z = std::min(min_z, points[i].z);
        max_x = std::max(max_x, points[i].x);
        max_y = std::max(max_y, points[i].y);
        max_z = std::max(max_z, points[i].z);
    }

    return bounding_box_3d_t({min_x, min_y, min_z}, {max_x, max_y, max_z});
}

std::string polygon_3d_t::to_string() const {
    std::ostringstream ss;
    ss << "Polygon3D(" << points.size() << " vertices)";
    return ss.str();
}

/* ----------- *
 * affine_3d_t *
 * ----------- */

affine_3d_t::affine_3d_t(std::tuple<std::tuple<double, double, double>,
                                    std::tuple<double, double, double>,
                                    std::tuple<double, double, double>>
                             rot,
                         std::tuple<double, double, double> trans)
    : r00(std::get<0>(std::get<0>(rot))),
      r01(std::get<0>(std::get<1>(rot))),
      r02(std::get<0>(std::get<2>(rot))),
      r10(std::get<1>(std::get<0>(rot))),
      r11(std::get<1>(std::get<1>(rot))),
      r12(std::get<1>(std::get<2>(rot))),
      r20(std::get<2>(std::get<0>(rot))),
      r21(std::get<2>(std::get<1>(rot))),
      r22(std::get<2>(std::get<2>(rot))),
      tx(std::get<0>(trans)),
      ty(std::get<1>(trans)),
      tz(std::get<2>(trans)) {}

affine_3d_t::affine_3d_t(
    std::optional<std::tuple<double, double, double>> rot,
    std::optional<std::tuple<double, double, double>> trans,
    std::optional<double> scale) {
    if (rot) {
        double x = std::get<0>(*rot);
        double y = std::get<1>(*rot);
        double z = std::get<2>(*rot);
        double cx = std::cos(x);
        double sx = std::sin(x);
        double cy = std::cos(y);
        double sy = std::sin(y);
        double cz = std::cos(z);
        double sz = std::sin(z);
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

affine_3d_t affine_3d_t::operator*=(const affine_3d_t &a) {
    double r00_ = r00 * a.r00 + r01 * a.r10 + r02 * a.r20;
    double r01_ = r00 * a.r01 + r01 * a.r11 + r02 * a.r21;
    double r02_ = r00 * a.r02 + r01 * a.r12 + r02 * a.r22;
    double r10_ = r10 * a.r00 + r11 * a.r10 + r12 * a.r20;
    double r11_ = r10 * a.r01 + r11 * a.r11 + r12 * a.r21;
    double r12_ = r10 * a.r02 + r11 * a.r12 + r12 * a.r22;
    double r20_ = r20 * a.r00 + r21 * a.r10 + r22 * a.r20;
    double r21_ = r20 * a.r01 + r21 * a.r11 + r22 * a.r21;
    double r22_ = r20 * a.r02 + r21 * a.r12 + r22 * a.r22;
    double tx_ = tx * a.r00 + ty * a.r10 + tz * a.r20 + a.tx;
    double ty_ = tx * a.r01 + ty * a.r11 + tz * a.r21 + a.ty;
    double tz_ = tx * a.r02 + ty * a.r12 + tz * a.r22 + a.tz;
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

affine_3d_t affine_3d_t::inverse() const {
    double det = r00 * (r11 * r22 - r12 * r21) - r01 * (r10 * r22 - r12 * r20) +
                 r02 * (r10 * r21 - r11 * r20);
    double r00_ = (r11 * r22 - r12 * r21) / det;
    double r01_ = (r02 * r21 - r01 * r22) / det;
    double r02_ = (r01 * r12 - r02 * r11) / det;
    double r10_ = (r12 * r20 - r10 * r22) / det;
    double r11_ = (r00 * r22 - r02 * r20) / det;
    double r12_ = (r02 * r10 - r00 * r12) / det;
    double r20_ = (r10 * r21 - r11 * r20) / det;
    double r21_ = (r01 * r20 - r00 * r21) / det;
    double r22_ = (r00 * r11 - r01 * r10) / det;
    double tx_ = -(r00 * tx + r01 * ty + r02 * tz);
    double ty_ = -(r10 * tx + r11 * ty + r12 * tz);
    double tz_ = -(r20 * tx + r21 * ty + r22 * tz);
    return {{{r00_, r01_, r02_}, {r10_, r11_, r12_}, {r20_, r21_, r22_}},
            {tx_, ty_, tz_}};
}

std::tuple<std::tuple<double, double, double>,
           std::tuple<double, double, double>,
           std::tuple<double, double, double>>
affine_3d_t::rotation() {
    return {{r00, r01, r02}, {r10, r11, r12}, {r20, r21, r22}};
}

std::tuple<double, double, double> affine_3d_t::translation() {
    return {tx, ty, tz};
}

std::string affine_3d_t::to_string() const {
    std::stringstream ss;
    ss << "Affine3D(((" << r00 << ", " << r01 << ", " << r02 << "), (" << r10
       << ", " << r11 << ", " << r12 << "), (" << r20 << ", " << r21 << ", "
       << r22 << ")), (" << tx << ", " << ty << ", " << tz << "))";
    return ss.str();
}

affine_3d_t operator*(const affine_3d_t &a1, const affine_3d_t &a2) {
    affine_3d_t a = a1;
    a *= a2;
    return a;
}

point_3d_t operator>>(const affine_3d_t &a, const point_3d_t &p) {
    double x = a.r00 * p.x + a.r01 * p.y + a.r02 * p.z + a.tx;
    double y = a.r10 * p.x + a.r11 * p.y + a.r12 * p.z + a.ty;
    double z = a.r20 * p.x + a.r21 * p.y + a.r22 * p.z + a.tz;
    return {x, y, z};
}

point_3d_t operator<<(const point_3d_t &p, const affine_3d_t &a) {
    return a >> p;
}

line_3d_t operator>>(const affine_3d_t &a, const line_3d_t &l) {
    point_3d_t p1 = a >> l.p1;
    point_3d_t p2 = a >> l.p2;
    return {p1, p2};
}

line_3d_t operator<<(const line_3d_t &l, const affine_3d_t &a) {
    return a >> l;
}

triangle_3d_t operator>>(const affine_3d_t &a, const triangle_3d_t &p) {
    return {a >> p.p1, a >> p.p2, a >> p.p3};
}

triangle_3d_t operator<<(const triangle_3d_t &p, const affine_3d_t &a) {
    return a >> p;
}

bounding_box_3d_t operator>>(const affine_3d_t &a, const bounding_box_3d_t &b) {
    return {a >> b.min, a >> b.max};
}

bounding_box_3d_t operator<<(const bounding_box_3d_t &b, const affine_3d_t &a) {
    return a >> b;
}

polygon_3d_t operator>>(const affine_3d_t &a, const polygon_3d_t &p) {
    std::vector<point_3d_t> points;
    for (const auto &v : p.points) {
        points.push_back(a >> v);
    }
    return {points};
}

polygon_3d_t operator<<(const polygon_3d_t &p, const affine_3d_t &a) {
    return a >> p;
}

trimesh_3d_t operator>>(const affine_3d_t &a, const trimesh_3d_t &t) {
    std::vector<point_3d_t> points;
    for (const auto &v : t.vertices()) {
        points.push_back(a >> v);
    }
    return {points, t.faces()};
}

trimesh_3d_t operator<<(const trimesh_3d_t &p, const affine_3d_t &a) {
    return a >> p;
}

tetrahedron_3d_t operator>>(const affine_3d_t &a, const tetrahedron_3d_t &t) {
    return {a >> t.p1, a >> t.p2, a >> t.p3, a >> t.p4};
}

tetrahedron_3d_t operator<<(const tetrahedron_3d_t &p, const affine_3d_t &a) {
    return a >> p;
}

tetramesh_3d_t operator>>(const affine_3d_t &a, const tetramesh_3d_t &p) {
    std::vector<point_3d_t> points;
    for (const auto &v : p.vertices()) {
        points.push_back(a >> v);
    }
    return {points, p.volumes()};
}

tetramesh_3d_t operator<<(const tetramesh_3d_t &p, const affine_3d_t &a) {
    return a >> p;
}

/* ------------ *
 * trimesh_3d_t *
 * ------------ */

trimesh_3d_t::trimesh_3d_t(const std::vector<point_3d_t> &vertices,
                           const face_set_t &faces)
    : _vertices(vertices), _faces(faces.begin(), faces.end()) {
    validate();
}

trimesh_3d_t::trimesh_3d_t(const std::vector<point_3d_t> &vertices,
                           const face_list_t &faces)
    : _vertices(vertices), _faces(faces) {
    validate();
}

trimesh_3d_t::trimesh_3d_t(const std::vector<point_3d_t> &vertices) {
    // TODO: Implement Delaunay triangulation in 3D for creating a trimesh
    // from a set of points without associated faces.
    throw std::runtime_error("Not implemented");
}

void trimesh_3d_t::validate() const {
    // Checks that there is at least one face.
    if (_faces.empty()) {
        throw std::runtime_error("No faces");
    }

    // Check that all vertices are valid.
    for (auto &face : _faces) {
        auto &[vi, vj, vk] = face;
        if (vi >= _vertices.size() || vj >= _vertices.size() ||
            vk >= _vertices.size()) {
            throw std::invalid_argument(
                "Invalid face: " + face.to_string() + " for " +
                std::to_string(_vertices.size()) + " vertices");
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
            throw std::runtime_error(
                "Degenerate face; one or more vertices are the same");
        }
    }
}

const std::vector<point_3d_t> &trimesh_3d_t::vertices() const {
    return _vertices;
}

const face_list_t &trimesh_3d_t::faces() const { return _faces; }

triangle_3d_t trimesh_3d_t::get_triangle(const face_t &face) const {
    auto &[vi, vj, vk] = face;
    return {_vertices[vi], _vertices[vj], _vertices[vk]};
}

std::vector<triangle_3d_t> trimesh_3d_t::get_triangles() const {
    std::vector<triangle_3d_t> result;
    for (auto &face : _faces) {
        result.push_back(get_triangle(face));
    }
    return result;
}

double trimesh_3d_t::signed_volume() const {
    point_3d_t center = {0, 0, 0};
    double volume = 0;
    for (auto &triangle : get_triangles()) {
        tetrahedron_3d_t tetr{center, triangle.p1, triangle.p2, triangle.p3};
        volume += tetr.signed_volume();
    }
    return volume;
}

trimesh_3d_t trimesh_3d_t::subdivide(bool at_edges) const {
    std::vector<point_3d_t> vertices = _vertices;
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
                vertices.push_back(v1 + (v2 - v1) / 2.0);
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
            auto center = (_vertices[vi] + _vertices[vj] + _vertices[vk]) / 3.0;
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

tetramesh_3d_t trimesh_3d_t::to_tetramesh() const {
    // Converts a trimesh to a tetramesh.
    // Description of algorithm is here:
    // https://www.youtube.com/watch?v=sNxz_Ht6Y1Y
    throw std::runtime_error("not implemented");
}

std::string trimesh_3d_t::to_string() const {
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
        ss << "    " << face.to_string() << "," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]" << std::endl;
    ss << ")" << std::endl;
    return ss.str();
}

trimesh_3d_t trimesh_3d_t::operator<<(const affine_3d_t &tf) const {
    std::vector<point_3d_t> vertices;
    face_list_t faces = this->_faces;
    std::transform(this->_vertices.begin(), this->_vertices.end(),
                   std::back_inserter(vertices),
                   [&tf](const point_3d_t &vertex) { return vertex << tf; });
    return {vertices, faces};
}

/* ------------ *
 * trimesh_3d_t *
 * ------------ */

tetramesh_3d_t::tetramesh_3d_t(const std::vector<point_3d_t> &vertices,
                               const volume_set_t &volumes)
    : _vertices(vertices), _volumes(volumes.begin(), volumes.end()) {
    validate();
}

tetramesh_3d_t::tetramesh_3d_t(const std::vector<point_3d_t> &vertices,
                               const volume_list_t &volumes)
    : _vertices(vertices), _volumes(volumes) {
    validate();
}

void tetramesh_3d_t::validate() const {
    // Checks that there is at least one face.
    if (_volumes.empty()) {
        throw std::runtime_error("No faces");
    }

    // Check that all vertices are valid.
    for (auto &volume : _volumes) {
        auto &[vi, vj, vk, vl] = volume;
        if (vi >= _vertices.size() || vj >= _vertices.size() ||
            vk >= _vertices.size() || vl >= _vertices.size()) {
            throw std::invalid_argument(
                "Invalid volume: " + volume.to_string() + " for " +
                std::to_string(_vertices.size()) + " vertices");
        }
    }

    // Check that all vertices are used.
    std::vector<bool> used(_vertices.size(), false);
    for (auto &volume : _volumes) {
        auto &[vi, vj, vk, vl] = volume;
        used[vi] = true;
        used[vj] = true;
        used[vk] = true;
        used[vl] = true;
    }
    for (bool b : used) {
        if (!b) {
            throw std::runtime_error("Unused vertex");
        }
    }

    // Check that all volumes are tetrahedrons.
    for (auto &volume : _volumes) {
        auto &[vi, vj, vk, vl] = volume;
        if (vi == vj || vi == vk || vj == vk || vi == vl || vj == vl ||
            vk == vl) {
            throw std::runtime_error(
                "Degenerate volume; points are not unique");
        }
    }

    // Checks that all faces point outwards.
    for (auto &volume : _volumes) {
        auto &[vi, vj, vk, vl] = volume;
        auto &a = _vertices[vi];
        auto &b = _vertices[vj];
        auto &c = _vertices[vk];
        auto &d = _vertices[vl];
        auto n = (b - a).cross(c - a);
        if (n.dot(d - a) < 0) {
            throw std::runtime_error("Volume " + volume.to_string() +
                                     " is not oriented correctly");
        }
    }
}

const std::vector<point_3d_t> &tetramesh_3d_t::vertices() const {
    return _vertices;
}

const volume_list_t &tetramesh_3d_t::volumes() const { return _volumes; }

tetrahedron_3d_t tetramesh_3d_t::get_tetrahedron(const volume_t &volume) const {
    auto &[vi, vj, vk, vl] = volume;
    return {this->_vertices[vi], this->_vertices[vj], this->_vertices[vk],
            this->_vertices[vl]};
}

std::vector<tetrahedron_3d_t> tetramesh_3d_t::get_tetrahedra() const {
    std::vector<tetrahedron_3d_t> tetrahedra;
    for (auto &volume : _volumes) {
        tetrahedra.push_back(get_tetrahedron(volume));
    }
    return tetrahedra;
}

trimesh_3d_t tetramesh_3d_t::to_trimesh() const {
    face_set_t faces;

    // Any face that is paired with it's flipped face is not on the surface.
    for (const auto &volume : _volumes) {
        for (const auto &face : volume.faces()) {
            const auto flipped_face = face.flip();
            if (faces.find(face) != faces.end())
                throw std::runtime_error("Degenerate tetramesh; face " +
                                         face.to_string() + " is used twice");
            if (faces.find(flipped_face) != faces.end()) {
                faces.erase(flipped_face);
            } else {
                faces.insert(face);
            }
        }
    }

    return {_vertices, faces};
}

std::string tetramesh_3d_t::to_string() const {
    std::stringstream ss;
    ss << "Tetramesh3D(" << std::endl;
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
    ss << "  " << _volumes.size() << " volumes = [" << std::endl;
    i = 0;
    for (auto &volume : _volumes) {
        ss << "    " << volume.to_string() << "," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]" << std::endl;
    ss << ")" << std::endl;
    return ss.str();
}

tetramesh_3d_t tetramesh_3d_t::operator<<(const affine_3d_t &tf) const {
    std::vector<point_3d_t> vertices;
    std::transform(this->_vertices.begin(), this->_vertices.end(),
                   std::back_inserter(vertices),
                   [&tf](const point_3d_t &vertex) { return vertex << tf; });
    return {vertices, this->_volumes};
}

tetramesh_3d_t tetramesh_3d_t::operator|(const tetramesh_3d_t &other) const {
    return mesh_union(*this, other);
}

tetramesh_3d_t tetramesh_3d_t::operator&(const tetramesh_3d_t &other) const {
    return mesh_intersection(*this, other);
}

tetramesh_3d_t tetramesh_3d_t::operator-(const tetramesh_3d_t &other) const {
    return mesh_difference(*this, other);
}

void add_3d_types_modules(py::module &m) {
    // Defines the classes first, so that methods can resolve types
    // correctly.
    auto point_3d = py::class_<point_3d_t>(m, "Point3D");
    auto line_3d = py::class_<line_3d_t>(m, "Line3D");
    auto sphere_3d = py::class_<sphere_3d_t>(m, "Sphere3D");
    auto triangle_3d = py::class_<triangle_3d_t>(m, "Triangle3D");
    auto tetrahedron_3d = py::class_<tetrahedron_3d_t>(m, "Tetrahedron3D");
    auto bbox_3d = py::class_<bounding_box_3d_t>(m, "BoundingBox3D");
    auto polygon_3d = py::class_<polygon_3d_t>(m, "Polygon3D");
    auto affine_3d = py::class_<affine_3d_t>(m, "Affine3D");
    auto trimesh_3d =
        py::class_<trimesh_3d_t, std::shared_ptr<trimesh_3d_t>>(m, "Trimesh3D");
    auto tetramesh_3d =
        py::class_<tetramesh_3d_t, std::shared_ptr<tetramesh_3d_t>>(
            m, "Tetramesh3D");

    // Defines Point3D methods.
    point_3d
        .def(py::init<double, double, double>(), "A point in 3D space", "x"_a,
             "y"_a, "z"_a)
        .def_readwrite("x", &point_3d_t::x, "The point's x coordinate")
        .def_readwrite("y", &point_3d_t::y, "The point's y coordinate")
        .def_readwrite("z", &point_3d_t::z, "The point's z coordinate")
        .def("__str__", &point_3d_t::to_string, py::is_operator())
        .def("__repr__", &point_3d_t::to_string, py::is_operator())
        .def("__hash__", &point_3d_hash_fn, py::is_operator())
        .def("__add__",
             py::overload_cast<const point_3d_t &, const point_3d_t &>(
                 &operator+),
             "Adds two points together", "other"_a, py::is_operator())
        .def("__iadd__", &point_3d_t::operator+=, "Adds a point to this point",
             "other"_a, py::is_operator())
        .def("__sub__",
             py::overload_cast<const point_3d_t &, const point_3d_t &>(
                 &operator-),
             "Subtracts two points", "other"_a, py::is_operator())
        .def("__isub__", &point_3d_t::operator-=,
             "Subtracts a point from this point", "other"_a, py::is_operator())
        .def("__mul__",
             py::overload_cast<const point_3d_t &, const point_3d_t &>(
                 &operator*),
             "Vector multiplication", "other"_a, py::is_operator())
        .def("__mul__",
             py::overload_cast<const point_3d_t &, double>(&operator*),
             "Multiplies a point by a scalar", "other"_a, py::is_operator())
        .def("__mul__",
             py::overload_cast<double, const point_3d_t &>(&operator*),
             "Multiplies a point by a scalar", "other"_a, py::is_operator())
        .def("__imul__",
             py::overload_cast<const point_3d_t &>(&point_3d_t::operator*=),
             "Vector multiplication", "other"_a, py::is_operator())
        .def("__imul__", py::overload_cast<double>(&point_3d_t::operator*=),
             "Multiplies this point by a scalar", "other"_a, py::is_operator())
        .def("__truediv__",
             py::overload_cast<const point_3d_t &, const point_3d_t &>(
                 &operator/),
             "Vector division", "other"_a, py::is_operator())
        .def("__truediv__",
             py::overload_cast<const point_3d_t &, double>(&operator/),
             "Divides a point by a scalar", "other"_a, py::is_operator())
        .def("__itruediv__",
             py::overload_cast<const point_3d_t &>(&point_3d_t::operator/=),
             "Vector division", "other"_a, py::is_operator())
        .def("__itruediv__", py::overload_cast<double>(&point_3d_t::operator/=),
             "Divides this point by a scalar", "other"_a, py::is_operator())
        .def("__eq__", &point_3d_t::operator==,
             "Checks if two points are equal", "other"_a, py::is_operator())
        .def("__ne__", &point_3d_t::operator!=,
             "Checks if two points are not equal", "other"_a, py::is_operator())
        .def("__lt__", &point_3d_t::operator<,
             "Checks if this point is less than another", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const point_3d_t &, const affine_3d_t &>(
                 operator<<),
             "Applies a affine transformation to the point", "other"_a,
             py::is_operator())
        .def("__ilshift__", &point_3d_t::operator<<=,
             "Applies a affine transformation to the point", "other"_a,
             py::is_operator())
        .def("determinant", &point_3d_t::determinant,
             "The determinant of a 3x3 matrix with two other points", "a"_a,
             "b"_a)
        .def("length", &point_3d_t::length, "The point's length")
        .def("dot", &point_3d_t::dot, "The dot product of the point", "other"_a)
        .def("cross", &point_3d_t::cross, "The cross product of the point",
             "other"_a)
        .def("barycentric_coordinates", &point_3d_t::barycentric_coordinates,
             "The barycentric coordinates of the point relative to a "
             "triangle",
             "t"_a)
        .def("is_inside_bounding_box", &point_3d_t::is_inside_bounding_box,
             "Checks if the point is inside a bounding box", "bb"_a)
        .def("distance_to_point", &point_3d_t::distance_to_point,
             "The distance to another point", "other"_a)
        .def("distance_to_line", &point_3d_t::distance_to_line,
             "The distance to a line", "line"_a)
        .def("distance_to_triangle", &point_3d_t::distance_to_triangle,
             "The distance to a triangle", "triangle"_a)
        .def("is_coplanar", &point_3d_t::is_coplanar,
             "Checks if the point is coplanar with a triangle", "t"_a)
        .def("project_to_line", &point_3d_t::project_to_line,
             "Projects the point onto a line", "l"_a)
        .def("project_to_triangle", &point_3d_t::project_to_triangle,
             "Projects the point onto a triangle", "t"_a);

    // Defines Line3D methods.
    line_3d
        .def(py::init<const point_3d_t &, const point_3d_t &>(),
             "A line in 3D space", "p1"_a, "p2"_a)
        .def_readwrite("p1", &line_3d_t::p1, "The line's first point")
        .def_readwrite("p2", &line_3d_t::p2, "The line's second point")
        .def("__str__", &line_3d_t::to_string, py::is_operator())
        .def("__repr__", &line_3d_t::to_string, py::is_operator())
        .def("__eq__", &line_3d_t::operator==, "Checks if two lines are equal",
             "other"_a, py::is_operator())
        .def("__ne__", &line_3d_t::operator!=,
             "Checks if two lines are not equal", "other"_a, py::is_operator())
        .def("__lshift__",
             py::overload_cast<const line_3d_t &, const affine_3d_t &>(
                 &operator<<),
             "Applies a affine transformation to the line", "other"_a,
             py::is_operator())
        .def("__ilshift__", &line_3d_t::operator<<=,
             "Applies a affine transformation to the line", "other"_a,
             py::is_operator())
        .def("distance_to_point", &line_3d_t::distance_to_point,
             "The distance to another point", "other"_a)
        .def("distance_to_line", &line_3d_t::distance_to_line,
             "The distance to another line", "other"_a)
        .def("closest_points", &line_3d_t::closest_points,
             "The closest points between two lines; returns None if the "
             "lines "
             "are parallel",
             "other"_a)
        .def("line_intersection", &line_3d_t::line_intersection,
             "The intersection point between two lines; returns None if the "
             "lines don't intersect",
             "other"_a)
        .def("intersects_triangle", &line_3d_t::intersects_triangle,
             "Checks if the line intersects a triangle", "t"_a)
        .def("triangle_intersection", &line_3d_t::triangle_intersection,
             "The intersection point between a line and a triangle; returns "
             "None if the line doesn't intersect the triangle",
             "t"_a)
        .def("intersects_bounding_box", &line_3d_t::intersects_bounding_box,
             "Checks if the line intersects a bounding box", "bb"_a);

    // Defines Sphere3D methods.
    sphere_3d
        .def(py::init<const point_3d_t &, double>(),
             "A sphere with a given center and radius", "center"_a, "radius"_a)
        .def(py::init<const tetrahedron_3d_t &>(),
             "The circumsphere of a tetrahedron", "t"_a)
        .def_readwrite("center", &sphere_3d_t::center, "The sphere's center")
        .def_readwrite("radius", &sphere_3d_t::radius, "The sphere's radius")
        .def("__str__", &sphere_3d_t::to_string, py::is_operator())
        .def("__repr__", &sphere_3d_t::to_string, py::is_operator())
        .def("__eq__", &sphere_3d_t::operator==,
             "Checks if two spheres are equal", "other"_a, py::is_operator())
        .def("__ne__", &sphere_3d_t::operator!=,
             "Checks if two spheres are not equal", "other"_a,
             py::is_operator())
        .def_property_readonly("volume", &sphere_3d_t::volume,
                               "The sphere's volume")
        .def("contains_point", &sphere_3d_t::contains_point,
             "Checks if the sphere contains a point", "p"_a);

    // Defines Triangle3D methods.
    triangle_3d
        .def(py::init<const point_3d_t &, const point_3d_t &,
                      const point_3d_t &>(),
             "A triangle in 3D space", "p1"_a, "p2"_a, "p3"_a)
        .def_readwrite("p1", &triangle_3d_t::p1, "The triangle's first point")
        .def_readwrite("p2", &triangle_3d_t::p2, "The triangle's second point")
        .def_readwrite("p3", &triangle_3d_t::p3, "The triangle's third point")
        .def("__str__", &triangle_3d_t::to_string, py::is_operator())
        .def("__repr__", &triangle_3d_t::to_string, py::is_operator())
        .def("__eq__", &triangle_3d_t::operator==,
             "Checks if two triangles are equal", "other"_a, py::is_operator())
        .def("__ne__", &triangle_3d_t::operator!=,
             "Checks if two triangles are not equal", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const triangle_3d_t &, const affine_3d_t &>(
                 operator<<),
             "Applies a affine transformation to the triangle", "other"_a,
             py::is_operator())
        .def("__ilshift__", &triangle_3d_t::operator<<=,
             "Applies a affine transformation to the triangle", "other"_a,
             py::is_operator())
        .def("area", &triangle_3d_t::area, "The triangle's area")
        .def("normal", &triangle_3d_t::normal, "The triangle's normal")
        .def("center", &triangle_3d_t::center, "The triangle's center")
        .def("vertices", &triangle_3d_t::vertices, "The triangle's vertices")
        .def("edges", &triangle_3d_t::edges, "The triangle's edges")
        .def("distance_to_point", &triangle_3d_t::distance_to_point,
             "The distance to another point", "other"_a)
        .def("is_coplanar", &triangle_3d_t::is_coplanar,
             "Checks if the triangle is coplanar with another triangle",
             "other"_a)
        .def("point_from_barycentric_coords",
             &triangle_3d_t::point_from_barycentric_coords,
             "The point from barycentric coordinates", "b"_a);

    // Defines Tetrahedron3D methods.
    tetrahedron_3d
        .def(py::init<const point_3d_t &, const point_3d_t &,
                      const point_3d_t &, const point_3d_t &>(),
             "Creates a tetrahedron from four points", "a"_a, "b"_a, "c"_a,
             "d"_a)
        .def_readwrite("p1", &tetrahedron_3d_t::p1,
                       "The tetrahedron's first point")
        .def_readwrite("p2", &tetrahedron_3d_t::p2,
                       "The tetrahedron's second point")
        .def_readwrite("p3", &tetrahedron_3d_t::p3,
                       "The tetrahedron's third point")
        .def_readwrite("p4", &tetrahedron_3d_t::p4,
                       "The tetrahedron's fourth point")
        .def("__str__", &tetrahedron_3d_t::to_string, py::is_operator())
        .def("__repr__", &tetrahedron_3d_t::to_string, py::is_operator())
        .def("__eq__", &tetrahedron_3d_t::operator==,
             "Checks if two tetrahedrons are equal", "other"_a,
             py::is_operator())
        .def("__ne__", &tetrahedron_3d_t::operator!=,
             "Checks if two tetrahedrons are not equal", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const tetrahedron_3d_t &, const affine_3d_t &>(
                 &operator<<),
             "Applies a affine transformation to the tetrahedron",
             "transform"_a, py::is_operator())
        .def("signed_volume", &tetrahedron_3d_t::signed_volume,
             "The signed volume of the tetrahedron")
        .def_property_readonly("faces", &tetrahedron_3d_t::faces,
                               "The faces of the tetrahedron")
        .def("surface_area", &tetrahedron_3d_t::surface_area,
             "The surface area of the tetrahedron")
        .def("circumcenter", &tetrahedron_3d_t::circumcenter,
             "The circumcenter of the tetrahedron")
        .def("incenter", &tetrahedron_3d_t::incenter,
             "The incenter of the tetrahedron")
        .def("centroid", &tetrahedron_3d_t::centroid,
             "The centroid of the tetrahedron")
        .def("circumsphere", &tetrahedron_3d_t::circumsphere,
             "The circumsphere of the tetrahedron");

    // Defines BoundingBox3D methods.
    bbox_3d
        .def(py::init<const point_3d_t &, const point_3d_t &>(),
             "Creates a bounding box from two points", "min"_a, "max"_a)
        .def(py::init<const std::vector<point_3d_t> &>(),
             "Creates a bounding box from a set of points", "points"_a)
        .def(py::init<const std::vector<line_3d_t> &>(),
             "Creates a bounding box from a set of lines", "lines"_a)
        .def(py::init<const std::vector<triangle_3d_t> &>(),
             "Creates a bounding box from a set of triangles", "triangles"_a)
        .def(py::init<const std::vector<bounding_box_3d_t> &>(),
             "Creates a bounding box from a set of bounding boxes", "boxes"_a)
        .def_readwrite("min", &bounding_box_3d_t::min,
                       "The bounding box's minimum point")
        .def_readwrite("max", &bounding_box_3d_t::max,
                       "The bounding box's maximum point")
        .def("__str__", &bounding_box_3d_t::to_string, py::is_operator())
        .def("__repr__", &bounding_box_3d_t::to_string, py::is_operator())
        .def("__eq__", &bounding_box_3d_t::operator==,
             "Checks if two bounding boxes are equal", "other"_a,
             py::is_operator())
        .def("__ne__", &bounding_box_3d_t::operator!=,
             "Checks if two bounding boxes are not equal", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const bounding_box_3d_t &, const affine_3d_t &>(
                 &operator<<),
             "Applies a affine transformation to the bounding box",
             "transform"_a, py::is_operator())
        .def("__ilshift__", &bounding_box_3d_t::operator<<=,
             "Applies a affine transformation to the bounding box", "other"_a,
             py::is_operator())
        .def("triangle_faces", &bounding_box_3d_t::triangle_faces,
             "The faces of the triangles that make up the bounding box")
        .def("tetrahedron_volumes", &bounding_box_3d_t::tetrahedron_volumes,
             "The volumes of the triangles that make up the bounding box")
        .def("corners", &bounding_box_3d_t::corners,
             "The bounding box's corners")
        .def("triangles", &bounding_box_3d_t::triangles,
             "The bounding box's triangles")
        .def("center", &bounding_box_3d_t::center, "The bounding box's center")
        .def("volume", &bounding_box_3d_t::volume, "The bounding box's volume");

    // Defines Polygon3D methods.
    polygon_3d
        .def(py::init<const std::vector<point_3d_t> &>(),
             "Creates a polygon from a set of points", "points"_a)
        .def_readwrite("points", &polygon_3d_t::points, "The polygon's points")
        .def("__str__", &polygon_3d_t::to_string, py::is_operator())
        .def("__repr__", &polygon_3d_t::to_string, py::is_operator())
        .def("__eq__", &polygon_3d_t::operator==,
             "Checks if two polygons are equal", "other"_a, py::is_operator())
        .def("__ne__", &polygon_3d_t::operator!=,
             "Checks if two polygons are not equal", "other"_a,
             py::is_operator())
        .def("__lshift__",
             py::overload_cast<const polygon_3d_t &, const affine_3d_t &>(
                 &operator<<),
             "Applies a affine transformation to the polygon", "transform"_a,
             py::is_operator())
        .def("__ilshift__", &polygon_3d_t::operator<<=,
             "Applies a affine transformation to the polygon", "other"_a,
             py::is_operator())
        .def("area", &polygon_3d_t::area, "The polygon's area")
        .def("normal", &polygon_3d_t::normal, "The polygon's normal")
        .def("center", &polygon_3d_t::center, "The polygon's center")
        .def("bounding_box", &polygon_3d_t::bounding_box,
             "The polygon's bounding box");

    // Defines Affine3D methods.
    affine_3d
        .def(py::init<std::tuple<std::tuple<double, double, double>,
                                 std::tuple<double, double, double>,
                                 std::tuple<double, double, double>>,
                      std::tuple<double, double, double>>(),
             "Creates an affine transformation from a rotation and translation "
             "matrices",
             "rot"_a, "trans"_a)
        .def(py::init<std::optional<std::tuple<double, double, double>>,
                      std::optional<std::tuple<double, double, double>>,
                      std::optional<double>>(),
             "Initialize affine transformation from rotation and translation "
             "vectors",
             "rot"_a = std::nullopt, "trans"_a = std::nullopt,
             "scale"_a = std::nullopt)
        .def("__str__", &affine_3d_t::to_string, py::is_operator())
        .def("__repr__", &affine_3d_t::to_string, py::is_operator())
        .def("__matmul__",
             py::overload_cast<const affine_3d_t &, const affine_3d_t &>(
                 &operator*),
             "Combine two affine transformations", "transform"_a,
             py::is_operator())
        .def("__imatmul__", &affine_3d_t::operator*=,
             "Applies an affine transformation to a point", "other"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const point_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a point", "point"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const line_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a line", "line"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const triangle_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a triangle", "triangle"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const bounding_box_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a bounding box", "bbox"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const polygon_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a polygon", "poly"_a,
             py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const trimesh_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a triangular mesh",
             "trimesh"_a, py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const tetrahedron_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a tetrahedron",
             "tetrahedron"_a, py::is_operator())
        .def("__rshift__",
             py::overload_cast<const affine_3d_t &, const tetramesh_3d_t &>(
                 &operator>>),
             "Applies an affine transformation to a tetrahedron mesh",
             "tetramesh"_a, py::is_operator())
        .def("inverse", &affine_3d_t::inverse,
             "The inverse of the affine transformation")
        .def_property_readonly("rotation", &affine_3d_t::rotation,
                               "The affine transformation's rotation matrix")
        .def_property_readonly(
            "translation", &affine_3d_t::translation,
            "The affine transformation's translation matrix");

    // Defines Trimesh3D methods.
    trimesh_3d
        // .def(py::init<vertices3d_t &, face_set_t &>(),
        //      "Creates a trimesh from vertices and faces", "vertices"_a,
        //      "faces"_a)
        .def_property_readonly("vertices", &trimesh_3d_t::vertices,
                               "The mesh vertices")
        .def_property_readonly("faces", &trimesh_3d_t::faces, "The mesh faces")
        .def("get_triangle", &trimesh_3d_t::get_triangle,
             "Gets a mesh triangle from a face", "face"_a)
        .def("get_triangles", &trimesh_3d_t::get_triangles,
             "Gets all mesh triangles")
        .def("signed_volume", &trimesh_3d_t::signed_volume,
             "Computes the signed volume of the mesh")
        .def("subdivide", &trimesh_3d_t::subdivide,
             "Subdivides the mesh into smaller triangles", "at_edges"_a = true)
        .def("__str__", &trimesh_3d_t::to_string, py::is_operator())
        .def("__repr__", &trimesh_3d_t::to_string, py::is_operator())
        .def("__lshift__", &trimesh_3d_t::operator<<,
             "Applies affine transformation to 3D mesh", "affine"_a,
             py::is_operator());

    // Defines Tetramesh3D methods.
    tetramesh_3d
        // .def(py::init<vertices3d_t &, volume_set_t &>(),
        //      "Creates a trimesh from vertices and volumes", "vertices"_a,
        //      "volumes"_a)
        .def_property_readonly("vertices", &tetramesh_3d_t::vertices,
                               "The mesh vertices")
        .def_property_readonly("volumes", &tetramesh_3d_t::volumes,
                               "The mesh volumes")
        .def("get_tetrahedron", &tetramesh_3d_t::get_tetrahedron,
             "Gets a mesh tetrahedron from a volume", "volume"_a)
        .def("get_tetrahedra", &tetramesh_3d_t::get_tetrahedra,
             "Gets all mesh tetrahedrons")
        .def("to_trimesh", &tetramesh_3d_t::to_trimesh,
             "Converts the tetrahedral mesh to a triangular mesh")
        .def("union", &tetramesh_3d_t::operator|,
             "Computes the union of two 3D meshes", "other"_a)
        .def("__or__", &tetramesh_3d_t::operator|,
             "Computes the union of two 3D meshes", "other"_a,
             py::is_operator())
        .def("intersection", &tetramesh_3d_t::operator&,
             "Computes the intersection of two 3D meshes", "other"_a)
        .def("__and__", &tetramesh_3d_t::operator&,
             "Computes the intersection of two 3D meshes", "other"_a,
             py::is_operator())
        .def("difference", &tetramesh_3d_t::operator-,
             "Computes the difference of two 3D meshes", "other"_a)
        .def("__sub__", &tetramesh_3d_t::operator-,
             "Computes the difference of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__str__", &tetramesh_3d_t::to_string, py::is_operator())
        .def("__repr__", &tetramesh_3d_t::to_string, py::is_operator())
        .def("__lshift__", &tetramesh_3d_t::operator<<,
             "Applies affine transformation to 3D mesh", "affine"_a,
             py::is_operator());
}

}  // namespace trimesh
