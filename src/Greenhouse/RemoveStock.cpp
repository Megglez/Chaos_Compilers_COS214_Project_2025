#include "RemoveStock.h"

void RemoveStock::execute(std::unique_ptr<Plant>&& plant, int quantity) {
	inventory->removeAll(std::move(plant));
	
}

RemoveStock::RemoveStock(Inventory* inv): inventory(inv) {
}

RemoveStock::~RemoveStock()
{
}
