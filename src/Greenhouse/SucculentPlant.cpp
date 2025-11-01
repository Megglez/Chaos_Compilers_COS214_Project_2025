#include "SucculentPlant.h"
#include "StageOfDevelopment.h"


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
    StageOfDevelopment* st = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    if(this->stage != nullptr){
        st = stage->clone();
    }
    return new SucculentPlant(
        this->water,
        this->soil,
        this->sunlight,
        st,
        cr,
        this->name
    );
}



SucculentPlant::~SucculentPlant()
{
}

void SucculentPlant::package(){}
