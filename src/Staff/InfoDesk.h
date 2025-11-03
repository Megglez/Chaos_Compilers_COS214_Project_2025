#ifndef INFODESK_H
#define INFODESK_H
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "./Customer/Customer.h"
//#include "Staff.h"

using namespace std;

class Staff;
//class Customer;
class InfoDesk {
	private:
	 // 
	Staff*chainHead; //staff member with most priority
	std::queue<Customer*> waitingCustomers; // queued customers 
	std::vector<Staff*> AllStaff; 
	
	Staff* findAvailableStaffThroughChain();

public:
	virtual void notify(Staff* staff);// notify 
	InfoDesk();
	virtual ~InfoDesk(); 
	InfoDesk* getInfodesk();
	void buildChain();
	void clearChain();
	//assogns staff to customer
	void handleCustomer(Customer* customer); // called by requestAssistance
	bool FindAvailableStaff(Customer* cc);
	bool removeStaff(Staff *);
	bool addStaff(Staff* ss);
	void processWaitingCustomers();
	void notifyStaffAvailable(Staff* freedStaff);
	std::vector<Staff*> getStaffByType(std::string ss) const;
	void AssignStaffToCustomer(Customer* cc);
	




};

#endif
