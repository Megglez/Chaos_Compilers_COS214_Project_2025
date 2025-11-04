#ifndef STAFFSTATE_H
#define STAFFSTATE_H
#include <iostream>
using namespace std;
//#include "./Staff.h"

class Staff;
class Customer;
class StaffState {
public:
	
	virtual void handle()=0; //completing the task
	virtual string getStateName()const=0;
	virtual bool canAcceptCustomer()=0;
	void setContext(Staff* staff);
	StaffState();
	virtual ~StaffState();

protected:
	Staff *staff; //staff member we are working with 
};

#endif
