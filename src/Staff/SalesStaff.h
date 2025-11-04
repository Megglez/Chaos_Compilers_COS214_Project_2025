#ifndef SALESSTAFF_H
#define SALESSTAFF_H
#include <iostream>
#include "../Staff/Staff.h"
using namespace std;

class SalesStaff : public Staff
{


public:

	void performDuty() override;
	bool canHandleEnquiry() override;
	SalesStaff(string& name,string& id,InfoDesk*infodesk);
	virtual ~SalesStaff();
	void setRole() override;

	
};

#endif
