#ifndef BUSY_H
#define BUSY_H

class Busy : StaffState {


public:
	void handle();

	Busy();

	virtual void ~Busy() = 0;
};

#endif
