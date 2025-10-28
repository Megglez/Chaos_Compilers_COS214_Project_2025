#ifndef STAFFSTATE_H
#define STAFFSTATE_H
#include <iostream>
using namespace std;

class Staff;
class Customer;
class StaffState {
	protected:
	Staff *staff; //staff member we are working with 
public:
	
	virtual void handle()=0; //completing the task
	virtual std::string getStateName()const=0;
	virtual bool canAcceptCustomer()=0;
	void setContext(Staff* staff);
	StaffState();
	virtual ~StaffState();
};

#endif
