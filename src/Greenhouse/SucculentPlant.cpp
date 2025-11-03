#include "SucculentPlant.h"
#include "StageOfDevelopment.h"

/**
 * @brief Constructs a SucculentPlant with the specified configuration
 * 
 * @param water Water level requirement (typically low, 0-10 scale)
 * @param soil Soil quality requirement (well-draining, 0-10 scale)
 * @param sunlight Sunlight level requirement (moderate to bright, 0-10 scale)
 * @param stage Pointer to the initial development stage
 * @param strategy Pointer to the care strategy implementation
 * @param name Unique identifier for this succulent
 * 
 * Initializes the plant with succulent-specific defaults and passes parameters
 * to the base Plant constructor for common initialization. Succulents typically
 * require minimal watering and well-draining soil conditions.
 */
SucculentPlant::SucculentPlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name): Plant(water, soil, sunlight, stage, strategy) 
{
    this->name = name;
    this->type = "Succulent";
}

/**
 * @brief Retrieves the name of this succulent plant
 * 
 * @return string The name identifier assigned during construction
 */
string SucculentPlant::getName()
{
    return name;
}

/**
 * @brief Returns the plant type classification
 * 
 * @return string Always returns "Succulent" to identify this as a succulent plant type
 */
string SucculentPlant::getType()
{
    return type;
}

/**
 * @brief Creates a deep copy of the SucculentPlant with cloned dependencies
 * 
 * @return Plant* A new SucculentPlant instance with identical attributes but
 * independently cloned strategy and stage objects
 * 
 * This implementation ensures that cloned SucculentPlants have their own copies
 * of CareStrategy and StageOfDevelopment objects, preventing shared state
 * between the original and the clone. This is particularly important for
 * succulent plants which may have specialized care requirements.
 */
Plant *SucculentPlant::clone()
{
    CareStrategy* cr = nullptr;
    StageOfDevelopment* st = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    if(this->stage != nullptr){
        st = stage->clone();
    }
    return new SucculentPlant(
        this->water,
        this->soil,
        this->sunlight,
        st,
        cr,
        this->name
    );
}

/**
 * @brief Destroys the SucculentPlant object
 * 
 * Cleans up resources associated with the succulent plant instance.
 * Base class destructor handles deletion of strategy and stage objects.
 */
SucculentPlant::~SucculentPlant()
{
}

/**
 * @brief Placeholder for succulent-specific packaging functionality
 * 
 * Intended to implement packaging operations specific to succulents in future versions.
 * Succulent packaging might involve special considerations for their fragile leaves
 * and specific moisture requirements during transport.
 * Currently serves as a no-operation placeholder to satisfy the interface contract.
 */
void SucculentPlant::package(){}