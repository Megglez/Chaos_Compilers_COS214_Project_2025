#ifndef TREEPLANT_H
#define TREEPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class TreePlant : public Plant
{
public:
	Plant *clone();
	void package();
	TreePlant();
	virtual ~TreePlant();
};

#endif
