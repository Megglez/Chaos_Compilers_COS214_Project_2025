#include "Stock.h"

Stock::Stock(Inventory* inv): inventory(inv) {
	
}

Stock::~Stock()
{
}

void Stock::Add(std::unique_ptr<Plant> plant, int quantity){
	StockList.push_back(plant);
	command = new AddStock(inventory);
	command->execute(std::move(plant), quantity);

}

void Stock::Remove(std::unique_ptr<Plant> plant){
	if(command){
		delete command;
	}
	command = new RemoveStock(inventory);
	command->execute(std::move(plant), 1);
}

void Stock::printStock(){
	for (auto it = StockList.begin(); it != StockList.end(); ++it) {
    	std::cout << "======STOCK CATALOGUE======" << std::endl;
		std::cout << "Name" << std::endl; //replace with (*it)->getName() + (*it)->getType()
	}
}