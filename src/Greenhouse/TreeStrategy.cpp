/**
 * @file TreeStrategy.cpp
 * @brief Implementation of the TreeStrategy class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "TreeStrategy.h"

/**
 * @brief Implements tree-specific care behavior
 * 
 * @param care The care method string that will be displayed
 * 
 * This method outputs the current care approach being used for tree maintenance,
 * demonstrating the concrete implementation of the tree care strategy.
 */
void TreeStrategy::helpPlant(std::string& care) {
    cout << "Tree currently being cared for by: " << care << std::endl;
}

/**
 * @brief Constructs a new TreeStrategy object
 * 
 * Initializes the tree care strategy with default settings.
 */
TreeStrategy::TreeStrategy() {
    // TODO - implement TreeStrategy::TreeStrategy
}

/**
 * @brief Destroys the TreeStrategy object
 * 
 * Cleans up any resources used by the tree strategy implementation.
 */
TreeStrategy::~TreeStrategy() {
}

/**
 * @brief Creates a polymorphic copy of this TreeStrategy
 * 
 * @return CareStrategy* A new TreeStrategy instance allocated on the heap
 * 
 * This method enables the Strategy pattern to work with prototype-based
 * object creation, allowing dynamic strategy switching at runtime.
 */
CareStrategy* TreeStrategy::clone(){
    return new TreeStrategy();
}