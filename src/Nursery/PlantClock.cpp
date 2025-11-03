#include "PlantClock.h"
#include <QDebug>

PlantClock::PlantClock(QObject *parent)
    : Clock(parent) 
{
    // Connect the base class's generic 'ticked' signal to our specialized slot
    connect(this, &Clock::ticked, this, &PlantClock::onBaseTick);
}

void PlantClock::startPlantClock()
{
    // Plant events happen every 3000 milliseconds (3 seconds)
    startClock(3000); 
}

void PlantClock::onBaseTick()
{
    // Emit the specialized signal that MainWindow connects to
    emit plantUpdate(); 
    qDebug() << "PlantClock: EMITTED plantUpdate()";
}