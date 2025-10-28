/**
 * @file Command.cpp
 * @brief Implementation of Command base class
 * 
 * Contains the implementation of Command class constructors and destructors.
 * Since Command is an abstract base class, most functionality is implemented
 * in concrete derived classes.
 */

#include "Command.h"

/**
 * @brief Default constructor for Command base class
 * 
 * Initializes the base class portion of Command objects.
 * Concrete command classes may extend this initialization
 * in their own constructors.
 * 
 * @note This constructor cannot be used to instantiate Command
 *       directly since the class is abstract.
 * 
 * @todo Implement any base class initialization logic needed
 */
Command::Command()
{
    // TODO - implement Command::Command
}

/**
 * @brief Virtual destructor for polymorphic cleanup
 * 
 * Provides proper cleanup for Command objects when deleted
 * through base class pointers. Ensures that derived class
 * destructors are called in the correct order.
 * 
 * @remark The destructor is virtual to support proper
 *          polymorphic deletion of derived command objects.
 */
Command::~Command()
{
}