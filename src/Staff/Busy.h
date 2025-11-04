#ifndef BUSY_H
#define BUSY_H
#include <iostream>
// #include "StaffState.h"
#include "./StaffState.h"

using namespace std;

class Busy : public StaffState
{
public:
	void handle() override;
	Busy();
	virtual ~Busy();
	std::string getStateName() const override;
	bool canAcceptCustomer() override;
};

#endif
