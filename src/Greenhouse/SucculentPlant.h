#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class SucculentPlant : public Plant {
public:
	Plant* clone();
	void package();
	SucculentPlant();
	virtual ~SucculentPlant();
};

#endif
