#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class FlowerPlant : public Plant {
public:
	Plant* clone();
	void package();
	FlowerPlant();
	virtual ~FlowerPlant();
};

#endif
