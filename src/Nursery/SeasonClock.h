/**
 * @file SeasonClock.h
 * @brief Specialized clock for managing seasonal transitions
 * 
 * This clock tracks and triggers seasonal changes in the nursery,
 * cycling through the four seasons and notifying the system when
 * transitions occur.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef SEASONCLOCK_H
#define SEASONCLOCK_H
#include "Clock.h"

/**
 * @enum Season
 * @brief Enumeration of the four seasons
 */
enum Season { SPRING, SUMMER, AUTUMN, WINTER };

/**
 * @class SeasonClock
 * @brief Clock that manages seasonal transitions in the nursery
 * 
 * Inherits from Clock to provide specialized timing for seasonal changes.
 * Tracks the current season and emits signals when the season should
 * transition, affecting plant availability and nursery operations.
 */
class SeasonClock : public Clock
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a SeasonClock object
     * 
     * Initializes with Spring as the starting season.
     * 
     * @param parent Optional parent QObject for Qt object hierarchy
     */
    explicit SeasonClock(QObject *parent = nullptr);
    
    /**
     * @brief Starts the season change clock
     * 
     * Initializes the clock to begin tracking time and emitting
     * season change signals at appropriate intervals.
     */
    void startSeasonClock(); 

signals:
    /**
     * @brief Signal emitted when the season changes
     * 
     * This signal notifies the Nursery or MainWindow that a new season
     * has begun, carrying the new season as a parameter.
     * 
     * @param newSeason The season that is now active
     */
    void seasonChanged(Season newSeason); 

private slots:
    /**
     * @brief Slot that handles base clock ticks
     * 
     * Processes the base Clock's ticked() signal, increments the tick count,
     * and determines when to transition to the next season.
     */
    void onBaseTick(); 

private:
    Season currentSeason = SPRING;  ///< The currently active season
    int tickCount = 0;              ///< Counter for determining season transitions
};

#endif