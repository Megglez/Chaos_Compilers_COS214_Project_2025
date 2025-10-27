#include "SucculentPlant.h"


SucculentPlant::SucculentPlant(int water,int soil,int sunlight,StageOfDevelopment stage,CareStrategy* strategy,string name,string type):Plant(water,soil,sunlight,stage,strategy) 
{
    this->name = name;
    this->type= type;
}

string SucculentPlant::getName()
{
    return name;
}

string SucculentPlant::getType()
{
    return type;
}

Plant *SucculentPlant::clone()
{
    CareStrategy* cr = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    return new SucculentPlant(
        this->water,
        this->soil,
        this->sunlight,
        this->stage,
        cr,
        this->name,
        this->type
    );
}

void SucculentPlant::setState(StageOfDevelopment state)
{
    stage= state;
}


SucculentPlant::~SucculentPlant()
{
    delete strategy;
    delete this;
}
