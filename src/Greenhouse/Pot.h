#ifndef POT_H
#define POT_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

/**
 * @brief Decorator for adding pot packaging functionality to plants
 * 
 * The Pot class is a concrete decorator that enhances plants with pot
 * packaging capabilities. It follows the Decorator pattern to dynamically
 * add pot containment behavior to plant objects without modifying their
 * underlying structure. This is commonly used for potted plants ready
 * for display or sale.
 */
class Pot : public PlantDecorator {
public:
    /**
     * @brief Enhances packaging with pot addition
     * 
     * Overrides the package method to add pot packaging behavior
     * on top of the existing plant packaging functionality.
     */
    virtual void package() override;
    
    /**
     * @brief Constructs a Pot decorator for a plant
     * 
     * @param plant Pointer to the plant object to be decorated with a pot
     * 
     * @note The decorator takes ownership of the plant pointer and will manage its memory
     */
    Pot(Plant* plant);
    
    /**
     * @brief Virtual destructor for proper polymorphism and memory management
     */
    virtual ~Pot();
    
    /**
     * @brief Creates a deep copy of the Pot decorator and its decorated plant
     * 
     * @return Plant* A new Pot instance containing a clone of the decorated plant
     * 
     * @note Implements deep copy semantics by cloning the underlying plant object
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual Plant* clone() override;
};

#endif