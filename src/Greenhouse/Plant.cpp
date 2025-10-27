#include "Plant.h"

Plant::Plant(int water,int soil,int sunlight, StageOfDevelopment stage,CareStrategy* strategy)
{
    this->water=water;
    this->soil=soil;
    this->sunlight=sunlight;
    StageOfDevelopment* stage = new StageOfDevelopment();
    CareStrategy* strategy = new CareStrategy();
}

Plant *Plant::clone()
{
    return nullptr;
}

void Plant::grow()
{
    this->grow();

}

void Plant::helpPlant() 
{
	// TODO - implement Plant::helpPlant
	
}

Plant::~Plant()
{
}
