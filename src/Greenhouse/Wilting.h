#ifndef WILTING_H
#define WILTING_H

#include <iostream>
#include "StageOfDevelopment.h"

using namespace std;

/**
 * @class Wilting
 * @brief Represents the wilting stage of a plant's development
 * 
 * The Wilting class represents the final decline stage before plant death.
 * In this stage, the plant shows visible signs of deterioration and is
 * transitioning toward the terminal Dead state. This is the last stage
 * where the plant might theoretically be saved (with intervention).
 * 
 * @see StageOfDevelopment
 * @see Prime
 * @see Dead
 * @see Plant
 */
class Wilting : public StageOfDevelopment {
public:
    /**
     * @brief Handles plant behavior specific to the Wilting stage
     * @param plant Pointer to the Plant context that owns this state
     * 
     * This method defines the behavior for a plant in the wilting stage,
     * including monitoring deterioration and triggering the transition
     * to Dead state when the plant can no longer be sustained.
     */
    virtual void handle(Plant* plant) override;
    
    /**
     * @brief Gets the next developmental stage after Wilting
     * @return Pointer to a new Dead object
     * 
     * This method implements the state transition from Wilting to Dead,
     * representing the final stage in the plant's life cycle.
     * The caller is responsible for managing the memory of the returned object.
     */
    virtual StageOfDevelopment* getNextStage() override;
    
    /**
     * @brief Default constructor for Wilting stage
     */
    Wilting();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Wilting();
};

#endif