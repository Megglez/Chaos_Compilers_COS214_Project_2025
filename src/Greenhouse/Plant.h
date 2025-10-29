#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include <string>
#include "StageOfDevelopment.h"
#include "CareStrategy.h"
using namespace std;

class Plant {
private:
	int water;
	int soil;
	int sunlight;
	StageOfDevelopment* stage;
	CareStrategy* strategy;
	string name;
	string type;
	
public:
	virtual Plant* clone();
	virtual void package();
	void grow();
	void setStage(StageOfDevelopment* stage);
	void helpPlant();
	virtual string getType();
	virtual string getName();
	Plant();
	Plant(int water,int soil,int sunlight,StageOfDevelopment stage,CareStrategy* strategy);
	virtual ~Plant();
};

#endif
