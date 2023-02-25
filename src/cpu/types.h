#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <unordered_set>

namespace py = pybind11;

namespace trimesh {

struct edge_t {
    size_t a, b;
    bool directed;

    edge_t(size_t a, size_t b, bool directed = true);
    ~edge_t() = default;

    bool operator==(const edge_t &f) const;
    bool operator!=(const edge_t &f) const;
    bool operator<(const edge_t &f) const;

    edge_t flip() const;

    std::string to_string() const;
};

struct __edge_hash_fn {
    size_t operator()(const edge_t &e) const;
};

typedef std::vector<edge_t> edge_list_t;
typedef std::unordered_set<edge_t, __edge_hash_fn> edge_set_t;
typedef std::unordered_map<edge_t, size_t, __edge_hash_fn> edge_map_t;

struct face_t {
    size_t a, b, c;

    face_t(size_t a, size_t b, size_t c);
    ~face_t() = default;

    bool operator==(const face_t &f) const;
    bool operator!=(const face_t &f) const;
    bool operator<(const face_t &f) const;
    face_t operator+(size_t offset) const;

    std::vector<size_t> get_vertices() const;
    std::vector<edge_t> get_edges(bool directed = true) const;
    bool has_edge(const edge_t &e) const;
    bool has_vertex(size_t v) const;
    size_t get_other_vertex(const edge_t &e) const;
    face_t flip() const;
    std::string to_string() const;
};

size_t face_hash_fn(const face_t &f);

struct __face_hash_fn {
    size_t operator()(const face_t &f) const;
};

typedef std::vector<face_t> face_list_t;
typedef std::unordered_set<face_t, __face_hash_fn> face_set_t;
typedef std::unordered_map<face_t, size_t, __face_hash_fn> face_map_t;

struct volume_t {
    size_t a, b, c, d;

    volume_t(size_t a, size_t b, size_t c, size_t d);
    ~volume_t() = default;

    bool operator==(const volume_t &f) const;
    bool operator!=(const volume_t &f) const;
    bool operator<(const volume_t &f) const;
    volume_t operator+(size_t offset) const;

    face_list_t faces() const;
    volume_t flip() const;
    std::string to_string() const;
};

size_t volume_hash_fn(const volume_t &v);

struct __volume_hash_fn {
    size_t operator()(const volume_t &v) const;
};

typedef std::vector<volume_t> volume_list_t;
typedef std::unordered_set<volume_t, __volume_hash_fn> volume_set_t;
typedef std::unordered_map<volume_t, size_t, __volume_hash_fn> volume_map_t;

struct barycentric_coordinates_t {
    double u, v, w;

    barycentric_coordinates_t(double u, double v, double w);

    bool operator==(const barycentric_coordinates_t &bc) const;
    bool operator!=(const barycentric_coordinates_t &bc) const;

    std::string to_string() const;
};

void check_file_ext(const std::string &filename, const std::string &ext);

void add_types_modules(py::module &m);

}  // namespace trimesh
