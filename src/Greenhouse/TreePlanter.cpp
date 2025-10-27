#include "TreePlanter.h"
#include "TreeStrategy.h"

Plant* TreePlanter::planterMethod() 
{
	int water =3;
	int sunlight =2;
	int soil =1;
	StageOfDevelopment* stage = new Seed();
	TreeStrategy* state = new TreeStrategy();
	Plant* plant = new Plant(water,soil,sunlight,stage,state);
	return plant;
}

TreePlanter::TreePlanter() 
{

}

TreePlanter::~TreePlanter()
{
}
