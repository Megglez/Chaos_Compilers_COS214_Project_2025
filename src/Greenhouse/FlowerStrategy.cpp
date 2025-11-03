#include "FlowerStrategy.h"

/**
 * @brief Implements flower-specific care behavior
 * 
 * @param care The care method string that will be displayed
 * 
 * This method outputs the current care approach being used for flower maintenance,
 * demonstrating the concrete implementation of flower care strategy.
 * Flowers typically require specific care like deadheading, proper pruning,
 * seasonal fertilization, and appropriate sunlight for optimal blooming.
 */
void FlowerStrategy::helpPlant(std::string& care) 
{
    cout << "Flower currently being cared for by: " << care << std::endl;
}

/**
 * @brief Constructs a new FlowerStrategy object
 * 
 * Initializes the flower care strategy with default settings appropriate
 * for flowering plants (proper pruning, deadheading, seasonal care, etc.).
 */
FlowerStrategy::FlowerStrategy() 
{

}

/**
 * @brief Destroys the FlowerStrategy object
 * 
 * Cleans up any resources used by the flower strategy implementation.
 */
FlowerStrategy::~FlowerStrategy()
{
}

/**
 * @brief Creates a polymorphic copy of this FlowerStrategy
 * 
 * @return CareStrategy* A new FlowerStrategy instance allocated on the heap
 * 
 * This method enables the Strategy pattern to work with prototype-based
 * object creation, allowing dynamic strategy switching at runtime for
 * flower plants specifically. This is useful for creating multiple
 * flower care strategy instances with identical behavior.
 */
CareStrategy* FlowerStrategy::clone(){
    return new FlowerStrategy();
}