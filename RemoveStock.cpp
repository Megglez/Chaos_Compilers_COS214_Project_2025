#include "RemoveStock.h"

void RemoveStock::execute(std::unique_ptr<Plant>&& plant, int quantity) {
	inventory->removePlant(std::move(plant), quantity);
	
}

RemoveStock::RemoveStock(Inventory* inv): inventory(inv) {
}

RemoveStock::~RemoveStock()
{
}
