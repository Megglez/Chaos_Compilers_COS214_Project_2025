# --- 1. Basic Project Setup ---
cmake_minimum_required(VERSION 3.14)
project(COS214_Project_2025)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

# --- 2. Fetch GoogleTest ---
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG      v1.14.0
)
set(GTEST_DISABLE_PTHREADS ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# --- 3. Build Your Library ---

# Gather all .cpp files in src/ and its subdirectories, but exclude build directory
file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*/build/.*")

add_library(project_lib ${PROJECT_SOURCES})

# Optionally, add include directories if you have headers outside src
target_include_directories(project_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)


# --- 4. Build Your Tests ---
# Add all test source files in tests/ as executables
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
if(TEST_SOURCES)
  add_executable(run_tests ${TEST_SOURCES})
  target_link_libraries(run_tests PRIVATE project_lib GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(run_tests)
endif()

