# Solid

## CMakeLists.txt file does the following:
1. Sets up the project and requires C++17.
2. Creates a shared library named SolidEngine from your source file.
3. Sets up the include directories for both build and install interfaces.
4. Specifies the output directory for the compiled library as the lib folder in your project.
5. Sets up installation rules for the library and header file.
6. Optionally adds the examples and tests subdirectories if they contain their own CMakeLists.txt files.

## To build your project:
1. Create a build directory:
```
mkdir build && cd build
```
2. Run CMake:
```
cmake ..
```
3. Build the project
```
make
```
This will compile your SolidEngine library and place it in the lib directory.

## To use this shared library in another project on macOS:

1. Include the header in your source file:
```cpp
#include "SolidEngine.hpp"
```

2. When compiling your program that uses SolidEngine, link against the library:
```
g++ your_program.cpp -L/path/to/SolidEngine/lib -lSolidEngine -o your_program
```

3. Before running your program, ensure the dynamic linker can find the library:
```
export DYLD_LIBRARY_PATH=/path/to/SolidEngine/lib:$DYLD_LIBRARY_PATH
```

4. Run your program
```
./your_program
```

## Use the SolidEngine library in a main.cpp file
To use your SolidEngine library in a main.cpp file, you can add an examples directory to your existing project structure. This approach keeps your main application code within the SolidEngine project while maintaining a clear separation. Here's how to do it:

1. Update your project structure:
```
SolidEngine/
├── include/
│   └── SolidEngine.hpp
├── src/
│   └── SolidEngine.cpp
├── lib/
├── tests/
├── examples/
│   ├── main.cpp
│   └── CMakeLists.txt
├── CMakeLists.txt
└── README.md
```

2. Create examples/main.cpp:
```cpp
#include <SolidEngine.hpp>
#include <iostream>

int main() {
    // Use SolidEngine here
    SolidEngine::StartEngine();
    std::cout << "Using SolidEngine in example application" << std::endl;
    return 0;
}
```

3. Create examples/CMakeLists.txt:
```cmake
add_executable(SolidEngineExample main.cpp)
target_link_libraries(SolidEngineExample PRIVATE SolidEngine)
```

5. To build the project and the example:
```
mkdir build && cd build
cmake ..
make
```

6. After successful compilation, you'll find the executable in the build/examples directory. Run it using:
```
./examples/SolidEngineExample
```

> If you encounter any issues with finding the shared library, you may need to set the DYLD_LIBRARY_PATH environment variable (on macOS) before running:
```
export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:path/to/SolidEngine/lib
./examples/SolidEngineExample

```