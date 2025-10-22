#ifndef STAFFSTATE_H
#define STAFFSTATE_H
#include <iostream>
using namespace std;

class StaffState {


public:
	virtual void handle() = 0;

	StaffState();

	virtual ~StaffState();
};

#endif
