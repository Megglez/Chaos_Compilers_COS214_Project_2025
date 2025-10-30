#ifndef STAFF_H
#define STAFF_H
#include <iostream>
//#include "../Greenhouse/Plant.h"
#include "StaffState.h"
#include "Available.h"
#include "Busy.h"
//#include "../Greenhouse/Inventory.h"
#include "InfoDesk.h"
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
	InfoDesk infoDesk;
	bool available;  

public:
	void update(const std::string &update);
	void changeState();
	virtual void getAvailability();
	void setAvailability(bool isAvailable);
	Staff();
	virtual ~Staff();
	virtual void setNextStaff(Staff next);
	virtual void handleCustomer(Customer cc);
	std::string getName();
	std::string getID();
	


};

#endif
