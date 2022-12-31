#include "trimesh.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

template <typename T>
Trimesh<T> &operator+=(Trimesh<T> &a, const Trimesh<T> &other) {
    auto offset = a.vertices.size();
    for (auto &face : other.faces) {
        a.faces.push_back(std::make_tuple(std::get<0>(face) + offset,
                                          std::get<1>(face) + offset,
                                          std::get<2>(face) + offset));
    }
    a.vertices.insert(a.vertices.end(), other.vertices.begin(),
                      other.vertices.end());
    return a;
}

template <typename T>
Trimesh<T> operator+(const Trimesh<T> &a, const Trimesh<T> &b) {
    Trimesh<T> result;
    result += a;
    result += b;
    return result;
}

Trimesh3D &operator<<=(Trimesh3D &t, const AffineTransformation &tf) {
    if (tf.rotation.has_value()) {
        for (auto &vertex : t.vertices) {
            vertex = geometry::rotate(vertex, tf.rotation.value());
        }
    }

    if (tf.translation.has_value()) {
        for (auto &vertex : t.vertices) {
            vertex = geometry::translate(vertex, tf.translation.value());
        }
    }

    if (tf.scale.has_value()) {
        for (auto &vertex : t.vertices) {
            vertex = geometry::scale(vertex, tf.scale.value());
        }
    }

    return t;
}

Trimesh3D operator<<(const Trimesh3D &t, const AffineTransformation &tf) {
    Trimesh3D result;
    result += t;
    result <<= tf;
    return result;
}

Trimesh3D operator>>(const AffineTransformation &tf, const Trimesh3D &t) {
    return t << tf;
}

bool is_ear(const geometry::Polygon2D &polygon, int vi, int vj, int vk) {
    geometry::Point2D pi = polygon[vi], pj = polygon[vj], pk = polygon[vk];

    // Checks if the triangle is convex.
    if (!geometry::is_convex(pi, pj, pk)) return false;

    // Checks if the triangle contains any other points.
    for (int l = 0; l < polygon.size(); l++) {
        if (l == vi || l == vj || l == vk) continue;
        if (geometry::is_inside(polygon[l], {pi, pj, pk})) return false;
    }

    return true;
}

Trimesh2D triangulate(const geometry::Polygon2D &polygon, bool is_convex) {
    if (polygon.size() < 3) throw std::runtime_error("Invalid polygon.");

    Trimesh2D result;

    // Gets the vertex indices from 0 to n - 1.
    std::vector<int> indices(polygon.size());
    std::iota(indices.begin(), indices.end(), 0);

    // Ensures that the polygon is counter-clockwise.
    if (geometry::is_clockwise(polygon)) {
        std::reverse(indices.begin(), indices.end());
    }

    // Add vertices to the mesh using indices.
    for (int i = 0; i < polygon.size(); i++) result.add_vertex(polygon[i]);

    // Runs ear clipping algorithm.
    while (indices.size() > 3) {
        bool found = false;
        int n = indices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            int vi = indices[i], vj = indices[j], vk = indices[k];
            geometry::Point2D pi = polygon[vi], pj = polygon[vj],
                              pk = polygon[vk];
            if (is_convex || is_ear(polygon, vi, vj, vk)) {
                result.add_face(vi, vj, vk);
                indices.erase(indices.begin() + j);
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Unable to triangulate polygon.");
        }
    }
    result.add_face(indices[0], indices[1], indices[2]);

    return result;
}

template <typename T>
py::class_<Trimesh<T>> add_trimesh_module_for(pybind11::module &m,
                                              const char *type_name) {
    return py::class_<Trimesh<T>>(m, type_name, "Defines trimesh class.")
        .def(py::init<>())
        .def("add_vertex", &Trimesh<T>::add_vertex, "Adds a vertex to the mesh",
             "vertex"_a)
        .def("set_vertices", &Trimesh<T>::set_vertices,
             "Sets the mesh vertices", "vertices"_a)
        .def("add_face", &Trimesh<T>::add_face, "Adds a face to the mesh",
             "i"_a, "j"_a, "k"_a)
        .def("set_faces", &Trimesh<T>::set_faces, "Sets the mesh faces",
             "faces"_a)
        .def("get_vertex", &Trimesh<T>::get_vertex,
             "Gets a mesh vertex from it's ID", "i"_a)
        .def("get_face", &Trimesh<T>::get_face, "Gets a mesh face from it's ID",
             "i"_a)
        .def_property_readonly("vertices", &Trimesh<T>::get_vertices,
                               "The mesh vertices")
        .def_property_readonly("faces", &Trimesh<T>::get_faces,
                               "The mesh faces")
        .def("num_vertices", &Trimesh<T>::num_vertices,
             "The number of vertices in the mesh")
        .def("num_faces", &Trimesh<T>::num_faces,
             "The number of faces in the mesh")
        .def("__add__", &operator+<T>, "Adds two meshes together", "other"_a,
             py::is_operator())
        .def("__iadd__", &operator+=<T>, "Adds two meshes together", "other"_a,
             py::is_operator());
}

void add_affine_transform_module(pybind11::module &m) {
    py::class_<AffineTransformation>(m, "AffineTransformation",
                                     "Defines affine transformation class.")
        .def(py::init<std::optional<geometry::Point3D>,
                      std::optional<geometry::Point3D>, std::optional<float>>(),
             "rotation"_a = std::nullopt, "translation"_a = std::nullopt,
             "scale"_a = std::nullopt)
        .def("__rshift__", &operator>>,
             "Applies affine transformation to 3D mesh", "trimesh"_a,
             py::is_operator());
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("trimesh");
    s.doc() = "CPU trimesh implementation.";

    add_trimesh_module_for<geometry::Point2D>(s, "Trimesh2D");
    add_trimesh_module_for<geometry::Point3D>(s, "Trimesh3D")
        .def("__lshift__", &operator<<,
             "Applies affine transformation to 3D mesh", "affine"_a,
             py::is_operator());

    add_affine_transform_module(s);

    s.def("triangulate", &triangulate, "Converts a polygon to a 2D trimesh",
          "polygon"_a, "is_convex"_a = false);
}

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
