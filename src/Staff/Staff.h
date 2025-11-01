#ifndef STAFF_H
#define STAFF_H
#include <iostream>
//#include "../Greenhouse/Plant.h"
#include "StaffState.h"
#include "Available.h"
#include "Busy.h"
//#include "../Greenhouse/Inventory.h"
#include "../Staff/InfoDesk.h"
//#include "Customer.h"
using namespace std;

class Inventory;
class Staff
{
private:
	string name;
	string staffID;
	string workArea;
	StaffState *state;
	InfoDesk *infoDesk;
	bool available;  
	Staff * nextInChain;
	Customer *currentCustomer;

public:
	void update(const std::string &update);
	void changeState();
	virtual void getAvailability();
	void setAvailability(bool isAvailable);
	Staff();
	virtual ~Staff();
	virtual void setNextInChain(Staff* next);
	virtual void assistCustomer(Customer *cc); //start Assisting customer
	std::string getName();
	std::string getID();
	std::string getStaffType();
	Staff* getNextInChain();

	


};

#endif
