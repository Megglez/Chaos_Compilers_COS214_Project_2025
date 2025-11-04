/**
 * @file SeasonClock.cpp
 * @brief Implementation of the SeasonClock class
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