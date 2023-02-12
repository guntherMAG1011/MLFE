# CMakeList.txt : Top-level CMake project file, do global configuration and include sub-projects here.

cmake_minimum_required (VERSION 3.8)
project ("MLFE" VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)

# Options
option (GIT_SUBMODULE "Check submodules during build" OFF)
#option (BUILD_GLFW "build glfw" OFF)
option (BUILD_LAFE_LIBRARY "build lafe library" ON)
option (BUILD_EXAMPLES "build examples" ON)

# Update submodules as needed
find_package (Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    if(GIT_SUBMODULE)
        message (STATUS "Submodules update")
        execute_process (COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message (FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# Include sub-projects.
# Build GLFW
#if(NOT EXISTS "${PROJECT_SOURCE_DIR}/3rdparty/glfw/CMakeLists.txt")
#    message (FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
#endif()
#message (STATUS "BUILD_GLFW option is ${BUILD_GLFW}")
#if(BUILD_GLFW)
#    set (GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#    set (GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#    set (GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#    add_subdirectory (3rdparty/glfw)
#endif()

# Build LAFE library
message (STATUS "BUILD_LAFE_LIBRARY option is ${BUILD_LAFE_LIBRARY}")
if(BUILD_LAFE_LIBRARY)
    add_subdirectory ("modules/lafe")
endif()

# Build examples
message (STATUS "BUILD_EXAMPLES option is ${BUILD_EXAMPLES}")
if(BUILD_EXAMPLES)
    add_subdirectory ("examples")
endif()
