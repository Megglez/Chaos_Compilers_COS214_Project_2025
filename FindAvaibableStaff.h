#ifndef FINDAVAIBABLESTAFF_H
#define FINDAVAIBABLESTAFF_H
#include <iostream>
using namespace std;

class FindAvaibableStaff : public InfoDesk {

public:
	Staff* staffList;

	virtual void notify(Staff* staffList) = 0;

	FindAvaibableStaff();

	virtual ~FindAvaibableStaff();
};

#endif
