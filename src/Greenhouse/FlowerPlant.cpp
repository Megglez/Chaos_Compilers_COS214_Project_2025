#include "FlowerPlant.h"
#include <string>

Plant *FlowerPlant::clone()
{
    CareStrategy* cr = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    return new FlowerPlant(
        this->water,
        this->soil,
        this->sunlight,
        this->stage,
        cr,
        this->name,
        this->isWinterFlower
    );
}



FlowerPlant::FlowerPlant(int water,int soil,int sunlight,StageOfDevelopment *stage,CareStrategy* strategy,string name,bool isWinter):Plant(water,soil,sunlight,stage,strategy) 
{
    this->name=name;
    this->type= "Flower";
    this->isWinterFlower = isWinter;
}


string FlowerPlant::getName()
{
    return name;
}

string FlowerPlant::getType()
{
    return type;
}


FlowerPlant::~FlowerPlant()
{
    delete strategy;
}

void FlowerPlant::package(){
    
}


bool FlowerPlant::isWinter() const  {
     return isWinterFlower;
}
