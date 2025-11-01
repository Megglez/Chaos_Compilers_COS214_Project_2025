#ifndef TREEPLANT_H
#define TREEPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

class TreePlant : public Plant
{
public:
	virtual Plant* clone() override;
	virtual string getName()override;
	virtual string getType() override;
	TreePlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name);
	virtual ~TreePlant();
	virtual void package() override;
};

#endif
