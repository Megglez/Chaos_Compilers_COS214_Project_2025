#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include "StageOfDevelopment.h"
#include "CareStrategy.h"
using namespace std;

class Plant {
private:
	int water;
	int soil;
	int sunlight;
	StageOfDevelopment stage;
	CareStrategy* strategy;
public:
	virtual Plant* clone();
	virtual void package();
	void grow();
	void helpPlant();
	Plant();
	virtual ~Plant();
};

#endif
