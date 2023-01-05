#include "trimesh.h"

#include <sstream>

#include "boolean.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

bool is_ear(const types::Polygon2D &polygon, int vi, int vj, int vk) {
    types::Point2D pi = polygon.points[vi], pj = polygon.points[vj],
                   pk = polygon.points[vk];

    // Checks if the triangle is convex.
    if (!types::is_convex(pi, pj, pk)) return false;

    // Checks if the triangle contains any other points.
    for (int l = 0; l < polygon.points.size(); l++) {
        if (l == vi || l == vj || l == vk) continue;
        types::Triangle2D triangle = {pi, pj, pk};
        if (polygon.points[l].is_inside_triangle(triangle)) return false;
    }

    return true;
}

Trimesh2D::Trimesh2D(const types::Polygon2D &polygon, bool is_convex) {
    if (polygon.points.size() < 3) throw std::runtime_error("Invalid polygon.");

    // Gets the vertex indices from 0 to n - 1.
    std::vector<int> indices(polygon.points.size());
    std::iota(indices.begin(), indices.end(), 0);

    // Ensures that the polygon is counter-clockwise.
    if (polygon.is_clockwise()) {
        std::reverse(indices.begin(), indices.end());
    }

    // Add vertices to the mesh using indices.
    for (int i = 0; i < polygon.points.size(); i++)
        vertices.push_back(polygon.points[i]);

    // Runs ear clipping algorithm.
    while (indices.size() > 3) {
        bool found = false;
        int n = indices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            int vi = indices[i], vj = indices[j], vk = indices[k];
            types::Point2D pi = polygon.points[vi], pj = polygon.points[vj],
                           pk = polygon.points[vk];
            if (is_convex || is_ear(polygon, vi, vj, vk)) {
                faces.insert({vi, vj, vk});
                indices.erase(indices.begin() + j);
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Unable to triangulate polygon.");
        }
    }
    faces.insert({indices[0], indices[1], indices[2]});
}

Trimesh2D &Trimesh2D::operator<<=(const types::Affine2D &tf) {
    for (auto &vertex : vertices) {
        vertex <<= tf;
    }
    return *this;
}

Trimesh2D Trimesh2D::operator<<(const types::Affine2D &tf) const {
    Trimesh2D result;
    result.vertices = vertices;
    result.faces = faces;
    result <<= tf;
    return result;
}

void Trimesh2D::validate() const {
    // Checks that there are at least 3 vertices.
    if (vertices.size() < 3)
        throw std::runtime_error("Trimesh2D should have at least 3 vertices.");

    // Checks that all vertices are part of at least one face.
    std::vector<bool> used(vertices.size(), false);

    for (auto &face : faces) {
        used[std::get<0>(face)] = true;
        used[std::get<1>(face)] = true;
        used[std::get<2>(face)] = true;

        // Checks that all vertices point to a valid vertex index.
        int i = std::get<0>(face), j = std::get<1>(face), k = std::get<2>(face);
        if (i < 0 || i >= vertices.size())
            throw std::runtime_error("Invalid face index.");
        if (j < 0 || j >= vertices.size())
            throw std::runtime_error("Invalid face index.");
        if (k < 0 || k >= vertices.size())
            throw std::runtime_error("Invalid face index.");

        // Checks that the face is counter-clockwise (points upwards).
        if (!types::is_convex(vertices[i], vertices[j], vertices[k]))
            throw std::runtime_error("Face is not counter-clockwise.");
    }

    for (int i = 0; i < used.size(); i++)
        if (!used[i]) throw std::runtime_error("Unused vertex.");
}

types::Triangle2D Trimesh2D::get_triangle(
    const std::tuple<int, int, int> &face) const {
    auto &[vi, vj, vk] = face;
    return {vertices[vi], vertices[vj], vertices[vk]};
}

