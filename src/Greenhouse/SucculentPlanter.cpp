#include "SucculentPlanter.h"
#include "SucculentPlant.h"
#include "SucculentStrategy.h"
#include "Seed.h"

Plant* SucculentPlanter::planterMethod() 
{
	int water =1;
	int sunlight =1;
	int soil =2;
	StageOfDevelopment* stage = new Seed();
	SucculentStrategy* state = new SucculentStrategy();
	string name = "Succulent";
	Plant* plant = new Plant(water,soil,sunlight,stage,state);
	return plant;
}

SucculentPlanter::SucculentPlanter():Planter()
{

}

SucculentPlanter::~SucculentPlanter()
{

}
