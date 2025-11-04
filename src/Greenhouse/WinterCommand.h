/**
 * @file WinterCommand.h
 * @brief Concrete command for winter seasonal operations
 *
 * Defines the WinterCommand class which implements seasonal transition
 * commands specific to the winter season within the State pattern.
 */

#ifndef WINCOMMAND_H
#define WINCOMMAND_H

#include <iostream>
using namespace std;
#include "StateCommand.h"
#include "Inventory.h"

/**
 * @class WinterCommand
 * @brief Concrete command for executing winter seasonal transitions
 *
 * The WinterCommand class implements the StateCommand interface to handle
 * the specific operations required when transitioning to winter season.
 * This command encapsulates the logic for applying winter-specific
 * inventory adjustments and seasonal changes.
 *
 * @design
 * Implements the Command pattern as part of the seasonal state system.
 * Specifically handles the transition from autumn to winter by invoking
 * the inventory's seasonal change mechanism with winter parameters.
 * @see StateCommand
 * @see Inventory
 * @see Winter
 * @see Autumn
 */
class WinterCommand : public StateCommand
{
private:
    /**
     * @brief Reference to the inventory system
     *
     * Pointer to the inventory where winter seasonal adjustments
     * will be applied. Used to invoke seasonalChange method.
     */
    Inventory *inventory;

public:
    /**
     * @brief Executes the winter seasonal transition command
     *
     * Implements the command execution logic that triggers the
     * seasonal change from autumn to winter in the inventory system.
     *
     * @override Implements pure virtual method from StateCommand base class
     *
     * @post Inventory seasonal change is triggered (autumn → winter)
     * @post Winter-specific stock adjustments are applied
     * @post Plant development stages are updated for winter conditions
     */
    virtual void execute() override;

    /**
     * @brief Constructs a WinterCommand with inventory reference
     * @param inv Pointer to the Inventory system for seasonal operations
     *
     * Initializes the command with access to the inventory system
     * where winter seasonal adjustments will be applied.
     *
     * @pre inv must be a valid Inventory pointer
     */
    WinterCommand(Inventory *inv);

    /**
     * @brief Destructor for WinterCommand
     *
     * Cleans up WinterCommand resources. The inventory pointer
     * is not owned by this class and is not deleted.
     */
    ~WinterCommand();
};

#endif