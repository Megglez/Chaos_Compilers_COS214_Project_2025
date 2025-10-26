/**
 * @file Stock.h
 * @brief Manages plant stock and coordinates inventory commands
 * 
 * The Stock class serves as a facade for stock management operations,
 * maintaining a local collection of plants and executing commands
 * to update the main inventory system.
 */

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include "Command.h"
#include "RemoveStock.h"
#include "AddStock.h"
#include "Inventory.h"
#include <memory>
#include "Plant.h"
using namespace std;
#include <vector>

/**
 * @class Stock
 * @brief Facade class for stock management operations
 * 
 * The Stock class provides a simplified interface for managing plant stock.
 * It maintains both a local stock list and coordinates with the main inventory
 * system using the Command pattern. This class acts as a central coordinator
 * for stock-related operations.
 * 
 * @note This class uses two separate collections: a local StockList and
 *       delegates to the main Inventory system via commands.
 * 
 * @see Inventory
 * @see Command
 * @see AddStock
 * @see RemoveStock
 */
class Stock {
public:
    /**
     * @brief Constructs a Stock manager with inventory reference
     * @param inv Pointer to the main Inventory system
     */
    Stock(Inventory* inv);
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Stock();
    
    /**
     * @brief Removes a plant from stock and inventory
     * @param plant Unique pointer to the plant to remove
     * 
     * Removes the plant from local stock and executes a remove command
     * on the main inventory system.
     */
    void Remove(std::unique_ptr<Plant> plant);
    
    /**
     * @brief Adds a plant to stock and inventory
     * @param plant Unique pointer to the plant to add
     * @param quantity Number of plants to add to inventory
     * 
     * Adds the plant to local stock and executes an add command
     * on the main inventory system with the specified quantity.
     */
    void Add(std::unique_ptr<Plant> plant, int quantity);
    
    /**
     * @brief Displays the current stock catalogue
     * 
     * Prints a formatted list of all plants in the local stock list.
     * Currently displays placeholder information.
     */
    void printStock();

private:
    Command* command; ///< Current command being executed
    Inventory* inventory; ///< Reference to the main inventory system
    std::vector<std::unique_ptr<Plant>> StockList; ///< Local collection of plants
};

#endif