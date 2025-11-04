/**
 * @file AutumnCommand.cpp
 * @brief Implementation of AutumnCommand seasonal operations
 * 
 * Contains the concrete implementation of autumn seasonal transition
 * commands including inventory adjustments and seasonal state changes.
 * This command manages the transition from growth to harvest season.
 */

#include "AutumnCommand.h"

/**
 * @brief Constructs AutumnCommand with inventory dependency
 * @param inv Pointer to Inventory system for seasonal operations
 * 
 * Initializes the AutumnCommand with a reference to the inventory
 * system where autumn seasonal adjustments will be applied.
 * 
 * @param inv Valid Inventory pointer for seasonal change operations
 * 
 * @post inventory member is set to the provided Inventory pointer
 */
AutumnCommand::AutumnCommand(Inventory* inv): inventory(inv){

}

/**
 * @brief Executes the autumn seasonal transition
 * 
 * Performs the concrete command execution by invoking the inventory's
 * seasonalChange method to transition from summer to autumn. This
 * triggers the complete autumn seasonal adjustment process including:
 * - Stock level adjustments for harvest season
 * - Plant development stage updates for decline phase
 * - Staff notifications about seasonal change
 * - Preparation for upcoming winter conditions
 * 
 * @override Implements StateCommand::execute()
 * 
 * @par Autumn Transition Effects:
 * Based on previous inventory logic, this typically applies:
 * - Succulents: 10 (low stock - frost kills them)
 * - Herbs: 20 (low stock - basil dies, others fade)
 * - Flowers: 50 (changing stock - annuals decline)
 * - Trees: 100 (high stock - prime planting time)
 * - Plant stages transition from "Prime" to "Wilting"
 * 
 * @see Inventory::seasonalChange
 * @see Inventory::adjustStockForSeason
 * @see Inventory::updatePlantStagesForSeason
 */
void AutumnCommand::execute(){
    std::string autumn = "Autumn";
    std::string summer = "Summer";
    inventory->seasonalChange(summer, autumn);
}

/**
 * @brief Destructor for AutumnCommand
 * 
 * Cleans up AutumnCommand-specific resources. The inventory
 * pointer is not owned by this class and is not deleted.
 * 
 * @note The inventory reference is borrowed - no cleanup required
 */
AutumnCommand::~AutumnCommand()
{
}