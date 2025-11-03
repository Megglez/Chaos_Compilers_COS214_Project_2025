#ifndef TREEPLANT_H
#define TREEPLANT_H
#include <iostream>
#include "Plant.h"
using namespace std;

/**
 * @brief Concrete implementation of a Tree plant type
 * 
 * Represents a specific tree plant in the system, inheriting from the abstract Plant class.
 * Provides tree-specific implementations and follows the Prototype pattern for cloning.
 */
class TreePlant : public Plant
{
public:
    /**
     * @brief Creates a deep copy of this TreePlant object
     * 
     * @return Plant* A new TreePlant instance with copied attributes and cloned strategies
     * 
     * @note Clones both the CareStrategy and StageOfDevelopment objects to ensure
     * deep copy semantics. Handles null pointers safely.
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual Plant* clone() override;
    
    /**
     * @brief Gets the name of this tree plant
     * 
     * @return string The name identifier of the tree
     */
    virtual string getName() override;
    
    /**
     * @brief Gets the type of plant
     * 
     * @return string Always returns "Tree" for TreePlant instances
     */
    virtual string getType() override;
    
    /**
     * @brief Constructs a new TreePlant with specified attributes
     * 
     * @param water The water level requirement for the tree
     * @param soil The soil quality requirement for the tree  
     * @param sunlight The sunlight level requirement for the tree
     * @param stage The current development stage of the tree
     * @param strategy The care strategy to use for this tree
     * @param name The name identifier for this tree
     * 
     * @note Sets the plant type to "Tree" automatically
     */
    TreePlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name);
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~TreePlant();
    
    /**
     * @brief Package operation for the tree plant
     * 
     * @note Currently implemented as an empty function, intended for future
     * packaging functionality specific to trees.
     */
    virtual void package() override;
};

#endif