# --- 1. Basic Project Setup ---
cmake_minimum_required(VERSION 3.16)
project(COS214_Project_2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

# --- Find Qt (Required for project_lib for QObject-based files like Clock.h) ---
# We only require Core and Widgets.
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# Enable automatic Qt tools for QObject classes (like Clock.h)
set(CMAKE_AUTOMOC ON) 


# --- 2. Fetch GoogleTest ---
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG      v1.14.0
)
set(GTEST_DISABLE_PTHREADS ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# --- 3. Build Your Library (project_lib) ---

# Gather all .cpp files in src/ and its subdirectories
file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*/build/.*")

# CRITICAL FIX: EXCLUDE all GUI files from the library build
# The GUI files (mainwindow.cpp, main.cpp, mainwindow.ui) should ONLY be compiled by the 'Nursery' executable.
list(REMOVE_ITEM PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Nursery/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Nursery/mainwindow.cpp
)

# Define the library with ONLY the non-GUI source files
add_library(project_lib ${PROJECT_SOURCES})
target_link_libraries(project_lib PRIVATE Qt::Core) # Link to Qt::Core for QObject support

# Add include directories (so files like Nursery.h can be found)
target_include_directories(project_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)


# --- 4. Build Your Tests ---
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
if(TEST_SOURCES)
  add_executable(run_tests ${TEST_SOURCES})
  target_link_libraries(run_tests PRIVATE project_lib GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(run_tests)
endif()


# --- 5. Delegate GUI Executable Build to Subdirectory ---
# This tells CMake to process the CMakeLists.txt file located in the src/Nursery folder.
add_subdirectory(src/Nursery)