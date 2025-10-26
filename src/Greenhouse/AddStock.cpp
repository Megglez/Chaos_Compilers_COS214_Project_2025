#include "AddStock.h"

void AddStock::execute(std::unique_ptr<Plant>&& plant, int quantity) {
	inventory->addPlant(std::move(plant), quantity);
}

AddStock::AddStock(Inventory* inv): inventory(inv) {

}

AddStock::~AddStock()
{
}
