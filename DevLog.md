# DevLog

## 2024.1.25
git: 0343f886119ef2d7676e7d2c7be41dfc05ec140d

## Setup Entry Point in SolidEngine
> Note: An empty while loop might cause `Trace/BPT trap: 5` error

Setup Entry Point in SolidEngine and create Application.cpp and let SandboxApp define 
the definition of `SolidEngine::CreateApplication()`, which returns `SandBox`.
`SolidEninge.hpp`: include all the files, so client only need to include this `SolidEngine.hpp`
```
SolidEngineProject/
├── SolidEngine/
│ ├── src/
│ │ └── Application.cpp
│ ├── include/
│ │ └── Application.hpp
│ │ └── EntryPoint.hpp
│ │ └── SolidEngine.hpp
│ ├── lib/
│ │ └── libSolidENgine.dylib
│ └── CMakeLists.txt
├── Sandbox/
│ ├── src/
│ │ └── SandboxApp.cpp
│ └── CMakeLists.txt
└── CMakeLists.txt
```

`build.sh`
The command cmake `--build . --config $BUILD_TYPE -- -j$(sysctl -n hw.logicalcpu)` is used to build a CMake project. Let's break it down:
1. `cmake --build .`: This tells CMake to build the project in the current directory.
2. `--config $BUILD_TYPE`: This specifies the build configuration (e.g., Release or Debug) as defined in the $BUILD_TYPE variable.
3. `--`: This separates CMake options from options that should be passed to the underlying build tool (like Make or Ninja).
4. `-j$(sysctl -n hw.logicalcpu)`: This is passed to the underlying build tool:
    - `-j` enables parallel builds
    - `$(sysctl -n hw.logicalcpu)` is a command substitution that gets the number of logical CPUs on macOS
The $(sysctl -n hw.logicalcpu) part queries the system for the number of logical CPU cores available. This allows the build process to utilize all available cores, potentially speeding up the compilation significantly.


## 2024.1.22
git: 76fd36297912db4b45574fe742e9025c0f85939c

## Separate SolidEngine library and Application
```
SolidEngineProject/
├── SolidEngine/
│ ├── src/
│ │ └── SolidEngine.cpp
│ ├── include/
│ │ └── SolidEngine.hpp
│ ├── lib/
│ │ └── libSolidENgine.dylib
│ └── CMakeLists.txt
├── Sandbox/
│ ├── src/
│ │ └── Application.cpp
│ └── CMakeLists.txt
└── CMakeLists.txt
```
Separated the library and the application, used CMakeLists.txt files to handle building and linking.


## 2024.1.21 
git: 854118e4b7394c6c86602363130ac13a27f1cb61

## Tried to build SolidEngine shared library, and able to create SolidEngine.dylib and used it in `examples/main.cpp`

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


## Update the library
1. Add function to `.hpp` and `.cpp` file
```cpp
// SolidEngine.hpp
#pragma once

namespace SolidEngine {
	void StartEngine();
	void EndEngine(); // added
}

// SolidEngine.cpp
// other stuff...
void EndEngine() {
    std::cout << "End Engine!" << std::endl;
}

// Use it in the examples/main.cpp
#include "SolidEngine.hpp"

int main() {
	SolidEngine::StartEngine();
	SolidEngine::EndEngine();
	return 0;
}
```

2. Build the `.sh` file
```
chmod +x build_library.sh
```

3. Run the script to build your library
```
./build_library.sh
```

4. Run the example
```
./build/examples/SolidEngineExample
```