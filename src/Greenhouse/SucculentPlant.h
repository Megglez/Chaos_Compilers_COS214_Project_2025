#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class SucculentPlant : public Plant 
{
public:
	virtual Plant* clone() override;
	virtual string getName() override;
	virtual string getType() override;
	SucculentPlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name);
	virtual ~SucculentPlant();
	virtual void package() override;
};

#endif
