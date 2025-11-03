#!/bin/bash

# Script to build and run the Chaotic Plants GUI

set -e

echo "======================================"
echo "Chaotic Plants Nursery Simulation"
echo "======================================"
echo ""

# Get the directory where the script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_DIR="${SCRIPT_DIR}/build"

# Check if build directory exists
if [ ! -d "$BUILD_DIR" ]; then
    echo "Build directory doesn't exist. Creating it..."
    mkdir -p "$BUILD_DIR"
fi

cd "$BUILD_DIR"

# Configure with CMake if needed
if [ ! -f "Makefile" ]; then
    echo "Configuring with CMake..."
    cmake ..
    echo ""
fi

# Build the project
echo "Building the project..."
make -j$(nproc)
echo ""

# Run the application
echo "Starting the simulation..."
echo "======================================"
./ChaoticPlants
