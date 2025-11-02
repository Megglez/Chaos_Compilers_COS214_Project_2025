#ifndef PLANTCLOCK_H
#define PLANTCLOCK_H
#include "Clock.h"

class PlantClock : public Clock
{
    Q_OBJECT
public:
    explicit PlantClock(QObject *parent = nullptr);
    ~PlantClock() {}
    void startPlantClock(); 

signals:
    // Signal to notify the Nursery/MainWindow to check or update plants
    void plantUpdate(); 

private slots:
    // Connects to the base 'ticked' signal to re-emit a specialized one
    void onBaseTick(); 
};

#endif