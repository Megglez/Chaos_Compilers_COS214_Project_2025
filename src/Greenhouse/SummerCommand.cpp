/**
 * @file SummerCommand.cpp
 * @brief Implementation of SummerCommand seasonal operations
 * 
 * Contains the concrete implementation of summer seasonal transition
 * commands including inventory adjustments and seasonal state changes.
 */

#include "SummerCommand.h"

/**
 * @brief Constructs SummerCommand with inventory dependency
 * @param inv Pointer to Inventory system for seasonal operations
 * 
 * Initializes the SummerCommand with a reference to the inventory
 * system where summer seasonal adjustments will be applied.
 * 
 * @param inv Valid Inventory pointer for seasonal change operations
 * 
 * @post inventory member is set to the provided Inventory pointer
 */
SummerCommand::SummerCommand(Inventory* inv): inventory(inv){

}

/**
 * @brief Executes the summer seasonal transition
 * 
 * Performs the concrete command execution by invoking the inventory's
 * seasonalChange method to transition from spring to summer. This
 * triggers the complete summer seasonal adjustment process including:
 * - Stock level adjustments for peak growing season
 * - Plant development stage updates to prime condition
 * - Staff notifications about seasonal change
 * 
 * @override Implements StateCommand::execute()
 * 
 * @par Summer Transition Effects:
 * Based on previous inventory logic, this typically applies:
 * - Succulents: 100 (high stock - peak season)
 * - Herbs: 100 (high stock - all types available)
 * - Flowers: 100 (high stock - summer annuals)
 * - Trees: 70 (medium stock)
 * - Plant stages transition to "Prime" (peak development)
 * 
 * @see Inventory::seasonalChange
 * @see Inventory::adjustStockForSeason
 * @see Inventory::updatePlantStagesForSeason
 */
void SummerCommand::execute(){
    std::string spring = "Spring";
    std::string summer = "Summer";
    inventory->seasonalChange(spring, summer);
}

/**
 * @brief Destructor for SummerCommand
 * 
 * Cleans up SummerCommand-specific resources. The inventory
 * pointer is not owned by this class and is not deleted.
 * 
 * @note The inventory reference is borrowed - no cleanup required
 */
SummerCommand::~SummerCommand()
{
}