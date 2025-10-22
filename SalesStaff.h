#ifndef SALESSTAFF_H
#define SALESSTAFF_H
#include <iostream>
#include "Staff .h"
using namespace std;

class SalesStaff : public Staff {
public:
	void interact();
	void QnA();
	void findPlant();
	void getAvailability();
	void setAvailability();
	SalesStaff();
	virtual ~SalesStaff();
};

#endif
