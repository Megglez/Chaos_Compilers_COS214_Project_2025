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

class Stock {
public:
	Stock(Inventory* inv);
	virtual ~Stock();
	void Remove(std::unique_ptr<Plant> plant, int quantity);
	void Add(std::unique_ptr<Plant> plant, int quantity);
private:
	Command* command;
	Inventory* inventory;
};

#endif
