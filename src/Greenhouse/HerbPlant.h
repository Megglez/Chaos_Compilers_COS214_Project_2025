#ifndef HERBPLANT_H
#define HERBPLANT_H
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

/**
 * @brief Concrete implementation of a Herb plant type
 * 
 * Represents a specific herb plant in the system, inheriting from the abstract Plant class.
 * Provides herb-specific implementations and follows the Prototype pattern for cloning.
 * Herb plants are characterized by their culinary and medicinal uses, and typically
 * require regular harvesting, moderate watering, and good sunlight.
 */
class HerbPlant : public Plant 
{
public:
    /**
     * @brief Creates a deep copy of this HerbPlant object
     * 
     * @return Plant* A new HerbPlant instance with copied attributes and cloned strategies
     * 
     * @note Clones both the CareStrategy and StageOfDevelopment objects to ensure
     * deep copy semantics. Handles null pointers safely.
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual Plant* clone() override;
    
    /**
     * @brief Gets the name of this herb plant
     * 
     * @return string The name identifier of the herb
     */
    virtual string getName() override;
    
    /**
     * @brief Gets the type of plant
     * 
     * @return string Always returns "Herb" for HerbPlant instances
     */
    virtual string getType() override;
    
    /**
     * @brief Constructs a new HerbPlant with specified attributes
     * 
     * @param water The water level requirement for the herb (typically moderate)
     * @param soil The soil quality requirement for the herb (well-draining)
     * @param sunlight The sunlight level requirement for the herb (typically high)
     * @param stage The current development stage of the herb
     * @param strategy The care strategy to use for this herb
     * @param name The name identifier for this herb
     * 
     * @note Sets the plant type to "Herb" automatically
     */
    HerbPlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name);
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~HerbPlant();
    
    /**
     * @brief Package operation for the herb plant
     * 
     * @note Currently implemented as an empty function, intended for future
     * packaging functionality specific to herbs (e.g., culinary packaging,
     * medicinal preparation, etc.).
     */
    virtual void package() override;
};

#endif