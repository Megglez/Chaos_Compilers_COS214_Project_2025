#ifndef HERBSTRATEGY_H
#define HERBSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

/**
 * @brief Concrete strategy for herb care operations
 * 
 * Implements the CareStrategy interface to provide herb-specific plant care functionality.
 * This class follows the Strategy pattern to encapsulate herb care behaviors,
 * which typically involve specific watering, harvesting, and sunlight requirements
 * appropriate for herb plants like basil, mint, rosemary, etc.
 */
class HerbStrategy : public CareStrategy {
public:
    /**
     * @brief Provides herb-specific care instructions
     * 
     * @param care A string describing the care method being applied to the herb
     * 
     * @note Outputs the current care method to standard output with herb-specific context
     */
    virtual void helpPlant(string& care) override;
    
    /**
     * @brief Default constructor for HerbStrategy
     */
    HerbStrategy();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~HerbStrategy();
    
    /**
     * @brief Creates a copy of this HerbStrategy object
     * 
     * @return CareStrategy* A new HerbStrategy instance with the same behavior
     * 
     * @note Implements the Prototype pattern for polymorphic copying
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual CareStrategy* clone() override;
};

#endif