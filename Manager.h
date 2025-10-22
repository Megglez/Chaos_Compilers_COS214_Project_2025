#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
using namespace std;

class Manager : Staff_ {

public:
	Inventory* subject;

	void trackInventory();

	void getAvailability();

	void setAvailability();

	Manager();

	virtual ~Manager();
};

#endif
