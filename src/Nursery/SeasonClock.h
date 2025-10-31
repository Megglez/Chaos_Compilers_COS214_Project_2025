#ifndef SEASONCLOCK_H
#define SEASONCLOCK_H
#include "Clock.h"

enum Season { SPRING, SUMMER, AUTUMN, WINTER };

class SeasonClock : public Clock
{
    Q_OBJECT
public:
    explicit SeasonClock(QObject *parent = nullptr);
    void startSeasonClock(); 

signals:
    // Signal carries the new season data
    void seasonChanged(Season newSeason); 

private slots:
    void onBaseTick(); 

private:
    Season currentSeason = SPRING;
    int tickCount = 0;
};

#endif