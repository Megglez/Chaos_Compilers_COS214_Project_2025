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
class InfoDesk {
	private:
	 // 
	Staff*chainHead; //staff member with most priority
	std::queue<Customer*> waitingCustomers; // queued customers 
	std::vector<Staff*> AllStaff; 
	std::vector<Staff*> AvailableStaff;
	Staff* findAvailableStaffThroughChain();

public:
	virtual void notify(Staff* staff);// notify 
	InfoDesk();
	virtual ~InfoDesk(); 
	InfoDesk* getInfodesk();
	void EnquiryChain();
	void buildChain();
	void clearChain();
	//assogns staff to customer
	void handleCustomer(Customer* customer); // called by requestAssistance
	bool FindAvailableStaff(Customer *cc);
	
	bool removeStaff(Staff *);
	bool addStaff(Staff* ss); //doing
	void processWaitingCustomers();
	void notifyStaffAvailable(Staff* freedStaff);
	std::vector<Staff*> getStaffByType(std::string ss) const;
	




};

#endif
