#ifndef MANAGER_H
#define MANAGER_H

class Manager : Staff_ {

public:
	Inventory* subject;

	void trackInventory();

	void getAvailability();

	void setAvailability();

	Manager();

	virtual void ~Manager() = 0;
};

#endif
