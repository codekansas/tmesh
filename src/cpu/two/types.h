#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <unordered_set>

#include "../types.h"

namespace py = pybind11;

namespace trimesh {

struct point_2d_t;
struct line_2d_t;
struct triangle_2d_t;
struct bounding_box_2d_t;
struct polygon_2d_t;
struct affine_2d_t;
struct trimesh_2d_t;

struct point_2d_t {
    float x, y;

    point_2d_t operator+=(const point_2d_t &p);
    point_2d_t operator-=(const point_2d_t &p);
    point_2d_t operator*=(const point_2d_t &p);
    point_2d_t operator*=(float s);
    point_2d_t operator/=(const point_2d_t &p);
    point_2d_t operator/=(float s);
    bool operator==(const point_2d_t &p) const;
    bool operator!=(const point_2d_t &p) const;
    bool operator<(const point_2d_t &p) const;
    point_2d_t operator<<=(const affine_2d_t &a);

    point_2d_t normalize() const;
    point_2d_t rotate(float angle) const;
    float determinant(const point_2d_t &other) const;
    float length() const;
    float dot(const point_2d_t &other) const;
    float cross(const point_2d_t &other) const;
    float angle(const point_2d_t &other) const;

    barycentric_coordinates_t barycentric_coordinates(
        const triangle_2d_t &t) const;
    bool is_inside_triangle(const triangle_2d_t &t) const;
    bool is_inside_bounding_box(const bounding_box_2d_t &bb) const;

    float distance_to_point(const point_2d_t &other) const;
    float distance_to_line(const line_2d_t &l) const;
    float distance_to_triangle(const triangle_2d_t &t) const;
    float distance_to_bounding_box(const bounding_box_2d_t &bb) const;

    std::optional<point_2d_t> project_to_line(const line_2d_t &l) const;

