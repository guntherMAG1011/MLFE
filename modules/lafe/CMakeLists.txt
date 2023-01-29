# Build Libraries

set (LAFE_SOURCE_FILES
	matrixOps.cpp
)

add_library (lafe ${LAFE_SOURCE_FILES})

target_include_directories (lafe PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(lafe glfw)