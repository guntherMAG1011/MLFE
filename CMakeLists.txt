# CMakeList.txt : Top-level CMake project file, do global configuration and include sub-projects here.

cmake_minimum_required (VERSION 3.8)
project ("MLFE" VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)

if (POLICY CMP0074)     # Policy to search packages at <package_name>_ROOT dir
  cmake_policy(SET CMP0074 NEW)
endif()

# Options
option (BUILD_GLFE_LIBRARY "build glfe library" ON)
option (BUILD_EXAMPLES "build examples" ON)

# Build LAFE library
message (STATUS "BUILD_GLFE_LIBRARY option is ${BUILD_GLFE_LIBRARY}")
if(BUILD_GLFE_LIBRARY)
    add_subdirectory ("modules/glfe")
endif()

# Build examples
message (STATUS "BUILD_EXAMPLES option is ${BUILD_EXAMPLES}")
if(BUILD_EXAMPLES)
    add_subdirectory ("examples")
endif()
