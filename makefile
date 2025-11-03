# Qt GUI build and run (combined)
.PHONY: gui

gui:
	cd gui/ChaoticPlants && mkdir -p build && cd build && cmake .. && $(MAKE) && ./ChaoticPlants
.PHONY: cmake_test


# Makefile for COS214_Project_2025

CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra $(QT_INCLUDES)
QT_DIR = /home/blegibz/Qt/6.10.0/gcc_64
QT_INCLUDES = -I$(QT_DIR)/include -I$(QT_DIR)/include/QtCore -I$(QT_DIR)/include/QtGui -I$(QT_DIR)/include/QtWidgets
QT_LIBS = -L$(QT_DIR)/lib -lQt6Core -lQt6Gui -lQt6Widgets
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# Find all source files in src subfolders
SRC_DIRS = src/Greenhouse src/Staff src/Customer
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
# Add ONLY Nursery.cpp but NOT mainwindow.cpp
SRCS += src/Nursery/Nursery.cpp
SRCS := $(filter-out %_test.cpp %Test.cpp, $(SRCS))
SRCS := $(filter-out src/Nursery/mainwindow.cpp, $(SRCS))  # ← EXCLUDE mainwindow.cpp

OBJS = $(SRCS:.cpp=.o)


# Main target for TestingMain.cpp
TARGET = TestingMain


all: $(TARGET)


$(TARGET): TestingMain.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(QT_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: $(TARGET)
	./$(TARGET)

# Test target (if you add test files in tests/)
TEST_SRCS = $(wildcard tests/*.cpp)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_TARGET = run_tests

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Valgrind targets
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

valgrind_test: $(TEST_TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TEST_TARGET)

# GDB targets
gdb: $(TARGET)
	gdb ./$(TARGET)

gdb_test: $(TEST_TARGET)
	gdb ./$(TEST_TARGET)

# Coverage targets
coverage: clean_gcda CXXFLAGS += $(GCOV_FLAGS)
coverage: clean $(TARGET)
	./$(TARGET)

coverage_test: clean_gcda CXXFLAGS += $(GCOV_FLAGS)
coverage_test: clean $(TEST_TARGET)
	./$(TEST_TARGET)

report: coverage
	rm -rf gcovr-report
	mkdir gcovr-report
	gcovr --root . --html --html-details --output gcovr-report/coverage.html

clean_gcda:
	rm -f *.gcda *.gcno

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET) *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt

.PHONY: all run clean test valgrind valgrind_test gdb gdb_test coverage coverage_test report clean_gcda

# Run CMake and execute unit tests
unit_tests:
	mkdir -p build
	cd build && cmake .. && $(MAKE)
	cd build && ctest --output-on-failure