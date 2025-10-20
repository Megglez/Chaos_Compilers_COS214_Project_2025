#ifndef FINDAVAIBABLESTAFF_H
#define FINDAVAIBABLESTAFF_H

class FindAvaibableStaff : InfoDesk {

public:
	Staff* staffList;

	virtual void notify(Staff* staffList) = 0;
};

#endif
