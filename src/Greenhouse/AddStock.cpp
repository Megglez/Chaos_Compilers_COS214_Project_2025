/**
 * @file AddStock.cpp
 * @brief Implementation of the AddStock command class
 * 
 * Contains the concrete implementation of the AddStock command
 * which handles adding plants to the inventory system.
 */

#include "AddStock.h"

/**
 * @brief Executes the add stock command
 * @param plant R-value reference to the plant to be added to inventory
 * @param quantity The number of plants to add to inventory
 * 
 * This method transfers ownership of the plant object to the inventory
 * by moving the unique_ptr. The inventory then adds the specified
 * quantity of this plant type to its stock.
 * 
 * @note After execution, the original plant unique_ptr will be empty
 *       due to the move operation. The inventory now owns the plant object.
 * 
 * @par Example:
 * @code
 * auto plant = make_unique<Plant>("Rose", "flower");
 * AddStock addCommand(&inventory);
 * addCommand.execute(move(plant), 10);  // Adds 10 rose plants
 * // 'plant' is now empty after move
 * @endcode
 * 
 * @see Inventory::addPlant
 */
void AddStock::execute(unique_ptr<Plant>&& plant, int quantity) {
	inventory->addPlant(move(plant), quantity);
}

/**
 * @brief Constructs an AddStock command with inventory reference
 * @param inv Pointer to the Inventory instance where plants will be added
 * 
 * Initializes the command with a reference to the target inventory.
 * The inventory must be valid and remain in scope for the lifetime
 * of this command object.
 * 
 * @warning The inventory pointer must not be null. The caller is responsible
 *          for ensuring the inventory object remains valid.
 */
AddStock::AddStock(Inventory* inv): inventory(inv) 
{

}

/**
 * @brief Destructor for AddStock command
 * 
 * Cleans up the AddStock command object. Note that the inventory
 * pointer is not owned by this class, so it is not deleted here.
 * 
 * @note The inventory pointer is only referenced, not owned, so
 *       no deletion occurs in the destructor.
 */
AddStock::~AddStock()
{
}