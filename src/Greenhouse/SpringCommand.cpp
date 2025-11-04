/**
 * @file SpringCommand.cpp
 * @brief Implementation of SpringCommand seasonal operations
 * 
 * Contains the concrete implementation of spring seasonal transition
 * commands including inventory adjustments and seasonal state changes.
 * This command initiates the new growing cycle after winter dormancy.
 */

#include "SpringCommand.h"

/**
 * @brief Constructs SpringCommand with inventory dependency
 * @param inv Pointer to Inventory system for seasonal operations
 * 
 * Initializes the SpringCommand with a reference to the inventory
 * system where spring seasonal adjustments will be applied.
 * 
 * @param inv Valid Inventory pointer for seasonal change operations
 * 
 * @post inventory member is set to the provided Inventory pointer
 */
SpringCommand::SpringCommand(Inventory* inv): inventory(inv){

}

/**
 * @brief Executes the spring seasonal transition
 * 
 * Performs the concrete command execution by invoking the inventory's
 * seasonalChange method to transition from winter to spring. This
 * triggers the complete spring seasonal adjustment process including:
 * - Stock level adjustments for new growing season
 * - Plant development stage updates from dormant to growing
 * - Staff notifications about seasonal change
 * - Completion and restart of the annual seasonal cycle
 * 
 * @override Implements StateCommand::execute()
 * 
 * @par Spring Transition Effects:
 * Based on previous inventory logic, this typically applies:
 * - Succulents: 25 (low stock - still risky after winter)
 * - Herbs: 80 (good stock - beginning to grow)
 * - Flowers: 90 (high stock - spring blooms)
 * - Trees: 100 (high stock - prime planting time)
 * - Plant stages transition from "Dead" to "Seed" or "Sapling"
 * 
 * @remark This command completes the annual cycle: Winter → Spring
 *         and begins the new growing season for all plants.
 * 
 * @see Inventory::seasonalChange
 * @see Inventory::adjustStockForSeason
 * @see Inventory::updatePlantStagesForSeason
 */
void SpringCommand::execute(){
    string winter = "Winter";
    string spring = "Spring";
    inventory->seasonalChange(winter, spring);
}

/**
 * @brief Destructor for SpringCommand
 * 
 * Cleans up SpringCommand-specific resources. The inventory
 * pointer is not owned by this class and is not deleted.
 * 
 * @note The inventory reference is borrowed - no cleanup required
 */
SpringCommand::~SpringCommand()
{
}