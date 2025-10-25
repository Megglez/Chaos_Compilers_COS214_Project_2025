#include "Stock.h"

Stock::Stock(Inventory* inv): inventory(inv) {
	
}

Stock::~Stock()
{
}

void Stock::Add(std::unique_ptr<Plant> plant, int quantity){
	command = new AddStock(inventory);
	command->execute(std::move(plant), quantity);

}

void Stock::Remove(std::unique_ptr<Plant> plant, int quantity){
	if(command){
		delete command;
	}

	command = new RemoveStock(inventory);
	command->execute(std::move(plant), quantity);
}