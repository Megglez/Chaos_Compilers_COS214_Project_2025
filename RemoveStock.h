#ifndef REMOVESTOCK_H
#define REMOVESTOCK_H

#include <iostream>
#include "Command.h"
#include <memory>
#include "Inventory.h"
#include "Plant.h"
using namespace std;

class RemoveStock : public Command {
public:
	bool isEmpty;
	void execute(std::unique_ptr<Plant>&& plant, int quantity) override;
	RemoveStock(Inventory* inv);
	virtual ~RemoveStock();
private:
	Inventory* inventory;
};

#endif
