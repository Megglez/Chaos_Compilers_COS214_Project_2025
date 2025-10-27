#ifndef HERBPLANT_H
#define HERBPLANT_H
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

class HerbPlant : public Plant 
{
public:
	Plant* clone() override;
	string getName();
	string getType();
	void setState(StageOfDevelopment state);
	HerbPlant(int water,int soil,int sunlight,StageOfDevelopment stage,CareStrategy* strategy,string name,string type);
	virtual ~HerbPlant();
};

#endif
