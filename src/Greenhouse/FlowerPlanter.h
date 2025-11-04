#ifndef FLOWERPLANTER_H
#define FLOWERPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
#include "FlowerStrategy.h"
using namespace std;

/**
 * @brief Concrete factory for creating FlowerPlant objects with seasonal awareness
 * 
 * Implements the Planter interface to provide flower-specific plant creation functionality
 * with consideration for seasonal variations. This class follows the Factory Method pattern
 * to encapsulate the creation logic for FlowerPlant instances with appropriate default
 * configurations optimized for flowering plants, including seasonal behavior for winter.
 */
class FlowerPlanter : public Planter {
public:
    /**
     * @brief Creates a new FlowerPlant instance with flower-specific configurations
     * 
     * @param name The name/identifier for the new flower plant
     * @return Plant* A pointer to a newly created FlowerPlant object
     * 
     * @note Configures the flower with appropriate water, sunlight, and soil levels
     * optimized for flower needs (ample water, moderate sunlight, rich soil),
     * and initializes it with a Seed stage and FlowerStrategy care strategy.
     * Includes seasonal awareness for winter conditions.
     * @warning The caller is responsible for managing the memory of the returned Plant pointer
     */
    virtual Plant* planterMethod(string name) override;
    
    /**
     * @brief Constructs a FlowerPlanter with optional seasonal configuration
     * 
     * @param isWinter Boolean indicating whether the planter should create
     *                 plants in winter mode (defaults to false)
     * 
     * @note Winter mode affects the behavior of created FlowerPlant objects,
     * potentially altering their growth patterns and care requirements.
     */
    FlowerPlanter(bool isWinter = false);
    
    /**
     * @brief Destructor for FlowerPlanter
     */
    ~FlowerPlanter();
    
private:
    bool isWinter;  ///< Seasonal flag indicating whether plants should be created in winter mode
};

#endif