#ifndef POT_H
#define POT_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

class Pot : public PlantDecorator {
public:
	virtual void package() override;
	Pot();
	virtual ~Pot();
};

#endif
