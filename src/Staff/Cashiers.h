#ifndef CASHIERS_H
#define CASHIERS_H
#include <iostream>
#include "Staff.h"
#include "../Greenhouse/Inventory.h"
using namespace std;

class Cashiers : public Staff
{
public:
	Inventory *subject;
	void makeTransaction();
	void getAvailability();
	void setAvailability();
	Cashiers();
	virtual ~Cashiers();
};

#endif
