#ifndef INFODESK_H
#define INFODESK_H
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

// Forward declarations
class Staff;
class Customer;
class InfoDesk 
{
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
	vector<Staff*> getStaffByType(string ss) const;
	void AssignStaffToCustomer(Customer* cc);
	
private:
	Staff* chainHead; //staff member with most priority
	queue<Customer*> waitingCustomers; // queued customers 
	vector<Staff*> AllStaff; 
	vector<Staff*> AvailableStaff;
	Staff* findAvailableStaffThroughChain();
};

#endif
