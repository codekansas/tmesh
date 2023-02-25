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
struct circle_2d_t;
struct bounding_box_2d_t;
struct polygon_2d_t;
struct affine_2d_t;
struct trimesh_2d_t;

struct point_2d_t {
    double x, y;

    point_2d_t operator+=(const point_2d_t &p);
    point_2d_t operator-=(const point_2d_t &p);
    point_2d_t operator*=(const point_2d_t &p);
    point_2d_t operator*=(double s);
    point_2d_t operator/=(const point_2d_t &p);
    point_2d_t operator/=(double s);
    bool operator==(const point_2d_t &p) const;
    bool operator!=(const point_2d_t &p) const;
    bool operator<(const point_2d_t &p) const;
    point_2d_t operator<<=(const affine_2d_t &a);

    point_2d_t normalize() const;
    point_2d_t rotate(double angle) const;
    double determinant(const point_2d_t &other) const;
    double length() const;
    double dot(const point_2d_t &other) const;
    double cross(const point_2d_t &other) const;
    double angle(const point_2d_t &other) const;

    barycentric_coordinates_t barycentric_coordinates(
        const triangle_2d_t &t) const;
    bool is_inside_triangle(const triangle_2d_t &t) const;
    bool is_inside_bounding_box(const bounding_box_2d_t &bb) const;

    double distance_to_point(const point_2d_t &other) const;
    double distance_to_line(const line_2d_t &l) const;
    double distance_to_triangle(const triangle_2d_t &t) const;
    double distance_to_bounding_box(const bounding_box_2d_t &bb) const;

    std::optional<point_2d_t> project_to_line(const line_2d_t &l) const;

    std::string to_string() const;
};

size_t point_2d_hash_fn(const point_2d_t &p);

struct __point_2d_hash_fn {
    size_t operator()(const point_2d_t &p) const;
};

point_2d_t operator+(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator-(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator*(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator*(double s, const point_2d_t &p);
point_2d_t operator*(const point_2d_t &p, double s);
point_2d_t operator/(const point_2d_t &p1, const point_2d_t &p2);
point_2d_t operator/(const point_2d_t &p, double s);

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

    double distance_to_point(const point_2d_t &p) const;
    double distance_to_line(const line_2d_t &l) const;
    double distance_to_triangle(const triangle_2d_t &t) const;
    double distance_to_bounding_box(const bounding_box_2d_t &bb) const;

    std::string to_string() const;
};

struct triangle_2d_t {
    point_2d_t p1, p2, p3;

    bool operator==(const triangle_2d_t &t) const;
    bool operator!=(const triangle_2d_t &t) const;
    bool operator<(const triangle_2d_t &p) const;
    triangle_2d_t operator<<=(const affine_2d_t &a);

    double area() const;
    point_2d_t center() const;
    std::vector<point_2d_t> vertices() const;
    std::vector<line_2d_t> edges() const;
    bool is_clockwise() const;

    circle_2d_t circumcircle() const;
    bool circumcircle_contains(const point_2d_t &p,
                               double tolerance = 0.0) const;
    bool contains_point(const point_2d_t &p) const;
    bool contains_triangle(const triangle_2d_t &t) const;
    bool intersects_bounding_box(const bounding_box_2d_t &bb) const;
    bool intersects_triangle(const triangle_2d_t &t) const;
    std::vector<point_2d_t> triangle_intersection(const triangle_2d_t &t) const;
    double distance_to_point(const point_2d_t &p) const;
    double distance_to_line(const line_2d_t &l) const;
    double distance_to_triangle(const triangle_2d_t &t) const;
    double distance_to_bounding_box(const bounding_box_2d_t &bb) const;
    point_2d_t point_from_barycentric_coords(
        const barycentric_coordinates_t &b) const;

    std::string to_string() const;
};

struct circle_2d_t {
    point_2d_t center;
    double radius;

    circle_2d_t();
    circle_2d_t(const point_2d_t &c, double r);
    circle_2d_t(const triangle_2d_t &t);

    bool operator==(const circle_2d_t &c) const;
    bool operator!=(const circle_2d_t &c) const;

    double area() const;
    double circumference() const;
    bool contains_point(const point_2d_t &p, double tolerance = 0.0) const;

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

    double area() const;
    point_2d_t center() const;
    std::vector<point_2d_t> vertices() const;
    std::vector<line_2d_t> edges() const;

    bool intersects_triangle(const triangle_2d_t &t) const;
    bool contains_point(const point_2d_t &p) const;
    bool contains_triangle(const triangle_2d_t &t) const;
    double distance_to_point(const point_2d_t &p) const;
    double distance_to_line(const line_2d_t &l) const;
    double distance_to_triangle(const triangle_2d_t &t) const;
    double distance_to_bounding_box(const bounding_box_2d_t &bb) const;

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

    double signed_area() const;
    bool is_clockwise() const;
    void reverse();
    polygon_2d_t convex_hull() const;
    bounding_box_2d_t bounding_box() const;
    point_2d_t center() const;
    trimesh_2d_t get_trimesh(bool delaunay = false,
                             bool is_convex = false) const;

    std::string to_string() const;
};

struct affine_2d_t {
    // Represents the affine transformation:
    // r00 r01 tx
    // r10 r11 ty
    // 0   0   1

    double r00, r01, r10, r11, tx, ty;

    affine_2d_t(
        std::tuple<std::tuple<double, double>, std::tuple<double, double>> rot,
        std::tuple<double, double> trans);
    affine_2d_t(std::optional<double> rot = std::nullopt,
                std::optional<std::tuple<double, double>> trans = std::nullopt,
                std::optional<double> scale = std::nullopt);

    affine_2d_t operator*=(const affine_2d_t &a);

    affine_2d_t inverse() const;
    std::tuple<std::tuple<double, double>, std::tuple<double, double>>
    rotation() const;
    std::tuple<double, double> translation() const;

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
    trimesh_2d_t make_delaunay() const;
    std::string to_string() const;

    trimesh_2d_t operator<<(const affine_2d_t &tf) const;
    trimesh_2d_t operator|(const trimesh_2d_t &other) const;
    trimesh_2d_t operator&(const trimesh_2d_t &other) const;
    trimesh_2d_t operator-(const trimesh_2d_t &other) const;
};

trimesh_2d_t triangulate(const std::vector<point_2d_t> &points,
                         bool triangulate = true);

void add_2d_types_modules(py::module &m);

}  // namespace trimesh
