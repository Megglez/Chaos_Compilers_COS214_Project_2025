// PlantDecorator.h
#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"

/**
 * @brief Abstract base class for Plant decorators following the Decorator pattern
 * 
 * The PlantDecorator class serves as the base for all plant decorators, enabling
 * dynamic addition of responsibilities to Plant objects without affecting other
 * objects. It maintains a reference to a Plant object and delegates operations
 * to it, allowing concrete decorators to add functionality before or after delegation.
 * 
 * @note This is an abstract class that cannot be instantiated directly.
 * Concrete decorators must implement the clone() method.
 */
class PlantDecorator : public Plant {
protected:
    Plant* plantDec;  ///< Pointer to the decorated Plant object

public:
    /**
     * @brief Constructs a PlantDecorator wrapping the specified plant
     * 
     * @param plant Pointer to the Plant object to be decorated
     * 
     * @note The decorator takes ownership of the plant pointer and will manage its memory
     */
    PlantDecorator(Plant* plant);
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures proper destruction of the decorated plant object and any derived decorators
     */
    ~PlantDecorator() override;
    
    // Implement pure virtual functions from Plant
    /**
     * @brief Pure virtual method for creating deep copies of decorators
     * 
     * @return Plant* A deep copy of the decorator and its decorated plant
     * 
     * @note Concrete decorators must implement this to properly clone themselves
     * and their decorated plants while maintaining the decoration chain.
     */
    virtual Plant* clone() = 0;
    
    /**
     * @brief Delegates packaging operation to the decorated plant
     * 
     * Concrete decorators should override this to add packaging functionality
     * before or after calling the base implementation.
     */
    virtual void package() override;
    
    /**
     * @brief Gets the plant type from the decorated plant
     * 
     * @return string The plant type from the underlying decorated plant
     */
    virtual string getType() override;
    
    /**
     * @brief Gets the plant name from the decorated plant
     * 
     * @return string The plant name from the underlying decorated plant
     */
    virtual string getName() override;
    
    // Delegate other methods to the decorated plant
    /**
     * @brief Delegates growth operation to the decorated plant
     */
    virtual void grow() override;
    
    /**
     * @brief Delegates state setting to the decorated plant
     * 
     * @param stage Pointer to the new development stage
     */
    virtual void setState(StageOfDevelopment* stage);
    
    /**
     * @brief Delegates plant care operation to the decorated plant
     */
    virtual void helpPlant() override;
    
    /**
     * @brief Gets the development stage from the decorated plant
     * 
     * @return StageOfDevelopment* Pointer to the current development stage
     */
    virtual StageOfDevelopment* getState() override;
    
    /**
     * @brief Checks winter status from the decorated plant
     * 
     * @return bool True if it's winter for the decorated plant, false otherwise
     */
    bool isWinter() const override;
};

#endif