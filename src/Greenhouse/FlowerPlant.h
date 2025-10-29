#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

class FlowerPlant : public Plant 
{
public:
	Plant* clone() override;
	string getName();
	string getType();
	void setState(StageOfDevelopment* state);
	FlowerPlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name);
	virtual ~FlowerPlant();
	virtual void package() override;
};

#endif
