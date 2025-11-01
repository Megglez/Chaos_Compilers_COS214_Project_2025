/**
 * @file Stock.cpp
 * @brief Implementation of the Stock management class
 * 
 * Contains the implementation of stock management operations including
 * adding, removing, and displaying plants in the stock system.
 */

#include "Stock.h"

/**
 * @brief Constructs a Stock manager with inventory dependency
 * @param inv Pointer to the Inventory system for command execution
 * 
 * Initializes the Stock manager with a reference to the main inventory.
 * The inventory must remain valid for the lifetime of this Stock object.
 * 
 * @warning The inventory pointer must not be null
 */
Stock::Stock(Inventory* inv): inventory(inv) {
	
}

/**
 * @brief Destructor cleans up command resources
 * 
 * Ensures proper cleanup of any allocated command objects.
 * The inventory pointer is not owned and is not deleted.
 */
Stock::~Stock()
{
	 for (Plant* plant : StockList) {
        delete plant;
    }
}

/**
 * @brief Adds a plant to both local stock and main inventory
 * @param plant Unique pointer to the plant to add
 * @param quantity Number of plants to add to inventory
 * 
 * This method performs two operations:
 * 1. Adds the plant to the local StockList vector
 * 2. Executes an AddStock command to update the main inventory
 * 
 * @note The plant is added to StockList before being moved to the command.
 *       This may cause issues if the plant object becomes invalid after move.
 * 
 * @bug The plant is added to StockList but then moved to the command execution,
 *      which may leave an invalid entry in StockList.
 * 
 * @see AddStock
 */
void Stock::Add(std::unique_ptr<Plant> plant, int quantity){
	StockList.push_back(plant->clone());  
	command = new AddStock(inventory);
	command->execute(std::move(plant), quantity);
	delete command;  // Clean up!
    command = nullptr;
}

/**
 * @brief Removes a plant from the system
 * @param plant Unique pointer to the plant to remove
 * 
 * Executes a RemoveStock command to remove the plant from the main inventory.
 * Cleans up any previous command before creating a new one.
 * 
 * @note Currently only removes from inventory, not from local StockList
 * @todo Implement removal from local StockList to maintain consistency
 * 
 * @see RemoveStock
 */
void Stock::Remove(std::unique_ptr<Plant> plant){
	if(command){
		delete command;
	}
	command = new RemoveStock(inventory);
	command->execute(std::move(plant), 1);
	delete command;
	command = nullptr;
}

/**
 * @brief Displays the current stock catalogue
 * 
 * Prints a formatted list of all plants in the local StockList.
 * Currently shows placeholder information and needs implementation
 * to display actual plant names and types.
 * 
 * @todo Implement proper plant information display using getName() and getType()
 * @bug Prints header multiple times - once for each plant in the list
 * 
 */
void Stock::printStock(){
	std::cout << "======STOCK CATALOGUE======" << std::endl;
	for (auto it = StockList.begin(); it != StockList.end(); ++it) {
		std::cout << (*it)->getName() << "-" << (*it)->getType() << std::endl; //replace with (*it)->getName() + (*it)->getType()
	}
}

int Stock::getTotalPlants(){
	return StockList.size();
}

/**
 * @brief Returns the total number of plants in stock
 * @return size_t Number of plants in the stock list
 */
size_t Stock::getStockListSize() const {
    return StockList.size();
}

/**
 * @brief Retrieves a plant at the specified index
 * @param index Index of the plant to retrieve
 * @return Plant* Pointer to the plant at the specified index
 * @throws std::out_of_range if index is out of bounds
 */
Plant* Stock::getPlantByIndex(size_t index) {
    if (index >= StockList.size()) {
        throw std::out_of_range("Plant index out of range");
    }
    return StockList[index];
}