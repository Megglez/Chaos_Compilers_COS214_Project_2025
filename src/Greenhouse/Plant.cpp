#include "Plant.h"
#include "StageOfDevelopment.h" 
#include "Seed.h"

Plant::Plant(int water,int soil,int sunlight, StageOfDevelopment* stage,CareStrategy* strategy)
{
    this->water=water;
    this->soil=soil;
    this->sunlight=sunlight;
    //StageOfDevelopment* stage = new StageOfDevelopment();
    //CareStrategy* strategy = new CareStrategy(); please fix it keeps trying to make a clone but thats pure virtual idk why it wont use the default constructor
}

void Plant::grow()
{
    stage->handle(this);
}

void Plant::helpPlant() 
{
	// TODO - implement Plant::helpPlant
	
}

void Plant::setState(StageOfDevelopment* state)
{
    if(stage){
        delete stage;
    }
    this->stage = state;
}

Plant::~Plant()
{
}
