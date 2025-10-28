#include "FlowerPlanter.h"
#include "FlowerPlant.h"

Plant* FlowerPlanter::planterMethod(std::string name) 
{
	int water =4;
	int sunlight =2;
	int soil =1;
	StageOfDevelopment* stage = new Seed();
	FlowerStrategy* state = new FlowerStrategy();
	Plant* plant = new FlowerPlant(water, soil, sunlight, stage, state, name);
	return plant;
}

FlowerPlanter::FlowerPlanter() 
{
	// TODO - implement FlowerPlanter::FlowerPlanter
	
}

FlowerPlanter::~FlowerPlanter()
{
}
