#ifndef SUCCULENTPLANTER_H
#define SUCCULENTPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
using namespace std;

/**
 * @brief Concrete factory for creating SucculentPlant objects
 * 
 * Implements the Planter interface to provide succulent-specific plant creation functionality.
 * This class follows the Factory Method pattern to encapsulate the creation logic
 * for SucculentPlant instances with appropriate default configurations optimized for succulents.
 */
class SucculentPlanter : public Planter 
{
private: 
    Seed seed;  ///< Seed instance used for succulent plant initialization
    
public:
    /**
     * @brief Creates a new SucculentPlant instance with succulent-specific configurations
     * 
     * @param name The name/identifier for the new succulent plant
     * @return Plant* A pointer to a newly created SucculentPlant object
     * 
     * @note Configures the succulent with appropriate water, sunlight, and soil levels
     * optimized for succulent needs (low water, moderate sunlight, well-draining soil),
     * and initializes it with a Seed stage and SucculentStrategy care strategy.
     * @warning The caller is responsible for managing the memory of the returned Plant pointer
     */
    virtual Plant* planterMethod(string name) override;
    
    /**
     * @brief Default constructor for SucculentPlanter
     */
    SucculentPlanter();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~SucculentPlanter();
};

#endif