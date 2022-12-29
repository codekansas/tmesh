#pragma once

#include <tuple>
#include <vector>

namespace fast_trimesh {
namespace cpu {

class Trimesh {
   private:
    std::vector<std::tuple<float, float, float>> vertices;
    std::vector<std::tuple<int, int, int>> faces;

   public:
    Trimesh() = default;
    ~Trimesh() = default;

    // Accessor methods
    void add_vertex(float x, float y, float z);
    void add_face(int i, int j, int k);
    std::vector<std::tuple<float, float, float>> get_vertices();
    std::vector<std::tuple<int, int, int>> get_faces();

    // Boolean operators
    Trimesh operator+(const Trimesh &other);
    Trimesh operator+=(const Trimesh &other);
};

}  // namespace cpu
}  // namespace fast_trimesh
