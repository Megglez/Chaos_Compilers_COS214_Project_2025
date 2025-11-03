#ifndef SALESSTAFF_H
#define SALESSTAFF_H
#include <iostream>
#include "../Staff/Staff.h"
using namespace std;

class SalesStaff : public Staff
{
public:

	SalesStaff();
	virtual ~SalesStaff();
	bool canHandleEnquiry();
	void performDuty() override;
	string response();

	
};

#endif
