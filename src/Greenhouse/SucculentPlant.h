#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

/**
 * @brief Concrete implementation of a Succulent plant type
 * 
 * Represents a specific succulent plant in the system, inheriting from the abstract Plant class.
 * Provides succulent-specific implementations and follows the Prototype pattern for cloning.
 * Succulent plants are characterized by their water-storing capabilities and drought tolerance.
 */
class SucculentPlant : public Plant 
{
public:
    /**
     * @brief Creates a deep copy of this SucculentPlant object
     * 
     * @return Plant* A new SucculentPlant instance with copied attributes and cloned strategies
     * 
     * @note Clones both the CareStrategy and StageOfDevelopment objects to ensure
     * deep copy semantics. Handles null pointers safely.
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual Plant* clone() override;
    
    /**
     * @brief Gets the name of this succulent plant
     * 
     * @return string The name identifier of the succulent
     */
    virtual string getName() override;
    
    /**
     * @brief Gets the type of plant
     * 
     * @return string Always returns "Succulent" for SucculentPlant instances
     */
    virtual string getType() override;
    
    /**
     * @brief Constructs a new SucculentPlant with specified attributes
     * 
     * @param water The water level requirement for the succulent (typically low)
     * @param soil The soil quality requirement for the succulent (well-draining)
     * @param sunlight The sunlight level requirement for the succulent
     * @param stage The current development stage of the succulent
     * @param strategy The care strategy to use for this succulent
     * @param name The name identifier for this succulent
     * 
     * @note Sets the plant type to "Succulent" automatically
     */
    SucculentPlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name);
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~SucculentPlant();
    
    /**
     * @brief Package operation for the succulent plant
     * 
     * @note Currently implemented as an empty function, intended for future
     * packaging functionality specific to succulents.
     */
    virtual void package() override;
};

#endif