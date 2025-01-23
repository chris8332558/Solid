# Create an executable target anmed Snadbox and specified the source file for it
add_executable(Sandbox src/Application.cpp)

# Links the Sandbox executable with the SolidEngine library
target_link_libraries(Sandbox PRIVATE SolidEngine)


# Adds the SolidEngine include directory to the Sandbox target
target_include_directories(Sandbox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../Solid/include
)