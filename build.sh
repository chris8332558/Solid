#!/bin/bash

# Set variables
PROJECT_ROOT=$(pwd)
BUILD_DIR="build"
BUILD_TYPE="Release"  # Change to "Debug" if needed

# Function to print messages
print_message() {
    echo "===> $1"
}

# Create and enter build directory
print_message "Creating build directory"
mkdir -p $BUILD_DIR
cd $BUILD_DIR || exit

# Configure CMake
print_message "Configuring CMake"
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..

# Build the project
print_message "Building the project"
cmake --build . --config $BUILD_TYPE -- -j$(nproc)

# Return to the original directory
cd $PROJECT_ROOT || exit

print_message "Build completed successfully."
