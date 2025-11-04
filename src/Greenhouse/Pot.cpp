/**
 * @file Pot.cpp
 * @brief Implementation of the Pot class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "Pot.h"

/**
 * @brief Implements pot packaging functionality
 * 
 * This method enhances the basic packaging functionality by adding
 * pot containment behavior. It first calls the base class package
 * method (if any) and then adds the pot packaging step.
 * 
 * The pot packaging typically involves placing the plant in an
 * appropriate container for display, transport, or retail sale.
 */
void Pot::package() {
    PlantDecorator::package();
    
    cout << "Adding the plant to a pot!" << endl;
}

/**
 * @brief Constructs a Pot decorator wrapping the specified plant
 * 
 * @param plant The plant object to be decorated with pot packaging capabilities
 * 
 * Initializes the decorator by wrapping the provided plant object, enabling
 * dynamic addition of pot functionality to any plant type. This allows
 * plants to be converted into potted plants without modifying their core class.
 */
Pot::Pot(Plant* plant): PlantDecorator(plant) {
    // TODO - implement Pot::Pot
}

/**
 * @brief Destroys the Pot decorator
 * 
 * Cleans up resources and ensures proper destruction of the decorated plant object
 * through the base class destructor chain.
 */
Pot::~Pot()
{
}

/**
 * @brief Creates a deep copy of the Pot decorator
 * 
 * @return Plant* A new Pot instance containing a cloned copy
 *         of the decorated plant, or nullptr if no plant was decorated
 * 
 * This method ensures that decorating a plant with pot capabilities
 * doesn't prevent the plant from being cloned. The clone operation
 * recursively clones the entire decoration chain, creating an independent
 * copy of both the pot decorator and the underlying plant.
 */
Plant* Pot::clone() {
    return new Pot(plantDec ? plantDec->clone() : nullptr);
}