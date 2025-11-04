/**
 * @file Winter.h
 * @brief Concrete winter season implementation
 * 
 * Defines the Winter class which implements the seasonal behavior
 * and transitions specific to the winter season.
 */

#ifndef WINTER_H
#define WINTER_H

#include <iostream>
using namespace std;
#include "Seasons.h"
#include "Spring.h"

/**
 * @class Winter
 * @brief Concrete implementation of the winter season state
 * 
 * The Winter class represents the winter season in the State pattern
 * hierarchy. It defines winter-specific behavior including seasonal
 * transitions and inventory adjustments for winter conditions.
 * 
 * @design
 * Implements the Seasons interface as part of the State pattern.
 * Handles transitions from winter to the next season (spring)
 * and executes winter-specific commands through the WinterCommand class.
 * Completes the seasonal cycle by transitioning back to spring.
 * 
 * @note This class follows the typical winter seasonal characteristics:
 *       - Dormant season for most plants
 *       - Low or zero stock of frost-sensitive plants
 *       - Plants in dormant or dead stages
 *       - Executes WinterCommand during construction
 * 
 * @see Seasons
 * @see Inventory
 * @see WinterCommand
 * @see Spring
 */
class Winter : public Seasons {
public:
    /**
     * @brief Handles the transition from winter to the next season
     * 
     * Implements the state transition logic for moving from winter
     * to the next season in the cycle (spring). This method
     * should update the context's state to Spring, completing the
     * seasonal cycle.
     * 
     * @override Implements pure virtual method from Seasons base class
     * 
     * @todo Implement the state transition to Spring
     * @note Currently contains placeholder implementation
     * 
     * @post The system transitions from winter to spring season
     * @post Completes the annual seasonal cycle
     */
    virtual void handleChange(Nursery* nursery) override;
    
    /**
     * @brief Returns the name of the winter season
     * @return String "winter" representing this season
     * 
     * @override Implements pure virtual method from Seasons base class
     */
    virtual string getSeason() override;
    
    /**
     * @brief Constructs a Winter season with inventory reference
     * @param inv Pointer to the Inventory system for seasonal adjustments
     * 
     * Initializes the winter season state with access to the inventory
     * system. Creates and executes a WinterCommand during construction
     * to apply winter-specific inventory adjustments.
     * 
     * @pre inv must be a valid Inventory pointer
     * @post WinterCommand is executed and commands pointer is set
     */
    Winter(Inventory* inv);
    
    /**
     * @brief Destructor for Winter season
     * 
     * Cleans up any resources specific to the winter season state.
     * The inventory pointer ownership is questioned in implementation.
     */
    ~Winter();

private:
    /**
     * @brief Reference to the inventory system
     * 
     * Pointer to the inventory for making winter-specific adjustments
     * to plant quantities and development stages.
     */
    Inventory* inventory;
};

#endif