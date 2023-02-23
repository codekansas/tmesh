#include "io.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace pybind11::literals;

namespace trimesh {

void save_svg(const std::string &filename, const trimesh_2d_t &mesh,
              double stroke_width_mul) {
    check_file_ext(filename, "svg");

    std::ofstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Could not open file");

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>"
         << std::endl;

    bounding_box_2d_t bbox{mesh.vertices()};

    // Viewport is the cropped area around the mesh.
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" "
         << "width=\"100%\" height=\"100%\" "
         << "viewBox=\"" << bbox.min.x - 1 << " " << bbox.min.y - 1 << " "
         << 2 + bbox.max.x - bbox.min.x << " " << 2 + bbox.max.y - bbox.min.y
         << "\">" << std::endl;

    // Gets stroke width as 1/200th of the bounding box.
    double stroke_width =
        stroke_width_mul * 0.005 *
        std::max(bbox.max.x - bbox.min.x, bbox.max.y - bbox.min.y);

    // Writes all vertices.
    for (const auto &t : mesh.get_triangles()) {
        file << "<polygon points=\"";
        for (const auto &v : t.vertices()) {
            file << v.x << "," << v.y << " ";
        }
        file << "\" style=\""
             << "fill:rgb(255,255,255)"
             << ";stroke-width:" << stroke_width << ";stroke:rgb(0,0,0)"
             << ";stroke-linejoin:round"
             << "\" />" << std::endl;
    }

    file << "</svg>" << std::endl;
}

void add_2d_io_modules(py::module &m) {
    m.def("save_svg", &save_svg, "filename"_a, "mesh"_a,
          "stroke_width_mul"_a = 1.0);
}

}  // namespace trimesh
