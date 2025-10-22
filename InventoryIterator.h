#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H
#include <iostream>
using namespace std;

class InventoryIterator : public Iterator {


public:
	void first();

	void next();

	void isDone();

	void currentItem();

	InventoryIterator();

	virtual ~InventoryIterator();
};

#endif
