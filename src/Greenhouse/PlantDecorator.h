#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H
#include <iostream>
#include "Plant.h"
using namespace std;

class PlantDecorator : public Plant {
public:
	virtual void package() override;
	PlantDecorator();
	virtual ~PlantDecorator();
private:
	Plant* plantDec;
};

#endif
