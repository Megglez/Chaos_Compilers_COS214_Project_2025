#ifndef POT_H
#define POT_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

class Pot : public PlantDecorator {
public:
	virtual void package() override;
	Pot(Plant* plant);
	virtual ~Pot();
	virtual Plant* clone() override;
};

#endif
