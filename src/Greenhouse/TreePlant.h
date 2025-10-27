#ifndef TREEPLANT_H
#define TREEPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class TreePlant : public Plant
{
public:
	Plant* clone() override;
	string getName();
	string getType();
	TreePlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name);
	virtual ~TreePlant();
};

#endif
