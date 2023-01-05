#include "io.h"

#include <fstream>
#include <iostream>
#include <sstream>

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
    for (auto &face : mesh.get_face_set()) {
        // Normal.
        types::Triangle3D triangle{mesh.get_vertex(std::get<0>(face)),
                                   mesh.get_vertex(std::get<1>(face)),
                                   mesh.get_vertex(std::get<2>(face))};
        types::Point3D normal = triangle.normal();
        f.write(reinterpret_cast<const char *>(&normal), 3 * sizeof(float));

        // Vertices.
        types::Point3D v1 = mesh.get_vertex(std::get<0>(face)),
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
    std::map<types::Point3D, size_t> vertex_map;

    // Lambda function to get the index of a vertex.
    auto get_vertex_index = [&vertex_map, &mesh](const types::Point3D &vertex) {
        if (vertex_map.find(vertex) == vertex_map.end()) {
            size_t index = mesh.add_vertex(vertex);
            vertex_map[vertex] = index;
        }
        return vertex_map[vertex];
    };

    // Read each triangle.
    for (size_t i = 0; i < num_triangles; i++) {
        // Normal.
        types::Point3D normal;
        f.read(reinterpret_cast<char *>(&normal), 3 * sizeof(float));

        // Vertices.
        types::Point3D v1, v2, v3;
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

void save_stl_text(const std::string &filename,
                   const trimesh::Trimesh3D &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out);

    // Write the header.
    f << "solid fast_trimesh STL file" << std::endl;

    // Write each triangle.
    for (auto &face : mesh.get_face_set()) {
        // Normal.
        types::Triangle3D triangle{mesh.get_vertex(std::get<0>(face)),
                                   mesh.get_vertex(std::get<1>(face)),
                                   mesh.get_vertex(std::get<2>(face))};
        types::Point3D normal = triangle.normal();
        f << "facet normal " << normal.x << " " << normal.y << " " << normal.z
          << std::endl;
        f << "outer loop" << std::endl;

        // Vertices.
        types::Point3D v1 = mesh.get_vertex(std::get<0>(face)),
                       v2 = mesh.get_vertex(std::get<1>(face)),
                       v3 = mesh.get_vertex(std::get<2>(face));
        f << "vertex " << v1.x << " " << v1.y << " " << v1.z << std::endl;
        f << "vertex " << v2.x << " " << v2.y << " " << v2.z << std::endl;
        f << "vertex " << v3.x << " " << v3.y << " " << v3.z << std::endl;

        f << "endloop" << std::endl;
        f << "endfacet" << std::endl;
    }

    // Write the footer.
    f << "endsolid fast_trimesh STL file" << std::endl;

    f.close();
}

trimesh::Trimesh3D load_stl_text(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in);

    // Skip the header.
    std::string line;
    std::getline(f, line);

    trimesh::Trimesh3D mesh;

    // Keeps track of the unique vertices.
    std::map<types::Point3D, size_t> vertex_map;

    // Lambda function to get the index of a vertex.
    auto get_vertex_index = [&vertex_map, &mesh](const types::Point3D &vertex) {
        if (vertex_map.find(vertex) == vertex_map.end()) {
            size_t index = mesh.add_vertex(vertex);
            vertex_map[vertex] = index;
        }
        return vertex_map[vertex];
    };

    auto read_point = [](const std::string &line) {
        std::istringstream ss(line);
        std::string token;
        ss >> token;
        float x, y, z;
        ss >> x >> y >> z;
        return types::Point3D{x, y, z};
    };

    while (true) {
        // Checks if the next line begins with "facet", which indicates the
        // start of a triangle.
        std::getline(f, line);
        if (line.find("facet") == std::string::npos) {
            break;
        }

        // Skip "outer loop".
        std::getline(f, line);

        // Read the vertices.
        std::getline(f, line);
        types::Point3D v1 = read_point(line);
        std::getline(f, line);
        types::Point3D v2 = read_point(line);
        std::getline(f, line);
        types::Point3D v3 = read_point(line);

        // Add the vertices.
        size_t v1_index = get_vertex_index(v1), v2_index = get_vertex_index(v2),
               v3_index = get_vertex_index(v3);

        // Add the triangle face.
        mesh.add_face(v1_index, v2_index, v3_index);

        // Skip "endloop" and "endfacet".
        std::getline(f, line);
        std::getline(f, line);
    }

    f.close();

    return mesh;
}

