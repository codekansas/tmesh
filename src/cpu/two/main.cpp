#include "main.h"

#include "boolean.h"
#include "bvh.h"
#include "io.h"
#include "types.h"

namespace trimesh {

void add_2d_modules(py::module &m) {
    add_2d_types_modules(m);
    add_2d_bvh_modules(m);
    add_2d_boolean_modules(m);
    add_2d_io_modules(m);
}

}  // namespace trimesh
