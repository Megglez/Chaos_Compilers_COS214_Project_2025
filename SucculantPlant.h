#ifndef SUCCULANTPLANT_H
#define SUCCULANTPLANT_H
#include <iostream>
using namespace std;

class SucculantPlant : public Plant {


public:
	virtual Plant* clone() = 0;

	void package();

	SucculantPlant();

	virtual ~SucculantPlant();
};

#endif
