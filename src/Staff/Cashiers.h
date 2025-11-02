#ifndef CASHIERS_H
#define CASHIERS_H
#include <iostream>
#include "Staff.h"
#include "../Greenhouse/Inventory.h"
using namespace std;

class Cashiers : public Staff
{
private:
std::queue<Customer*> CustomerQueue;
Customer *currentCustomer;

public:
	Inventory *subject;
	bool canHandleEnquiry() ;
	void performDuty();
	void emptyBasket();
	Cashiers(std::string& name, std::string& id);
	virtual ~Cashiers();
	string printSlip(vector<Plant*> basket);
	
	
};

#endif
