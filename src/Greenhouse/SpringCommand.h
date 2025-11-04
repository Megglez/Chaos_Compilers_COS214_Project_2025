/**
 * @file SpringCommand.h
 * @brief Concrete command for spring seasonal operations
 *
 * Defines the SpringCommand class which implements seasonal transition
 * commands specific to the spring season within the State pattern.
 */

#ifndef SPRCOMMAND_H
#define SPRCOMMAND_H

#include <iostream>
using namespace std;
#include "StateCommand.h"
#include "Inventory.h"

/**
 * @class SpringCommand
 * @brief Concrete command for executing spring seasonal transitions
 *
 * The SpringCommand class implements the StateCommand interface to handle
 * the specific operations required when transitioning to spring season.
 * This command encapsulates the logic for applying spring-specific
 * inventory adjustments and seasonal changes that initiate the growing cycle.
 *
 * @design
 * Implements the Command pattern as part of the seasonal state system.
 * Specifically handles the transition from winter to spring by invoking
 * the inventory's seasonal change mechanism with spring parameters.
 * This command completes the annual seasonal cycle and begins new growth.
 *
 * @see StateCommand
 * @see Inventory
 * @see Spring
 * @see Winter
 */
class SpringCommand : public StateCommand
{
private:
    /**
     * @brief Reference to the inventory system
     *
     * Pointer to the inventory where spring seasonal adjustments
     * will be applied. Used to invoke seasonalChange method.
     */
    Inventory *inventory;

public:
    /**
     * @brief Executes the spring seasonal transition command
     *
     * Implements the command execution logic that triggers the
     * seasonal change from winter to spring in the inventory system.
     * This transition marks the end of dormancy and beginning of new growth.
     *
     * @override Implements pure virtual method from StateCommand base class
     *
     * @post Inventory seasonal change is triggered (winter → spring)
     * @post Spring-specific stock adjustments are applied
     * @post Plant development stages are updated for new growing season
     * @post Annual seasonal cycle is completed and restarted
     */
    virtual void execute() override;

    /**
     * @brief Constructs a SpringCommand with inventory reference
     * @param inv Pointer to the Inventory system for seasonal operations
     *
     * Initializes the command with access to the inventory system
     * where spring seasonal adjustments will be applied.
     *
     * @pre inv must be a valid Inventory pointer
     */
    SpringCommand(Inventory *inv);

    /**
     * @brief Destructor for SpringCommand
     *
     * Cleans up SpringCommand resources. The inventory pointer
     * is not owned by this class and is not deleted.
     */
    ~SpringCommand();
};

#endif