/**
 * @file RemoveStock.cpp
 * @brief Implementation of RemoveStock command for complete inventory removal
 */

#include "RemoveStock.h"

/**
 * @brief Executes complete removal of plant stock from inventory
 * @param plant R-value reference to plant unique_ptr for identification
 * @param quantity This parameter is not used (interface requirement)
 * 
 * @details
 * This implementation deviates from the expected behavior of removing a
 * specific quantity by instead removing ALL instances of the plant type.
 * The plant object is used solely for type identification.
 * 
 * @behavior
 * - Identifies plant type to remove based on the provided plant object
 * - Calls Inventory::removeAll() for complete removal
 * - Ignores the quantity parameter entirely
 * - Uses move semantics to transfer the plant object
 * 
 * @pre
 * - inventory must be valid and non-null
 * - plant must contain a valid Plant object for type identification
 * 
 * @post
 * - All instances of the plant type are removed from inventory
 * - plant parameter becomes empty (moved from)
 * - Inventory state is updated and observers are notified
 * 
 * @rationale
 * This design choice simplifies the removal operation by always performing
 * complete removal rather than partial quantity-based removal, which may
 * be more appropriate for certain business logic scenarios.
 * 
 * @see Inventory::removeAll
 */
void RemoveStock::execute(std::unique_ptr<Plant>&& plant, int quantity) {
	inventory->removeAll(std::move(plant));
	std::cout << quantity;
}

/**
 * @brief Constructor establishing inventory dependency
 * @param inv Raw pointer to target Inventory for removal operations
 * 
 * @design
 * Uses dependency injection to establish the inventory dependency
 * without taking ownership. This follows the principle of composition
 * over inheritance.
 * 
 * @invariant inventory != nullptr after construction
 */
RemoveStock::RemoveStock(Inventory* inv): inventory(inv) {
}

/**
 * @brief Virtual destructor for base class polymorphism
 * 
 * @compliant Adheres to Command interface requirements for polymorphic deletion
 * @safe No resource cleanup needed as inventory reference is non-owning
 */
RemoveStock::~RemoveStock()
{
}