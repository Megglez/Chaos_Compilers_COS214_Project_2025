#include "SucculentPlanter.h"
#include "SucculentPlant.h"
#include "SucculentStrategy.h"
#include "Seed.h"

Plant* SucculentPlanter::planterMethod(std::string name) 
{
	int water =1;
	int sunlight =1;
	int soil =2;
	StageOfDevelopment* stage = new Seed();
	SucculentStrategy* state = new SucculentStrategy();
	Plant* plant = new SucculentPlant(water,soil,sunlight,stage,state,name);
	return plant;
}

SucculentPlanter::SucculentPlanter():Planter()
{

}

SucculentPlanter::~SucculentPlanter()
{

}
