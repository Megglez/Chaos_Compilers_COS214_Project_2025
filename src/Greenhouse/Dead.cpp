#include "Dead.h"
#include "Plant.h"

/**
 * @brief Gets the next developmental stage after Dead
 * @return nullptr always, as Dead is a terminal state
 * 
 * This method implements the terminal nature of the Dead state by
 * always returning nullptr. This prevents any further state transitions
 * in the plant's life cycle.
 * 
 * @retval nullptr No next stage exists after death
 */
StageOfDevelopment* Dead::getNextStage()
{
    return nullptr;
}

/**
 * @brief Handles plant behavior in the Dead state
 * @param plant Pointer to the Plant context
 * 
 * In the Dead state, this method typically:
 * - Performs no operations (plant is dead)
 * - Logs the dead state for monitoring
 * - Prevents any growth or development actions
 * - May trigger cleanup or decay processes
 * 
 * @note Since the plant is dead, most operations should be no-ops
 * or the Plant context should check if it's dead before calling handle().
 */
void Dead::handle(Plant* plant)
{
    plant->setStage(nullptr);
}

/**
 * @brief Constructs a new Dead object
 * 
 * Initializes the terminal dead state. This could set flags or
 * properties indicating the plant is no longer alive.
 */
Dead::Dead() {
    // Initialization code for dead state
    // Could set: isAlive = false, trigger decay timers, etc.
}

/**
 * @brief Destroys the Dead object
 * 
 * Cleans up any resources specific to the Dead stage.
 */
Dead::~Dead()
{
    // Cleanup code if needed
}

std::string Dead::getStageName(){
    return "Dead";
}

StageOfDevelopment* Dead::clone(){  
    return new Dead();
}