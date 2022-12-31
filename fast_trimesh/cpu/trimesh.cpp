#include "trimesh.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

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
void add_module_for(pybind11::module &m, const char *type_name) {
    py::class_<Trimesh<T>>(m, type_name,
                           "Defines " + std::string(type_name) + " class.")
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
        .def("__add__", &Trimesh<T>::operator+, "Adds two meshes together",
             py::is_operator())
        .def("__iadd__", &Trimesh<T>::operator+=, "Adds two meshes together",
             py::is_operator());
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("trimesh");
    s.doc() = "CPU trimesh implementation.";

    add_module_for<geometry::Point2D>(s, "Trimesh2D");
    add_module_for<geometry::Point3D>(s, "Trimesh3D");
    s.def("triangulate", &triangulate, "Converts a polygon to a 2D trimesh",
          "polygon"_a, "is_convex"_a = false);
}

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
