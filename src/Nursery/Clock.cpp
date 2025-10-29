#include "Clock.h"
#include <QDebug> // For simple console output

Clock::Clock(QObject *parent)
    : QObject(parent)
{
    // Create the timer
    timer = new QTimer(this);
    
    // Connect the timer's timeout signal to your slot
    connect(timer, &QTimer::timeout, this, &Clock::onTimerTimeout);

    // Set the interval in milliseconds (e.g., 1000ms = 1 second)
    timer->start(1000); 

    qDebug() << "Timer started.";
}

void Clock::Clock()
{
    // This is the code that runs every time the timer fires
    qDebug() << "Timer executed!";
    // If you want it to stop after one time, use timer->stop() or QTimer::singleShot()
}