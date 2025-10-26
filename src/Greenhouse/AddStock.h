/**
 * @file AddStock.h
 * @brief Command class for adding stock to inventory
 * 
 * Implements the Command pattern for adding plants to the inventory.
 * This class encapsulates the operation of adding stock and allows
 * for undo/redo functionality and queuing of operations.
 */

#ifndef ADDSTOCK_H
#define ADDSTOCK_H

// AddStock.h dependencies
#include <iostream>
#include <memory>
#include "Command.h"
#include "Inventory.h"
#include "Plant.h"
using namespace std;

/**
 * @class AddStock
 * @brief Concrete command for adding plants to inventory
 * 
 * The AddStock class implements the Command interface to handle
 * the operation of adding plants to the inventory system. It maintains
 * a reference to the inventory and executes the add operation when invoked.
 * 
 * @note This class uses move semantics for plant objects to transfer ownership
 * @see Command
 * @see Inventory
 * @see Plant
 */
class AddStock : public Command
{
public:
    
    /**
     * @brief Executes the add stock command
     * @param plant R-value reference to the plant to be added
     * @param quantity Number of plants to add to inventory
     * 
     * Transfers ownership of the plant to the inventory and updates
     * the stock levels accordingly. Uses move semantics to avoid
     * unnecessary copying of plant objects.
     * 
     * @note The plant parameter is moved into the inventory, so the
     *       original unique_ptr will be empty after execution
     */
    void execute(std::unique_ptr<Plant> &&plant, int quantity) override;
    
    /**
     * @brief Constructs an AddStock command with inventory reference
     * @param inv Pointer to the Inventory instance to operate on
     * 
     * Initializes the command with a reference to the target inventory
     * where plants will be added when the command is executed.
     */
    AddStock(Inventory *inv);
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures proper destruction of the command object and any
     * resources it may hold.
     */
    virtual ~AddStock();

private:
    /**
     * @brief Pointer to the inventory system
     * 
     * Reference to the inventory where plants will be added
     * when the execute method is called.
     */
    Inventory *inventory;
};

#endif