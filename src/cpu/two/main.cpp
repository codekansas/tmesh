#include "main.h"

#include "boolean.h"
#include "bvh.h"
#include "types.h"

namespace fast_trimesh {
namespace cpu {
namespace two {

void add_2d_modules(py::module &m) {
    types::add_2d_types_modules(m);
    bvh::add_2d_bvh_modules(m);
    boolean::add_2d_boolean_modules(m);
}

}  // namespace two
}  // namespace cpu
}  // namespace fast_trimesh
