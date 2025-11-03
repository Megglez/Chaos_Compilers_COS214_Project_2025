#include "PlantDecorator.h"
#include "StageOfDevelopment.h"

/**
 * @brief Constructs a PlantDecorator wrapping the specified plant
 * 
 * @param plant Pointer to the Plant object to be decorated
 * 
 * Initializes the decorator by storing a reference to the plant to be decorated.
 * The decorator takes ownership of the plant pointer and will manage its memory.
 */
PlantDecorator::PlantDecorator(Plant* plant) : Plant(), plantDec(plant) {
}

/**
 * @brief Destroys the PlantDecorator and its decorated plant
 * 
 * Cleans up the decorated plant object and ensures proper memory management
 * through the decorator chain. This is crucial for preventing memory leaks
 * in decorated object hierarchies.
 */
PlantDecorator::~PlantDecorator() {
    if(plantDec != nullptr) {
        delete plantDec;
        plantDec = nullptr;
    }
}

/**
 * @brief Delegates packaging operation to the decorated plant
 * 
 * Concrete decorators should call this base implementation and then
 * add their specific packaging functionality to extend the behavior.
 */
void PlantDecorator::package() {
    if(plantDec) {
        plantDec->package();
    }
}

/**
 * @brief Delegates growth operation to the decorated plant
 * 
 * Forwards the grow() call to the underlying decorated plant object.
 */
void PlantDecorator::grow() {
    if(plantDec) {
        plantDec->grow();
    }
}

/**
 * @brief Delegates state setting to the decorated plant
 * 
 * @param stage Pointer to the new development stage to set on the decorated plant
 */
void PlantDecorator::setState(StageOfDevelopment* stage) {
    if(plantDec) {
        plantDec->setStage(stage);
    }
}

/**
 * @brief Delegates plant care operation to the decorated plant
 * 
 * Forwards the helpPlant() call to the underlying decorated plant object.
 */
void PlantDecorator::helpPlant() {
    if(plantDec) {
        plantDec->helpPlant();
    }
}

/**
 * @brief Gets the plant type from the decorated plant
 * 
 * @return string The plant type from the underlying decorated plant,
 *         or "DecoratedPlant" if no plant is decorated
 */
string PlantDecorator::getType() {
    return plantDec ? plantDec->getType() : "DecoratedPlant";
}

/**
 * @brief Gets the plant name from the decorated plant
 * 
 * @return string The plant name from the underlying decorated plant,
 *         or "Unknown" if no plant is decorated
 */
string PlantDecorator::getName() {
    return plantDec ? plantDec->getName() : "Unknown";
}

/**
 * @brief Gets the development stage from the decorated plant
 * 
 * @return StageOfDevelopment* Pointer to the current development stage
 *         of the decorated plant, or nullptr if no plant is decorated
 */
StageOfDevelopment* PlantDecorator::getState() {
    return plantDec ? plantDec->getState() : nullptr;
}

/**
 * @brief Checks winter status from the decorated plant
 * 
 * @return bool True if it's winter for the decorated plant,
 *         false otherwise or if no plant is decorated
 */
bool PlantDecorator::isWinter() const {
    return plantDec ? plantDec->isWinter() : false;
}