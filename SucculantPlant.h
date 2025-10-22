#ifndef SUCCULANTPLANT_H
#define SUCCULANTPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class SucculantPlant : public Plant {
public:
	Plant* clone();
	void package();
	SucculantPlant();
	virtual ~SucculantPlant();
};

#endif
