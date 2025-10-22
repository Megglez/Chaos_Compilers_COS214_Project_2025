#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H
#include <iostream>
using namespace std;

class PlantDecorator : public Plant {

public:
	Plant* plant;

	void package();

	PlantDecorator();

	virtual ~PlantDecorator();
};

#endif
