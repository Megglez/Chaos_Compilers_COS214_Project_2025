#include "PlantDecorator.h"

PlantDecorator::PlantDecorator(Plant* plant) : plantDec(plant) {
    // Initialize base Plant members using public interface or protected direct access
    if(plant) {
        // Since we're in a derived class, we can access our own protected members directly
        this->water = plant->getWater(); // This works because we're accessing OUR OWN water member
        this->soil = plant->getSoil();    // Not through the plant pointer
        this->sunlight = plant->getSunlight();
        this->stage = plant->getState(); // Use public method
        this->name = plant->getName();   // Use public method
        this->type = plant->getType();   // Use public method
    } else {
        this->water = 0;
        this->soil = 0;
        this->sunlight = 0;
        this->stage = nullptr;
        this->name = "Unknown";
        this->type = "Decorated";
    }
    this->strategy = nullptr; // Initialize strategy appropriately
}

PlantDecorator::~PlantDecorator() {
    // Decide on ownership - either delete plantDec or not
    // If PlantDecorator owns plantDec, delete it:
    // delete plantDec;
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