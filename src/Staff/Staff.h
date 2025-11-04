#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include "StaffState.h"
#include "Available.h"
#include "Busy.h"
using namespace std;
 
class StaffState;
class Inventory;
class InfoDesk;  // Forward declaration
class Customer;  // Forward declaration
class Staff
{
public:
	virtual void update(const string &update);
	void changeState();
	virtual bool getAvailability();
	virtual void setAvailability(bool isAvailable);
	Staff();
	Staff(const string& name, const string& id);
	virtual ~Staff();
	virtual void setNextInChain(Staff* next);
	virtual void assistCustomer(Customer *cc); // start Assisting customer
	string getName();
	string getID();
	string getStaffType();
	Staff* getNextInChain();
	string getStateName();
	Customer * getCurrentCustomer();
	void setCurrentCustomer(Customer * cc);
	InfoDesk* getInfodesk();
	Staff* handleEnquiryRequest();
	virtual void performDuty() = 0;
	void completeTask();
	virtual bool canHandleEnquiry()=0;
	void registerToAllStaff(InfoDesk*desk);
	void unregisterFromAllStaff();

private:
	string name;
	string staffID;
	string workArea;
	StaffState* state;
	InfoDesk* infoDesk;
	bool available;  
	Staff* nextInChain;
	Customer* currentCustomer;
};

#endif