std::string Trimesh2D::to_string() const {
    std::stringstream ss;
    ss << "Trimesh2D(" << std::endl;
    ss << "  " << vertices.size() << " vertices = [" << std::endl;
    size_t i = 0;
    for (auto &vertex : vertices) {
        ss << "    " << vertex.to_string() << "," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]," << std::endl;
    ss << "  " << faces.size() << " faces = [" << std::endl;
    i = 0;
    for (auto &face : faces) {
        ss << "    (" << std::get<0>(face) << ", " << std::get<1>(face) << ", "
           << std::get<2>(face) << ")," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]" << std::endl;
    ss << ")" << std::endl;
    return ss.str();
}

types::Triangle3D Trimesh3D::get_triangle(
    const std::tuple<int, int, int> &face) const {
    auto &[vi, vj, vk] = face;
    return {vertices[vi], vertices[vj], vertices[vk]};
}

std::vector<types::Triangle3D> Trimesh3D::get_triangles() const {
    std::vector<types::Triangle3D> result;
    for (auto &face : faces) {
        result.push_back(get_triangle(face));
    }
    return result;
}

void Trimesh3D::validate() const {
    // Checks that there are at least 3 vertices.
    throw std::runtime_error("Trimesh3D should have at least 3 vertices.");

    // Checks that all vertices point to a valid vertex index.
    for (auto &face : faces) {
        int i = std::get<0>(face), j = std::get<1>(face), k = std::get<2>(face);
        if (i < 0 || i >= vertices.size())
            throw std::runtime_error("Invalid face index.");
        if (j < 0 || j >= vertices.size())
            throw std::runtime_error("Invalid face index.");
        if (k < 0 || k >= vertices.size())
            throw std::runtime_error("Invalid face index.");
    }

    // Checks that all vertices are part of at least one face.
    std::vector<bool> used(vertices.size(), false);
    for (auto &face : faces) {
        used[std::get<0>(face)] = true;
        used[std::get<1>(face)] = true;
        used[std::get<2>(face)] = true;
    }
    for (int i = 0; i < used.size(); i++)
        if (!used[i]) throw std::runtime_error("Unused vertex.");
}

Trimesh3D &Trimesh3D::operator<<=(const types::Affine3D &tf) {
    for (auto &vertex : vertices) {
        vertex <<= tf;
    }

    return *this;
}

Trimesh3D Trimesh3D::operator<<(const types::Affine3D &tf) const {
    Trimesh3D result;
    result.vertices = vertices;
    result.faces = faces;
    result <<= tf;
    return result;
}

Trimesh3D &Trimesh3D::operator|=(const Trimesh3D &other) {
    boolean::mesh_intersection(*this, {other});
    return *this;
}

Trimesh3D Trimesh3D::operator|(const Trimesh3D &other) const {
    Trimesh3D result = *this;
    result |= other;
    return result;
}

Trimesh3D &Trimesh3D::operator&=(const Trimesh3D &other) {
    boolean::mesh_union(*this, {other});
    return *this;
}

Trimesh3D Trimesh3D::operator&(const Trimesh3D &other) const {
    Trimesh3D result = *this;
    result &= other;
    return result;
}

Trimesh3D &Trimesh3D::operator-=(const Trimesh3D &other) {
    boolean::mesh_difference(*this, {other});
    return *this;
}

Trimesh3D Trimesh3D::operator-(const Trimesh3D &other) const {
    Trimesh3D result = *this;
    result -= other;
    return result;
}

std::string Trimesh3D::to_string() const {
    std::stringstream ss;
    ss << "Trimesh3D(" << std::endl;
    ss << "  " << vertices.size() << " vertices = [" << std::endl;
    size_t i = 0;
    for (auto &vertex : vertices) {
        ss << "    " << vertex.to_string() << "," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]," << std::endl;
    ss << "  " << faces.size() << " faces = [" << std::endl;
    i = 0;
    for (auto &face : faces) {
        ss << "    (" << std::get<0>(face) << ", " << std::get<1>(face) << ", "
           << std::get<2>(face) << ")," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]" << std::endl;
    ss << ")" << std::endl;
    return ss.str();
}

