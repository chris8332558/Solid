# Create an executable target named "SolidEngineExample" from the
# source file "main.cpp"
add_executable(SolidEngineExample main.cpp)

# Links the "SolidEngineExample" executable with the "SolidEngine" library
# PRIVATE means the library is only used to build this target, not any dependent targets
target_link_libraries(SolidEngineExample PRIVATE SolidEngine)