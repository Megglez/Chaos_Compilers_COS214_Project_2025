/**
 * @file StateCommand.h
 * @brief Abstract base class for state pattern commands
 * 
 * Defines the StateCommand interface that serves as the base class
 * for all seasonal command implementations within the state pattern.
 */

#ifndef STATE_H
#define STATE_H

using namespace std;
#include <iostream>
#include "Inventory.h"

/**
 * @class StateCommand
 * @brief Abstract base class for seasonal state commands
 * 
 * The StateCommand class defines the interface for all concrete
 * command classes that implement seasonal operations within the
 * state pattern. This abstract base class ensures that all
 * seasonal commands provide a consistent execute() method.
 * 
 * @design
 * Implements the Command pattern as part of the seasonal state system.
 * Serves as the foundation for the four seasonal command classes:
 * SpringCommand, SummerCommand, AutumnCommand, and WinterCommand.
 * Each concrete command encapsulates the specific logic for
 * transitioning between seasons and applying seasonal adjustments.
 * 
 * @note This is a pure abstract class (interface) that cannot be
 *       instantiated directly. Concrete implementations must
 *       provide the execute() method implementation.
 * 
 * @par Seasonal Command Hierarchy:
 * - SpringCommand: Handles winter→spring transition
 * - SummerCommand: Handles spring→summer transition  
 * - AutumnCommand: Handles summer→autumn transition
 * - WinterCommand: Handles autumn→winter transition
 * 
 * @see SpringCommand
 * @see SummerCommand
 * @see AutumnCommand
 * @see WinterCommand
 * @see Inventory
 * @see Seasons
 */
class StateCommand{

public:
    /**
     * @brief Executes the state command operation
     * 
     * Pure virtual method that concrete state command classes must implement.
     * Defines the specific seasonal transition logic and inventory adjustments
     * for each season. Typically invokes Inventory::seasonalChange() with
     * appropriate seasonal parameters.
     * 
     * @post Seasonal transition is executed in the inventory system
     * @post Season-specific stock adjustments are applied
     * @post Plant development stages are updated
     * @post Staff notifications are triggered
     */
    virtual void execute() = 0;
    
    /**
     * @brief Default constructor for StateCommand base class
     * 
     * Initializes the base class portion of all state command objects.
     * Cannot be used to instantiate StateCommand directly since the
     * class is abstract due to the pure virtual execute() method.
     */
    StateCommand(){};
    
    /**
     * @brief Virtual destructor for proper polymorphic deletion
     * 
     * Ensures that derived state command class destructors are called
     * properly when deleting through base class pointers. The destructor
     * is virtual to support safe polymorphic behavior.
     * 
     * @note Even though the class is abstract, it needs a virtual
     *       destructor for proper cleanup of derived objects.
     */
    virtual ~StateCommand(){};
};

#endif