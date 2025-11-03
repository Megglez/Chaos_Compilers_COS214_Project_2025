#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H
#include <iostream>
#include <string>
#include "Plant.h"

using namespace std;

/**
 * @brief Concrete implementation of a Flower plant type with seasonal behavior
 * 
 * Represents a specific flower plant in the system, inheriting from the abstract Plant class.
 * Provides flower-specific implementations and follows the Prototype pattern for cloning.
 * Flower plants are characterized by their blooming cycles, aesthetic appeal, and
 * seasonal sensitivity. This implementation includes special handling for winter conditions
 * that affect flower growth and behavior.
 */
class FlowerPlant : public Plant 
{
private:
    bool isWinterFlower;  ///< Seasonal state indicating whether the flower is in winter conditions

public:
    /**
     * @brief Creates a deep copy of this FlowerPlant object
     * 
     * @return Plant* A new FlowerPlant instance with copied attributes and cloned strategies
     * 
     * @note Clones both the CareStrategy and StageOfDevelopment objects to ensure
     * deep copy semantics. Handles null pointers safely and preserves seasonal state.
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual Plant* clone() override;
    
    /**
     * @brief Gets the name of this flower plant
     * 
     * @return string The name identifier of the flower
     */
    virtual string getName() override;
    
    /**
     * @brief Gets the type of plant
     * 
     * @return string Always returns "Flower" for FlowerPlant instances
     */
    virtual string getType() override;
    
    /**
     * @brief Checks if the flower plant is in winter conditions
     * 
     * @return bool True if the flower is in winter mode, false otherwise
     * 
     * @note Overrides the base class implementation to provide flower-specific
     * seasonal behavior. Winter conditions may affect growth rates, blooming,
     * and care requirements for flowering plants.
     */
    virtual bool isWinter() const override;
    
    /**
     * @brief Constructs a new FlowerPlant with specified attributes and seasonal state
     * 
     * @param water The water level requirement for the flower
     * @param soil The soil quality requirement for the flower
     * @param sunlight The sunlight level requirement for the flower
     * @param stage The current development stage of the flower
     * @param strategy The care strategy to use for this flower
     * @param name The name identifier for this flower
     * @param isWinter Boolean indicating if the flower is in winter conditions
     * 
     * @note Sets the plant type to "Flower" automatically and stores seasonal state
     */
    FlowerPlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name, bool isWinter);
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~FlowerPlant();
    
    /**
     * @brief Package operation for the flower plant
     * 
     * @note Currently implemented as an empty function, intended for future
     * packaging functionality specific to flowers (e.g., bouquet arrangement,
     * vase packaging, decorative presentation, etc.).
     */
    virtual void package() override;
};

#endif