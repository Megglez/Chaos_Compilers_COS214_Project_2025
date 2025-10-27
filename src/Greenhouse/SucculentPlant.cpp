#include "SucculentPlant.h"


SucculentPlant::SucculentPlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name):Plant(water,soil,sunlight,stage,strategy) 
{
    this->name = name;
    this->type= "Succulent";
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
        this->name
    );
}



SucculentPlant::~SucculentPlant()
{
    delete strategy;
}
