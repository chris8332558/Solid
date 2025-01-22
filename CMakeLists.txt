cmake_minimum_required(VERSION 3.10)
project(SolidEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the shared library
add_library(SolidEngine SHARED
	src/SolidEngine.cpp
)

# Set include directories
target_include_directories(SolidEngine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Set output directory for the library
set_target_properties(SolidEngine PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# Install rules
install(TARGETS SolidEngine
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

install(FILES include/SolideEngine.hpp DESTINATION include)

# Add examples subdirectory if it exists
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/examples/CMakeLists.txt)
    add_subdirectory(examples)
endif()

# Add tests subdirectory if it exists
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt)
    add_subdirectory(tests)
endif()