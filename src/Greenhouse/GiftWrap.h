#ifndef GIFTWRAP_H
#define GIFTWRAP_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

/**
 * @brief Decorator for adding gift wrapping functionality to plants
 * 
 * The GiftWrap class is a concrete decorator that enhances plants with
 * gift wrapping capabilities, making them suitable for presentation as gifts.
 * It follows the Decorator pattern to dynamically add gift presentation
 * behavior to plant objects without modifying their underlying structure.
 * This is commonly used for special occasions, holidays, or retail displays.
 */
class GiftWrap : public PlantDecorator {
public:
    /**
     * @brief Enhances packaging with gift wrapping presentation
     * 
     * Overrides the package method to add gift wrapping behavior
     * on top of the existing plant packaging functionality.
     * Adds decorative elements like bows and wrapping paper.
     */
    virtual void package() override;
    
    /**
     * @brief Constructs a GiftWrap decorator for a plant
     * 
     * @param plant Pointer to the plant object to be decorated with gift wrap
     * 
     * @note The decorator takes ownership of the plant pointer and will manage its memory
     */
    GiftWrap(Plant* plant);
    
    /**
     * @brief Virtual destructor for proper polymorphism and memory management
     */
    virtual ~GiftWrap();
    
    /**
     * @brief Creates a deep copy of the GiftWrap decorator and its decorated plant
     * 
     * @return Plant* A new GiftWrap instance containing a clone of the decorated plant
     * 
     * @note Implements deep copy semantics by cloning the underlying plant object
     * @warning Caller is responsible for memory management of the returned pointer
     */
    virtual Plant* clone() override;
};

#endif