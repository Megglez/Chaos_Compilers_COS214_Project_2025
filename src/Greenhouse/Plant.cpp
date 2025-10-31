#include "Plant.h"
#include "StageOfDevelopment.h" 
#include "Seed.h"

Plant::Plant(int water,int soil,int sunlight, StageOfDevelopment* stage,CareStrategy* strategy)
{
    this->water=water;
    this->soil=soil;
    this->sunlight=sunlight;
    this->stage = stage;
    this->strategy = strategy; 
}

void Plant::grow()
{
    stage->handle(this);
}

void Plant::helpPlant() 
{
    if(stage->getStageName() == "Seed"){ 
        cout << "Seed care: " << endl;
        std::string message = "Gentle misting and warm conditions";
        strategy->helpPlant(message);
        
    } else if(stage->getStageName() == "Sapling"){
        cout << "Sapling care: " << endl;
        std::string message = "Regular watering and protection from harsh elements";
        strategy->helpPlant(message);
        
    } else if(stage->getStageName() == "Prime"){
        cout << "Prime care: " << endl;
        std::string message = "Full care regimen for mature plant";
        strategy->helpPlant(message);
        
    } else if(stage->getStageName() == "Wilting"){
        cout << "Wilting care: " << endl;
        std::string message = "Extra attention and recovery measures";
        strategy->helpPlant(message);
    } else if(stage->getStageName() == "Dead"){
        std::cout << "Unfortunately, your plant is dead, and there's no amount of water that can save it. Sorrows, sorrows, prayers" << std::endl;
    }
}

void Plant::setState(StageOfDevelopment* state)
{
    if(stage){
        delete stage;
    }
    this->stage = state;
}

Plant::~Plant()
{
    if(stage != nullptr){
        delete stage;
        stage = nullptr;
    }
    if(strategy != nullptr){
        delete strategy;
        strategy =  nullptr;
    }
}

bool Plant::isWinter() const  { return false; }

StageOfDevelopment* Plant::getState(){
    return stage;
}

int Plant::getWater(){
    return water;
}
int Plant::getSoil(){
    return soil;
}
int Plant::getSunlight(){
    return sunlight;
}

CareStrategy* Plant::getCare(){
    return strategy;
}