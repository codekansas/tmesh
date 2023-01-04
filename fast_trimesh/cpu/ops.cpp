#include "ops.h"

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace ops {

trimesh::Trimesh3D linear_extrude(const types::Polygon2D &polygon,
                                  float height) {
    trimesh::Trimesh3D mesh3d;

    // Converts polygon to a 2D trimesh, where faces are pointing upwards
    // (counter-clockwise).
    trimesh::Trimesh2D mesh2d{polygon};

    // Adds bottom face.
    auto mesh2d_vertices = mesh2d.get_vertices();
    auto mesh2d_faces = mesh2d.get_faces();
    for (int i = 0; i < mesh2d.get_vertices().size(); i++) {
        float x = mesh2d_vertices[i].x, y = mesh2d_vertices[i].y;
        mesh3d.add_vertex({x, y, 0.0f});
    }
    for (int i = 0; i < mesh2d_faces.size(); i++) {
        int v0 = std::get<0>(mesh2d_faces[i]),
            v1 = std::get<1>(mesh2d_faces[i]),
            v2 = std::get<2>(mesh2d_faces[i]);
        // Note that the order of vertices is reversed, because the face is
        // pointing downwards.
        mesh3d.add_face(v2, v1, v0);
    }

    // Adds top face.
    for (int i = 0; i < mesh2d_vertices.size(); i++) {
        float x = mesh2d_vertices[i].x, y = mesh2d_vertices[i].y;
        mesh3d.add_vertex({x, y, height});
    }
    for (int i = 0; i < mesh2d_faces.size(); i++) {
        int v0 = std::get<0>(mesh2d_faces[i]) + mesh2d_vertices.size(),
            v1 = std::get<1>(mesh2d_faces[i]) + mesh2d_vertices.size(),
            v2 = std::get<2>(mesh2d_faces[i]) + mesh2d_vertices.size();
        mesh3d.add_face(v0, v1, v2);
    }

    // Adds side faces. Each side face is a quad, meaning that it has 4 vertices
    // and 2 triangles.
    for (int i = 0; i < mesh2d_faces.size(); i++) {
        int v0 = std::get<0>(mesh2d_faces[i]),
            v1 = std::get<1>(mesh2d_faces[i]),
            v2 = std::get<2>(mesh2d_faces[i]);
        mesh3d.add_face(v0, v1, v1 + mesh2d_vertices.size());
        mesh3d.add_face(v0, v1 + mesh2d_vertices.size(),
                        v0 + mesh2d_vertices.size());
        mesh3d.add_face(v1, v2, v2 + mesh2d_vertices.size());
        mesh3d.add_face(v1, v2 + mesh2d_vertices.size(),
                        v1 + mesh2d_vertices.size());
        mesh3d.add_face(v2, v0, v0 + mesh2d_vertices.size());
        mesh3d.add_face(v2, v0 + mesh2d_vertices.size(),
                        v2 + mesh2d_vertices.size());
    }

    return mesh3d;
}

void add_modules(py::module &m) {
    py::module o = m.def_submodule("ops");
    o.doc() = "Mesh operations.";

    o.def("linear_extrude", &linear_extrude, "Linearly extrudes a 2D mesh",
          "mesh"_a, "height"_a);
}

}  // namespace ops
}  // namespace cpu
}  // namespace fast_trimesh
