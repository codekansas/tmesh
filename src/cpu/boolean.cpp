#include "boolean.h"

#include "bvh.h"

#define TOLERANCE 1e-6

using namespace pybind11::literals;

namespace fast_trimesh {
namespace cpu {
namespace boolean {

trimesh::Trimesh3D triangulation(const types::Triangle3D &triangle,
                                 const std::vector<types::Point3D> &points) {
    trimesh::Trimesh3D mesh;

    // Checks that all points are inside the triangle.
    for (auto &point : points) {
        if (!triangle.contains(point))
            throw std::runtime_error("Point " + point.to_string() +
                                     " is not inside triangle " +
                                     triangle.to_string() + ".");
    }

    // Adds vertices to mesh.
    for (auto &point : triangle.vertices()) mesh.add_vertex(point);
    for (auto &point : points) mesh.add_vertex(point);

    // Adds super triangle to mesh.
    mesh.add_face(0, 1, 2);

    for (size_t i = 0; i < points.size(); i++) {
        auto &point = points[i];

        // Gets the triangle that contains the point.
        bool found_triangle = false;
        for (auto &face : mesh.get_face_set()) {
            auto &[a, b, c] = face;
            auto triangle = mesh.get_triangle(face);
            if (point.projects_to_triangle(triangle)) {
                mesh.add_face(a, b, i + 3);
                mesh.add_face(b, c, i + 3);
                mesh.add_face(c, a, i + 3);
                mesh.remove_face(a, b, c);
                found_triangle = true;
                break;
            }
        }
        if (!found_triangle) {
            throw std::runtime_error("Point " + point.to_string() +
                                     " was outside of the triangle " +
                                     triangle.to_string());
        }
    }

    return mesh;
}

enum boolean_op { UNION, INTERSECTION, DIFFERENCE };

trimesh::Trimesh3D mesh_op(trimesh::Trimesh3D &mesh,
                           const std::vector<trimesh::Trimesh3D> &meshes,
                           boolean_op op) {
    if (meshes.empty()) return mesh;

    // for (auto &other_mesh : meshes) {
    //     // Gets boundary volume hierarchy of each mesh.
    //     bvh::BoundaryVolumeHierarchy bvh_a(mesh);
    //     bvh::BoundaryVolumeHierarchy bvh_b(other_mesh);

    //     // Finds intersections of other mesh with main mesh.
    //     std::vector<bvh::Intersection> intersections =
    //         bvh::find_intersections(bvh_a, bvh_b);

    //     // Applies boolean operation to the main mesh.
    //     for (auto &intersection : intersections) {
    //         switch (op) {
    //             case UNION:
    //                 mesh.add_triangle(intersection.triangle);
    //                 break;
    //             case INTERSECTION:
    //                 mesh.add_triangle(intersection.triangle);
    //                 break;
    //             case DIFFERENCE:
    //                 mesh.remove_triangle(intersection.triangle);
    //                 break;
    //         }
    //     }
    // }

    return mesh;
}

trimesh::Trimesh3D mesh_union(trimesh::Trimesh3D &mesh,
                              const std::vector<trimesh::Trimesh3D> &meshes) {
    return mesh_op(mesh, meshes, UNION);
}

trimesh::Trimesh3D mesh_intersection(
    trimesh::Trimesh3D &mesh, const std::vector<trimesh::Trimesh3D> &meshes) {
    return mesh_op(mesh, meshes, INTERSECTION);
}

trimesh::Trimesh3D mesh_difference(
    trimesh::Trimesh3D &mesh, const std::vector<trimesh::Trimesh3D> &meshes) {
    return mesh_op(mesh, meshes, DIFFERENCE);
}

void add_modules(py::module &m) {
    py::module s = m.def_submodule("boolean");
    s.doc() = "Boolean operations";

    s.def("triangulation", &triangulation,
          "Gets a triangulation of a triangle and a set of points",
          "triangle"_a, "points"_a);

    s.def("union", &mesh_union, "Union of two meshes", "mesh"_a, "meshes"_a);
    s.def("intersection", &mesh_intersection, "Intersection of two meshes",
          "mesh"_a, "meshes"_a);
    s.def("difference", &mesh_difference, "Difference of two meshes", "mesh"_a,
          "meshes"_a);
}

}  // namespace boolean
}  // namespace cpu
}  // namespace fast_trimesh
