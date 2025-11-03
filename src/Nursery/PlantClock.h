/**
 * @file PlantClock.h
 * @brief Specialized clock for triggering plant update events
 * 
 * This clock generates periodic signals to check plant status, growth,
 * and maintenance needs within the nursery simulation.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef PLANTCLOCK_H
#define PLANTCLOCK_H
#include "Clock.h"

/**
 * @class PlantClock
 * @brief Clock that triggers plant state update events
 * 
 * Inherits from Clock to provide specialized timing for plant-related
 * operations such as growth, state transitions, and maintenance checks.
 * Emits signals at regular intervals to update plant conditions.
 */
class PlantClock : public Clock
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a PlantClock object
     * 
     * @param parent Optional parent QObject for Qt object hierarchy
     */
    explicit PlantClock(QObject *parent = nullptr);
    
    /**
     * @brief Destroys the PlantClock object
     */
    ~PlantClock() {}
    
    /**
     * @brief Starts the plant update clock
     * 
     * Initializes the clock to begin emitting plant update signals
     * at regular intervals.
     */
    void startPlantClock(); 

signals:
    /**
     * @brief Signal emitted when plants should be updated
     * 
     * This signal notifies the Nursery or MainWindow to check and update
     * plant states, growth levels, or maintenance requirements.
     */
    void plantUpdate(); 

private slots:
    /**
     * @brief Slot that handles base clock ticks
     * 
     * Connects to the base Clock's ticked() signal and re-emits
     * the specialized plantUpdate() signal.
     */
    void onBaseTick(); 
};

#endif