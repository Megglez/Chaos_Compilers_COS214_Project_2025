#ifndef POT_H
#define POT_H
#include <iostream>
using namespace std;

class Pot : public PlantDecorator {


public:
	void package();

	Pot();

	virtual ~Pot();
};

#endif
