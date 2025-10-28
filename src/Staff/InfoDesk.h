#ifndef INFODESK_H
#define INFODESK_H
#include <iostream>
#include <queue>
#include <vector>
#include "Customer.h"
using namespace std;

class Staff;
class InfoDesk {
	private:
	Staff*chainHead; //staff member with most priority
	std::queue<Customer*> waitingCustomers;
	std::vector<Staff*> AllStaff;
public:
	virtual void notify(Staff* staff);
	InfoDesk();
	virtual ~InfoDesk();
	Staff *staffList;
	//FindAvailableStaff();
	//virtual ~FindAvailableStaff();
};

#endif
