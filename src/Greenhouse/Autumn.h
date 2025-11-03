/**
 * @file Autumn.h
 * @brief Concrete autumn season implementation
 * 
 * Defines the Autumn class which implements the seasonal behavior
 * and transitions specific to the autumn season.
 */

#ifndef AUTUMN_H
#define AUTUMN_H

#include <iostream>
using namespace std;
#include "Seasons.h"
#include "Winter.h"

/**
 * @class Autumn
 * @brief Concrete implementation of the autumn season state
 * 
 * The Autumn class represents the autumn season in the State pattern
 * hierarchy. It defines autumn-specific behavior including seasonal
 * transitions and inventory adjustments for autumn conditions.
 * 
 * @design
 * Implements the Seasons interface as part of the State pattern.
 * Handles transitions from autumn to the next season (typically winter)
 * and executes autumn-specific commands through the AutumnCommand class.
 * 
 * @note This class follows the typical autumn seasonal characteristics:
 *       - Plants begin to wilt and die back
 *       - Trees are prime for planting
 *       - Summer plants are phased out
 *       - Executes AutumnCommand during construction
 * 
 * @see Seasons
 * @see Inventory
 * @see AutumnCommand
 * @see Winter
 */
class Autumn : public Seasons {
public:
    /**
     * @brief Handles the transition from autumn to the next season
     * 
     * Implements the state transition logic for moving from autumn
     * to the next season in the cycle (typically winter). This method
     * should update the context's state to Winter.
     * 
     * @override Implements pure virtual method from Seasons base class
     * 
     * @todo Implement the state transition to Winter
     * @note Currently contains placeholder implementation
     * 
     * @post The system transitions from autumn to winter season
     */
    virtual void handleChange(Nursery* nursery) override;
    
    /**
     * @brief Returns the name of the autumn season
     * @return String "autumn" representing this season
     * 
     * @override Implements pure virtual method from Seasons base class
     */
    virtual std::string getSeason() override;
    
    /**
     * @brief Constructs an Autumn season with inventory reference
     * @param inv Pointer to the Inventory system for seasonal adjustments
     * 
     * Initializes the autumn season state with access to the inventory
     * system. Creates and executes an AutumnCommand during construction
     * to apply autumn-specific inventory adjustments.
     * 
     * @pre inv must be a valid Inventory pointer
     * @post AutumnCommand is executed and commands pointer is set
     */
    Autumn(Inventory* inv);
    
    /**
     * @brief Destructor for Autumn season
     * 
     * Cleans up any resources specific to the autumn season state.
     * The inventory pointer is not owned and is not deleted.
     */
    ~Autumn();

private:
    /**
     * @brief Reference to the inventory system
     * 
     * Pointer to the inventory for making autumn-specific adjustments
     * to plant quantities and development stages.
     */
    Inventory* inventory;
};

#endif