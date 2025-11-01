#ifndef CASHIERS_H
#define CASHIERS_H
#include <iostream>
#include <queue>
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
	void makeTransaction();
	std::string getStaffType();
	bool canHandleEnquiry() ;
	void performDuty();
	void emptyBasket();
	Cashiers(std::string& name, std::string& id);
	virtual ~Cashiers();
	

};

#endif
