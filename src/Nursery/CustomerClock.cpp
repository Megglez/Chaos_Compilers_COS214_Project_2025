/**
 * @file CustomerClock.cpp
 * @brief Implementation of the CustomerClock class
 * 
 * Implements random customer arrival timing for the nursery simulation.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include "CustomerClock.h"
#include <QDebug>

CustomerClock::CustomerClock(QObject *parent)
    : Clock(parent) 
{
    connect(this, &Clock::ticked, this, &CustomerClock::onBaseTick);
}

void CustomerClock::startCustomerClock()
{
    // Check for new customers frequently, e.g., every 500ms
    startClock(500); 
}

void CustomerClock::onBaseTick()
{
    // Generate a random number between 0 and 99. 
    // Example: 20% chance of a customer arriving on this tick.
    int chance = QRandomGenerator::global()->bounded(100); 
    
    if (chance < 20) { // 20% chance
        emit customerArrived(); 
        qDebug() << "CustomerClock: EMITTED customerArrived()!";
    }
}