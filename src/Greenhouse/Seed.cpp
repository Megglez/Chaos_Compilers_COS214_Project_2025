#include "Seed.h"
#include "Sapling.h"
#include "Plant.h"

/**
 * @brief Gets the next developmental stage after Seed
 * @return StageOfDevelopment* Pointer to a new Sapling instance
 * 
 * When a seed grows, it transitions to the Sapling stage.
 * The caller is responsible for deleting the returned object.
 */
StageOfDevelopment* Seed::getNextStage()
{
    return new Sapling();
}

/**
 * @brief Handles plant behavior in the Seed stage
 * @param plant Pointer to the Plant context
 * 
 * This method could implement seed-specific behavior such as:
 * - Checking growth conditions
 * - Triggering state transition to Sapling when ready
 * - Implementing seed-specific animations or effects
 */
void Seed::handle(Plant* plant)
{
    plant->setStage(new Sapling());
}

/**
 * @brief Constructs a new Seed object
 * 
 * Initializes the seed stage. Could set up initial properties
 * or seed-specific attributes.
 */
Seed::Seed() {
    // Initialization code for seed stage
}

/**
 * @brief Destroys the Seed object
 * 
 * Cleans up any resources specific to the Seed stage.
 */
Seed::~Seed()
{
    // Cleanup code if needed
}

std::string Seed::getStageName(){
    return "Seed";
}