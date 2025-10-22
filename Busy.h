#ifndef BUSY_H
#define BUSY_H
#include <iostream>
using namespace std;

class Busy : StaffState {


public:
	void handle();

	Busy();

	virtual ~Busy();
};

#endif
