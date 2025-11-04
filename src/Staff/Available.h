#ifndef AVAILABLE_H
#define AVAILABLE_H
#include <iostream>
#include "StaffState.h"
using namespace std;

class Available : public StaffState
{
public:
	void handle() override;
	Available();
	~Available();
	string getStateName()const override;
	bool canAcceptCustomer() override;
};

#endif
