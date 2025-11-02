#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "Staff.h"
using namespace std;

class Manager : Staff
{

private:
Inventory *subject;
public:
	Inventory *subject;
	string trackInventory();
	string getInventory();
	void trackStaff();
	Manager();
	virtual ~Manager();
	bool canHandleEnquiry();
	void performDuty();

	
};

#endif
