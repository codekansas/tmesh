#include "main.h"

#include "ops.h"
#include "shapes.h"
#include "three/main.h"
#include "two/main.h"
#include "types.h"

namespace trimesh {

void add_cpu_modules(py::module &m) {
    add_types_modules(m);
    add_2d_modules(m);
    add_3d_modules(m);
    add_shapes_modules(m);
    add_ops_modules(m);
}

}  // namespace trimesh
