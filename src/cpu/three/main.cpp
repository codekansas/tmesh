#include "main.h"

#include "boolean.h"
#include "bvh.h"
#include "io.h"
#include "types.h"

namespace trimesh {

void add_3d_modules(py::module &m) {
    add_3d_types_modules(m);
    add_3d_bvh_modules(m);
    add_3d_boolean_modules(m);
    add_3d_io_modules(m);
}

}  // namespace trimesh
