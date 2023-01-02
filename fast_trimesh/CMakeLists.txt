cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(fast_trimesh LANGUAGES CXX)
set(LIBRARY_NAME fast_trimesh)

# Sets C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Shared library settings
if(APPLE)
  set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
elseif(WIN32)
  message(FATAL_ERROR "Windows is not supported")
endif()

# Finds Python and PyBind11 depeendencies.
find_package(PythonLibs REQUIRED)
find_package(pybind11 REQUIRED)

# Main package files.
file(GLOB SRC_FILES *.cpp)

# C++ backend files.
file(GLOB_RECURSE SRC_CPP_FILES cpu/*.cpp)
set_source_files_properties(${SRC_CPP_FILES} PROPERTIES LANGUAGE CXX)
set(SRC_FILES ${SRC_FILES} ${SRC_CPP_FILES})

# Include CUDA, if available.
include(CheckLanguage)
check_language(CUDA)
if(CMAKE_CUDA_COMPILER)
  enable_language(CUDA)
  set(CMAKE_CUDA_STANDARD 17)
  set(CMAKE_CUDA_STANDARD_REQUIRED ON)
  set(CMAKE_CUDA_EXTENSIONS OFF)

  # CUDA backend files.
  file(GLOB_RECURSE SRC_CUDA_FILES cuda/*.cu)
  file(GLOB_RECURSE SRC_CPP_FILES cuda/*.cpp)
  set_source_files_properties(${SRC_CUDA_FILES} PROPERTIES LANGUAGE CUDA)
  set_source_files_properties(${SRC_CPP_FILES} PROPERTIES LANGUAGE CXX)
  set(SRC_FILES ${SRC_FILES} ${SRC_CPP_FILES} ${SRC_CUDA_FILES})
  add_definitions(-DWITH_CUDA)

else()
  message(WARNING "CUDA not found, building without CUDA support")
endif()

pybind11_add_module(${LIBRARY_NAME} ${SRC_FILES})
