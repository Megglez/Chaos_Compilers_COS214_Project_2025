#include "SucculentPlant.h"
#include "StageOfDevelopment.h"

/**
 * @brief Constructs a SucculentPlant with the specified configuration
 * 
 * @param water Water level requirement (typically low, 0-10 scale)
 * @param soil Soil quality requirement (well-draining, 0-10 scale)
 * @param sunlight Sunlight level requirement (moderate to bright, 0-10 scale)
 * @param stage Pointer to the initial development stage
 * @param strategy Pointer to the care strategy implementation
 * @param name Unique identifier for this succulent
 * 
 * Initializes the plant with succulent-specific defaults and passes parameters
 * to the base Plant constructor for common initialization. Succulents typically
 * require minimal watering and well-draining soil conditions.
 */
SucculentPlant::SucculentPlant(int water, int soil, int sunlight, StageOfDevelopment* stage, CareStrategy* strategy, string name): Plant(water, soil, sunlight, stage, strategy) 
{
    this->name = name;
    this->type = "Succulent";
}

/**
 * @brief Retrieves the name of this succulent plant
 * 
 * @return string The name identifier assigned during construction
 */
string SucculentPlant::getName()
{
    return name;
}

/**
 * @brief Returns the plant type classification
 * 
 * @return string Always returns "Succulent" to identify this as a succulent plant type
 */
string SucculentPlant::getType()
{
    return type;
}

/**
 * @brief Creates a deep copy of the SucculentPlant with cloned dependencies
 * 
 * @return Plant* A new SucculentPlant instance with identical attributes but
 * independently cloned strategy and stage objects
 * 
 * This implementation ensures that cloned SucculentPlants have their own copies
 * of CareStrategy and StageOfDevelopment objects, preventing shared state
 * between the original and the clone. This is particularly important for
 * succulent plants which may have specialized care requirements.
 */
Plant *SucculentPlant::clone()
{
    CareStrategy* cr = nullptr;
    StageOfDevelopment* st = nullptr;
    if (this->strategy != nullptr)
        cr = this->strategy->clone();
    if(this->stage != nullptr){
        st = stage->clone();
    }
    return new SucculentPlant(
        this->water,
        this->soil,
        this->sunlight,
        st,
        cr,
        this->name
    );
}

/**
 * @brief Destroys the SucculentPlant object
 * 
 * Cleans up resources associated with the succulent plant instance.
 * Base class destructor handles deletion of strategy and stage objects.
 */
SucculentPlant::~SucculentPlant()
{
}

/**
 * @brief Placeholder for succulent-specific packaging functionality
 * 
 * Intended to implement packaging operations specific to succulents in future versions.
 * Succulent packaging might involve special considerations for their fragile leaves
 * and specific moisture requirements during transport.
 * Currently serves as a no-operation placeholder to satisfy the interface contract.
 */
void SucculentPlant::package(){}

void SucculentPlant::helpPlant(){
    if(watered == 0){
        if(stage->getStageName() == "Seed"){ 
            cout << "Seed care: " << endl;
            string message = "Gentle misting and warm conditions\n";
            strategy->helpPlant(message);
            grow();
            
        } else if(stage->getStageName() == "Sapling"){
            cout << "Sapling care: " << endl;
            string message = "Regular watering and protection from harsh elements\n";
            strategy->helpPlant(message);
            grow();
            
        } else if(stage->getStageName() == "Prime"){
            cout << "Prime care: " << endl;
            string message = "Full care regimen for mature plant\n";
            strategy->helpPlant(message);
            grow();
            
        } else if(stage->getStageName() == "Wilting"){
            cout << "Wilting care: " << endl;
            string message = "Extra attention and recovery measures\n";
            strategy->helpPlant(message);
            grow();

        } else if(stage->getStageName() == "Dead"){
            cout<<"Dead:"<<endl;
            cout << "Unfortunately, your plant is dead, and there's no amount of water that can save it. Sorrows, sorrows, prayers\n" << endl;
        }
        watered++;
    }else{
        cout << "The succulent was already watered. Please refrain from watering the succulent." << endl;
    }
}