/**
 * @file TreePlant.cpp
 * @brief Implementation of the TreePlant class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "TreePlant.h"
#include "StageOfDevelopment.h"

/**
 * @brief Creates a deep copy of the TreePlant with cloned dependencies
 * 
 * @return Plant* A new TreePlant instance with identical attributes but
 * independently cloned strategy and stage objects
 * 
 * This implementation ensures that cloned TreePlants have their own copies
 * of CareStrategy and StageOfDevelopment objects, preventing shared state
 * between the original and the clone.
 */
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

/**
 * @brief Constructs a TreePlant with the specified configuration
 * 
 * @param water Water level requirement (0-10 scale)
 * @param soil Soil quality requirement (0-10 scale)
 * @param sunlight Sunlight level requirement (0-10 scale)
 * @param stage Pointer to the initial development stage
 * @param strategy Pointer to the care strategy implementation
 * @param name Unique identifier for this tree
 * 
 * Initializes the plant with tree-specific defaults and passes parameters
 * to the base Plant constructor for common initialization.
 */
TreePlant::TreePlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name): Plant(water, soil, sunlight, stage, strategy) 
{
    this->name = name;
    this->type = "Tree";
}

/**
 * @brief Retrieves the name of this tree plant
 * 
 * @return string The name identifier assigned during construction
 */
string TreePlant::getName()
{
    return name;
}

/**
 * @brief Returns the plant type classification
 * 
 * @return string Always returns "Tree" to identify this as a tree plant type
 */
string TreePlant::getType()
{
    return type;
}

/**
 * @brief Destroys the TreePlant object
 * 
 * Cleans up resources associated with the tree plant instance.
 * Base class destructor handles deletion of strategy and stage objects.
 */
TreePlant::~TreePlant()
{
}

/**
 * @brief Placeholder for tree-specific packaging functionality
 * 
 * Intended to implement packaging operations specific to trees in future versions.
 * Currently serves as a no-operation placeholder to satisfy the interface contract.
 */
void TreePlant::package(){}