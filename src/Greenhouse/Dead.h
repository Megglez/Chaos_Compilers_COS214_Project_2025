#ifndef DEAD_H
#define DEAD_H

#include <iostream>
#include "StageOfDevelopment.h"

using namespace std;

/**
 * @class Dead
 * @brief Represents the terminal death stage of a plant's development
 * 
 * The Dead class is the final, terminal state in the plant's life cycle.
 * Once a plant enters this state, it cannot transition to any other stage
 * and all growth/development ceases permanently.
 * 
 * This class implements the terminal state pattern where getNextStage()
 * returns nullptr and handle() typically does nothing or performs cleanup.
 * 
 * @see StageOfDevelopment
 * @see Wilting
 * @see Plant
 */
class Dead : public StageOfDevelopment {
public:
    /**
     * @brief Gets the next developmental stage after Dead
     * @return nullptr always, as Dead is a terminal state
     * 
     * This method returns nullptr to indicate that no further state
     * transitions are possible from the Dead state.
     */
    virtual StageOfDevelopment* getNextStage() override;
    
    /**
     * @brief Handles plant behavior in the Dead state
     * @param plant Pointer to the Plant context that owns this state
     * 
     * This method typically performs no actions or implements terminal
     * behaviors such as cleanup, decay processes, or preventing further
     * operations on the dead plant.
     */
    virtual void handle(Plant* plant) override;
    
    /**
     * @brief Default constructor for Dead stage
     */
    Dead();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Dead();
    virtual std::string getStageName() override;
    virtual StageOfDevelopment* clone() override;
};

#endif