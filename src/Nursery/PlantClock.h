#ifndef PLANTCLOCK_H
#define PLANTCLOCK_H
#include "Clock.h"

class PlantClock : public Clock
{
    Q_OBJECT
public:
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
    // Signal to notify the Nursery/MainWindow to check or update plants
    void plantUpdate(); 

private slots:
    // Connects to the base 'ticked' signal to re-emit a specialized one
    void onBaseTick(); 
};

#endif