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
    this->grow();

}

void Plant::helpPlant() 
{
    if(stage->getStageName() == "Seed"){ 
        cout << "Seed care: " << endl;
        std::string message = "Gentle misting and warm conditions\n";
        strategy->helpPlant(message);
        
    } else if(stage->getStageName() == "Sapling"){
        cout << "Sapling care: " << endl;
        std::string message = "Regular watering and protection from harsh elements\n";
        strategy->helpPlant(message);
        
    } else if(stage->getStageName() == "Prime"){
        cout << "Prime care: " << endl;
        std::string message = "Full care regimen for mature plant\n";
        strategy->helpPlant(message);
        
    } else if(stage->getStageName() == "Wilting"){
        cout << "Wilting care: " << endl;
        std::string message = "Extra attention and recovery measures\n";
        strategy->helpPlant(message);
    } else if(stage->getStageName() == "Dead"){
        cout<<"Dead:"<<endl;
        std::cout << "Unfortunately, your plant is dead, and there's no amount of water that can save it. Sorrows, sorrows, prayers\n" << std::endl;
    }
}

void Plant::setStage(StageOfDevelopment* stage){
    if(this->stage){
        delete this->stage;
    }

    this->stage = stage;
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