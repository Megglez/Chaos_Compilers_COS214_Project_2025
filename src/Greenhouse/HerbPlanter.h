#ifndef HERBPLANTER_H
#define HERBPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
using namespace std;

/**
 * @brief Concrete factory for creating HerbPlant objects
 * 
 * Implements the Planter interface to provide herb-specific plant creation functionality.
 * This class follows the Factory Method pattern to encapsulate the creation logic
 * for HerbPlant instances with appropriate default configurations optimized for herbs.
 * Herb plants typically require moderate watering, good sunlight, and well-draining soil.
 */
class HerbPlanter : public Planter 
{
public:
    /**
     * @brief Creates a new HerbPlant instance with herb-specific configurations
     * 
     * @param name The name/identifier for the new herb plant
     * @return Plant* A pointer to a newly created HerbPlant object
     * 
     * @note Configures the herb with appropriate water, sunlight, and soil levels
     * optimized for herb needs (moderate water, good sunlight, well-draining soil),
     * and initializes it with a Seed stage and HerbStrategy care strategy.
     * @warning The caller is responsible for managing the memory of the returned Plant pointer
     */
    virtual Plant* planterMethod(std::string name) override;
    
    /**
     * @brief Default constructor for HerbPlanter
     */
    HerbPlanter();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~HerbPlanter();
};

#endif