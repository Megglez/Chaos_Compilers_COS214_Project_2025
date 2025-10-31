#include "Wilting.h"
#include "Plant.h"
#include "Dead.h"

/**
 * @brief Handles plant behavior in the Wilting stage
 * @param plant Pointer to the Plant context
 * 
 * This method implements wilting-stage specific behavior such as:
 * - Monitoring plant health for critical deterioration
 * - Triggering transition to Dead state when beyond recovery
 * - Implementing visual/behavioral signs of decline
 * - Reducing plant functions as it nears death
 * 
 * @note In a real system, you might include checks for recovery
 * (e.g., if water/nutrients are provided) before transitioning to Dead
 */
void Wilting::handle(Plant* plant) {
    plant->setStage(new Dead());
 
}

/**
 * @brief Gets the next developmental stage after Wilting
 * @return StageOfDevelopment* Pointer to a new Dead instance
 * 
 * The wilting stage naturally progresses to death as the plant
 * can no longer sustain biological functions.
 * The caller is responsible for deleting the returned object.
 */
StageOfDevelopment* Wilting::getNextStage() {
    return new Dead();
}

/**
 * @brief Constructs a new Wilting object
 * 
 * Initializes the wilting stage with properties appropriate for
 * a plant in decline, such as reduced vitality and visible signs
 * of deterioration.
 */
Wilting::Wilting() {
    // Initialization code for wilting stage
    // Could set properties like deterioration rate, visual state, etc.
}

/**
 * @brief Destroys the Wilting object
 * 
 * Cleans up any resources specific to the Wilting stage.
 */
Wilting::~Wilting() {
    // Cleanup code if needed
}

std::string Wilting::getStageName(){
    return "Wilting";
}


StageOfDevelopment* Wilting::clone(){
    return new Wilting();
}
