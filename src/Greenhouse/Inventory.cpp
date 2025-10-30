/**
 * @file Inventory.cpp
 * @brief Implementation of the Inventory class methods
 * 
 * This file contains the implementation of all Inventory class methods
 * including inventory management, seasonal changes, and staff notifications.
 */

#include "Inventory.h"

/**
 * @brief Default constructor for Inventory
 * 
 * Initializes an empty inventory with no plants and no staff observers.
 */
Inventory::Inventory() {
	// TODO - implement Inventory::Inventory
	
}


/**
 * @brief Adds a plant to the inventory with specified quantity
 * @param plant Unique pointer to the plant object to add
 * @param quantity Number of plants to add (default is 1)
 * 
 * If the plant already exists in inventory, increases the quantity.
 * If it's a new plant, creates a new entry in the inventory map.
 */

void Inventory::addPlant(std::unique_ptr<Plant> plant, int quantity) {
	std::string plantName = plant->getName(); // Assuming Plant has getName()
    
    auto it = inventoryList.find(plantName);
    if (it != inventoryList.end()) {
        // Plant exists - update quantity
        it->second.second += quantity;
        std::cout << "Added " << quantity << " " << plantName << ". Total: " << it->second.second << std::endl;
    } else {
        // New plant - insert with quantity
        inventoryList[plantName] = std::make_pair(std::move(plant), quantity);
        std::cout << "Added new plant: " << plantName 
                  << " with quantity: " << quantity << std::endl;
        std::string message = plantName + " has just been added to the Inventory";
        notify(message);
    }	
	
}

/**
 * @brief Removes a specified quantity of plants from inventory
 * @param plant Unique pointer to the plant to remove
 * @param quantity Number of plants to remove
 * 
 * Reduces the quantity of the specified plant. If quantity reaches zero,
 * removes the plant entirely from inventory. Notifies staff of changes.
 */
void Inventory::removePlant(std::unique_ptr<Plant> plant, int quantity) {
	auto it = inventoryList.find(plant->getName()); 
    if (it != inventoryList.end()) {
        if (it->second.second >= quantity) {
            it->second.second -= quantity;
            std::cout << "Removed " << quantity << " " << plant->getName() 
                      << ". Remaining: " << it->second.second << std::endl;
            
            // Remove entry if quantity reaches zero
            if (it->second.second == 0) {
                inventoryList.erase(it);
                std::cout << plant->getName() << " is now out of stock." << std::endl; // replace with plant->getName()
                std::string message = plant->getName() + "is now out of Stock. Please restock soon";// replace with plant->getName()
                notify(message);
            }
        } else {
            std::cout << "Error: Only " << it->second.second << " " << plant->getName() << " available. Cannot remove " // replace with plant->getName()
            << quantity << std::endl;

        }
    } else {
        std::cout << "Error: Plant " << plant->getName() << " not found in inventory." << std::endl; // replace with plant->getName()
    }
}

/**
 * @brief Removes all instances of a specific plant from inventory
 * @param plant Unique pointer to the plant to remove completely
 * 
 * Completely removes the plant from inventory regardless of quantity.
 * Useful for discontinuing plant types or complete stock clearance.
 */
void Inventory::removeAll(std::unique_ptr<Plant> plant){
    auto it = inventoryList.find(plant->getName()); // replace with plant->getName()
    std::string message = plant->getName() + " has just been removed from the inventory";
    if (it != inventoryList.end()) {
        inventoryList.erase(it);
        notify(message);
    }else {
        std::cout << "Error: Plant " << plant->getName() << " not found in inventory." << std::endl; // replace with plant->getName()
    }

}

/**
 * @brief Updates development stages of all plants for a new season
 * @param season The new season to adjust stages for
 * 
 * Applies seasonal development changes to all plants in inventory.
 * Each plant's stage is evaluated and potentially updated based on
 * the new seasonal conditions.
 */
void Inventory::updatePlantStagesForSeason(const std::string& season) {
    for (auto& [plantName, plantData] : inventoryList) {
        auto& [plantPtr, currentStock] = plantData;
        
        if (plantPtr) {
            StageOfDevelopment* newStage = determineStageForSeason(plantPtr.get(), season);
            if (newStage) {
                plantPtr->setState(newStage); // Assuming you have a setter for the stage
                std::cout << plantName << " stage updated for " << season << std::endl;
            }
        }
    }
}

