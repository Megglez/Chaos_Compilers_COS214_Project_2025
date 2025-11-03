/**
 * @file CustomerClock.h
 * @brief Specialized clock for triggering customer arrival events
 * 
 * This clock generates periodic customer arrival events with random
 * intervals to simulate realistic customer traffic in the nursery.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef CUSTOMERCLOCK_H
#define CUSTOMERCLOCK_H
#include "Clock.h"
#include <QRandomGenerator> // For generating random numbers

/**
 * @class CustomerClock
 * @brief Clock that triggers customer arrival events
 * 
 * Inherits from Clock to provide specialized timing for customer arrivals.
 * Uses random intervals to create varied customer traffic patterns and
 * emits signals when new customers should enter the nursery.
 */
class CustomerClock : public Clock
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a CustomerClock object
     * 
     * @param parent Optional parent QObject for Qt object hierarchy
     */
    explicit CustomerClock(QObject *parent = nullptr);
    
    /**
     * @brief Destroys the CustomerClock object
     */
    ~CustomerClock() {}
    
    /**
     * @brief Starts the customer arrival clock
     * 
     * Initializes the clock to begin emitting customer arrival signals
     * at random intervals.
     */
    void startCustomerClock(); 

signals:
    /**
     * @brief Signal emitted when a new customer should arrive
     * 
     * This signal notifies the Nursery or MainWindow to create and add
     * a new customer to the simulation.
     */
    void customerArrived(); 

private slots:
    /**
     * @brief Slot that handles base clock ticks
     * 
     * Processes the base Clock's ticked() signal and decides whether
     * to emit a customerArrived() signal based on random timing logic.
     */
    void onBaseTick(); 
};

#endif