    std::string to_string() const;
};

point_2d_t operator+(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator-(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator*(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator*(float s, const point_2d_t &p);
point_2d_t operator*(const point_2d_t &p, float s);
point_2d_t operator/(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator/(const point_2d_t &p, float s);

bool is_convex(const point_2d_t &a, const point_2d_t &b, const point_2d_t &c);

struct line_2d_t {
    point_2d_t p1, p2;

    bool operator==(const line_2d_t &l) const;
    bool operator!=(const line_2d_t &l) const;
    bool operator<(const line_2d_t &p) const;
    line_2d_t operator<<=(const affine_2d_t &a);

    point_2d_t closest_point(const point_2d_t &p) const;
    std::optional<point_2d_t> line_intersection(const line_2d_t &l) const;
    bool intersects_triangle(const triangle_2d_t &t) const;
    std::vector<point_2d_t> triangle_intersection(const triangle_2d_t &t) const;
    bool intersects_bounding_box(const bounding_box_2d_t &b) const;

    float distance_to_point(const point_2d_t &p) const;
    float distance_to_line(const line_2d_t &l) const;
    float distance_to_triangle(const triangle_2d_t &t) const;
    float distance_to_bounding_box(const bounding_box_2d_t &bb) const;

    std::string to_string() const;
};

struct triangle_2d_t {
    point_2d_t p1, p2, p3;

    bool operator==(const triangle_2d_t &t) const;
    bool operator!=(const triangle_2d_t &t) const;
    bool operator<(const triangle_2d_t &p) const;
    triangle_2d_t operator<<=(const affine_2d_t &a);

    float area() const;
    point_2d_t center() const;
    std::vector<point_2d_t> vertices() const;
    std::vector<line_2d_t> edges() const;
    bool is_clockwise() const;

    bool contains_point(const point_2d_t &p) const;
    bool contains_triangle(const triangle_2d_t &t) const;
    bool intersects_bounding_box(const bounding_box_2d_t &bb) const;
    bool intersects_triangle(const triangle_2d_t &t) const;
    std::vector<point_2d_t> triangle_intersection(const triangle_2d_t &t) const;
    float distance_to_point(const point_2d_t &p) const;
    float distance_to_line(const line_2d_t &l) const;
    float distance_to_triangle(const triangle_2d_t &t) const;
    float distance_to_bounding_box(const bounding_box_2d_t &bb) const;
    point_2d_t point_from_barycentric_coords(
        const barycentric_coordinates_t &b) const;

    std::string to_string() const;
};

struct bounding_box_2d_t {
    point_2d_t min, max;

    bounding_box_2d_t();
    bounding_box_2d_t(const point_2d_t &min, const point_2d_t &max);
    bounding_box_2d_t(const std::vector<point_2d_t> &points);
    bounding_box_2d_t(const std::vector<line_2d_t> &lines);
    bounding_box_2d_t(const std::vector<triangle_2d_t> &triangles);
    bounding_box_2d_t(const std::vector<bounding_box_2d_t> &bboxes);

    bool operator==(const bounding_box_2d_t &bb) const;
    bool operator!=(const bounding_box_2d_t &bb) const;
    bounding_box_2d_t operator<<=(const affine_2d_t &a);

    float area() const;
    point_2d_t center() const;
    std::vector<point_2d_t> vertices() const;
    std::vector<line_2d_t> edges() const;

    bool intersects_triangle(const triangle_2d_t &t) const;
    bool contains_point(const point_2d_t &p) const;
    bool contains_triangle(const triangle_2d_t &t) const;
    float distance_to_point(const point_2d_t &p) const;
    float distance_to_line(const line_2d_t &l) const;
    float distance_to_triangle(const triangle_2d_t &t) const;
    float distance_to_bounding_box(const bounding_box_2d_t &bb) const;

    std::string to_string() const;
};

struct polygon_2d_t {
    std::vector<point_2d_t> points;

    polygon_2d_t(const std::vector<point_2d_t> &points);

    bool operator==(const polygon_2d_t &p) const;
    bool operator!=(const polygon_2d_t &p) const;
    polygon_2d_t operator<<=(const affine_2d_t &a);
    polygon_2d_t operator+(const polygon_2d_t &p) const;
    polygon_2d_t operator+=(const polygon_2d_t &p);

    float signed_area() const;
    bool is_clockwise() const;
    void reverse();
    polygon_2d_t convex_hull() const;
    bounding_box_2d_t bounding_box() const;
    point_2d_t center() const;
    bool is_ear(int vi, int vj, int vk) const;
    trimesh_2d_t get_trimesh(bool is_convex = false) const;

    std::string to_string() const;
};

struct affine_2d_t {
    // Represents the affine transformation:
    // r00 r01 tx
    // r10 r11 ty
    // 0   0   1

    float r00, r01, r10, r11, tx, ty;

    affine_2d_t(float r00, float r01, float r10, float r11, float tx, float ty);
    affine_2d_t(std::optional<float> rot = std::nullopt,
                std::optional<std::tuple<float, float>> trans = std::nullopt,
                std::optional<float> scale = std::nullopt);

    affine_2d_t operator*=(const affine_2d_t &a);

    affine_2d_t inverse() const;

    std::string to_string() const;
};

affine_2d_t operator*(const affine_2d_t &a1, const affine_2d_t &a2);
point_2d_t operator>>(const affine_2d_t &a, const point_2d_t &p);
point_2d_t operator<<(const point_2d_t &p, const affine_2d_t &a);
line_2d_t operator>>(const affine_2d_t &a, const line_2d_t &l);
line_2d_t operator<<(const line_2d_t &l, const affine_2d_t &a);
triangle_2d_t operator>>(const affine_2d_t &a, const triangle_2d_t &t);
triangle_2d_t operator<<(const triangle_2d_t &t, const affine_2d_t &a);
bounding_box_2d_t operator>>(const affine_2d_t &a, const bounding_box_2d_t &bb);
bounding_box_2d_t operator<<(const bounding_box_2d_t &bb, const affine_2d_t &a);
polygon_2d_t operator>>(const affine_2d_t &a, const polygon_2d_t &p);
polygon_2d_t operator<<(const polygon_2d_t &p, const affine_2d_t &a);

struct trimesh_2d_t {
   private:
    const std::vector<point_2d_t> _vertices;
    const face_list_t _faces;
    const std::vector<std::tuple<polygon_2d_t, std::vector<size_t>>>
    get_polygon(const face_set_t &component) const;
    const std::vector<face_set_t> get_connected_components() const;

   public:
    trimesh_2d_t(const std::vector<point_2d_t> &vertices,
                 const face_set_t &faces, bool validate = true);
    trimesh_2d_t(const std::vector<point_2d_t> &vertices,
                 const face_list_t &faces, bool validate = true);

    void validate() const;
    const std::vector<point_2d_t> &vertices() const;
    const face_list_t &faces() const;
    const triangle_2d_t get_triangle(const face_t &face) const;
    const std::vector<triangle_2d_t> get_triangles() const;
    static const std::tuple<std::vector<point_2d_t>, face_set_t> merge_vertices(
        const std::vector<point_2d_t> &vertices, const face_set_t &faces);
    static const std::tuple<std::vector<point_2d_t>, face_set_t>
    remove_unused_vertices(const std::vector<point_2d_t> &vertices,
                           const face_set_t &faces);
    static const std::tuple<std::vector<point_2d_t>, face_set_t>
    merge_triangles(const std::vector<point_2d_t> &vertices,
                    const face_set_t &faces);
    const std::vector<std::tuple<polygon_2d_t, std::vector<size_t>>>
    get_polygons() const;
    trimesh_2d_t subdivide(bool at_edges = true) const;
    std::string to_string() const;

    trimesh_2d_t operator<<(const affine_2d_t &tf) const;
    trimesh_2d_t operator|(const trimesh_2d_t &other) const;
    trimesh_2d_t operator&(const trimesh_2d_t &other) const;
    trimesh_2d_t operator-(const trimesh_2d_t &other) const;
};

void add_2d_types_modules(py::module &m);

}  // namespace trimesh
