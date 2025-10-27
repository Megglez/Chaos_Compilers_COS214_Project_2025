#include "Plant.h"

Plant *Plant::clone()
{
    return nullptr;
}

void Plant::package()
{
}

void Plant::grow()
{
    // TODO - implement Plant::grow
	
}

void Plant::setStage(StageOfDevelopment* stage){
    if(this->stage){
        delete this->stage;
    }

    this->stage = stage;
}

void Plant::helpPlant() {
	// TODO - implement Plant::helpPlant
	
}

Plant::Plant() {
	// TODO - implement Plant::Plant
	
}

Plant::~Plant()
{
}
