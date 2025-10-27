#ifndef SEED_H
#define SEED_H

#include <iostream>
#include "StageOfDevelopment.h"

using namespace std;

/**
 * @class Seed
 * @brief Represents the initial seed stage of a plant's development
 * 
 * The Seed class is the first stage in the plant's life cycle. From this stage,
 * the plant transitions to the Sapling stage when it grows.
 * 
 * @see StageOfDevelopment
 * @see Sapling
 * @see Plant
 */
class Seed : public StageOfDevelopment {
public:
    /**
     * @brief Gets the next developmental stage after Seed
     * @return Pointer to a new Sapling object
     * 
     * This method implements the state transition from Seed to Sapling.
     * The caller is responsible for managing the memory of the returned object.
     */
    virtual StageOfDevelopment* getNextStage() override;
    
    /**
     * @brief Handles plant behavior specific to the Seed stage
     * @param plant Pointer to the Plant context that owns this state
     * 
     * This method defines the behavior and potential state transitions
     * for a plant in the Seed stage. It may trigger growth to Sapling
     * based on certain conditions.
     */
    virtual void handle(Plant* plant) override;
    
    /**
     * @brief Default constructor for Seed stage
     */
    Seed();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Seed();
};

#endif