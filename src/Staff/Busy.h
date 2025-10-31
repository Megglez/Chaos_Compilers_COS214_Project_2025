#ifndef BUSY_H
#define BUSY_H
#include <iostream>
#include "StaffState.h"
#include "Staff.h"
using namespace std;

class Busy : public StaffState
{
public:
	void handle();
	Busy();
	virtual ~Busy();
	std::string getStateName()const override;
	bool canAcceptCustomer() override;
};

#endif
