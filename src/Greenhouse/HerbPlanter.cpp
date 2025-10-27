#include "HerbPlanter.h"
#include "HerbStrategy.h"

Plant* HerbPlanter::planterMethod() 
{
	int water =2;
	int sunlight =3;
	int soil =3;
	StageOfDevelopment* stage = new Seed();
	HerbStrategy* state = new HerbStrategy();
	Plant* plant = new Plant(water,soil,sunlight,stage,state);
	return plant;
}

HerbPlanter::HerbPlanter() 
{
	
}

HerbPlanter::~HerbPlanter()
{
}
