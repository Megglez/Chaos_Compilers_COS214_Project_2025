#ifndef GARDENER_H
#define GARDENER_H
#include <iostream>
using namespace std;

class Gardener : Staff_ {

public:
	Inventory* subject;

	void helpPlant();

	void getCareStrategy();

	void getAvailability();

	void setAvailability();

	Gardener();

	virtual ~Gardener();
};

#endif
