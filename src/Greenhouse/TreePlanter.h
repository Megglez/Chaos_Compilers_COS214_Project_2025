#ifndef TREEPLANTER_H
#define TREEPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
using namespace std;

/**
 * @brief Concrete factory for creating TreePlant objects
 * 
 * Implements the Planter interface to provide tree-specific plant creation functionality.
 * This class follows the Factory Method pattern to encapsulate the creation logic
 * for TreePlant instances with appropriate default configurations.
 */
class TreePlanter : public Planter 
{
public:
    /**
     * @brief Creates a new TreePlant instance with tree-specific configurations
     * 
     * @param name The name/identifier for the new tree plant
     * @return Plant* A pointer to a newly created TreePlant object
     * 
     * @note Configures the tree with appropriate water, sunlight, and soil levels,
     * and initializes it with a Seed stage and TreeStrategy care strategy.
     * @warning The caller is responsible for managing the memory of the returned Plant pointer
     */
    virtual Plant* planterMethod(std::string name) override;
    
    /**
     * @brief Default constructor for TreePlanter
     */
    TreePlanter();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~TreePlanter(); 
    
};

#endif