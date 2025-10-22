#ifndef STAFF _H
#define STAFF _H
#include <iostream>
using namespace std;

class Staff {

private:
	String name;
	String staffID;
	String workArea;
	StaffState state;
	InfoDesk infoDesk;

public:
	void changeState();

	virtual void getAvailability() = 0;

	virtual void setAvailability() = 0;

	Staff_();

	virtual ~Staff();
};

#endif
