# Build Libraries

set (LAFE_SOURCE_FILES
	operations.cpp
)

add_library (lafe ${LAFE_SOURCE_FILES})

target_include_directories (lafe PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries (lafe PUBLIC ${PROJECT_SOURCE_DIR}/3rdparty/lapack/libblas.a)
target_link_libraries (lafe PUBLIC ${PROJECT_SOURCE_DIR}/3rdparty/lapack/liblapack.a)
# target_link_libraries(lafe glfw)