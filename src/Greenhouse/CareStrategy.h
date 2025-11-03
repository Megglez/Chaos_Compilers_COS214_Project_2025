#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H
#include <iostream>
using namespace std;

/**
 * @brief Abstract base class for plant care strategies following the Strategy pattern
 * 
 * The CareStrategy class defines the interface for all plant care algorithms in the system.
 * Concrete strategy classes implement specific care behaviors for different plant types
 * (trees, flowers, herbs, succulents, etc.). This enables flexible and interchangeable
 * care algorithms that can be selected at runtime based on plant requirements.
 * 
 * @note This is an abstract class that cannot be instantiated directly.
 * Concrete strategy classes must implement all pure virtual methods.
 */
class CareStrategy {
public:
    /**
     * @brief Pure virtual method for providing plant-specific care instructions
     * 
     * @param care A string reference describing the care method to be applied
     * 
     * @note Concrete implementations should provide specific care instructions
     * tailored to particular plant types and their unique requirements.
     */
    virtual void helpPlant(std::string& care) = 0;
    
    /**
     * @brief Default constructor for CareStrategy base class
     */
    CareStrategy();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~CareStrategy();
    
    /**
     * @brief Pure virtual method for creating deep copies of strategy objects
     * 
     * @return CareStrategy* A deep copy of the concrete strategy object
     * 
     * @note Concrete strategy classes must implement this to support the
     * Prototype pattern, enabling polymorphic copying of strategy objects.
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual CareStrategy* clone() = 0;
};

#endif