/**
 * @file Spring.h
 * @brief Concrete spring season implementation
 * 
 * Defines the Spring class which implements the seasonal behavior
 * and transitions specific to the spring season.
 */

#ifndef SPRING_H
#define SPRING_H

#include <iostream>
#include "Seasons.h"
#include "Summer.h"
using namespace std;

/**
 * @class Spring
 * @brief Concrete implementation of the spring season state
 * 
 * The Spring class represents the spring season in the State pattern
 * hierarchy. It defines spring-specific behavior including seasonal
 * transitions and inventory adjustments for spring conditions.
 * 
 * @design
 * Implements the Seasons interface as part of the State pattern.
 * Handles transitions from spring to the next season (summer)
 * and executes spring-specific commands through the SpringCommand class.
 * 
 * @note This class follows the typical spring seasonal characteristics:
 *       - Planting and growth season begins
 *       - High stock of flowers, herbs, and trees
 *       - Plants transition from dormant to growing stages
 *       - Executes SpringCommand during construction
 * 
 * @see Seasons
 * @see Inventory
 * @see SpringCommand
 * @see Summer
 */
class Spring : public Seasons {
public:
    /**
     * @brief Handles the transition from spring to the next season
     * 
     * Implements the state transition logic for moving from spring
     * to the next season in the cycle (summer). This method
     * should update the context's state to Summer.
     * 
     * @override Implements pure virtual method from Seasons base class
     * 
     * @todo Implement the state transition to Summer
     * @note Currently contains placeholder implementation
     * 
     * @post The system transitions from spring to summer season
     */
    virtual void handleChange(Nursery* nursery) override;
    
    /**
     * @brief Returns the name of the spring season
     * @return String "spring" representing this season
     * 
     * @override Implements pure virtual method from Seasons base class
     */
    virtual string getSeason() override;
    
    /**
     * @brief Constructs a Spring season with inventory reference
     * @param inv Pointer to the Inventory system for seasonal adjustments
     * 
     * Initializes the spring season state with access to the inventory
     * system. Creates and executes a SpringCommand during construction
     * to apply spring-specific inventory adjustments.
     * 
     * @pre inv must be a valid Inventory pointer
     * @post SpringCommand is executed and commands pointer is set
     */
    Spring(Inventory* inv);
    
    /**
     * @brief Destructor for Spring season
     * 
     * Cleans up any resources specific to the spring season state.
     * The inventory pointer is not owned and is not deleted.
     */
    ~Spring();

private:
    /**
     * @brief Reference to the inventory system
     * 
     * Pointer to the inventory for making spring-specific adjustments
     * to plant quantities and development stages.
     */
    Inventory* inventory;
};

#endif