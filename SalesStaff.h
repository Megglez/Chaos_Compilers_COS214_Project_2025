#ifndef SALESSTAFF_H
#define SALESSTAFF_H

class SalesStaff : Staff_ {


public:
	void interact();

	void QnA();

	void findPlant();

	void getAvailability();

	void setAvailability();

	SalesStaff();

	virtual void ~SalesStaff() = 0;
};

#endif