float Trimesh3D::signed_volume() const {
    types::Point3D center = {0, 0, 0};
    float volume = 0;
    for (auto &triangle : get_triangles()) {
        volume +=
            types::signed_volume(center, triangle.p1, triangle.p2, triangle.p3);
    }
    return volume;
}

void Trimesh3D::flip_inside_out() {
    std::set<std::tuple<int, int, int>> new_faces;
    std::transform(
        faces.begin(), faces.end(), std::inserter(new_faces, new_faces.begin()),
        [](const std::tuple<int, int, int> &face) {
            return std::make_tuple(std::get<0>(face), std::get<2>(face),
                                   std::get<1>(face));
        });
    faces = new_faces;
}

template <typename T>
py::class_<T> add_trimesh_module_for(pybind11::module &m,
                                     const char *type_name) {
    return py::class_<T, std::shared_ptr<T>>(m, type_name,
                                             "Defines trimesh class.")
        .def(py::init<>(), "Creates an empty trimesh.")
        .def("add_vertex", &T::add_vertex, "Adds a vertex to the mesh",
             "vertex"_a)
        .def("set_vertices", &T::set_vertices, "Sets the mesh vertices",
             "vertices"_a)
        .def("add_face", &T::add_face, "Adds a face to the mesh", "i"_a, "j"_a,
             "k"_a)
        .def("set_faces", &T::set_faces, "Sets the mesh faces", "faces"_a)
        .def("get_vertex", &T::get_vertex, "Gets a mesh vertex from it's ID",
             "i"_a)
        .def_property_readonly("vertices", &T::get_vertices,
                               "The mesh vertices")
        .def_property_readonly("faces", &T::get_faces, "The mesh faces")
        .def("num_vertices", &T::num_vertices,
             "The number of vertices in the mesh")
        .def("num_faces", &T::num_faces, "The number of faces in the mesh");
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("trimesh");
    s.doc() = "CPU trimesh implementation.";

    auto t2 = add_trimesh_module_for<Trimesh2D>(s, "Trimesh2D");
    auto t3 = add_trimesh_module_for<Trimesh3D>(s, "Trimesh3D");

    t2.def(py::init<const types::Polygon2D &, bool>(),
           "Creates a trimesh from a polygon", "polygon"_a,
           "is_convex"_a = false)
        .def("__str__", &Trimesh2D::to_string, "Converts the mesh to a string")
        .def("__repr__", &Trimesh2D::to_string, "Converts the mesh to a string")
        .def("validate", &Trimesh2D::validate, "Validates the mesh");

    t3.def("get_triangle", &Trimesh3D::get_triangle,
           "Gets a mesh triangle from a face", "face"_a)
        .def("get_triangles", &Trimesh3D::get_triangles,
             "Gets all mesh triangles")
        .def("signed_volume", &Trimesh3D::signed_volume,
             "Computes the signed volume of the mesh")
        .def("flip_inside_out", &Trimesh3D::flip_inside_out,
             "Flips the mesh inside out")
        .def("validate", &Trimesh3D::validate, "Validates the mesh")
        .def("__str__", &Trimesh3D::to_string, "Converts the mesh to a string")
        .def("__repr__", &Trimesh3D::to_string, "Converts the mesh to a string")
        .def("__or__", &Trimesh3D::operator|,
             "Computes the union of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__ior__", &Trimesh3D::operator|=,
             "Computes the union of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__and__", &Trimesh3D::operator&,
             "Computes the intersection of two "
             "3D meshes",
             "other"_a, py::is_operator())
        .def("__iand__", &Trimesh3D::operator&=,
             "Computes the intersection of two "
             "3D meshes",
             "other"_a, py::is_operator())
        .def("__sub__", &Trimesh3D::operator-,
             "Computes the difference of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__isub__", &Trimesh3D::operator-=,
             "Computes the difference of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__lshift__", &Trimesh3D::operator<<,
             "Applies affine transformation to 3D mesh", "affine"_a,
             py::is_operator())
        .def("__ilshift__", &Trimesh3D::operator<<=,
             "Applies affine transformation to 3D mesh", "affine"_a,
             py::is_operator());
}

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
