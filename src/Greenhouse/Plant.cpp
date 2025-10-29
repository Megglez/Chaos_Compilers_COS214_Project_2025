#include "Plant.h"
#include "StageOfDevelopment.h" 
#include "Seed.h"

Plant::Plant(int water,int soil,int sunlight, StageOfDevelopment* stage,CareStrategy* strategy)
{
    this->water=water;
    this->soil=soil;
    this->sunlight=sunlight;
    this->stage = new Seed();
    this->strategy = strategy; 
}

void Plant::grow()
{
    this->grow();

}

<<<<<<< HEAD
void Plant::helpPlant() 
{
=======
void Plant::setStage(StageOfDevelopment* stage){
    if(this->stage){
        delete this->stage;
    }

    this->stage = stage;
}

void Plant::helpPlant() {
>>>>>>> 230abb5af0d65aed0c55dae95f15c304ff260b5a
	// TODO - implement Plant::helpPlant
	
}

Plant::~Plant()
{
}
