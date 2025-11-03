#ifndef SAPLING_H
#define SAPLING_H

#include <iostream>
#include "StageOfDevelopment.h"

using namespace std;

/**
 * @class Sapling
 * @brief Represents the sapling stage of a plant's development
 * 
 * The Sapling class is the intermediate growth stage between Seed and Prime.
 * In this stage, the plant has germinated and is developing but is not yet mature.
 * 
 * @see StageOfDevelopment
 * @see Seed
 * @see Prime
 * @see Plant
 */
class Sapling : public StageOfDevelopment {
public:
    /**
     * @brief Gets the next developmental stage after Sapling
     * @return Pointer to a new Prime object
     * 
     * This method implements the state transition from Sapling to Prime (mature stage).
     * The caller is responsible for managing the memory of the returned object.
     */
    virtual StageOfDevelopment* getNextStage() override;
    
    /**
     * @brief Handles plant behavior specific to the Sapling stage
     * @param plant Pointer to the Plant context that owns this state
     * 
     * This method defines the behavior and potential state transitions
     * for a plant in the Sapling stage. It may trigger growth to Prime
     * based on certain conditions like time, nutrients, or environment.
     */
    virtual void handle(Plant* plant) override;
    
    /**
     * @brief Default constructor for Sapling stage
     */
    Sapling();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Sapling();
    /**
     * @brief returns the name of he current stage the plant is in
     * @return a string of the name of the curent stage
     */
    virtual std::string getStageName() override;

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
    virtual StageOfDevelopment* clone() override;
};

#endif