/**
 * @file AutumnCommand.h
 * @brief Concrete command for autumn seasonal operations
 * 
 * Defines the AutumnCommand class which implements seasonal transition
 * commands specific to the autumn season within the State pattern.
 */

#ifndef AUTCOMMAND_H
#define AUTCOMMAND_H

using namespace std;
#include <iostream>
#include "StateCommand.h"
#include "Inventory.h"

/**
 * @class AutumnCommand
 * @brief Concrete command for executing autumn seasonal transitions
 * 
 * The AutumnCommand class implements the StateCommand interface to handle
 * the specific operations required when transitioning to autumn season.
 * This command encapsulates the logic for applying autumn-specific
 * inventory adjustments and seasonal changes that prepare for winter.
 * 
 * @design
 * Implements the Command pattern as part of the seasonal state system.
 * Specifically handles the transition from summer to autumn by invoking
 * the inventory's seasonal change mechanism with autumn parameters.
 * This command manages the decline phase of the plant growth cycle.
 * 
 * @see StateCommand
 * @see Inventory
 * @see Autumn
 * @see Summer
 */
class AutumnCommand: public StateCommand
{
public:
    /**
     * @brief Executes the autumn seasonal transition command
     * 
     * Implements the command execution logic that triggers the
     * seasonal change from summer to autumn in the inventory system.
     * This transition marks the end of peak growth and beginning of
     * harvest and preparation for winter.
     * 
     * @override Implements pure virtual method from StateCommand base class
     * 
     * @post Inventory seasonal change is triggered (summer → autumn)
     * @post Autumn-specific stock adjustments are applied
     * @post Plant development stages are updated for harvest and decline
     * @post Preparation for winter dormancy begins
     */
    virtual void execute() override;
    
    /**
     * @brief Constructs an AutumnCommand with inventory reference
     * @param inv Pointer to the Inventory system for seasonal operations
     * 
     * Initializes the command with access to the inventory system
     * where autumn seasonal adjustments will be applied.
     * 
     * @pre inv must be a valid Inventory pointer
     */
    AutumnCommand(Inventory* inv);
    
    /**
     * @brief Destructor for AutumnCommand
     * 
     * Cleans up AutumnCommand resources. The inventory pointer
     * is not owned by this class and is not deleted.
     */
    ~AutumnCommand();

private:
    /**
     * @brief Reference to the inventory system
     * 
     * Pointer to the inventory where autumn seasonal adjustments
     * will be applied. Used to invoke seasonalChange method.
     */
    Inventory* inventory;
};

#endif