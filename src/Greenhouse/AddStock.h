#ifndef ADDSTOCK_H
#define ADDSTOCK_H
#include <iostream>
#include "Command.h"
#include "Inventory.h"
using namespace std;

class AddStock : public Command {
public:
	bool isEmpty;
	void execute(std::unique_ptr<Plant>&& plant, int quantity) override;
	AddStock(Inventory* inv);
	virtual ~AddStock();
private:
	Inventory* inventory;
};

#endif
