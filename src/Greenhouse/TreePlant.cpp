#include "TreePlant.h"

Plant *TreePlant::clone()
{
    CareStrategy* cr = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    return new TreePlant
    (
        this->water,
        this->soil,
        this->sunlight,
        this->stage,
        cr,
        this->name,
        this->type
    );
    delete this;
}

TreePlant::TreePlant(int water,int soil,int sunlight,StageOfDevelopment stage,CareStrategy* strategy,string name,string type): Plant(water,soil,sunlight, stage,strategy) 
{
    this->name=name;
    this->type=type;
}

string TreePlant::getName()
{
    return name;
}

string TreePlant::getType()
{
    return type;
}

void TreePlant::setState(StageOfDevelopment state)
{
    this->stage=state;
}

TreePlant::~TreePlant()
{
    delete strategy;
    delete this;
}
