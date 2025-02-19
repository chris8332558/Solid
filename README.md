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


## To update the library:

1. Make changes to your SolidEngine library:
- Update source files in Solid/src/
- Modify or add header files in Solid/include/
- If you're adding new files, make sure to include them in Solid/CMakeLists.txt

2. Rebuild the project
This will rebuild the SolidEngine library with your change
```
./build.sh
```

3. Update Sandbox if necessary
- If you've changed the SolidEngine API, update Sandbox/src/Application.cpp accordingly
- Rebuild the project as in step 2

This process allows you to:
- Incrementally update your library
- Automatically propagate changes to dependent projects (like Sandbox)
- Maintain a clean separation between your library and applications using it

Remember to:
1. Use version control (like Git) to track changes
2. Update your library's version number if making significant changes
3. Keep your API documentation up-to-date


## Q&A
- Q: If I only changed my `Application.cpp`, do I need to run the `build.sh` file?
- A: Yes, if you make changes to your Application.cpp file, you should run the build.sh script again to recompile your project. Here's why:
    1. Incremental builds: CMake and make are designed to handle incremental builds efficiently. When you run build.sh after modifying Application.cpp:
        -  CMake will detect the changes in your source files.
        - Only the modified files and their dependencies will be recompiled.
        - The linking process will be redone to create the updated executable.
    2. Consistency: Running build.sh ensures that your entire project is in a consistent state, with all dependencies properly updated.
    3. Simplicity: The build script automates the entire build process, so you don't have to remember specific CMake commands or worry about being in the correct directory.
    4. Error detection: If your changes introduced any errors or broke any dependencies, running the full build script will catch these issues early.

    While it's possible to manually recompile just the Sandbox target if you're certain only Application.cpp has changed, using build.sh is generally safer and ensures everything is up to date. The incremental build system will minimize unnecessary recompilation, so the process should be relatively quick for small changes.