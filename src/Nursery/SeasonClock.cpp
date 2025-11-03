/**
 * @file SeasonClock.cpp
 * @brief Implementation of the SeasonClock class
 * 
 * Implements seasonal transition timing for the nursery simulation,
 * cycling through the four seasons at regular intervals.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include "SeasonClock.h"
#include <QDebug>

SeasonClock::SeasonClock(QObject *parent)
    : Clock(parent) 
{
    connect(this, &Clock::ticked, this, &SeasonClock::onBaseTick);
}

void SeasonClock::startSeasonClock()
{
    // Season changes are checked every 1000 milliseconds (1 second)
    startClock(1000); 
}

void SeasonClock::onBaseTick()
{
    // For every 10 ticks (10 seconds), advance the season
    if (++tickCount % 10 == 0) {
        currentSeason = static_cast<Season>((currentSeason + 1) % 4);
        
        emit seasonChanged(currentSeason); 
        qDebug() << "SeasonClock: EMITTED seasonChanged() - New Season!";

        tickCount = 0;
    }
}