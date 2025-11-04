#ifndef GARDENER_H
#define GARDENER_H
#include <iostream>
#include "Staff.h"
using namespace std;

class Gardener : public Staff
{
public:
	Inventory *subject;
	Gardener(std::string &name, std::string &id,InfoDesk& infodesk);
	virtual ~Gardener();
	void performDuty();
	void careForPlants();
	void setRole() override;
	

};

#endif
