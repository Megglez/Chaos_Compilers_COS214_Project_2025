/**
 * @file Seasons.h
 * @brief Abstract base class for seasonal states in state pattern
 * 
 * Defines the interface for all seasonal state classes that implement
 * the State design pattern for handling seasonal changes in the system.
 */

#ifndef SEASONS_H
#define SEASONS_H

#include <iostream>
using namespace std;
#include "StateCommand.h"
class Nursery;

/**
 * @class Seasons
 * @brief Abstract base class for seasonal state implementations
 * 
 * The Seasons class serves as the base class in the State pattern
 * for representing different seasons. Each concrete season class
 * (Summer, Winter, Spring, Autumn) implements the seasonal behavior
 * and transition logic.
 * 
 * @design
 * Implements the State pattern where each season represents a state
 * that defines season-specific behavior and handles transitions to
 * other seasonal states.
 * 
 * @note All concrete season classes must implement the pure virtual methods
 * @note Uses the StateCommand pattern for season-specific operations
 * 
 * @see Summer
 * @see Winter
 * @see Spring
 * @see Autumn
 * @see StateCommand
 */
class Seasons {
public:
    /**
     * @brief Handles seasonal state transitions
     * 
     * Pure virtual method that concrete season classes must implement.
     * Defines the logic for transitioning from the current season to
     * the next season in the cycle.
     * 
     * @todo Update method signature to accept facade context parameter
     * @param context The facade or context object that maintains seasonal state
     * 
     * @post The system transitions to the next appropriate season
     */
    virtual void handleChange(Nursery* nursery) = 0; // should take in facade as the context
    
    /**
     * @brief Gets the name of the current season
     * @return String representing the current season name
     * 
     * Pure virtual method that returns the identifier for the
     * concrete season implementation (e.g., "summer", "winter").
     */
    virtual std::string getSeason() = 0;
    
    /**
     * @brief Default constructor for Seasons base class
     */
    Seasons();
    
    /**
     * @brief Virtual destructor for proper polymorphic deletion
     * 
     * Ensures that derived season class destructors are called
     * properly when deleting through base class pointers.
     */
    virtual ~Seasons();

protected:
    /**
     * @brief Protected command object for season-specific operations
     * 
     * StateCommand object available to all derived season classes
     * for executing season-specific commands and operations.
     * 
     * @see StateCommand
     */
    StateCommand* commands;
};

#endif