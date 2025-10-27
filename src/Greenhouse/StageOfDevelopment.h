#ifndef STAGEOFDEVELOPMENT_H
#define STAGEOFDEVELOPMENT_H

#include <iostream>
using namespace std;

// Forward declaration
class Plant;

/**
 * @class StageOfDevelopment
 * @brief Abstract base class defining the interface for all plant growth stages
 * 
 * This class implements the State pattern for managing plant growth stages.
 * Each concrete state (Seed, Sapling, Prime, Wilting, Dead) inherits from
 * this class and provides specific behavior for that stage of development.
 * 
 * The State pattern allows a Plant object to change its behavior when its
 * internal state changes, without changing the Plant class itself.
 * 
 * @see Plant
 * @see Seed
 * @see Sapling
 * @see Prime
 * @see Wilting
 * @see Dead
 */
class StageOfDevelopment {
public:
    /**
     * @brief Handles plant behavior specific to the current development stage
     * @param plant Pointer to the Plant context that owns this state
     * 
     * This pure virtual method must be implemented by concrete states to
     * define stage-specific behavior and potentially trigger state transitions.
     * 
     * @par Example behaviors:
     * - Seed: Check germination conditions
     * - Sapling: Monitor growth toward maturity
     * - Prime: Handle flowering/fruiting and aging
     * - Wilting: Manage decline process
     * - Dead: Perform no operations (terminal state)
     */
    virtual void handle(Plant* plant) = 0;
    
    /**
     * @brief Gets the next developmental stage in the plant's life cycle
     * @return Pointer to the next StageOfDevelopment object
     * 
     * This pure virtual method must be implemented by concrete states to
     * define the state transition logic. The caller is responsible for
     * managing the memory of the returned object.
     * 
     * @note For terminal states (like Dead), this should return nullptr
     * to indicate no further transitions are possible.
     */
    virtual StageOfDevelopment* getNextStage() = 0;
    
    /**
     * @brief Default constructor for StageOfDevelopment
     * 
     * Initializes the base state properties. Can be extended by
     * derived classes to set stage-specific initial values.
     */
    StageOfDevelopment();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     * 
     * Ensures proper cleanup of derived class objects when deleted
     * through a base class pointer.
     */
    virtual ~StageOfDevelopment();

};

#endif