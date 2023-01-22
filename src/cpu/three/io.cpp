#include "io.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace pybind11::literals;

namespace trimesh {

face_list_t get_sorted_faces(const face_list_t &faces) {
    face_list_t sorted_faces(faces.begin(), faces.end());
    std::sort(sorted_faces.begin(), sorted_faces.end());
    return sorted_faces;
}

void save_stl(const std::string &filename, const trimesh_3d_t &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out | std::ios::binary);

    // 80 byte header.
    f.write("tmesh STL file", 80);

    // Number of triangles.
    uint32_t num_triangles = mesh.faces().size();
    f.write(reinterpret_cast<char *>(&num_triangles), sizeof(uint32_t));

    // Write each triangle.
    for (auto &face : get_sorted_faces(mesh.faces())) {
        // Normal.
        triangle_3d_t triangle{mesh.vertices()[face.a], mesh.vertices()[face.b],
                               mesh.vertices()[face.c]};
        point_3d_t normal = triangle.normal();
        f.write(reinterpret_cast<const char *>(&normal), 3 * sizeof(float));

        // Vertices.
        point_3d_t v1 = mesh.vertices()[face.a], v2 = mesh.vertices()[face.b],
                   v3 = mesh.vertices()[face.c];
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

trimesh_3d_t load_stl(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in | std::ios::binary);

    // 80 byte header.
    char header[80];
    f.read(header, 80);

    // Number of triangles.
    uint32_t num_triangles;
    f.read(reinterpret_cast<char *>(&num_triangles), sizeof(uint32_t));

    std::vector<point_3d_t> vertices;
    face_set_t faces;

    // Keeps track of the unique vertices.
    std::map<point_3d_t, size_t> vertex_map;

    // Lambda function to get the index of a vertex.
    auto get_vertex_index = [&vertex_map, &vertices](const point_3d_t &vertex) {
        if (vertex_map.find(vertex) == vertex_map.end()) {
            size_t index = vertices.size();
            vertices.push_back(vertex);
            vertex_map[vertex] = index;
        }
        return vertex_map[vertex];
    };

    // Read each triangle.
    for (size_t i = 0; i < num_triangles; i++) {
        // Normal.
        point_3d_t normal;
        f.read(reinterpret_cast<char *>(&normal), 3 * sizeof(float));

        // Vertices.
        point_3d_t v1, v2, v3;
        f.read(reinterpret_cast<char *>(&v1), 3 * sizeof(float));
        f.read(reinterpret_cast<char *>(&v2), 3 * sizeof(float));
        f.read(reinterpret_cast<char *>(&v3), 3 * sizeof(float));

        // Add the vertices.
        size_t v1_index = get_vertex_index(v1), v2_index = get_vertex_index(v2),
               v3_index = get_vertex_index(v3);

        // Add the triangle face.
        faces.insert({v1_index, v2_index, v3_index});

        // Attribute byte count.
        uint16_t attribute_byte_count;
        f.read(reinterpret_cast<char *>(&attribute_byte_count),
               sizeof(uint16_t));
    }

    f.close();

    return {vertices, faces};
}

void save_stl_text(const std::string &filename, const trimesh_3d_t &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out);

    // Write the header.
    f << "solid tmesh STL file" << std::endl;

    // Write each triangle.
    for (auto &face : get_sorted_faces(mesh.faces())) {
        // Normal.
        triangle_3d_t triangle{mesh.vertices()[face.a], mesh.vertices()[face.b],
                               mesh.vertices()[face.c]};
        point_3d_t normal = triangle.normal();
        f << "facet normal " << normal.x << " " << normal.y << " " << normal.z
          << std::endl;
        f << "outer loop" << std::endl;

        // Vertices.
        point_3d_t v1 = mesh.vertices()[face.a], v2 = mesh.vertices()[face.b],
                   v3 = mesh.vertices()[face.c];
        f << "vertex " << v1.x << " " << v1.y << " " << v1.z << std::endl;
        f << "vertex " << v2.x << " " << v2.y << " " << v2.z << std::endl;
        f << "vertex " << v3.x << " " << v3.y << " " << v3.z << std::endl;

        f << "endloop" << std::endl;
        f << "endfacet" << std::endl;
    }

    // Write the footer.
    f << "endsolid tmesh STL file" << std::endl;

    f.close();
}

