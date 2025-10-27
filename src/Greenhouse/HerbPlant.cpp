#include "HerbPlant.h"

HerbPlant::HerbPlant(int water,int soil,int sunlight,StageOfDevelopment stage,CareStrategy* strategy,string name,string type):Plant(water,soil,sunlight,stage,strategy) 
{
    this->name=name;
    this->type = type;
}


Plant *HerbPlant::clone()
{
    CareStrategy* cr = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    return new HerbPlant
    (
        this->water,
        this->soil,
        this->sunlight,
        this->stage,
        cr,
        this->name,
        this->type
    );
}

string HerbPlant::getName()
{
    return name;
}

string HerbPlant::getType()
{
    return type;
}

void HerbPlant::setState(StageOfDevelopment state)
{
    stage= state;
}

HerbPlant::~HerbPlant()
{
    delete strategy;
    delete this;
}
