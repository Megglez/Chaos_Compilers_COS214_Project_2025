/**
 * @file Clock.cpp
 * @brief Implementation of the Clock base class
 * 
 * Provides the implementation for the generic timer functionality
 * used by all specialized clock classes.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include "Clock.h"
#include <QDebug>

Clock::Clock(QObject *parent)
    : QObject(parent)
{
    internalTimer = new QTimer(this);
    // Connect the QTimer to the base class's private slot
    connect(internalTimer, &QTimer::timeout, this, &Clock::onInternalTimeout);
}

void Clock::startClock(int intervalMs)
{
    if (intervalMs > 0) {
        internalTimer->start(intervalMs);
        qDebug() << "Base Clock started with interval:" << intervalMs << "ms";
    }
}

void Clock::onInternalTimeout()
{
    // The base clock's only job: emit a generic tick event
    emit ticked(); 
}