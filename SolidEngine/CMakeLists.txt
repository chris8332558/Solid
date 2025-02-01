# Create the shared library target named 'SolidEngine' from "src/SolidEngine.cpp"
add_library(SolidEngine SHARED
	src/Application.cpp
	src/Log.cpp
)

# Set include directories for the library
target_include_directories(SolidEngine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # Used when building the project
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/spdlog/include> # Used when building the project
    # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/Events> # Used when building the project
    $<INSTALL_INTERFACE:include> # Used when the library is installed
)

# Set output directory for the library
set_target_properties(SolidEngine PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# Install rules
install(TARGETS SolidEngine
    LIBRARY DESTINATION lib # Installs the library to the 'lib' directory
    PUBLIC_HEADER DESTINATION include # Installs public headers to the 'include' directory
)

# Installs the SolideEngine.hpp header file to the 'include' directory
install(FILES include/SolidEngine.hpp DESTINATION include)