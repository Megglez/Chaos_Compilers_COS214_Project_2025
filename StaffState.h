#ifndef STAFFSTATE_H
#define STAFFSTATE_H

class StaffState {


public:
	virtual void handle() = 0;

	StaffState();

	virtual void ~StaffState() = 0;
};

#endif
