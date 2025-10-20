#ifndef CASHIERS_H
#define CASHIERS_H

class Cashiers : Staff_ {

public:
	Inventory* subject;

	void makeTransaction();

	void getAvailability();

	void setAvailability();
};

#endif
