/**
 * @file GiftWrap.cpp
 * @brief Implementation of the GiftWrap class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "GiftWrap.h"

/**
 * @brief Implements gift wrapping packaging functionality
 * 
 * This method enhances the basic packaging functionality by adding
 * gift wrapping presentation. It first calls the base class package
 * method (if any) and then adds the gift wrapping step with decorative
 * elements like bows and wrapping paper.
 * 
 * The gift wrapping transforms a regular plant into an attractive
 * gift suitable for special occasions, celebrations, or retail presentation.
 */
void GiftWrap::package() {
    PlantDecorator::package();
    
    cout << "Adding beautiful gift wrap with a bow!" << endl;
}

/**
 * @brief Constructs a GiftWrap decorator wrapping the specified plant
 * 
 * @param plant The plant object to be decorated with gift wrapping capabilities
 * 
 * Initializes the decorator by wrapping the provided plant object, enabling
 * dynamic addition of gift presentation functionality to any plant type.
 * This allows plants to be converted into gift items without modifying
 * their core class structure.
 */
GiftWrap::GiftWrap(Plant* plant): PlantDecorator(plant) {
    // TODO - implement GiftWrap::GiftWrap
}

/**
 * @brief Destroys the GiftWrap decorator
 * 
 * Cleans up resources and ensures proper destruction of the decorated plant object
 * through the base class destructor chain.
 */
GiftWrap::~GiftWrap()
{
}

/**
 * @brief Creates a deep copy of the GiftWrap decorator
 * 
 * @return Plant* A new GiftWrap instance containing a cloned copy
 *         of the decorated plant, or nullptr if no plant was decorated
 * 
 * This method ensures that decorating a plant with gift wrapping capabilities
 * doesn't prevent the plant from being cloned. The clone operation
 * recursively clones the entire decoration chain, creating an independent
 * copy of both the gift wrap decorator and the underlying plant.
 * This is particularly useful for creating multiple identical gift plants.
 */
Plant* GiftWrap::clone() {
    return new GiftWrap(plantDec ? plantDec->clone() : nullptr);
}