#include "TreePlanter.h"
#include "TreeStrategy.h"
#include "TreePlant.h"

/**
 * @brief Implements the factory method for creating TreePlant instances
 * 
 * @param name The name to assign to the newly created tree plant
 * @return Plant* A fully configured TreePlant object with:
 *               - Water level: 3
 *               - Soil quality: 1  
 *               - Sunlight level: 2
 *               - Initial stage: Seed
 *               - Care strategy: TreeStrategy
 *               - Provided name
 * 
 * This method demonstrates the Factory Method pattern by encapsulating the
 * complex initialization logic for TreePlant objects and providing sensible
 * default values for tree-specific attributes.
 */
Plant* TreePlanter::planterMethod(string name) 
{
    int water = 3;
    int sunlight = 2;
    int soil = 1;
    StageOfDevelopment* stage = new Seed();
    TreeStrategy* state = new TreeStrategy();
    Plant* plant = new TreePlant(water, soil, sunlight, stage, state, name);
    return plant;
}

/**
 * @brief Constructs a new TreePlanter factory object
 * 
 * Initializes the tree planter with default settings. This factory can be
 * used to create multiple TreePlant instances with consistent configurations.
 */
TreePlanter::TreePlanter() 
{

}

/**
 * @brief Destroys the TreePlanter object
 * 
 * Cleans up any resources used by the tree planter factory.
 */
TreePlanter::~TreePlanter()
{
}