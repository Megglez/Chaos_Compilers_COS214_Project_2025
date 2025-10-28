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
    std::string message = "PlantName has just been removed from the inventory";
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
    std::string plantType = getPlantType(plant);
    
    if (season == "spring") {
        // Spring: Most plants start growing
        if (plantType == "flower" || plantType == "herb") {
            return new Seed(); // or new Sapling() depending on your logic
        } else if (plantType == "tree") {
            return new Sapling();
        } else if (plantType == "succulent") {
            return new Prime(); // Succulents are resilient
        }
        
    } else if (season == "summer") {
        // Summer: Peak growth for most plants
        if (plantType == "flower" || plantType == "herb") {
            return new Prime();
        } else if (plantType == "tree") {
            return new Prime();
        } else if (plantType == "succulent") {
            return new Prime();
        }
        
    } else if (season == "autumn") {
        // Autumn: Plants start declining
        if (plantType == "flower") {
            return new Wilting(); // Annual flowers die back
        } else if (plantType == "herb") {
            return new Wilting(); // Herbs start fading
        } else if (plantType == "tree") {
            return new Prime(); // Trees still okay
        } else if (plantType == "succulent") {
            return new Wilting(); // Succulents struggle with cold
        }
        
    } else if (season == "winter") {
        // Winter: Most plants dormant or dead
        if (plantType == "flower" || plantType == "herb") {
            return new Dead(); // Most die in winter
        } else if (plantType == "tree") {
            return new Wilting(); // Trees dormant but not dead
        } else if (plantType == "succulent") {
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
 * @brief Updates stock level for a specific plant type
 * @param targetType The type of plant to update (e.g., "herb", "flower")
 * @param newStockLevel The new stock level to set
 * 
 * Iterates through all plants of the specified type and updates their
 * quantities to the new stock level. Used primarily for seasonal adjustments.
 */
void Inventory::updateStockByPlantType(const std::string& targetType, int newStockLevel) {
    for (auto& [plantName, plantData] : inventoryList) {
        auto& [plantPtr, currentStock] = plantData;
        
        if (plantPtr && getPlantType(plantPtr.get()) == targetType) {
            std::cout << "Updating " << plantName << " (" << targetType 
                      << ") stock from " << currentStock << " to " << newStockLevel << std::endl;
            currentStock = newStockLevel;
        }
    }
}

/**
 * @brief Gets the type classification of a plant
 * @param plant Pointer to the plant to check
 * @return String representing the plant type (e.g., "herb", "flower")
 * 
 * Returns the categorical type of the plant, used for seasonal
 * adjustments and inventory management operations.
 */
std::string Inventory::getPlantType(Plant* plant) {
    if (!plant) return "unknown";
    return "Herb"; //plant->returnType(); // This returns "succulent", "herb", "flower", "tree", etc.
}

/**
 * @brief Adjusts stock levels based on seasonal requirements
 * @param season The season to adjust stock for
 * 
 * Modifies inventory quantities for different plant types according to
 * seasonal demand and growing conditions. Each season has specific
 * stock level requirements for different plant categories.
 */
void Inventory::adjustStockForSeason(const std::string& season){
     if (season == "summer") {
        // Spring → Summer changes
        updateStockByPlantType("succulent", 100);  // High stock - peak season
        updateStockByPlantType("herb", 100);       // High stock - all types available  
        updateStockByPlantType("flower", 100);     // High stock - summer annuals
        updateStockByPlantType("tree", 70);        // Medium stock
        
    } else if (season == "autumn") {
        // Summer → Autumn changes
        updateStockByPlantType("succulent", 10);   // Low stock - frost kills them
        updateStockByPlantType("herb", 20);        // Low stock - basil dies, others fade
        updateStockByPlantType("flower", 50);      // Changing stock
        updateStockByPlantType("tree", 100);       // High stock - prime planting time
        
    } else if (season == "winter") {
        // Autumn → Winter changes
        updateStockByPlantType("succulent", 0);    // Out of stock
        updateStockByPlantType("herb", 0);         // Out of stock
        updateStockByPlantType("flower", 5);       // Very low stock
        updateStockByPlantType("tree", 30);        // Low stock
        
    } else if (season == "spring") {
        // Winter → Spring changes
        updateStockByPlantType("succulent", 25);   // Low stock - still risky
        updateStockByPlantType("herb", 80);        // Good stock
        updateStockByPlantType("flower", 90);      // High stock
        updateStockByPlantType("tree", 100);       // High stock
    }
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
