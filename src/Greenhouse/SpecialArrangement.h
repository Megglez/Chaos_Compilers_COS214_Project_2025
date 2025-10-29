#ifndef SPECIALARRANGEMENT_H
#define SPECIALARRANGEMENT_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

class SpecialArrangement : public PlantDecorator {
public:
	virtual void package() override;
	SpecialArrangement();
	virtual ~SpecialArrangement();
};

#endif