/**
 * @brief Determines appropriate development stage for a plant in given season
 * @param plant Pointer to the plant to evaluate
 * @param season The season to determine stage for
 * @return Pointer to appropriate StageOfDevelopment object
 * 
 * Uses plant type and seasonal information to determine the most
 * appropriate development stage. Implements plant lifecycle logic
 * based on seasonal changes.
 */
StageOfDevelopment* Inventory::determineStageForSeason(Plant* plant, const std::string& season) {
    std::string plantType = plant->getType();
    
    if (season == "Spring") {
        // Spring: Most plants start growing
        if (plantType == "flower") {
            if(plant->isWinter()){
                return new Wilting();
            }else{
                return new Seed();
            }
        } else if(plantType == "Herb"){
            return new Seed();
        }else if (plantType == "Tree") {
            return new Sapling();
        } else if (plantType == "Succulent") {
            return new Prime(); // Succulents are resilient
        }
        
    } else if (season == "Summer") {
        // Summer: Peak growth for most plants
        if (plantType == "flower") {
            if(plant->isWinter()){
                return new Dead();
            }else{
                return new Prime();
            }
        } else if(plantType == "Herb"){
            return new Prime();
        } else if (plantType == "Tree") {
            return new Prime();
        } else if (plantType == "Succulent") {
            return new Prime();
        }
        
    } else if (season == "Autumn") {
        // Autumn: Plants start declining
        if (plantType == "Flower") {
            if(plant->isWinter()){
                return new Sapling();
            }else{
                return new Wilting();
            }
        } else if (plantType == "Herb") {
            return new Wilting(); // Herbs start fading
        } else if (plantType == "Tree") {
            return new Prime(); // Trees still okay
        } else if (plantType == "Succulent") {
            return new Wilting(); // Succulents struggle with cold
        }
        
    } else if (season == "Winter") {
        // Winter: Most plants dormant or dead
        if (plantType == "Flower") {
            if(plant->isWinter()){
                return new Prime();
            }else{
                return new Dead();
            }
        } else if (plantType == "Herb") {
            return new Dead(); // Most die in Winter
        } else if (plantType == "Tree") {
            return new Wilting(); // Trees dormant but not dead
        } else if (plantType == "Succulent") {
            return new Dead(); // Succulents can't handle frost
        }
    }
    
    return nullptr; // No change
}

/**
 * @brief Handles seasonal transition and updates inventory accordingly
 * @param fromSeason The current season being transitioned from
 * @param toSeason The new season being transitioned to
 * 
 * Coordinates both stock adjustments and plant stage changes during
 * seasonal transitions. Notifies all staff members of the seasonal change.
 */
void Inventory::seasonalChange(std::string& fromSeason, std::string& toSeason){
    std::cout << "Season changing from " << fromSeason << " to " << toSeason << std::endl;
    adjustStockForSeason(toSeason);
    updatePlantStagesForSeason(toSeason);

    std::string message = "The Inventory has just been adjusted for the " + toSeason;
    for(Staff* staff: staffList){
        staff->update(message);
    }
}



/**
 * @brief Adjusts stock levels based on seasonal requirements
 * @param season The season to adjust stock for
 * 
 * Modifies inventory quantities for different plant types according to
 * seasonal demand and growing conditions. Each season has specific
 * stock level requirements for different plant categories.
 * 
 * Decided modify it to include WinterFlowers
 */
