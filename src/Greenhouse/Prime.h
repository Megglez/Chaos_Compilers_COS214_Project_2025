#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include "StageOfDevelopment.h"

using namespace std;

/**
 * @class Prime
 * @brief Represents the mature/prime stage of a plant's development
 * 
 * The Prime class represents the peak maturity stage of a plant's life cycle.
 * In this stage, the plant is fully grown and may begin to show signs of aging
 * before transitioning to the Wilting stage.
 * 
 * @see StageOfDevelopment
 * @see Sapling
 * @see Wilting
 * @see Plant
 */
class Prime : public StageOfDevelopment {
public:
    /**
     * @brief Gets the next developmental stage after Prime
     * @return Pointer to a new Wilting object
     * 
     * This method implements the state transition from Prime to Wilting,
     * representing the natural aging process of a mature plant.
     * The caller is responsible for managing the memory of the returned object.
     */
    virtual StageOfDevelopment* getNextStage() override;
    
    /**
     * @brief Handles plant behavior specific to the Prime stage
     * @param plant Pointer to the Plant context that owns this state
     * 
     * This method defines the behavior for a plant in its prime stage,
     * including potential transitions to Wilting based on age, health,
     * or environmental factors.
     */
    virtual void handle(Plant* plant) override;
    
    /**
     * @brief Default constructor for Prime stage
     */
    Prime();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Prime();
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