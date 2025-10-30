#ifndef PLANTER_H
#define PLANTER_H
#include <iostream>
#include "Plant.h"
using namespace std;

class Planter
{
public:
	virtual Plant *planterMethod(std::string name) =0;
	Planter();
	virtual ~Planter();
};

#endif
