#include "HerbPlant.h"
#include "StageOfDevelopment.h"

HerbPlant::HerbPlant(int water,int soil,int sunlight,StageOfDevelopment* stage,CareStrategy* strategy,string name):Plant(water,soil,sunlight,stage,strategy) 
{
    this->name=name;
    this->type = "Herb";
}


Plant *HerbPlant::clone()
{
    CareStrategy* cr = nullptr;
    StageOfDevelopment* st = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    if(this->stage != nullptr){
        st = stage->clone();
    }
    return new HerbPlant
    (
        this->water,
        this->soil,
        this->sunlight,
        st,
        cr,
        this->name
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



HerbPlant::~HerbPlant()
{
}

void HerbPlant::package(){
    
}
