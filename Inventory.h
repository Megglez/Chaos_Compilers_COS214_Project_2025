#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
using namespace std;

class Inventory {

private:
	AddStock receiver;
	static Inventory* uniqueInstance;
	Plant** inventoryList;
	Staff* staff;

public:
	static Inventory* instance();

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

protected:
	Inventory(Inventory Inventory_);

public:
	Iterator* createIterator();

	virtual ~Inventory();
};

#endif
