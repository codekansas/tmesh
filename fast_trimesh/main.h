#include <pybind11/pybind11.h>

#include "cpu/trimesh.h"

#ifdef WITH_CUDA
#include "cuda/trimesh.h"
#endif
