#include "Plant.h"
#include "StageOfDevelopment.h" 
#include "Seed.h"

/**
 * @brief Constructs a Plant with specified attributes and strategies
 * 
 * @param water Water requirement level (typically 0-10 scale)
 * @param soil Soil quality requirement (typically 0-10 scale)
 * @param sunlight Sunlight requirement level (typically 0-10 scale)
 * @param stage Pointer to initial development stage object
 * @param strategy Pointer to care strategy object
 * 
 * Initializes all plant attributes and takes ownership of the stage and strategy objects.
 * This constructor is typically called by concrete plant classes or factories.
 */
Plant::Plant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy)
{
    this->water = water;
    this->soil = soil;
    this->sunlight = sunlight;
    this->stage = stage;
    this->strategy = strategy; 
}

/**
 * @brief Advances the plant's development stage
 * 
 * Delegates to the current StageOfDevelopment object to handle the growth
 * transition. This implements the State pattern where each stage knows
 * how to transition to the next appropriate stage.
 */
void Plant::grow()
{
    stage->handle(this);
}

/**
 * @brief Provides stage-specific care for the plant
 * 
 * Implements a template method that provides different care instructions
 * based on the plant's current development stage. Each stage (Seed, Sapling,
 * Prime, Wilting, Dead) receives appropriate care instructions and may
 * trigger growth to the next stage.
 * 
 * The method demonstrates the integration of Strategy pattern (care strategies)
 * with State pattern (development stages).
 */
void Plant::helpPlant() 
{
    if(stage->getStageName() == "Seed"){ 
        cout << "Seed care: " << endl;
        std::string message = "Gentle misting and warm conditions\n";
        strategy->helpPlant(message);
        grow();
        
    } else if(stage->getStageName() == "Sapling"){
        cout << "Sapling care: " << endl;
        std::string message = "Regular watering and protection from harsh elements\n";
        strategy->helpPlant(message);
        grow();
        
    } else if(stage->getStageName() == "Prime"){
        cout << "Prime care: " << endl;
        std::string message = "Full care regimen for mature plant\n";
        strategy->helpPlant(message);
        grow();
        
    } else if(stage->getStageName() == "Wilting"){
        cout << "Wilting care: " << endl;
        std::string message = "Extra attention and recovery measures\n";
        strategy->helpPlant(message);
        grow();

    } else if(stage->getStageName() == "Dead"){
        cout<<"Dead:"<<endl;
        std::cout << "Unfortunately, your plant is dead, and there's no amount of water that can save it. Sorrows, sorrows, prayers\n" << std::endl;
    }
}

/**
 * @brief Changes the plant's development stage
 * 
 * @param stage Pointer to the new development stage object
 * 
 * Safely replaces the current stage object, deleting the old one
 * and taking ownership of the new stage object.
 */
void Plant::setStage(StageOfDevelopment* stage){
    if(this->stage){
        delete this->stage;
    }

    this->stage = stage;
}

/**
 * @brief Destroys the Plant object and its components
 * 
 * Cleans up the stage and strategy objects to prevent memory leaks.
 * This ensures proper resource management for the State and Strategy
 * pattern objects owned by the plant.
 */
Plant::~Plant()
{
    if(stage) delete stage;
    if(strategy) delete strategy;
}

/**
 * @brief Checks if the plant is in winter conditions
 * 
 * @return bool Always returns false in base implementation
 * 
 * Derived classes can override this to implement seasonal behavior
 * specific to certain plant types or environments.
 */
bool Plant::isWinter() const { return false; }

/**
 * @brief Gets the current development stage object
 * 
 * @return StageOfDevelopment* Pointer to the current stage object
 */
StageOfDevelopment* Plant::getState(){
    return stage;
}

/**
 * @brief Gets the water requirement level
 * 
 * @return int The water requirement value
 */
int Plant::getWater(){
    return water;
}

/**
 * @brief Gets the soil quality requirement
 * 
 * @return int The soil quality value
 */
int Plant::getSoil(){
    return soil;
}

/**
 * @brief Gets the sunlight requirement level
 * 
 * @return int The sunlight requirement value
 */
int Plant::getSunlight(){
    return sunlight;
}

/**
 * @brief Gets the current care strategy object
 * 
 * @return CareStrategy* Pointer to the care strategy object
 */
CareStrategy* Plant::getCare(){
    return strategy;
}