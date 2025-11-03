#ifndef PLANTER_H
#define PLANTER_H
#include <iostream>
#include "Plant.h"
using namespace std;

/**
 * @brief Abstract factory interface for creating Plant objects
 * 
 * The Planter class defines the Factory Method interface for creating
 * different types of plants. Concrete subclasses implement specific
 * plant creation logic for various plant types (trees, succulents, etc.).
 * This follows the Factory Method pattern to encapsulate plant creation
 * and allow flexible extension for new plant types.
 */
class Planter
{
public:
    /**
     * @brief Pure virtual factory method for creating Plant objects
     * 
     * @param name The name/identifier for the new plant
     * @return Plant* A pointer to a newly created Plant object
     * 
     * @note Concrete subclasses must implement this method to create
     * specific types of plants with appropriate configurations.
     * @warning Caller is responsible for memory management of the returned Plant pointer
     */
    virtual Plant *planterMethod(string name) = 0;
    
    /**
     * @brief Default constructor for Planter base class
     */
    Planter();
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Planter();
};

#endif