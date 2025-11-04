/**
 * @file WinterCommand.cpp
 * @brief Implementation of WinterCommand seasonal operations
 * 
 * Contains the concrete implementation of winter seasonal transition
 * commands including inventory adjustments and seasonal state changes.
 */

#include "WinterCommand.h"

/**
 * @brief Constructs WinterCommand with inventory dependency
 * @param inv Pointer to Inventory system for seasonal operations
 * 
 * Initializes the WinterCommand with a reference to the inventory
 * system where winter seasonal adjustments will be applied.
 * 
 * @param inv Valid Inventory pointer for seasonal change operations
 * 
 * @post inventory member is set to the provided Inventory pointer
 */
WinterCommand::WinterCommand(Inventory* inv): inventory(inv){

}

/**
 * @brief Executes the winter seasonal transition
 * 
 * Performs the concrete command execution by invoking the inventory's
 * seasonalChange method to transition from autumn to winter. This
 * triggers the complete winter seasonal adjustment process including:
 * - Stock level adjustments for winter conditions
 * - Plant development stage updates
 * - Staff notifications about seasonal change
 * 
 * 
 * @par Winter Transition Effects:
 * Based on previous inventory logic, this typically applies:
 * - Succulents: 0 (out of stock - frost kills them)
 * - Herbs: 0 (out of stock)
 * - Flowers: 5 (very low stock)
 * - Trees: 30 (low stock)
 * - Plant stages transition to "Dead" or "Wilting"
 * 
 * @see Inventory::seasonalChange
 * @see Inventory::adjustStockForSeason
 * @see Inventory::updatePlantStagesForSeason
 */
void WinterCommand::execute(){
    std::string autumn = "Autumn";
    std::string winter = "Winter";
    inventory->seasonalChange(autumn, winter);
}

/**
 * @brief Destructor for WinterCommand
 * 
 * Cleans up WinterCommand-specific resources. The inventory
 * pointer is not owned by this class and is not deleted.
 * 
 * @note The inventory reference is borrowed - no cleanup required
 */
WinterCommand::~WinterCommand()
{
}