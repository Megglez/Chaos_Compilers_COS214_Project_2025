/**
 * @file RemoveStock.h
 * @brief Command class for removing stock from inventory
 * 
 * Implements the Command pattern for removing plants from the inventory.
 * This class encapsulates the operation of removing stock and allows
 * for undo/redo functionality and queuing of operations.
 */

#ifndef REMOVESTOCK_H
#define REMOVESTOCK_H

#include <iostream>
#include "Command.h"
#include <memory>
#include "Inventory.h"
#include "Plant.h"
using namespace std;

/**
 * @class RemoveStock
 * @brief Concrete command for removing plants from inventory
 * 
 * The RemoveStock class implements the Command interface to handle
 * the operation of removing plants from the inventory system. It maintains
 * a reference to the inventory and executes the remove operation when invoked.
 * 
 * This command can be used for various removal scenarios:
 * - Reducing stock quantities
 * - Removing specific plant instances
 * - Inventory management operations
 * 
 * @note Uses move semantics for plant objects to maintain consistency
 *       with the command pattern interface
 * 
 * @see Command
 * @see Inventory
 * @see Plant
 * @see AddStock
 */
class RemoveStock : public Command {
public:
    /**
     * @brief Executes the remove stock command
     * @param plant R-value reference to the plant to be removed
     * @param quantity Number of plants to remove from inventory (default: 1)
     * 
     * Removes the specified quantity of the given plant from inventory.
     * If the quantity exceeds available stock, behavior depends on the
     * inventory implementation (may remove all available or throw error).
     * 
     * @note The plant parameter is used for identification; the actual
     *       plant object may not be removed if the inventory uses a map
     *       structure with plant names as keys.
     */
    void execute(std::unique_ptr<Plant>&& plant, int quantity = 1) override;
    
    /**
     * @brief Constructs a RemoveStock command with inventory reference
     * @param inv Pointer to the Inventory instance to operate on
     * 
     * Initializes the command with a reference to the target inventory
     * where plants will be removed when the command is executed.
     * 
     * @pre inv must point to a valid Inventory object
     */
    RemoveStock(Inventory* inv);
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures proper destruction of the command object. Note that
     * the inventory pointer is not owned by this class.
     */
    virtual ~RemoveStock();

private:
    /**
     * @brief Pointer to the inventory system
     * 
     * Reference to the inventory where plants will be removed
     * when the execute method is called. This is an observer
     * reference - the RemoveStock class does not own the inventory.
     */
    Inventory* inventory;
};

#endif