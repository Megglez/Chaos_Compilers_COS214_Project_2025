/**
 * @file Seasons.cpp
 * @brief Base class implementation for seasonal state pattern
 */

#include "Seasons.h"

/**
 * @brief Constructor for abstract Seasons interface
 */
Seasons::Seasons()
{
    commands = nullptr;
}

/**
 * @brief Virtual destructor for polymorphic cleanup
 */
Seasons::~Seasons()
{
    delete commands;
}