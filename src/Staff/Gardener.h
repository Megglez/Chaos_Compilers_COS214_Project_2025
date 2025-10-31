#ifndef GARDENER_H
#define GARDENER_H
#include <iostream>
#include "Staff.h"
using namespace std;

class Gardener : public Staff
{
public:
	Inventory *subject;
	void helpPlant();
	void getCareStrategy();
	virtual void getAvailability();
	virtual void setAvailability();
	Gardener();
	virtual ~Gardener();

};

#endif
