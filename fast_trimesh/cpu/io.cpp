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
        auto face = mesh.get_face(i);
        auto triangle =
            geometry::Triangle3D(mesh.get_vertex(std::get<0>(face)),
                                 mesh.get_vertex(std::get<1>(face)),
                                 mesh.get_vertex(std::get<2>(face)));
        auto normal = geometry::normal(triangle);
        f.write(reinterpret_cast<const char *>(&normal), 3 * sizeof(float));

        // Vertices.
        auto v1 = mesh.get_vertex(std::get<0>(face)),
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

void add_modules(py::module &m) {
    py::module s = m.def_submodule("io");
    s.doc() = "CPU IO implementation.";

    s.def("save_stl", &save_stl, "Saves a mesh to an STL file", "filename"_a,
          "mesh"_a);
}

}  // namespace io
}  // namespace cpu
}  // namespace fast_trimesh
