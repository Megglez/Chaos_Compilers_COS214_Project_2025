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
private:
	string name;
	string staffID;
	string workArea;
	StaffState* state;
	InfoDesk* infoDesk;
	bool available;  
	Staff* nextInChain;
	Customer* currentCustomer;

public:
	virtual void update(const std::string &update);
	void changeState();
	virtual void getAvailability();
	void setAvailability(bool isAvailable);
	Staff();
	virtual ~Staff();
	virtual void setNextInChain(Staff* next);
	virtual void assistCustomer(Customer *cc) = 0; //start Assisting customer - pure virtual
	std::string getName();
	std::string getID();
	std::string getStaffType();
	Staff* getNextInChain();
	std::string getStateName();
	Customer * getCurrentCustomer();
	void setCurrentCustomer(Customer * cc);
	InfoDesk* getInfodesk();
	Staff* handleEnquiryRequest();
	virtual void performDuty();
	void completeTask();
	virtual bool canHandleEnquiry()=0;
	void registerToAllStaff(InfoDesk*desk);
	void unregisterFromAllStaff();
 	
	
	


};

#endif
