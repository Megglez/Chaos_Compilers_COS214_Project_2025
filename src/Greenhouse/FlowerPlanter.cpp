#include "FlowerPlanter.h"
#include "FlowerPlant.h"

Plant* FlowerPlanter::planterMethod(std::string name) 
{
	int water =4;
	int sunlight =2;
	int soil =1;
	return new FlowerPlant(water, soil, sunlight, new Seed(), new FlowerStrategy(), name, isWinter);
}

FlowerPlanter::FlowerPlanter(bool isWinter) 
{
	this->isWinter = isWinter;
	
}

FlowerPlanter::~FlowerPlanter()
{
}
