#ifndef FINDAVAILABLESTAFF_H
#define FINDAVAILABLESTAFF_H
#include <iostream>
#include "InfoDesk.h"
using namespace std;

class FindAvailableStaff : public InfoDesk {
public:
	Staff* staffList;
	virtual void notify(Staff* staffList) = 0;
	FindAvailableStaff();
	virtual ~FindAvailableStaff();
};

#endif
