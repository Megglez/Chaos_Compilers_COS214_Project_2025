#ifndef SALESSTAFF_H
#define SALESSTAFF_H
#include <iostream>
using namespace std;

class SalesStaff : Staff_ {


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
