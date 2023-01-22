#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <unordered_set>

#include "../types.h"

namespace py = pybind11;

namespace trimesh {

struct point_3d_t;
struct line_3d_t;
struct circumcircle_3d_t;
struct triangle_3d_t;
struct bounding_box_3d_t;
struct polygon_3d_t;
struct affine_3d_t;
struct trimesh_3d_t;

struct point_3d_t {
    float x, y, z;

    point_3d_t operator+=(const point_3d_t &p);
    point_3d_t operator-=(const point_3d_t &p);
    point_3d_t operator*=(const point_3d_t &p);
    point_3d_t operator*=(float s);
    point_3d_t operator/=(const point_3d_t &p);
    point_3d_t operator/=(float s);
    bool operator==(const point_3d_t &p) const;
    bool operator!=(const point_3d_t &p) const;
    bool operator<(const point_3d_t &p) const;
    point_3d_t operator<<=(const affine_3d_t &q);

    point_3d_t normalize() const;
    float determinant(const point_3d_t &a, const point_3d_t &b) const;
    float length() const;
    float dot(const point_3d_t &other) const;
    point_3d_t cross(const point_3d_t &other) const;

    barycentric_coordinates_t barycentric_coordinates(
        const triangle_3d_t &t) const;
    bool is_inside_bounding_box(const bounding_box_3d_t &bb) const;

    float distance_to_point(const point_3d_t &other) const;
    float distance_to_line(const line_3d_t &l) const;
    float distance_to_triangle(const triangle_3d_t &t) const;
    bool is_coplanar(const triangle_3d_t &t) const;

    std::optional<point_3d_t> project_to_line(const line_3d_t &l) const;
    std::optional<point_3d_t> project_to_triangle(const triangle_3d_t &t) const;
    bool projects_to_triangle(const triangle_3d_t &t) const;

