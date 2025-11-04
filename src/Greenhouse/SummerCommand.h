/**
 * @file SummerCommand.h
 * @brief Concrete command for summer seasonal operations
 * 
 * Defines the SummerCommand class which implements seasonal transition
 * commands specific to the summer season within the State pattern.
 */

#ifndef SUMCOMMAND_H
#define SUMCOMMAND_H

using namespace std;
#include <iostream>
#include "StateCommand.h"
#include "Inventory.h"

/**
 * @class SummerCommand
 * @brief Concrete command for executing summer seasonal transitions
 * 
 * The SummerCommand class implements the StateCommand interface to handle
 * the specific operations required when transitioning to summer season.
 * This command encapsulates the logic for applying summer-specific
 * inventory adjustments and seasonal changes during peak growing season.
 * 
 * @design
 * Implements the Command pattern as part of the seasonal state system.
 * Specifically handles the transition from spring to summer by invoking
 * the inventory's seasonal change mechanism with summer parameters.
 * 
 * @see StateCommand
 * @see Inventory
 * @see Summer
 * @see Spring
 */
class SummerCommand: public StateCommand
{    
public:
    /**
     * @brief Executes the summer seasonal transition command
     * 
     * Implements the command execution logic that triggers the
     * seasonal change from spring to summer in the inventory system.
     * 
     * @override Implements pure virtual method from StateCommand base class
     * 
     * @post Inventory seasonal change is triggered (spring → summer)
     * @post Summer-specific stock adjustments are applied
     * @post Plant development stages are updated for peak growing conditions
     */
    virtual void execute() override;
    
    /**
     * @brief Constructs a SummerCommand with inventory reference
     * @param inv Pointer to the Inventory system for seasonal operations
     * 
     * Initializes the command with access to the inventory system
     * where summer seasonal adjustments will be applied.
     * 
     * @pre inv must be a valid Inventory pointer
     */
    SummerCommand(Inventory* inv);
    
    /**
     * @brief Destructor for SummerCommand
     * 
     * Cleans up SummerCommand resources. The inventory pointer
     * is not owned by this class and is not deleted.
     */
    ~SummerCommand();

private:
    /**
     * @brief Reference to the inventory system
     * 
     * Pointer to the inventory where summer seasonal adjustments
     * will be applied. Used to invoke seasonalChange method.
     */
    Inventory* inventory;    
};

#endif