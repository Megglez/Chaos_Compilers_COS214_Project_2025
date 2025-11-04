#ifndef CASHIERS_H
#define CASHIERS_H
#include <iostream>
#include <queue>
#include "Staff.h"
#include "../Greenhouse/Inventory.h"
using namespace std;

class Cashiers : public Staff
{
public:
	Inventory *subject;

	// Queue management
	void enqueueCustomer(Customer *customer);
	Customer *dequeueCustomer();
	bool hasCustomersInQueue() const;
	int getQueueSize() const;

	// Transaction processing
	void makeTransaction();
	void emptyBasket(Customer *customer);
	void processNextCustomer();

	// Staff interface
	string getStaffType();
	bool canHandleEnquiry();
	void performDuty();

	Cashiers(string &name, string &id);
	virtual ~Cashiers();

private:
	queue<Customer *> customerQueue;
	Customer *currentCustomer;
	bool isProcessing;

};

#endif
