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
struct sphere_3d_t;
struct triangle_3d_t;
struct tetrahedron_3d_t;
struct bounding_box_3d_t;
struct polygon_3d_t;
struct affine_3d_t;
struct trimesh_3d_t;
struct tetramesh_3d_t;

struct point_3d_t {
    double x, y, z;

    point_3d_t operator+=(const point_3d_t &p);
    point_3d_t operator-=(const point_3d_t &p);
    point_3d_t operator*=(const point_3d_t &p);
    point_3d_t operator*=(double s);
    point_3d_t operator/=(const point_3d_t &p);
    point_3d_t operator/=(double s);
    bool operator==(const point_3d_t &p) const;
    bool operator!=(const point_3d_t &p) const;
    bool operator<(const point_3d_t &p) const;
    point_3d_t operator<<=(const affine_3d_t &q);

    point_3d_t normalize() const;
    double determinant(const point_3d_t &a, const point_3d_t &b) const;
    double length() const;
    double dot(const point_3d_t &other) const;
    point_3d_t cross(const point_3d_t &other) const;

    barycentric_coordinates_t barycentric_coordinates(
        const triangle_3d_t &t) const;
    bool is_inside_bounding_box(const bounding_box_3d_t &bb) const;

    double distance_to_point(const point_3d_t &other) const;
    double distance_to_line(const line_3d_t &l) const;
    double distance_to_triangle(const triangle_3d_t &t) const;
    bool is_coplanar(const triangle_3d_t &t) const;

    std::optional<point_3d_t> project_to_line(const line_3d_t &l) const;
    std::optional<point_3d_t> project_to_triangle(const triangle_3d_t &t) const;
    bool projects_to_triangle(const triangle_3d_t &t) const;

    std::string to_string() const;
};

size_t point_3d_hash_fn(const point_3d_t &p);

struct __point_3d_hash_fn {
    size_t operator()(const point_3d_t &p) const;
};

