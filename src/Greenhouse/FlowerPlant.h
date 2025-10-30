#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

class FlowerPlant : public Plant 
{
public:
	virtual Plant* clone() override;
	virtual string getName() override;
	virtual string getType() override;
	virtual bool isWinter() const override;
	FlowerPlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name, bool isWinter);
	virtual ~FlowerPlant();
	virtual void package() override;
	
private:
	bool isWinterFlower;
};

#endif
