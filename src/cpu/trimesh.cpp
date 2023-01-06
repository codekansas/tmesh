#include "trimesh.h"

#include <sstream>

#include "boolean.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace trimesh {

/* --------- *
 * Trimesh2D *
 * --------- */

Trimesh2D::Trimesh2D(vertices2d_t &vertices, face_set_t &faces)
    : _vertices(vertices), _faces(faces) {}

const vertices2d_t &Trimesh2D::vertices() const { return _vertices; }

const face_set_t &Trimesh2D::faces() const { return _faces; }

const types::Triangle2D Trimesh2D::get_triangle(
    const std::tuple<int, int, int> &face) const {
    auto &[vi, vj, vk] = face;
    return {_vertices[vi], _vertices[vj], _vertices[vk]};
}

const std::vector<types::Triangle2D> Trimesh2D::get_triangles() const {
    std::vector<types::Triangle2D> result;
    for (auto &face : _faces) {
        result.push_back(get_triangle(face));
    }
    return result;
}

std::string Trimesh2D::to_string() const {
    std::stringstream ss;
    ss << "Trimesh2D(" << std::endl;
    ss << "  " << _vertices.size() << " vertices = [" << std::endl;
    size_t i = 0;
    for (auto &vertex : _vertices) {
        ss << "    " << vertex.to_string() << "," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]," << std::endl;
    ss << "  " << _faces.size() << " faces = [" << std::endl;
    i = 0;
    for (auto &face : _faces) {
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

Trimesh2D Trimesh2D::operator<<(const types::Affine2D &tf) const {
    vertices2d_t vertices;
    face_set_t faces = this->_faces;
    std::transform(
        this->_vertices.begin(), this->_vertices.end(),
        std::back_inserter(vertices),
        [&tf](const types::Point2D &vertex) { return vertex << tf; });
    return {vertices, faces};
}

/* --------- *
 * Trimesh3D *
 * --------- */

Trimesh3D::Trimesh3D(vertices3d_t &vertices, face_set_t &faces)
    : _vertices(vertices), _faces(faces) {}

const vertices3d_t &Trimesh3D::vertices() const { return _vertices; }

const face_set_t &Trimesh3D::faces() const { return _faces; }

types::Triangle3D Trimesh3D::get_triangle(
    const std::tuple<int, int, int> &face) const {
    auto &[vi, vj, vk] = face;
    return {_vertices[vi], _vertices[vj], _vertices[vk]};
}

std::vector<types::Triangle3D> Trimesh3D::get_triangles() const {
    std::vector<types::Triangle3D> result;
    for (auto &face : _faces) {
        result.push_back(get_triangle(face));
    }
    return result;
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

Trimesh3D Trimesh3D::flip_inside_out() const {
    vertices3d_t vertices = this->_vertices;
    face_set_t faces;
    std::transform(this->_faces.begin(), this->_faces.end(),
                   std::inserter(faces, faces.begin()),
                   [](const std::tuple<int, int, int> &face) {
                       return std::make_tuple(std::get<0>(face),
                                              std::get<2>(face),
                                              std::get<1>(face));
                   });
    return {vertices, faces};
}

std::string Trimesh3D::to_string() const {
    std::stringstream ss;
    ss << "Trimesh3D(" << std::endl;
    ss << "  " << _vertices.size() << " vertices = [" << std::endl;
    size_t i = 0;
    for (auto &vertex : _vertices) {
        ss << "    " << vertex.to_string() << "," << std::endl;
        if (i++ > 10) {
            ss << "    ..." << std::endl;
            break;
        }
    }
    ss << "  ]," << std::endl;
    ss << "  " << _faces.size() << " faces = [" << std::endl;
    i = 0;
    for (auto &face : _faces) {
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

Trimesh3D Trimesh3D::operator<<(const types::Affine3D &tf) const {
    vertices3d_t vertices;
    face_set_t faces = this->_faces;
    std::transform(
        this->_vertices.begin(), this->_vertices.end(),
        std::back_inserter(vertices),
        [&tf](const types::Point3D &vertex) { return vertex << tf; });
    return {vertices, faces};
}

Trimesh3D Trimesh3D::operator|(const Trimesh3D &other) const {
    return boolean::mesh_intersection(*this, other);
}

Trimesh3D Trimesh3D::operator&(const Trimesh3D &other) const {
    return boolean::mesh_union(*this, other);
}

Trimesh3D Trimesh3D::operator-(const Trimesh3D &other) const {
    return boolean::mesh_difference(*this, other);
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("trimesh");
    s.doc() = "CPU trimesh implementation.";

    py::class_<Trimesh2D, std::shared_ptr<Trimesh2D>>(
        m, "Trimesh2D", "Defines 2D trimesh class.")
        // .def(py::init<std::vector<const types::Point2D> &,
        //               std::unordered_set<const face_t> &>(),
        //      "Creates a trimesh from vertices and faces", "vertices"_a,
        //      "faces"_a)
        // .def_property_readonly("vertices", &Trimesh2D::vertices,
        //                        "The mesh vertices")
        // .def_property_readonly("faces", &Trimesh2D::faces, "The mesh faces")
        .def("__str__", &Trimesh2D::to_string, "Converts the mesh to a string",
             py::is_operator())
        .def("__repr__", &Trimesh2D::to_string, "Converts the mesh to a string",
             py::is_operator())
        .def("__lshift__", &Trimesh2D::operator<<,
             "Applies affine transformation to the mesh", "affine"_a,
             py::is_operator());

    py::class_<Trimesh3D, std::shared_ptr<Trimesh3D>>(
        m, "Trimesh3D", "Defines 3D trimesh class.")
        // .def(py::init<std::vector<const types::Point3D> &,
        //               std::unordered_set<const face_t> &>(),
        //      "Creates a trimesh from vertices and faces", "vertices"_a,
        //      "faces"_a)
        // .def_property_readonly("vertices", &Trimesh3D::vertices,
        //                        "The mesh vertices")
        // .def_property_readonly("faces", &Trimesh3D::faces, "The mesh faces")
        .def("get_triangle", &Trimesh3D::get_triangle,
             "Gets a mesh triangle from a face", "face"_a)
        .def("get_triangles", &Trimesh3D::get_triangles,
             "Gets all mesh triangles")
        .def("signed_volume", &Trimesh3D::signed_volume,
             "Computes the signed volume of the mesh")
        .def("flip_inside_out", &Trimesh3D::flip_inside_out,
             "Flips the mesh inside out")
        .def("__str__", &Trimesh3D::to_string, "Converts the mesh to a string")
        .def("__repr__", &Trimesh3D::to_string, "Converts the mesh to a string")
        .def("__or__", &Trimesh3D::operator|,
             "Computes the union of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__and__", &Trimesh3D::operator&,
             "Computes the intersection of two "
             "3D meshes",
             "other"_a, py::is_operator())
        .def("__sub__", &Trimesh3D::operator-,
             "Computes the difference of two 3D meshes", "other"_a,
             py::is_operator())
        .def("__lshift__", &Trimesh3D::operator<<,
             "Applies affine transformation to 3D mesh", "affine"_a,
             py::is_operator());
}

}  // namespace trimesh
}  // namespace cpu
}  // namespace fast_trimesh