void save_obj(const std::string &filename, const trimesh::Trimesh3D &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out);

    // Write the vertices.
    for (size_t i = 0; i < mesh.num_vertices(); i++) {
        types::Point3D vertex = mesh.get_vertex(i);
        f << "v " << vertex.x << " " << vertex.y << " " << vertex.z
          << std::endl;
    }

    // Write the faces.
    for (auto &face : mesh.get_face_set()) {
        f << "f " << std::get<0>(face) + 1 << " " << std::get<1>(face) + 1
          << " " << std::get<2>(face) + 1 << std::endl;
    }

    f.close();
}

trimesh::Trimesh3D load_obj(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in);

    trimesh::Trimesh3D mesh;

    // Keeps track of the unique vertices.
    std::map<types::Point3D, size_t> vertex_map;

    std::string line;
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v") {
            // Vertex.
            float x, y, z;
            ss >> x >> y >> z;
            mesh.add_vertex({x, y, z});
        } else if (type == "f") {
            // Face.
            int v1, v2, v3;
            ss >> v1 >> v2 >> v3;
            mesh.add_face(v1 - 1, v2 - 1, v3 - 1);
        }
    }

    f.close();

    return mesh;
}

void save_ply(const std::string &filename, const trimesh::Trimesh3D &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out);

    // Write the header.
    f << "ply" << std::endl;
    f << "format ascii 1.0" << std::endl;
    f << "element vertex " << mesh.num_vertices() << std::endl;
    f << "property float x" << std::endl;
    f << "property float y" << std::endl;
    f << "property float z" << std::endl;
    f << "element face " << mesh.num_faces() << std::endl;
    f << "property list uchar int vertex_index" << std::endl;
    f << "end_header" << std::endl;

    // Write the vertices.
    for (size_t i = 0; i < mesh.num_vertices(); i++) {
        types::Point3D vertex = mesh.get_vertex(i);
        f << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
    }

    // Write the faces.
    for (auto &face : mesh.get_face_set()) {
        f << "3 " << std::get<0>(face) << " " << std::get<1>(face) << " "
          << std::get<2>(face) << std::endl;
    }

    f.close();
}

trimesh::Trimesh3D load_ply(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in);

    // Skip the header.
    std::string line;
    while (std::getline(f, line)) {
        if (line == "end_header") {
            break;
        }
    }

    trimesh::Trimesh3D mesh;

    while (std::getline(f, line)) {
        std::istringstream ss(line);

        // If there are 2 spaces in the line, it's a vertex. Otherwise if
        // there are 3 spaces in the line and it starts with "3 " then it's a
        // face. Otherwise ignore.
        int num_spaces = std::count(line.begin(), line.end(), ' ');
        if (num_spaces == 2) {
            // Vertex.
            float x, y, z;
            ss >> x >> y >> z;
            mesh.add_vertex({x, y, z});
        } else if (num_spaces == 3 && line.substr(0, 2) == "3 ") {
            // Face.
            int start, v1, v2, v3;
            ss >> start >> v1 >> v2 >> v3;
            mesh.add_face(v1, v2, v3);
        }
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

    s.def("save_stl_text", &save_stl_text,
          "Saves a mesh to an STL file in text format", "filename"_a, "mesh"_a);
    s.def("load_stl_text", &load_stl_text,
          "Loads a mesh from an STL file in text format", "filename"_a);

    s.def("save_obj", &save_obj, "Saves a mesh to an OBJ file", "filename"_a,
          "mesh"_a);
    s.def("load_obj", &load_obj, "Loads a mesh from an OBJ file", "filename"_a);

    s.def("save_ply", &save_ply, "Saves a mesh to a PLY file", "filename"_a,
          "mesh"_a);
    s.def("load_ply", &load_ply, "Loads a mesh from a PLY file", "filename"_a);
}

}  // namespace io
}  // namespace cpu
}  // namespace fast_trimesh
