#ifndef GARDENER_H
#define GARDENER_H
#include <iostream>
#include "../Staff/Staff.h"
using namespace std;

class Gardener : public Staff
{

private:
 
queue<Plant*>plantRequestList;

public:
	Inventory *subject;
	Gardener(std::string &name, std::string &id,InfoDesk& infodesk);
	virtual ~Gardener();
	void performDuty();
	void careForPlants();
	void setRole() override;
	

};

#endif
