#ifndef SPECIALARRANGEMENT_H
#define SPECIALARRANGEMENT_H
#include <iostream>
using namespace std;

class SpecialArrangement : public PlantDecorator {


public:
	void package();

	SpecialArrangement();

	virtual ~SpecialArrangement();
};

#endif
