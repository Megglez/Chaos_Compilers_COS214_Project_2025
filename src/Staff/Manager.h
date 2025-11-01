#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "Staff.h"
using namespace std;

class Manager : public Staff
{
public:
	Inventory *subject;
	void trackInventory();
	bool getAvailability() override;
	void setAvailability(bool isAvailable) override;
	void performDuty() override;
	bool canHandleEnquiry() override;
	Manager();
	virtual ~Manager();
	
};

#endif
