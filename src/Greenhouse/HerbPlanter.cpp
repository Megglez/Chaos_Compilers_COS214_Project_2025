#include "HerbPlanter.h"
#include "HerbStrategy.h"
#include "HerbPlant.h"

Plant* HerbPlanter::planterMethod() 
{
	int water =2;
	int sunlight =3;
	int soil =3;
	StageOfDevelopment* stage = new Seed();
	HerbStrategy* state = new HerbStrategy();
	string name = "Herb";
	HerbPlant* plant = new HerbPlant(water,soil,sunlight,stage,state,name);
	return plant;
}

HerbPlanter::HerbPlanter() 
{

}

HerbPlanter::~HerbPlanter()
{
}
