#ifndef PLANTER_H
#define PLANTER_H
#include <iostream>
#include "Plant.h"
using namespace std;

class Planter
{
public:
	virtual Plant *planterMethod();
	Planter();
	virtual ~Planter();
};

#endif
