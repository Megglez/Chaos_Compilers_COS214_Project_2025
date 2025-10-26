#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include "Command.h"
#include "RemoveStock.h"
#include "AddStock.h"
#include "Inventory.h"
#include <memory>
#include "Plant.h"
using namespace std;
#include <vector>

class Stock {
public:
	Stock(Inventory* inv);
	virtual ~Stock();
	void Remove(std::unique_ptr<Plant> plant);
	void Add(std::unique_ptr<Plant> plant, int quantity);
	void printStock();
private:
	Command* command;
	Inventory* inventory;
	std::vector<std::unique_ptr<Plant>> StockList;

};

#endif
