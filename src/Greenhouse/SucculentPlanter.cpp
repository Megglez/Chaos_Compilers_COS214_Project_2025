/**
 * @file SucculentPlanter.cpp
 * @brief Implementation of the SucculentPlanter class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "SucculentPlanter.h"
#include "SucculentPlant.h"
#include "SucculentStrategy.h"
#include "Seed.h"

/**
 * @brief Implements the factory method for creating SucculentPlant instances
 * 
 * @param name The name to assign to the newly created succulent plant
 * @return Plant* A fully configured SucculentPlant object with:
 *               - Water level: 1 (low - succulents require minimal watering)
 *               - Soil quality: 2 (well-draining soil preferred)
 *               - Sunlight level: 1 (moderate to bright indirect light)
 *               - Initial stage: Seed
 *               - Care strategy: SucculentStrategy
 *               - Provided name
 * 
 * This method demonstrates the Factory Method pattern by encapsulating the
 * complex initialization logic for SucculentPlant objects and providing sensible
 * default values optimized for succulent plant requirements.
 */
Plant* SucculentPlanter::planterMethod(std::string name) 
{
    int water = 1;      // Low water requirement - succulents are drought-tolerant
    int sunlight = 1;   // Moderate sunlight - bright indirect light preferred
    int soil = 2;       // Well-draining soil crucial for succulent health
    StageOfDevelopment* stage = new Seed();
    SucculentStrategy* state = new SucculentStrategy();
    Plant* plant = new SucculentPlant(water, soil, sunlight, stage, state, name);
    return plant;
}

/**
 * @brief Constructs a new SucculentPlanter factory object
 * 
 * Initializes the succulent planter with default settings. This factory can be
 * used to create multiple SucculentPlant instances with consistent configurations
 * optimized for succulent plant characteristics.
 */
SucculentPlanter::SucculentPlanter():Planter()
{

}

/**
 * @brief Destroys the SucculentPlanter object
 * 
 * Cleans up any resources used by the succulent planter factory.
 */
SucculentPlanter::~SucculentPlanter()
{

}