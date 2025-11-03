#include "Prime.h"
#include "Wilting.h"
#include "Plant.h"

/**
 * @brief Gets the next developmental stage after Prime
 * @return StageOfDevelopment* Pointer to a new Wilting instance
 * 
 * After reaching peak maturity, the plant naturally progresses to the
 * Wilting stage as part of its life cycle.
 * The caller is responsible for deleting the returned object.
 */
StageOfDevelopment* Prime::getNextStage()
{
    return new Wilting();
}

/**
 * @brief Handles plant behavior in the Prime stage
 * @param plant Pointer to the Plant context
 * 
 * This method implements prime-stage specific behavior such as:
 * - Monitoring plant health and age for signs of decline
 * - Triggering transition to Wilting when the plant begins to age
 * - Maintaining mature plant characteristics (flowering, fruiting, etc.)
 * - Handling environmental stress that might accelerate wilting
 */
void Prime::handle(Plant* plant)
{
    
    plant->setStage(new Wilting());
}

/**
 * @brief Constructs a new Prime object
 * 
 * Initializes the prime stage with properties appropriate for a
 * fully mature plant at its peak development.
 */
Prime::Prime() {
    // Initialization code for prime stage
    // Could set mature plant properties like maximum size, fruit production rate, etc.
}

/**
 * @brief Destroys the Prime object
 * 
 * Cleans up any resources specific to the Prime stage.
 */
Prime::~Prime()
{
    // Cleanup code if needed
}


 /**
* @brief returns the name of he current stage the plant is in
* @return a string of the name of the curent stage
*/
std::string Prime::getStageName(){
    return "Prime";
}

/**
* @brief Creates a deep copy of the StageOfDevelopment object
     * 
     * @return StageOfDevelopment* A pointer to a newly allocated copy of the current object.
     * The caller is responsible for managing the memory of the returned object.
     * 
     * @note This method implements the Prototype pattern, allowing polymorphic copying
     * of derived stage objects without knowing their concrete types.
     * 
     */
StageOfDevelopment* Prime::clone(){
    return new Prime();
}