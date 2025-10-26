#ifndef HERBPLANT_H
#define HERBPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class HerbPlant : public Plant {
public:
	Plant* clone();
	void package();
	HerbPlant();
	virtual ~HerbPlant();
};

#endif
