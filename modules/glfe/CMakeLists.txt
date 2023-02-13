# Build GLFE Library

set (GLFE_SOURCE_FILES
	operations.cpp
)

add_library (glfe ${GLFE_SOURCE_FILES})

set (MKL_INTERFACE_FULL "intel_lp64")
set (MKL_LINK "static")
find_package (MKL CONFIG REQUIRED)
message (STATUS "${MKL_IMPORTED_TARGETS}")
target_include_directories (glfe PUBLIC $<TARGET_PROPERTY:MKL::MKL,INTERFACE_INCLUDE_DIRECTORIES>)
target_link_libraries (glfe PUBLIC $<LINK_ONLY:MKL::MKL>)
target_compile_options (glfe PUBLIC $<TARGET_PROPERTY:MKL::MKL,INTERFACE_COMPILE_OPTIONS>)

set (Boost_USE_STATIC_LIBS ON)  # only find static libs
set (Boost_USE_DEBUG_LIBS OFF) # ignore debug libs and 
find_package (Boost REQUIRED) 
if(Boost_FOUND)
    target_include_directories (glfe PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_directories (glfe PUBLIC ${Boost_LIBRARY_DIRS})
    target_compile_options (glfe PUBLIC -DBLAZE_USE_BOOST_THREADS)
endif()

find_package (blaze REQUIRED)
if(blaze_FOUND)
   add_library (blaze_target INTERFACE)
   target_link_libraries (blaze_target INTERFACE blaze::blaze)
endif()

target_include_directories (glfe PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries (glfe PUBLIC blaze_target)