#include "main.h"

#include "boolean.h"
#include "bvh.h"
#include "io.h"
#include "types.h"

namespace fast_trimesh {
namespace cpu {
namespace three {

void add_3d_modules(py::module &m) {
    types::add_3d_types_modules(m);
    bvh::add_3d_bvh_modules(m);
    boolean::add_3d_boolean_modules(m);
    io::add_3d_io_modules(m);
}

}  // namespace three
}  // namespace cpu
}  // namespace fast_trimesh
