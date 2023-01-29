# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

cmake_minimum_required (VERSION 3.8)

project ("MLFE" VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)

find_package (Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option (GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message (STATUS "Submodule update")
        execute_process (COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/3rdparty/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

option (BUILD_LAFE_LIBRARY "build lafe library" ON)
message (STATUS "BUILD_LAFE_LIBRARY option is ${BUILD_LAFE_LIBRARY}")

# Include sub-projects.
add_subdirectory ("include")

if(BUILD_LAFE_LIBRARY)
    add_subdirectory ("modules/lafe")
endif()


# Build examples
option (BUILD_EXAMPLES "build examples" ON)
message (STATUS "BUILD_EXAMPLES option is ${BUILD_EXAMPLES}")

if(BUILD_EXAMPLES)
    add_subdirectory ("examples")
endif()
