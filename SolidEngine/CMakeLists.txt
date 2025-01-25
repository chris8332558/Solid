# Create the shared library target named 'SolidEngine' from "src/SolidEngine.cpp"
add_library(SolidEngine SHARED
	src/Application.cpp
)

# Set include directories for the library
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