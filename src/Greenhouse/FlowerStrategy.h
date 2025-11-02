#ifndef FLOWERSTRATEGY_H
#define FLOWERSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

/**
 * @brief Concrete strategy for flower care operations
 * 
 * Implements the CareStrategy interface to provide flower-specific plant care functionality.
 * This class follows the Strategy pattern to encapsulate flower care behaviors,
 * which typically involve specific watering, pruning, deadheading, and seasonal
 * care requirements appropriate for flowering plants like roses, tulips, daisies, etc.
 */
class FlowerStrategy : public CareStrategy 
{
public:
    /**
     * @brief Provides flower-specific care instructions
     * 
     * @param care A string describing the care method being applied to the flower
     * 
     * @note Outputs the current care method to standard output with flower-specific context
     */
    virtual void helpPlant(std::string& care) override;
    
    /**
     * @brief Default constructor for FlowerStrategy
     */
    FlowerStrategy();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~FlowerStrategy();
    
    /**
     * @brief Creates a copy of this FlowerStrategy object
     * 
     * @return CareStrategy* A new FlowerStrategy instance with the same behavior
     * 
     * @note Implements the Prototype pattern for polymorphic copying
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual CareStrategy* clone() override;
};

#endif