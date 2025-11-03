#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "Staff.h"
using namespace std;

class Manager : public Staff
{

private:
Inventory *subject;
public:
	
	string *trackInventory();
	void manageStaff();
	Manager();
	virtual ~Manager();
	bool canHandleEnquiry();
	void performDuty();//for staffs
	void setRole() override
	

	
};

#endif
