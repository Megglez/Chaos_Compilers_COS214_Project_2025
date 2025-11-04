#include "FlowerPlanter.h"
#include "FlowerPlant.h"

/**
 * @brief Implements the factory method for creating FlowerPlant instances
 * 
 * @param name The name to assign to the newly created flower plant
 * @return Plant* A fully configured FlowerPlant object with:
 *               - Water level: 4 (ample water - flowers often need consistent moisture)
 *               - Soil quality: 1 (rich, fertile soil for optimal blooming)
 *               - Sunlight level: 2 (moderate sunlight suitable for most flowering plants)
 *               - Initial stage: Seed
 *               - Care strategy: FlowerStrategy
 *               - Provided name
 *               - Seasonal winter flag
 * 
 * This method demonstrates the Factory Method pattern by encapsulating the
 * complex initialization logic for FlowerPlant objects and providing sensible
 * default values optimized for flowering plant requirements. The seasonal
 * awareness allows for appropriate behavior adjustments during winter months
 * when many flowering plants have different growth patterns.
 */
Plant* FlowerPlanter::planterMethod(string name) 
{
    int water = 4;      // Ample water requirement - flowers need consistent moisture for blooming
    int sunlight = 2;   // Moderate sunlight - many flowers thrive with balanced light exposure
    int soil = 1;       // Rich, fertile soil - flowers benefit from nutrient-rich soil for vibrant blooms
    return new FlowerPlant(water, soil, sunlight, new Seed(), new FlowerStrategy(), name, isWinter);
}

/**
 * @brief Constructs a FlowerPlanter factory with seasonal configuration
 * 
 * @param isWinter Indicates whether created plants should operate in winter mode
 * 
 * Initializes the flower planter with seasonal awareness. When isWinter is true,
 * created FlowerPlant objects will exhibit winter-specific behaviors such as
 * reduced growth rates or different care requirements appropriate for the season.
 */
FlowerPlanter::FlowerPlanter(bool isWinter) 
{
    this->isWinter = isWinter;
}

/**
 * @brief Destroys the FlowerPlanter object
 * 
 * Cleans up any resources used by the flower planter factory.
 */
FlowerPlanter::~FlowerPlanter()
{
}