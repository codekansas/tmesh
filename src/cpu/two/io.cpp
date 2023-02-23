#include "io.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace pybind11::literals;

namespace trimesh {

void save_svg(const std::string &filename, const trimesh_2d_t &mesh) {
    std::ofstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Could not open file");

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>"
         << std::endl;

    bounding_box_2d_t bbox{mesh.vertices()};

    // Viewport is the cropped area around the mesh.
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" "
         << "width=\"100%\" height=\"100%\" "
         << "viewBox=\"" << bbox.min.x << " " << bbox.min.y << " "
         << bbox.max.x - bbox.min.x << " " << bbox.max.y - bbox.min.y << "\">"
         << std::endl;

    // Writes all vertices.
    for (const auto &t : mesh.get_triangles()) {
        file << "<polygon points=\"";
        for (const auto &v : t.vertices()) {
            file << v.x << "," << v.y << " ";
        }
        file << "\" style=\""
             << "fill:rgb(255,255,255)"
             << ";stroke-width:1"
             << ";stroke:rgb(0,0,0)"
             << ";stroke-linejoin:round"
             << "\" />" << std::endl;
    }

    file << "</svg>" << std::endl;
}

void add_2d_io_modules(py::module &m) {
    m.def("save_svg", &save_svg, "filename"_a, "mesh"_a);
}

}  // namespace trimesh
