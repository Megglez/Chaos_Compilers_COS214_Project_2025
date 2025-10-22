#ifndef HERBPLANT_H
#define HERBPLANT_H
#include <iostream>
using namespace std;

class HerbPlant : public Plant {


public:
	virtual Plant* clone() = 0;

	void package();

	HerbPlant();

	virtual ~HerbPlant();
};

#endif