void Inventory::adjustStockForSeason(const std::string& season) {
    std::cout << "Adjusting stock for season: " << season << std::endl;
    

    for (auto& [plantName, plantData] : inventoryList) {
        
        auto& [plantPtr, currentStock] = plantData;
        
        if (plantPtr) {
            int newStockLevel = currentStock; // Default to current stock
            
            // Check if it's a Winter flower using the virtual method
            if (plantPtr->isWinter()) {
                // Winter flowers have reversed seasonal cycle
                if (season == "Winter") {
                    newStockLevel = 100;  // Peak season - high stock
                } else if (season == "Autumn") {
                    newStockLevel = 80;   // Planting season - good stock
                } else if (season == "Spring") {
                    newStockLevel = 20;   // Fading season - low stock
                } else if (season == "Summer") {
                    newStockLevel = 0;    // Dormant season - no stock
                }
                
                std::cout << "Winter flower '" << plantName << "' stock adjusted from " 
                          << currentStock << " to " << newStockLevel << " for " << season << std::endl;
                          
            } else {
                // Handle regular plants by type
                std::string plantType = plantPtr->getType();
                
                if (season == "Spring") {
                    if (plantType == "Succulent") {
                        newStockLevel = 55;   // Low stock - still risky
                    } else if (plantType == "Herb") {
                        newStockLevel = 80;   // Good stock - starting to grow
                    } else if (plantType == "Flower") {
                        newStockLevel = 90;   // High stock - Spring blooms
                    } else if (plantType == "Tree") {
                        newStockLevel = 100;  // High stock - prime planting
                    }
                    
                } else if (season == "Summer") {
                    if (plantType == "Succulent") {
                        newStockLevel = 100;  // High stock - peak season
                    } else if (plantType == "Herb") {
                        newStockLevel = 100;  // High stock - all types available
                    } else if (plantType == "Flower") {
                        newStockLevel = 100;  // High stock - Summer annuals
                    } else if (plantType == "Tree") {
                        newStockLevel = 70;   // Medium stock
                    }
                    
                } else if (season == "Autumn") {
                    if (plantType == "Succulent") {
                        newStockLevel = 50;   // Low stock - frost kills them
                    } else if (plantType == "Herb") {
                        newStockLevel = 20;   // Low stock - basil dies, others fade
                    } else if (plantType == "Flower") {
                        newStockLevel = 50;   // Changing stock
                    } else if (plantType == "Tree") {
                        newStockLevel = 90;   // High stock - prime planting time
                    }
                    
                } else if (season == "Winter") {
                    if (plantType == "Succulent") {
                        newStockLevel = 0;    // Out of stock
                    } else if (plantType == "Herb") {
                        newStockLevel = 0;    // Out of stock
                    } else if (plantType == "Flower") {
                        newStockLevel = 5;    // Very low stock
                    } else if (plantType == "Tree") {
                        newStockLevel = 60;   // Low stock
                    }
                }
                
                std::cout << "Regular " << plantType << " '" << plantName 
                          << "' stock adjusted from " << currentStock << " to " 
                          << newStockLevel << " for " << season << std::endl;
            }
            
            // Update the stock level
            currentStock = newStockLevel;
        }
    }
    
    std::cout << "Seasonal stock adjustment completed for " << season << std::endl;
}


/**
 * @brief Displays the current inventory catalogue
 * 
 * Prints a formatted list of all plants in inventory with their
 * current quantities and relevant information. Used for reporting
 * and inventory checking purposes.
 */
void Inventory::getCatalogue() {
	std::cout << "\n=== INVENTORY CATALOGUE ===" << std::endl;
    for (const auto& entry : inventoryList) {
        std::cout << "- " << entry.first << ": " << entry.second.second << " units" << std::endl;
    }
    std::cout << "===========================\n" << std::endl;
}

/**
 * @brief Attaches a staff member to receive notifications
 * @param staff Pointer to the staff member to attach
 * 
 * Adds a staff member to the notification list. Attached staff
 * will receive updates about inventory changes and seasonal transitions.
 */
void Inventory::attach(Staff* staff) {
	staffList.push_back(staff);
}

/**
 * @brief Detaches a staff member from notifications
 * @param staff Pointer to the staff member to detach
 * 
 * Removes a staff member from the notification list. The staff
 * member will no longer receive inventory updates.
 */
void Inventory::detach(Staff* staff) {
	auto it = std::find(staffList.begin(), staffList.end(), staff);
    if (it != staffList.end()) {
        staffList.erase(it);
    }

}

std::map<std::string, std::pair<std::unique_ptr<Plant>, int>>& Inventory::getInventory(){
    return inventoryList;
}

/**
 * @brief Notifies all attached staff members with a message
 * @param message The message to send to staff members
 * 
 * Sends a notification to all registered staff observers.
 * Used for communicating important inventory changes and updates.
 */
void Inventory::notify(std::string& message) {
	for(Staff* staff: staffList){
		staff->update(message);
	}
}

/**
 * @brief Destructor for Inventory
 * 
 * Cleans up resources and ensures proper destruction of plant objects
 * and staff references.
 */
Inventory::~Inventory()
{
}
