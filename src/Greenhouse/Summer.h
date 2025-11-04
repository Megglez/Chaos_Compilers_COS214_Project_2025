/**
 * @file Summer.h
 * @brief Concrete summer season implementation
 * 
 * Defines the Summer class which implements the seasonal behavior
 * and transitions specific to the summer season.
 */

#ifndef SUMMER_H
#define SUMMER_H

#include <iostream>
using namespace std;
#include "Seasons.h"
#include "Autumn.h"

/**
 * @class Summer
 * @brief Concrete implementation of the summer season state
 * 
 * The Summer class represents the summer season in the State pattern
 * hierarchy. It defines summer-specific behavior including seasonal
 * transitions and inventory adjustments for summer conditions.
 * 
 * @design
 * Implements the Seasons interface as part of the State pattern.
 * Handles transitions from summer to the next season (autumn)
 * and executes summer-specific commands through the SummerCommand class.
 * 
 * @note This class follows the typical summer seasonal characteristics:
 *       - Peak growing season for most plants
 *       - High stock of succulents, herbs, and flowers
 *       - Plants in prime development stage
 *       - Executes SummerCommand during construction
 * 
 * @see Seasons
 * @see Inventory
 * @see SummerCommand
 * @see Autumn
 */
class Summer : public Seasons {
public:
    /**
     * @brief Handles the transition from summer to the next season
     * 
     * Implements the state transition logic for moving from summer
     * to the next season in the cycle (autumn). This method
     * should update the context's state to Autumn.
     * 
     * @override Implements pure virtual method from Seasons base class
     * 
     * @todo Implement the state transition to Autumn
     * @note Currently contains placeholder implementation
     * 
     * @post The system transitions from summer to autumn season
     */
    virtual void handleChange(Nursery* nursery) override;
    
    /**
     * @brief Returns the name of the summer season
     * @return String "summer" representing this season
     * 
     * @override Implements pure virtual method from Seasons base class
     */
    virtual std::string getSeason() override;
    
    /**
     * @brief Constructs a Summer season with inventory reference
     * @param inv Pointer to the Inventory system for seasonal adjustments
     * 
     * Initializes the summer season state with access to the inventory
     * system. Creates and executes a SummerCommand during construction
     * to apply summer-specific inventory adjustments.
     * 
     * @pre inv must be a valid Inventory pointer
     * @post SummerCommand is executed and commands pointer is set
     */
    Summer(Inventory* inv);
    
    /**
     * @brief Destructor for Summer season
     * 
     * Cleans up any resources specific to the summer season state.
     * The inventory pointer is not owned and is not deleted.
     */
    ~Summer();

private:
    /**
     * @brief Reference to the inventory system
     * 
     * Pointer to the inventory for making summer-specific adjustments
     * to plant quantities and development stages.
     */
    Inventory* inventory;
};

#endif