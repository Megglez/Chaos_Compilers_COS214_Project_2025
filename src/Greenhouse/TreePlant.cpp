#include "TreePlant.h"
#include "StageOfDevelopment.h"

Plant *TreePlant::clone()
{
    CareStrategy* cr = nullptr;
    StageOfDevelopment* st = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    if(this->stage != nullptr){
        st = stage->clone();
    }
    return new TreePlant
    (
        this->water,
        this->soil,
        this->sunlight,
        st,
        cr,
        this->name
    );
}

TreePlant::TreePlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name): Plant(water,soil,sunlight, stage,strategy) 
{
    this->name=name;
    this->type= "Tree";
}

string TreePlant::getName()
{
    return name;
}

string TreePlant::getType()
{
    return type;
}


TreePlant::~TreePlant()
{
}


void TreePlant::package(){}