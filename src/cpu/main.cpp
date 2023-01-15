#include "main.h"

#include "ops.h"
#include "shapes.h"
#include "three/main.h"
#include "two/main.h"
#include "types.h"

namespace fast_trimesh {
namespace cpu {

void add_cpu_modules(py::module &m) {
    types::add_types_modules(m);
    two::add_2d_modules(m);
    three::add_3d_modules(m);
    shapes::add_shapes_modules(m);
    ops::add_ops_modules(m);
}

}  // namespace cpu
}  // namespace fast_trimesh
