#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include "../Greenhouse/Plant.h"
#include "StaffState.h"
class Inventory;
#include "InfoDesk.h"
using namespace std;

class Staff
{
private:
	string name;
	string staffID;
	string workArea;
	StaffState state;
	InfoDesk infoDesk;

public:
	void update(const std::string &update);
	void changeState();
	virtual void getAvailability();
	virtual void setAvailability();
	Staff();
	virtual ~Staff();
};

#endif
