#ifndef INFODESK_H
#define INFODESK_H
#include <iostream>
#include <queue>
#include <vector>
#include "./Customer/Customer.h"
#include "Staff.h"

using namespace std;

//class Staff;
class InfoDesk {
	private:
	 // 
	Staff*chainHead; //staff member with most priority
	std::queue<Customer*> waitingCustomers; // queued customers 
	std::vector<Staff*> AllStaff; 
	std::vector<Staff*> AvailableStaff;

public:
	virtual void notify(Staff* staff);// notify 
	InfoDesk();
	virtual ~InfoDesk(); 
	InfoDesk* getInfodesk();
	void handleCustomer(); // called by requestAssistance
	bool FindAvailableStaff(Customer cc);
	bool removeAvailableStaff(Staff ss);
	bool addAvailableStaff(Staff ss);


};

#endif
