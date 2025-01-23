#!/bin/bash

# Set variables
BUILD_DIR="build"

mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}

# Configure CMake
cmake ..

# Build the project
make

# Return to the original directory
cd ..

echo "Build completed successfully."