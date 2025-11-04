/**
 * @file HerbStrategy.cpp
 * @brief Implementation of the HerbStrategy class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "HerbStrategy.h"

/**
 * @brief Implements herb-specific care behavior
 * 
 * @param care The care method string that will be displayed
 * 
 * This method outputs the current care approach being used for herb maintenance,
 * demonstrating the concrete implementation of herb care strategy.
 * Herbs typically require regular harvesting, moderate watering, and good drainage.
 */
void HerbStrategy::helpPlant(std::string& care) {
    cout << "Herb currently being cared for by: " << care << std::endl;
}

/**
 * @brief Constructs a new HerbStrategy object
 * 
 * Initializes the herb care strategy with default settings appropriate
 * for herb plants (regular harvesting, moderate watering, good sunlight, etc.).
 */
HerbStrategy::HerbStrategy() {
    // TODO - implement HerbStrategy::HerbStrategy
}

/**
 * @brief Destroys the HerbStrategy object
 * 
 * Cleans up any resources used by the herb strategy implementation.
 */
HerbStrategy::~HerbStrategy()
{
}

/**
 * @brief Creates a polymorphic copy of this HerbStrategy
 * 
 * @return CareStrategy* A new HerbStrategy instance allocated on the heap
 * 
 * This method enables the Strategy pattern to work with prototype-based
 * object creation, allowing dynamic strategy switching at runtime for
 * herb plants specifically.
 */
CareStrategy* HerbStrategy::clone(){
    return new HerbStrategy();
}