trimesh_3d_t load_stl_text(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in);

    // Skip the header.
    std::string line;
    std::getline(f, line);

    std::vector<point_3d_t> vertices;
    face_set_t faces;

    // Keeps track of the unique vertices.
    std::map<point_3d_t, size_t> vertex_map;

    // Lambda function to get the index of a vertex.
    auto get_vertex_index = [&vertex_map, &vertices](const point_3d_t &vertex) {
        if (vertex_map.find(vertex) == vertex_map.end()) {
            size_t index = vertices.size();
            vertices.push_back(vertex);
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
        return point_3d_t{x, y, z};
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
        point_3d_t v1 = read_point(line);
        std::getline(f, line);
        point_3d_t v2 = read_point(line);
        std::getline(f, line);
        point_3d_t v3 = read_point(line);

        // Add the vertices.
        size_t v1_index = get_vertex_index(v1), v2_index = get_vertex_index(v2),
               v3_index = get_vertex_index(v3);

        // Add the triangle face.
        faces.insert({v1_index, v2_index, v3_index});

        // Skip "endloop" and "endfacet".
        std::getline(f, line);
        std::getline(f, line);
    }

    f.close();

    return {vertices, faces};
}

void save_obj(const std::string &filename, const trimesh_3d_t &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out);

    // Write the vertices.
    for (auto &vertex : mesh.vertices()) {
        f << "v " << vertex.x << " " << vertex.y << " " << vertex.z
          << std::endl;
    }

    // Write the faces.
    for (auto &face : get_sorted_faces(mesh.faces())) {
        f << "f " << face.a + 1 << " " << face.b + 1 << " " << face.c + 1
          << std::endl;
    }

    f.close();
}

trimesh_3d_t load_obj(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in);

    std::vector<point_3d_t> vertices;
    face_set_t faces;

    // Keeps track of the unique vertices.
    std::map<point_3d_t, size_t> vertex_map;

    std::string line;
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v") {
            // Vertex.
            float x, y, z;
            ss >> x >> y >> z;
            vertices.push_back({x, y, z});
        } else if (type == "f") {
            // Face.
            size_t v1, v2, v3;
            ss >> v1 >> v2 >> v3;
            faces.insert({v1 - 1, v2 - 1, v3 - 1});
        }
    }

    f.close();

    return {vertices, faces};
}

void save_ply(const std::string &filename, const trimesh_3d_t &mesh) {
    std::ofstream f;
    f.open(filename, std::ios::out);

    // Write the header.
    f << "ply" << std::endl;
    f << "format ascii 1.0" << std::endl;
    f << "element vertex " << mesh.vertices().size() << std::endl;
    f << "property float x" << std::endl;
    f << "property float y" << std::endl;
    f << "property float z" << std::endl;
    f << "element face " << mesh.vertices().size() << std::endl;
    f << "property list uchar int vertex_index" << std::endl;
    f << "end_header" << std::endl;

    // Write the vertices.
    for (auto &vertex : mesh.vertices()) {
        f << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
    }

    // Write the faces.
    for (auto &face : get_sorted_faces(mesh.faces())) {
        f << "3 " << face.a << " " << face.b << " " << face.c << std::endl;
    }

    f.close();
}

trimesh_3d_t load_ply(const std::string &filename) {
    std::ifstream f;
    f.open(filename, std::ios::in);

    // Skip the header.
    std::string line;
    while (std::getline(f, line)) {
        if (line == "end_header") {
            break;
        }
    }

    std::vector<point_3d_t> vertices;
    face_set_t faces;

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
            vertices.push_back({x, y, z});
        } else if (num_spaces == 3 && line.substr(0, 2) == "3 ") {
            // Face.
            size_t start, v1, v2, v3;
            ss >> start >> v1 >> v2 >> v3;
            faces.insert({v1, v2, v3});
        }
    }

    f.close();

    return {vertices, faces};
}

void add_3d_io_modules(py::module &m) {
    m.def("save_stl", &save_stl, "Saves a mesh to an STL file", "filename"_a,
          "mesh"_a);
    m.def("load_stl", &load_stl, "Loads a mesh from an STL file", "filename"_a);

    m.def("save_stl_text", &save_stl_text,
          "Saves a mesh to an STL file in text format", "filename"_a, "mesh"_a);
    m.def("load_stl_text", &load_stl_text,
          "Loads a mesh from an STL file in text format", "filename"_a);

    m.def("save_obj", &save_obj, "Saves a mesh to an OBJ file", "filename"_a,
          "mesh"_a);
    m.def("load_obj", &load_obj, "Loads a mesh from an OBJ file", "filename"_a);

    m.def("save_ply", &save_ply, "Saves a mesh to a PLY file", "filename"_a,
          "mesh"_a);
    m.def("load_ply", &load_ply, "Loads a mesh from a PLY file", "filename"_a);
}

}  // namespace trimesh
