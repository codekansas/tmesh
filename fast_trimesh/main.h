#pragma once

#include <pybind11/pybind11.h>

#include "cpu/main.h"

#ifdef WITH_CUDA
#include "cuda/main.h"
#endif
