#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

namespace py = pybind11;

namespace trimesh {

struct BarycentricCoordinates;

typedef std::tuple<size_t, size_t, size_t> face_t;

struct __face_hash_fn {
    std::size_t operator()(const face_t &f) const {
        auto hf = std::hash<size_t>();
        return hf(std::get<0>(f)) ^ hf(std::get<1>(f)) ^ hf(std::get<2>(f));
    }
};

typedef std::vector<face_t> face_list_t;
typedef std::unordered_set<face_t, __face_hash_fn> face_set_t;

std::vector<std::tuple<size_t, size_t>> get_edges(const face_t &face);

struct BarycentricCoordinates {
    float u, v, w;

    BarycentricCoordinates(float u, float v, float w);

    bool operator==(const BarycentricCoordinates &bc) const;
    bool operator!=(const BarycentricCoordinates &bc) const;

    std::string to_string() const;
};

void add_types_modules(py::module &m);

}  // namespace trimesh
