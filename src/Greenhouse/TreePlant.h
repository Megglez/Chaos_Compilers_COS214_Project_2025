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
	void setState(StageOfDevelopment state);
	TreePlant(int water,int soil,int sunlight,StageOfDevelopment stage,CareStrategy* strategy,string name,string type);
	virtual ~TreePlant();
};

#endif
