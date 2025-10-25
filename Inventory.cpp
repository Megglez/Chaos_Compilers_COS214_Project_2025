#include "Inventory.h"

Inventory::Inventory() {
	// TODO - implement Inventory::Inventory
	
}

void Inventory::action() {
	// TODO - implement Inventory::action
	
}

void Inventory::addPlant(std::unique_ptr<Plant> plant, int quantity) {
	std::string plantName = "Name";//plant->getName(); // Assuming Plant has getName()
    
    auto it = inventoryList.find(plantName);
    if (it != inventoryList.end()) {
        // Plant exists - update quantity
        it->second.second += quantity;
        std::cout << "Added " << quantity << " " << plantName 
                  << ". Total: " << it->second.second << std::endl;
    } else {
        // New plant - insert with quantity
        inventoryList[plantName] = std::make_pair(std::move(plant), quantity);
        std::cout << "Added new plant: " << plantName 
                  << " with quantity: " << quantity << std::endl;
    }	
	notify();
}

void Inventory::removePlant(std::unique_ptr<Plant> plant, int quantity) {
	auto it = inventoryList.find("Name"); // replace with plant->getName()
    if (it != inventoryList.end()) {
        if (it->second.second >= quantity) {
            it->second.second -= quantity;
            std::cout << "Removed " << quantity << " " << "plantName " // replace with plant->getName()
                      << ". Remaining: " << it->second.second << std::endl;
            
            // Remove entry if quantity reaches zero
            if (it->second.second == 0) {
                inventoryList.erase(it);
                std::cout << "Name" << " is now out of stock." << std::endl; // replace with plant->getName()
            }
        } else {
            std::cout << "Error: Only " << it->second.second 
                      << " " << "plantName" << " available. Cannot remove " // replace with plant->getName()
                      << quantity << std::endl;
        }
    } else {
        std::cout << "Error: Plant " << "plantName" << " not found in inventory." << std::endl; // replace with plant->getName()
    }
    notify();
}

void Inventory::seasonalChange(std::string& fromSeason, std::string& toSeason){
    std::cout << "Season changing from " << fromSeason << " to " << toSeason << std::endl;
    adjustStockForSeason(toSeason);

    for(Staff* staff: staffList){
        //staff->notify();
    }
}

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

std::string Inventory::getPlantType(Plant* plant) {
    if (!plant) return "unknown";
    return "Herb"; //plant->returnType(); // This returns "succulent", "herb", "flower", "tree", etc.
}

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

void Inventory::getCatalogue() {
	std::cout << "\n=== INVENTORY CATALOGUE ===" << std::endl;
    for (const auto& entry : inventoryList) {
        std::cout << "- " << entry.first << ": " << entry.second.second << " units" << std::endl;
    }
    std::cout << "===========================\n" << std::endl;
}

void Inventory::attach(Staff* staff) {
	staffList.push_back(staff);
}

void Inventory::detach(Staff* staff) {
	auto it = std::find(staffList.begin(), staffList.end(), staff);
    if (it != staffList.end()) {
        staffList.erase(it);
    }
}

void Inventory::notify() {
	for(Staff* staff: staffList){
		//update staff function
	}
	
}

Inventory::~Inventory()
{
}
