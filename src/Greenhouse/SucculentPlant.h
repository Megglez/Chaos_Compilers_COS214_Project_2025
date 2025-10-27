#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class SucculentPlant : public Plant 
{
public:
	Plant* clone() override;
	string getName();
	string getType();
	void setState(StageOfDevelopment state);
	SucculentPlant(int water,int soil,int sunlight,StageOfDevelopment stage,CareStrategy* strategy,string name,string type);
	virtual ~SucculentPlant();
};

#endif