    std::string to_string() const;
};

point_3d_t operator+(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator-(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator*(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator*(float s, const point_3d_t &p);
point_3d_t operator*(const point_3d_t &p, float s);
point_3d_t operator/(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator/(const point_3d_t &p, float s);
point_3d_t operator<<(const point_3d_t &p, const affine_3d_t &q);

float triangle_signed_volume(const point_3d_t &a, const point_3d_t &b,
                             const point_3d_t &c, const point_3d_t &d);

struct line_3d_t {
    point_3d_t p1, p2;

    bool operator==(const line_3d_t &l) const;
    bool operator!=(const line_3d_t &l) const;
    line_3d_t operator<<=(const affine_3d_t &q);

    std::optional<std::tuple<point_3d_t, point_3d_t>> closest_points(
        const line_3d_t &p) const;
    std::optional<point_3d_t> line_intersection(const line_3d_t &l) const;
    bool intersects_triangle(const triangle_3d_t &t) const;
    std::optional<point_3d_t> triangle_intersection(
        const triangle_3d_t &t) const;
    bool intersects_bounding_box(const bounding_box_3d_t &b) const;

    float distance_to_point(const point_3d_t &p) const;
    float distance_to_line(const line_3d_t &l) const;

    std::string to_string() const;
};

struct circumcircle_3d_t {
    point_3d_t center;
    float radius;

    bool operator==(const circumcircle_3d_t &c) const;
    bool operator!=(const circumcircle_3d_t &c) const;

    bool contains_point(const point_3d_t &p) const;

    std::string to_string() const;
};

struct triangle_3d_t {
    point_3d_t p1, p2, p3;

    bool operator==(const triangle_3d_t &t) const;
    bool operator!=(const triangle_3d_t &t) const;
    triangle_3d_t operator<<=(const affine_3d_t &q);

    float area() const;
    point_3d_t center() const;
    point_3d_t normal() const;
    std::vector<point_3d_t> vertices() const;
    std::vector<line_3d_t> edges() const;

    float distance_to_point(const point_3d_t &p) const;
    bool contains_point(const point_3d_t &p) const;
    bool is_coplanar(const triangle_3d_t &t) const;
    circumcircle_3d_t circumcircle() const;
    point_3d_t point_from_barycentric_coords(
        const barycentric_coordinates_t &b) const;
    std::vector<point_3d_t> triangle_intersection(const triangle_3d_t &t) const;

    std::string to_string() const;
};

struct bounding_box_3d_t {
    point_3d_t min, max;

    bounding_box_3d_t();
    bounding_box_3d_t(const point_3d_t &min, const point_3d_t &max);
    bounding_box_3d_t(const std::vector<point_3d_t> &ps);
    bounding_box_3d_t(const std::vector<line_3d_t> &lines);
    bounding_box_3d_t(const std::vector<triangle_3d_t> &triangles);
    bounding_box_3d_t(const std::vector<bounding_box_3d_t> &bboxes);

    bool operator==(const bounding_box_3d_t &bb) const;
    bool operator!=(const bounding_box_3d_t &bb) const;
    bounding_box_3d_t operator<<=(const affine_3d_t &q);

    std::vector<face_t> triangle_indices() const;
    std::vector<point_3d_t> corners() const;
    std::vector<line_3d_t> edges() const;
    std::vector<triangle_3d_t> triangles() const;

    point_3d_t center() const;
    float volume() const;

    std::string to_string() const;
};

struct polygon_3d_t {
    std::vector<point_3d_t> points;

    polygon_3d_t(const std::vector<point_3d_t> &points);

    bool operator==(const polygon_3d_t &p) const;
    bool operator!=(const polygon_3d_t &p) const;
    polygon_3d_t operator<<=(const affine_3d_t &q);

    float area() const;
    point_3d_t normal() const;
    point_3d_t center() const;
    bounding_box_3d_t bounding_box() const;

    std::string to_string() const;
};

struct affine_3d_t {
    // Represents the affine transformation:
    // r00 r01 r02 tx
    // r10 r11 r12 ty
    // r20 r21 r22 tz
    // 0   0   0   1

    float r00, r01, r02, r10, r11, r12, r20, r21, r22, tx, ty, tz;

    affine_3d_t(float r00, float r01, float r02, float r10, float r11,
                float r12, float r20, float r21, float r22, float tx, float ty,
                float tz);
    affine_3d_t(
        std::optional<std::tuple<float, float, float>> rot = std::nullopt,
        std::optional<std::tuple<float, float, float>> trans = std::nullopt,
        std::optional<float> scale = std::nullopt);

    affine_3d_t operator*=(const affine_3d_t &a);

    affine_3d_t inverse() const;

    std::string to_string() const;
};

affine_3d_t operator*(const affine_3d_t &a1, const affine_3d_t &a2);
point_3d_t operator>>(const affine_3d_t &a, const point_3d_t &p);
point_3d_t operator<<(const point_3d_t &p, const affine_3d_t &a);
line_3d_t operator>>(const affine_3d_t &a, const line_3d_t &l);
line_3d_t operator<<(const line_3d_t &l, const affine_3d_t &a);
triangle_3d_t operator>>(const affine_3d_t &a, const triangle_3d_t &t);
triangle_3d_t operator<<(const triangle_3d_t &t, const affine_3d_t &a);
bounding_box_3d_t operator>>(const affine_3d_t &a, const bounding_box_3d_t &bb);
bounding_box_3d_t operator<<(const bounding_box_3d_t &bb, const affine_3d_t &a);
polygon_3d_t operator>>(const affine_3d_t &a, const polygon_3d_t &p);
polygon_3d_t operator<<(const polygon_3d_t &p, const affine_3d_t &a);

struct trimesh_3d_t {
   private:
    const std::vector<point_3d_t> _vertices;
    const face_list_t _faces;
    void validate() const;

   public:
    trimesh_3d_t(const std::vector<point_3d_t> &vertices,
                 const face_set_t &faces);
    trimesh_3d_t(const std::vector<point_3d_t> &vertices,
                 const face_list_t &faces);

    const std::vector<point_3d_t> &vertices() const;
    const face_list_t &faces() const;
    triangle_3d_t get_triangle(const face_t &face) const;
    std::vector<triangle_3d_t> get_triangles() const;
    float signed_volume() const;
    trimesh_3d_t flip_inside_out() const;
    trimesh_3d_t subdivide(bool at_edges = true) const;
    std::string to_string() const;

    trimesh_3d_t operator<<(const affine_3d_t &tf) const;
    trimesh_3d_t operator|(const trimesh_3d_t &other) const;
    trimesh_3d_t operator&(const trimesh_3d_t &other) const;
    trimesh_3d_t operator-(const trimesh_3d_t &other) const;
};

void add_3d_types_modules(py::module &m);

}  // namespace trimesh
