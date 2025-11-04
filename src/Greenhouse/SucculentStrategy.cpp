/**
 * @file SucculentStrategy.cpp
 * @brief Implementation of the SucculentStrategy class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "SucculentStrategy.h"

/**
 * @brief Implements succulent-specific care behavior
 * 
 * @param care The care method string that will be displayed
 * 
 * This method outputs the current care approach being used for succulent maintenance,
 * demonstrating the concrete implementation of succulent care strategy.
 * Succulents typically require less frequent watering and well-draining soil.
 */
void SucculentStrategy::helpPlant(std::string& care) 
{
    cout << "Succulent currently being cared for by: " << care << std::endl;
}

/**
 * @brief Constructs a new SucculentStrategy object
 * 
 * Initializes the succulent care strategy with default settings appropriate
 * for succulent plants (minimal watering, good drainage, etc.).
 */
SucculentStrategy::SucculentStrategy() 
{
    // TODO - implement SucculentStrategy::SucculentStrategy
}

/**
 * @brief Destroys the SucculentStrategy object
 * 
 * Cleans up any resources used by the succulent strategy implementation.
 */
SucculentStrategy::~SucculentStrategy()
{
}

/**
 * @brief Creates a polymorphic copy of this SucculentStrategy
 * 
 * @return CareStrategy* A new SucculentStrategy instance allocated on the heap
 * 
 * This method enables the Strategy pattern to work with prototype-based
 * object creation, allowing dynamic strategy switching at runtime for
 * succulent plants specifically.
 */
CareStrategy* SucculentStrategy::clone(){
    return new SucculentStrategy();
}