#ifndef STAFF _H
#define STAFF _H

class Staff_ {

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
};

#endif
