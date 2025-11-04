/**
 * @file HerbPlanter.cpp
 * @brief Implementation of the HerbPlanter class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "HerbPlanter.h"
#include "HerbStrategy.h"
#include "HerbPlant.h"

/**
 * @brief Implements the factory method for creating HerbPlant instances
 * 
 * @param name The name to assign to the newly created herb plant
 * @return Plant* A fully configured HerbPlant object with:
 *               - Water level: 2 (moderate - herbs need consistent but not excessive watering)
 *               - Soil quality: 3 (well-draining soil crucial for herb health)
 *               - Sunlight level: 3 (good sunlight for optimal growth and flavor)
 *               - Initial stage: Seed
 *               - Care strategy: HerbStrategy
 *               - Provided name
 * 
 * This method demonstrates the Factory Method pattern by encapsulating the
 * complex initialization logic for HerbPlant objects and providing sensible
 * default values optimized for herb plant requirements. Herbs like basil,
 * mint, and rosemary thrive with these settings.
 */
Plant* HerbPlanter::planterMethod(std::string name){
    int water = 2;      // Moderate water requirement - herbs need consistent moisture
    int sunlight = 3;   // Good sunlight - most herbs require ample light for flavor
    int soil = 3;       // Well-draining soil essential to prevent root rot
    StageOfDevelopment* stage = new Seed();
    HerbStrategy* state = new HerbStrategy();
    HerbPlant* plant = new HerbPlant(water, soil, sunlight, stage, state, name);
    return plant;
}

/**
 * @brief Constructs a new HerbPlanter factory object
 * 
 * Initializes the herb planter with default settings. This factory can be
 * used to create multiple HerbPlant instances with consistent configurations
 * optimized for herb plant characteristics and growth requirements.
 */
HerbPlanter::HerbPlanter() 
{

}

/**
 * @brief Destroys the HerbPlanter object
 * 
 * Cleans up any resources used by the herb planter factory.
 */
HerbPlanter::~HerbPlanter()
{
}