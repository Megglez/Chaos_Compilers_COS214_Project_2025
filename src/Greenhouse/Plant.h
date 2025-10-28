#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include <string>
#include "CareStrategy.h"
using namespace std;
class StageOfDevelopment;
class Plant 
{
protected:
	int water;
	int soil;
	int sunlight;
	StageOfDevelopment* stage;
	CareStrategy* strategy;
	string name;
	string type;

public:
	virtual Plant* clone() =0;
	void grow();
	void setState(StageOfDevelopment* stage);
	void helpPlant();
	virtual void package() = 0;
	virtual string getType() = 0;
	virtual string getName() = 0;
	Plant(){};
	Plant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy);
	virtual ~Plant();
};

#endif
