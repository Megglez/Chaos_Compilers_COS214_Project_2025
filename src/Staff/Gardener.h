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
	bool getAvailability() override;
	void setAvailability(bool isAvailable) override;
	void performDuty() override;
	bool canHandleEnquiry() override;
	Gardener();
	virtual ~Gardener();
	

};

#endif
