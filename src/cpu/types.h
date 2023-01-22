#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

namespace py = pybind11;

namespace trimesh {

struct face_t {
    size_t a, b, c;

    face_t(size_t a, size_t b, size_t c);
    ~face_t() = default;

    bool operator==(const face_t &f) const;
    bool operator!=(const face_t &f) const;
    bool operator<(const face_t &f) const;

    std::vector<size_t> get_vertices() const;
    std::vector<std::tuple<size_t, size_t>> get_edges() const;
    std::string to_string() const;
};

struct __face_hash_fn {
    std::size_t operator()(const face_t &f) const {
        auto hf = std::hash<size_t>();
        const auto &[a, b, c] = f;
        return hf(a) ^ hf(b) ^ hf(c);
    }
};

typedef std::vector<face_t> face_list_t;
typedef std::unordered_set<face_t, __face_hash_fn> face_set_t;

struct barycentric_coordinates_t {
    float u, v, w;

    barycentric_coordinates_t(float u, float v, float w);

    bool operator==(const barycentric_coordinates_t &bc) const;
    bool operator!=(const barycentric_coordinates_t &bc) const;

    std::string to_string() const;
};

void add_types_modules(py::module &m);

}  // namespace trimesh
