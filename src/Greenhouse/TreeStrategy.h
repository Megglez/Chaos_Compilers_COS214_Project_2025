#ifndef TREESTRATEGY_H
#define TREESTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

/**
 * @brief Concrete strategy for tree care operations
 * 
 * Implements the CareStrategy interface to provide tree-specific plant care functionality.
 * This class follows the Strategy pattern to encapsulate tree care behaviors.
 */
class TreeStrategy : public CareStrategy {
public:
    /**
     * @brief Provides tree-specific care instructions
     * 
     * @param care A string describing the care method being applied to the tree
     * 
     * @note Outputs the current care method to standard output
     */
    virtual void helpPlant(string& care) override;
    
    /**
     * @brief Default constructor for TreeStrategy
     */
    TreeStrategy();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~TreeStrategy();
    
    /**
     * @brief Creates a copy of this TreeStrategy object
     * 
     * @return CareStrategy* A new TreeStrategy instance with the same behavior
     * 
     * @note Implements the Prototype pattern for polymorphic copying
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual CareStrategy* clone() override;
};

#endif