#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include "Staff .h"
using namespace std;

class Inventory {

private:
	Plant** inventoryList;
	Staff* staff;
protected:
	Inventory();
public:
	void action();
	void addPlant();
	void removePlant();
	void getCatalogue();
	void attach(Staff* staff);
	void detach(Staff* staff);
	void notify();
	virtual ~Inventory();
};

#endif
