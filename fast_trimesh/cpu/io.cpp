#include "io.h"

#include <fstream>
#include <iostream>

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace io {

void save_stl(const std::string &filename, const trimesh::Trimesh3D &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out | std::ios::binary);

    // 80 byte header.
    f.write("fast_trimesh STL file", 80);

    // Number of triangles.
    uint32_t num_triangles = mesh.num_faces();
    f.write(reinterpret_cast<char *>(&num_triangles), sizeof(uint32_t));

    // Write each triangle.
    for (size_t i = 0; i < num_triangles; i++) {
        // Normal.
        std::tuple<int, int, int> face = mesh.get_face(i);
        geometry::Triangle3D triangle(mesh.get_vertex(std::get<0>(face)),
                                      mesh.get_vertex(std::get<1>(face)),
                                      mesh.get_vertex(std::get<2>(face)));
        geometry::Point3D normal = geometry::normal(triangle);
        f.write(reinterpret_cast<const char *>(&normal), 3 * sizeof(float));

        // Vertices.
        geometry::Point3D v1 = mesh.get_vertex(std::get<0>(face)),
                          v2 = mesh.get_vertex(std::get<1>(face)),
                          v3 = mesh.get_vertex(std::get<2>(face));
        f.write(reinterpret_cast<const char *>(&v1), 3 * sizeof(float));
        f.write(reinterpret_cast<const char *>(&v2), 3 * sizeof(float));
        f.write(reinterpret_cast<const char *>(&v3), 3 * sizeof(float));

        // Attribute byte count.
        uint16_t attribute_byte_count = 0;
        f.write(reinterpret_cast<char *>(&attribute_byte_count),
                sizeof(uint16_t));
    }

    f.close();
}

trimesh::Trimesh3D load_stl(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in | std::ios::binary);

    // 80 byte header.
    char header[80];
    f.read(header, 80);

    // Number of triangles.
    uint32_t num_triangles;
    f.read(reinterpret_cast<char *>(&num_triangles), sizeof(uint32_t));

    trimesh::Trimesh3D mesh;

    // Keeps track of the unique vertices.
    std::map<geometry::Point3D, size_t> vertex_map;

    // Lambda function to get the index of a vertex.
    auto get_vertex_index = [&vertex_map,
                             &mesh](const geometry::Point3D &vertex) {
        if (vertex_map.find(vertex) == vertex_map.end()) {
            size_t index = mesh.add_vertex(vertex);
            vertex_map[vertex] = index;
        }
        return vertex_map[vertex];
    };

    // Read each triangle.
    for (size_t i = 0; i < num_triangles; i++) {
        // Normal.
        geometry::Point3D normal;
        f.read(reinterpret_cast<char *>(&normal), 3 * sizeof(float));

        // Vertices.
        geometry::Point3D v1, v2, v3;
        f.read(reinterpret_cast<char *>(&v1), 3 * sizeof(float));
        f.read(reinterpret_cast<char *>(&v2), 3 * sizeof(float));
        f.read(reinterpret_cast<char *>(&v3), 3 * sizeof(float));

        // Add the vertices.
        size_t v1_index = get_vertex_index(v1), v2_index = get_vertex_index(v2),
               v3_index = get_vertex_index(v3);

        // Add the triangle face.
        mesh.add_face(v1_index, v2_index, v3_index);

        // Attribute byte count.
        uint16_t attribute_byte_count;
        f.read(reinterpret_cast<char *>(&attribute_byte_count),
               sizeof(uint16_t));
    }

    f.close();

    return mesh;
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("io");
    s.doc() = "CPU IO implementation.";

    s.def("save_stl", &save_stl, "Saves a mesh to an STL file", "filename"_a,
          "mesh"_a);
    s.def("load_stl", &load_stl, "Loads a mesh from an STL file", "filename"_a);
}

}  // namespace io
}  // namespace cpu
}  // namespace fast_trimesh
