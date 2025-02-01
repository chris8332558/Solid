# Create an executable target named Snadbox and specified the source file for it
add_executable(Sandbox src/SandboxApp.cpp)

# Links the Sandbox executable with the SolidEngine library
target_link_libraries(Sandbox PRIVATE SolidEngine)


# Adds the SolidEngine include directory to the Sandbox target
target_include_directories(Sandbox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../SolidEngine/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../SolidEngine/include/Events
    ${CMAKE_CURRENT_SOURCE_DIR}/../SolidEngine/thirdparty/spdlog/include
)