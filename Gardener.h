#ifndef GARDENER_H
#define GARDENER_H

class Gardener : Staff_ {

public:
	Inventory* subject;

	void helpPlant();

	void getCareStrategy();

	void getAvailability();

	void setAvailability();

	Gardener();

	virtual void ~Gardener() = 0;
};

#endif
