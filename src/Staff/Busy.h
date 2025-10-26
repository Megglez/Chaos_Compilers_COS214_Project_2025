#ifndef BUSY_H
#define BUSY_H
#include <iostream>
#include "StaffState.h"
using namespace std;

class Busy : public StaffState
{
public:
	void handle();
	Busy();
	virtual ~Busy();
};

#endif
