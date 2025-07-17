#!/bin/zsh

# This script ensures a clean build by removing the old build directory
# before each compilation. This prevents issues with stale build artifacts.

# Force remove the build directory to ensure a clean slate
echo "Cleaning previous build..."
rm -rf bin

# Create a new build directory
echo "Creating build directory..."
mkdir -p bin

# Change into the build directory
cd bin

# Generate the build system with CMake
echo "Generating build system with CMake..."
cmake ..

# Compile the project
echo "Compiling the project..."
make

# Check if the build was successful before running
if [ -f "./Quest" ]; then
    echo "Build successful! Starting the game..."
    echo "---------------------------------------"
    # Run the executable
    ./Quest
else
    echo "Build failed. Please check the compilation errors above."
fi
