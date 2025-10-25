#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include "Staff .h"
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
using namespace std;

class Inventory {

private:
	std::map<std::string, std::pair<std::unique_ptr<Plant>, int>> inventoryList;
	std::vector<Staff*> staffList;
protected:
	Inventory();
	~Inventory() = default;
public:
	void action();
	void addPlant(std::unique_ptr<Plant> plant, int quantity = 1);
	void removePlant(std::unique_ptr<Plant> plant, int quantity);
	void seasonalChange(std::string& fromSeason, std::string& toSeason);
	void adjustStockForSeason(const std::string& season);
	void updateStockByPlantType(const std::string& targetType, int newStockLevel);
	std::string getPlantType(Plant* plant);
	void getCatalogue();
	void attach(Staff* staff);
	void detach(Staff* staff);
	void notify();
	virtual ~Inventory();
};

#endif
