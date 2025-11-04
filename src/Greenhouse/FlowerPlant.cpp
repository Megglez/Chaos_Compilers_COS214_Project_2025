/**
 * @file FlowerPlant.cpp
 * @brief Implementation of the FlowerPlant class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "FlowerPlant.h"
#include <string>
#include "StageOfDevelopment.h"

/**
 * @brief Creates a deep copy of the FlowerPlant with cloned dependencies and seasonal state
 * 
 * @return Plant* A new FlowerPlant instance with identical attributes but
 * independently cloned strategy and stage objects, preserving the seasonal state
 * 
 * This implementation ensures that cloned FlowerPlants have their own copies
 * of CareStrategy and StageOfDevelopment objects while maintaining the same
 * seasonal conditions as the original. This is particularly important for
 * flower plants which may have different care requirements based on season.
 */
Plant *FlowerPlant::clone()
{
    CareStrategy* cr = nullptr;
    StageOfDevelopment* st = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    if(this->stage != nullptr){
        st = stage->clone();
    }
    return new FlowerPlant(
        this->water,
        this->soil,
        this->sunlight,
        st,
        cr,
        this->name,
        this->isWinterFlower
    );
}

/**
 * @brief Constructs a FlowerPlant with the specified configuration and seasonal state
 * 
 * @param water Water level requirement (typically ample, 0-10 scale)
 * @param soil Soil quality requirement (rich and fertile, 0-10 scale)
 * @param sunlight Sunlight level requirement (moderate, 0-10 scale)
 * @param stage Pointer to the initial development stage
 * @param strategy Pointer to the care strategy implementation
 * @param name Unique identifier for this flower
 * @param isWinter Seasonal flag indicating winter conditions
 * 
 * Initializes the plant with flower-specific defaults and seasonal awareness.
 * Flowers typically have specific requirements for blooming and may behave
 * differently during winter months, with many species going dormant or
 * requiring special protection from cold temperatures.
 */
FlowerPlant::FlowerPlant(int water, int soil, int sunlight, StageOfDevelopment *stage, CareStrategy* strategy, string name, bool isWinter): Plant(water, soil, sunlight, stage, strategy) 
{
    this->name = name;
    this->type = "Flower";
    this->isWinterFlower = isWinter;
}

/**
 * @brief Retrieves the name of this flower plant
 * 
 * @return string The name identifier assigned during construction
 */
string FlowerPlant::getName()
{
    return name;
}

/**
 * @brief Returns the plant type classification
 * 
 * @return string Always returns "Flower" to identify this as a flower plant type
 */
string FlowerPlant::getType()
{
    return type;
}

/**
 * @brief Destroys the FlowerPlant object
 * 
 * Cleans up resources associated with the flower plant instance.
 * Base class destructor handles deletion of strategy and stage objects.
 */
FlowerPlant::~FlowerPlant()
{
}

/**
 * @brief Placeholder for flower-specific packaging functionality
 * 
 * Intended to implement packaging operations specific to flowers in future versions.
 * Flower packaging might involve special considerations for bouquet arrangement,
 * vase presentation, decorative wrapping, or preservation techniques.
 * Currently serves as a no-operation placeholder to satisfy the interface contract.
 */
void FlowerPlant::package(){
    
}

/**
 * @brief Checks seasonal winter conditions for the flower plant
 * 
 * @return bool True if the flower is in winter conditions, false otherwise
 * 
 * This override provides flower-specific seasonal behavior. During winter,
 * many flowering plants may enter dormancy, reduce growth, or require
 * different care regimens. This information can be used by the care
 * system to adjust watering, fertilization, and other maintenance activities.
 */
bool FlowerPlant::isWinter() const {
     return isWinterFlower;
}