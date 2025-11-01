#ifndef INFODESK_H
#define INFODESK_H
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "./Customer/Customer.h"
#include "Staff.h"

using namespace std;

//class Staff;
//class Customer;
class InfoDesk {
	private:
	 // 
	Staff*chainHead; //staff member with most priority
	std::queue<Customer*> waitingCustomers; // queued customers 
	std::vector<Staff*> AllStaff; 
	//std::vector<Staff*> AvailableStaff;
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
	bool FindAvailableStaff();
	
	bool removeStaff(Staff *ss);
	bool addStaff(Staff* ss); //doing
	void processWaitingCustomers();
	void notifyStaffAvailable(Staff* freedStaff);
	std::vector<Staff*> getStaffByType(std::string ss);
	void AssignStaffToCustomer(Customer * c);




};

#endif
