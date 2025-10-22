#ifndef AVAILABLE_H
#define AVAILABLE_H
#include <iostream>
using namespace std;

class Available : public StaffState {


public:
	void handle();

	Available();

	virtual ~Available();
};

#endif
