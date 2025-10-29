#include "TreePlanter.h"
#include "TreeStrategy.h"
#include "TreePlant.h"

Plant* TreePlanter::planterMethod(std::string name) 
{
	int water =3;
	int sunlight =2;
	int soil =1;
	StageOfDevelopment* stage = new Seed();
	TreeStrategy* state = new TreeStrategy();
	Plant* plant = new TreePlant(water,soil,sunlight,stage,state, name);
	return plant;
}

TreePlanter::TreePlanter() 
{

}

TreePlanter::~TreePlanter()
{
}
