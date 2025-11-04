#include "HerbPlant.h"
#include "StageOfDevelopment.h"

/**
 * @brief Constructs a HerbPlant with the specified configuration
 * 
 * @param water Water level requirement (typically moderate, 0-10 scale)
 * @param soil Soil quality requirement (well-draining, 0-10 scale)
 * @param sunlight Sunlight level requirement (typically high, 0-10 scale)
 * @param stage Pointer to the initial development stage
 * @param strategy Pointer to the care strategy implementation
 * @param name Unique identifier for this herb
 * 
 * Initializes the plant with herb-specific defaults and passes parameters
 * to the base Plant constructor for common initialization. Herbs typically
 * require moderate watering, well-draining soil, and ample sunlight for
 * optimal growth and flavor development.
 */
HerbPlant::HerbPlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name): Plant(water, soil, sunlight, stage, strategy) 
{
    this->name = name;
    this->type = "Herb";
}

/**
 * @brief Creates a deep copy of the HerbPlant with cloned dependencies
 * 
 * @return Plant* A new HerbPlant instance with identical attributes but
 * independently cloned strategy and stage objects
 * 
 * This implementation ensures that cloned HerbPlants have their own copies
 * of CareStrategy and StageOfDevelopment objects, preventing shared state
 * between the original and the clone. This is particularly important for
 * herb plants which may have specialized harvesting and care requirements.
 */
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

/**
 * @brief Retrieves the name of this herb plant
 * 
 * @return string The name identifier assigned during construction
 */
string HerbPlant::getName()
{
    return name;
}

/**
 * @brief Returns the plant type classification
 * 
 * @return string Always returns "Herb" to identify this as a herb plant type
 */
string HerbPlant::getType()
{
    return type;
}

/**
 * @brief Destroys the HerbPlant object
 * 
 * Cleans up resources associated with the herb plant instance.
 * Base class destructor handles deletion of strategy and stage objects.
 */
HerbPlant::~HerbPlant()
{
}

/**
 * @brief Placeholder for herb-specific packaging functionality
 * 
 * Intended to implement packaging operations specific to herbs in future versions.
 * Herb packaging might involve special considerations for culinary use,
 * medicinal preparation, drying processes, or retail display.
 * Currently serves as a no-operation placeholder to satisfy the interface contract.
 */
void HerbPlant::package(){
    
}