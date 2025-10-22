#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H
#include <iostream>
using namespace std;

class FlowerPlant : public Plant {


public:
	virtual Plant* clone() = 0;

	void package();

	FlowerPlant();

	virtual ~FlowerPlant();
};

#endif
