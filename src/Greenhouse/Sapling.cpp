#include "Sapling.h"
#include "Prime.h"
#include "Plant.h"

/**
 * @brief Gets the next developmental stage after Sapling
 * @return StageOfDevelopment* Pointer to a new Prime instance
 * 
 * When a sapling matures, it transitions to the Prime (mature) stage.
 * The caller is responsible for deleting the returned object.
 */
StageOfDevelopment* Sapling::getNextStage()
{
    return new Prime();
}

/**
 * @brief Handles plant behavior in the Sapling stage
 * @param plant Pointer to the Plant context
 * 
 * This method implements sapling-specific behavior such as:
 * - Monitoring growth progress toward maturity
 * - Triggering state transition to Prime when fully grown
 * - Implementing sapling-specific characteristics like faster growth rate
 * - Handling environmental factors affecting young plants
 */
void Sapling::handle(Plant* plant)
{
    // Example implementation:
    // if (plant->getGrowthProgress() >= MATURITY_THRESHOLD) {
    //     plant->setState(new Prime());
    // }
    // plant->increaseSize(SAPLING_GROWTH_RATE);
}

/**
 * @brief Constructs a new Sapling object
 * 
 * Initializes the sapling stage with appropriate properties
 * for a young, growing plant.
 */
Sapling::Sapling() {
    // Initialization code for sapling stage
    // Could set initial size, growth rate, etc.
}

/**
 * @brief Destroys the Sapling object
 * 
 * Cleans up any resources specific to the Sapling stage.
 */
Sapling::~Sapling()
{
    // Cleanup code if needed
}