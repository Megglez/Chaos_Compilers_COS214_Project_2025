#ifndef SPECIALARRANGEMENT_H
#define SPECIALARRANGEMENT_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

class SpecialArrangement : public PlantDecorator {
public:
	virtual void package() override;
	SpecialArrangement(Plant* plant);
	virtual ~SpecialArrangement();
	virtual Plant* clone() override;

};

#endif
