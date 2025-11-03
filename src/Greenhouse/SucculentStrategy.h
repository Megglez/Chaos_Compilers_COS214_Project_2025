#ifndef SUCCULENTSTRATEGY_H
#define SUCCULENTSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

/**
 * @brief Concrete strategy for succulent care operations
 * 
 * Implements the CareStrategy interface to provide succulent-specific plant care functionality.
 * This class follows the Strategy pattern to encapsulate succulent care behaviors,
 * which typically involve minimal watering and specific sunlight requirements.
 */
class SucculentStrategy : public CareStrategy 
{
public:
    /**
     * @brief Provides succulent-specific care instructions
     * 
     * @param care A string describing the care method being applied to the succulent
     * 
     * @note Outputs the current care method to standard output with succulent-specific context
     */
    virtual void helpPlant(std::string& care) override;
    
    /**
     * @brief Default constructor for SucculentStrategy
     */
    SucculentStrategy();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~SucculentStrategy();
    
    /**
     * @brief Creates a copy of this SucculentStrategy object
     * 
     * @return CareStrategy* A new SucculentStrategy instance with the same behavior
     * 
     * @note Implements the Prototype pattern for polymorphic copying
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual CareStrategy* clone() override;
};

#endif