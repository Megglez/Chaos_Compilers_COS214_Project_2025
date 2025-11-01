#ifndef HERBPLANT_H
#define HERBPLANT_H
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

class HerbPlant : public Plant 
{
public:
	virtual Plant* clone() override;
	virtual string getName() override;
	virtual string getType() override;
	HerbPlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name);
	virtual ~HerbPlant();
	virtual void package() override;
};

#endif