point_3d_t operator+(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator-(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator*(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator*(double s, const point_3d_t &p);
point_3d_t operator*(const point_3d_t &p, double s);
point_3d_t operator/(const point_3d_t &p1, const point_3d_t &p2);
point_3d_t operator/(const point_3d_t &p, double s);
point_3d_t operator<<(const point_3d_t &p, const affine_3d_t &q);

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

    double distance_to_point(const point_3d_t &p) const;
    double distance_to_line(const line_3d_t &l) const;

    std::string to_string() const;
};

struct sphere_3d_t {
    point_3d_t center;
    double radius;

    sphere_3d_t();
    sphere_3d_t(const point_3d_t &c, double r);
    sphere_3d_t(const tetrahedron_3d_t &t);

    bool operator==(const sphere_3d_t &s) const;
    bool operator!=(const sphere_3d_t &s) const;

    double volume() const;
    bool contains_point(const point_3d_t &p) const;

    std::string to_string() const;
};

struct triangle_3d_t {
    point_3d_t p1, p2, p3;

    bool operator==(const triangle_3d_t &t) const;
    bool operator!=(const triangle_3d_t &t) const;
    triangle_3d_t operator<<=(const affine_3d_t &q);

    double area() const;
    point_3d_t center() const;
    point_3d_t normal() const;
    std::vector<point_3d_t> vertices() const;
    std::vector<line_3d_t> edges() const;

    double distance_to_point(const point_3d_t &p) const;
    bool contains_point(const point_3d_t &p) const;
    bool is_coplanar(const triangle_3d_t &t) const;
    point_3d_t point_from_barycentric_coords(
        const barycentric_coordinates_t &b) const;
    std::vector<point_3d_t> triangle_intersection(const triangle_3d_t &t) const;
    point_3d_t orthocenter() const;

    std::string to_string() const;
};

struct tetrahedron_3d_t {
    point_3d_t p1, p2, p3, p4;

    bool operator==(const tetrahedron_3d_t &t) const;
    bool operator!=(const tetrahedron_3d_t &t) const;
    tetrahedron_3d_t operator<<=(const affine_3d_t &a);

    double signed_volume() const;
    std::vector<triangle_3d_t> faces() const;
    double surface_area() const;
    point_3d_t circumcenter() const;
    point_3d_t incenter() const;
    point_3d_t centroid() const;
    sphere_3d_t circumsphere() const;

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
    bounding_box_3d_t operator<<=(const affine_3d_t &a);

    std::vector<face_t> triangle_faces() const;
    std::vector<volume_t> tetrahedron_volumes() const;
    std::vector<point_3d_t> corners() const;
    std::vector<line_3d_t> edges() const;
    std::vector<triangle_3d_t> triangles() const;
    std::vector<tetrahedron_3d_t> tetrahedrons() const;

    point_3d_t center() const;
    double volume() const;

    std::string to_string() const;
};

struct polygon_3d_t {
    std::vector<point_3d_t> points;

    polygon_3d_t(const std::vector<point_3d_t> &points);

    bool operator==(const polygon_3d_t &p) const;
    bool operator!=(const polygon_3d_t &p) const;
    polygon_3d_t operator<<=(const affine_3d_t &q);

    double area() const;
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

    double r00, r01, r02, r10, r11, r12, r20, r21, r22, tx, ty, tz;

    affine_3d_t(std::tuple<std::tuple<double, double, double>,
                           std::tuple<double, double, double>,
                           std::tuple<double, double, double>>
                    rot,
                std::tuple<double, double, double> trans);
    affine_3d_t(
        std::optional<std::tuple<double, double, double>> rot = std::nullopt,
        std::optional<std::tuple<double, double, double>> trans = std::nullopt,
        std::optional<double> scale = std::nullopt);

    affine_3d_t operator*=(const affine_3d_t &a);

    affine_3d_t inverse() const;
    std::tuple<std::tuple<double, double, double>,
               std::tuple<double, double, double>,
               std::tuple<double, double, double>>
    rotation();
    std::tuple<double, double, double> translation();

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
trimesh_3d_t operator>>(const affine_3d_t &a, const trimesh_3d_t &p);
trimesh_3d_t operator<<(const trimesh_3d_t &p, const affine_3d_t &a);
tetrahedron_3d_t operator>>(const affine_3d_t &a, const tetrahedron_3d_t &p);
tetrahedron_3d_t operator<<(const tetrahedron_3d_t &p, const affine_3d_t &a);
tetramesh_3d_t operator>>(const affine_3d_t &a, const tetramesh_3d_t &p);
tetramesh_3d_t operator<<(const tetramesh_3d_t &p, const affine_3d_t &a);

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
    trimesh_3d_t(const std::vector<point_3d_t> &vertices);

    const std::vector<point_3d_t> &vertices() const;
    const face_list_t &faces() const;
    triangle_3d_t get_triangle(const face_t &face) const;
    std::vector<triangle_3d_t> get_triangles() const;
    double signed_volume() const;
    trimesh_3d_t subdivide(bool at_edges = true) const;
    tetramesh_3d_t to_tetramesh() const;
    std::string to_string() const;

    trimesh_3d_t operator<<(const affine_3d_t &tf) const;
};

struct tetramesh_3d_t {
   private:
    const std::vector<point_3d_t> _vertices;
    const volume_list_t _volumes;
    void validate() const;

   public:
    tetramesh_3d_t(const std::vector<point_3d_t> &vertices,
                   const volume_set_t &volumes);
    tetramesh_3d_t(const std::vector<point_3d_t> &vertices,
                   const volume_list_t &volumes);

    const std::vector<point_3d_t> &vertices() const;
    const volume_list_t &volumes() const;
    tetrahedron_3d_t get_tetrahedron(const volume_t &volume) const;
    std::vector<tetrahedron_3d_t> get_tetrahedra() const;
    trimesh_3d_t to_trimesh() const;
    std::string to_string() const;

    tetramesh_3d_t operator<<(const affine_3d_t &tf) const;
    tetramesh_3d_t operator|(const tetramesh_3d_t &other) const;
    tetramesh_3d_t operator&(const tetramesh_3d_t &other) const;
    tetramesh_3d_t operator-(const tetramesh_3d_t &other) const;
};

void add_3d_types_modules(py::module &m);

}  // namespace trimesh
