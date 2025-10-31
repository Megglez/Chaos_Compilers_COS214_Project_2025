#include "FlowerPlanter.h"

Plant* FlowerPlanter::planterMethod() 
{
	int water =4;
	int sunlight =2;
	int soil =1;
	StageOfDevelopment* stage = new Seed();
	FlowerStrategy* state = new FlowerStrategy();
	Plant* plant = new Plant(water,soil,sunlight,stage,state);
	return plant;
}

FlowerPlanter::FlowerPlanter() 
{
	// TODO - implement FlowerPlanter::FlowerPlanter
	
}

FlowerPlanter::~FlowerPlanter()
{
}
