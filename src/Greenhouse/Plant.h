#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include <string>
#include "CareStrategy.h"
#
using namespace std;
class StageOfDevelopment;

/**
 * @brief Abstract base class representing a plant in the system
 * 
 * The Plant class serves as the foundation for all plant types, providing
 * common attributes and behaviors while defining the interface that all
 * concrete plants must implement. It follows the Template Method pattern
 * for growth and care operations while using Strategy pattern for care
 * behaviors and State pattern for development stages.
 */
class Plant 
{
protected:
    int water;                      ///< Water requirement level for the plant
    int soil;                       ///< Soil quality requirement for the plant
    int sunlight;                   ///< Sunlight requirement level for the plant
    StageOfDevelopment* stage;      ///< Current development stage (State pattern)
    CareStrategy* strategy;         ///< Care strategy (Strategy pattern)
    string name;                    ///< Name identifier for the plant
    string type;                    ///< Plant type classification

public:
    /**
     * @brief Pure virtual method for creating deep copies of plants
     * 
     * @return Plant* A deep copy of the plant object
     * 
     * @note Concrete plant classes must implement this to support
     * the Prototype pattern for object creation.
     */
    virtual Plant* clone() = 0;
    
    /**
     * @brief Advances the plant to its next development stage
     * 
     * Delegates to the current StageOfDevelopment object to handle
     * the growth transition according to the State pattern.
     */
    virtual void grow();
    
    /**
     * @brief Changes the plant's current development stage
     * 
     * @param stage Pointer to the new development stage object
     * 
     * @note Takes ownership of the stage pointer and manages its memory
     */
    virtual void setStage(StageOfDevelopment* stage);
    
    /**
     * @brief Provides care for the plant based on its current development stage
     * 
     * Implements a template method that provides different care instructions
     * depending on the plant's current development stage (Seed, Sapling, Prime, etc.)
     */
    virtual void helpPlant();
    
    /**
     * @brief Pure virtual method for plant packaging
     * 
     * @note Concrete plant classes must implement plant-specific packaging logic
     */
    virtual void package() = 0;
    
    /**
     * @brief Pure virtual method to get plant type
     * 
     * @return string The plant type classification
     */
    virtual string getType() = 0;
    
    /**
     * @brief Pure virtual method to get plant name
     * 
     * @return string The plant name identifier
     */
    virtual string getName() = 0;
    
    /**
     * @brief Gets the current development stage of the plant
     * 
     * @return StageOfDevelopment* Pointer to the current development stage object
     */
    virtual StageOfDevelopment* getState();
    
    /**
     * @brief Gets the water requirement level
     * 
     * @return int The water requirement value
     */
    virtual int getWater();
    
    /**
     * @brief Gets the soil quality requirement
     * 
     * @return int The soil quality value
     */
    virtual int getSoil();
    
    /**
     * @brief Gets the sunlight requirement level
     * 
     * @return int The sunlight requirement value
     */
    virtual int getSunlight();
    
    /**
     * @brief Default constructor
     * 
     * Initializes stage and strategy pointers to nullptr
     */
    Plant(){ stage = nullptr; strategy = nullptr; };
    
    /**
     * @brief Parameterized constructor for plant initialization
     * 
     * @param water Water requirement level
     * @param soil Soil quality requirement
     * @param sunlight Sunlight requirement level
     * @param stage Initial development stage object
     * @param strategy Care strategy object
     * 
     * @note Takes ownership of both stage and strategy pointers
     */
    Plant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy);
    
    /**
     * @brief Virtual destructor for proper polymorphism
     * 
     * Ensures proper cleanup of stage and strategy objects
     */
    virtual ~Plant();
    
    /**
     * @brief Checks if the plant is in winter season
     * 
     * @return bool Always returns false in base implementation
     * 
     * @note Can be overridden by derived classes for seasonal behavior
     */
    virtual bool isWinter() const;
    
    /**
     * @brief Gets the current care strategy
     * 
     * @return CareStrategy* Pointer to the care strategy object
     */
    virtual CareStrategy* getCare();
};

#endif