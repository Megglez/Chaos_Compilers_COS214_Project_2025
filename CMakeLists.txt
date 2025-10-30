# --- 1. Basic Project Setup ---
cmake_minimum_required(VERSION 3.14)
project(COS214_Project_2025)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

# --- Add this block to your root CMakeLists.txt (COS214_Project_2025) ---

# Find Qt. We only need the Core module for Clock.h/cpp.
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# Enable automatic Qt tools. CMAKE_AUTOMOC is crucial for QObject in Clock.h
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


# --- 3. Build Your Library ---

# Gather all .cpp files (path assumed correct: src/*.cpp)
file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*/build/.*")

# 1. DEFINITIVE UI FIX: Manually invoke UIC on your .ui file at its new location
# This creates a variable (UI_HEADERS) containing the path to the generated ui_mainwindow.h
qt_wrap_ui(UI_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Nursery/mainwindow.ui # <-- NEW CORRECTED PATH
)

# 2. Add both C++ sources and the generated UI headers to the library
add_library(project_lib
    ${PROJECT_SOURCES}
    ${UI_HEADERS}
)

# 3. Ensure linking to both Core and Widgets (as per previous steps)
target_link_libraries(project_lib PRIVATE Qt::Core Qt::Widgets)

# 4. Explicitly add include directories
target_include_directories(project_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Nursery # <-- NEW CORRECTED INCLUDE PATH
)

# 5. Explicitly add include directories (especially where mainwindow.h lives)
target_include_directories(project_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Nursery 
    # We no longer need the 'project_lib_autogen/include' path because qt_wrap_ui
    # handles the generated file path directly via the ${UI_HEADERS} variable.
)


# --- 6. Build Your Tests ---
# Add all test source files in tests/ as executables
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
if(TEST_SOURCES)
  add_executable(run_tests ${TEST_SOURCES})
  target_link_libraries(run_tests PRIVATE project_lib GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(run_tests)
endif()

