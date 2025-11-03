/**
 * @file Command.h
 * @brief Abstract base class for command pattern implementation
 * 
 * Defines the interface for all command objects in the system.
 * This abstract class follows the Command design pattern to encapsulate
 * all information needed to perform an action or trigger an event.
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <memory>
#include "Plant.h"
using namespace std;

/**
 * @class Command
 * @brief Abstract base class for all command objects
 * 
 * The Command class defines the interface for executing operations
 * on Plant objects. Concrete command classes implement specific
 * behaviors while maintaining a uniform interface.
 * 
 * @design
 * Implements the Command pattern to encapsulate requests as objects,
 * allowing for parameterization of clients with different requests,
 * queuing of requests, and logging of operations.
 * 
 * @note All concrete commands must implement the execute method
 * @note Uses move semantics for Plant objects to transfer ownership efficiently
 * 
 * @see AddStock
 * @see RemoveStock
 * @see Plant
 */
class Command {
public:
    /**
     * @brief Executes the command operation
     * @param plant R-value reference to a Plant unique_ptr for move semantics
     * @param quantity Additional parameter specifying operation magnitude
     * 
     * Pure virtual method that concrete commands must implement.
     * Performs the specific operation defined by the concrete command class.
     * 
     * @pre plant must be a valid unique_ptr (can be empty for some commands)
     * @post The command operation is completed, plant may be moved from
     */
    virtual void execute(unique_ptr<Plant>&& plant, int quantity) = 0;
    
    /**
     * @brief Default constructor for Command base class
     */
    Command();
    
    /**
     * @brief Virtual destructor for proper polymorphic deletion
     * 
     * Ensures that derived class destructors are called properly
     * when deleting through a base class pointer.
     */
    virtual ~Command();
};

#endif