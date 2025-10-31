#include "PlantDecorator.h"
#include "StageOfDevelopment.h"

PlantDecorator::PlantDecorator(Plant* plant) :plantDec(plant->clone()){

}

PlantDecorator::~PlantDecorator() {
    if(plantDec != nullptr){
        delete plantDec;
        plantDec = nullptr;
    }
}

void PlantDecorator::package() {
    if(plantDec) {
        plantDec->package();
    }
}

void PlantDecorator::grow() {
    if(plantDec) {
        plantDec->grow();
    }
}

void PlantDecorator::setState(StageOfDevelopment* stage) {
    if(plantDec) {
        plantDec->setStage(stage);
    }
}

void PlantDecorator::helpPlant() {
    if(plantDec) {
        plantDec->helpPlant();
    }
}

string PlantDecorator::getType() {
    return plantDec ? plantDec->getType() : "DecoratedPlant";
}

string PlantDecorator::getName() {
    return plantDec ? plantDec->getName() : "Unknown";
}

StageOfDevelopment* PlantDecorator::getState() {
    return plantDec ? plantDec->getState() : nullptr;
}

bool PlantDecorator::isWinter() const {
    return plantDec ? plantDec->isWinter() : false;
}