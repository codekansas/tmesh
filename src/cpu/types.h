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

    std::string to_string() const;
};

struct __edge_hash_fn {
    size_t operator()(const edge_t &e) const {
        auto hf = std::hash<size_t>();
        auto [a, b, directed] = e;
        if (!directed && a > b) std::swap(a, b);
        return hf(e.a) ^ hf(e.b);
    }
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
    size_t get_other_vertex(const edge_t &e) const;
    std::string to_string() const;
};

struct __face_hash_fn {
    size_t operator()(const face_t &e) const {
        auto hf = std::hash<size_t>();
        return hf(e.a) ^ hf(e.b) ^ hf(e.c);
    }
};

typedef std::vector<face_t> face_list_t;
typedef std::unordered_set<face_t, __face_hash_fn> face_set_t;
typedef std::unordered_map<face_t, size_t, __face_hash_fn> face_map_t;

struct barycentric_coordinates_t {
    float u, v, w;

    barycentric_coordinates_t(float u, float v, float w);

    bool operator==(const barycentric_coordinates_t &bc) const;
    bool operator!=(const barycentric_coordinates_t &bc) const;

    std::string to_string() const;
};

void add_types_modules(py::module &m);

}  // namespace trimesh
