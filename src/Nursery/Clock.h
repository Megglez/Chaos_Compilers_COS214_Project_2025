/**
 * @file Clock.h
 * @brief Base class for timing mechanisms in the nursery simulation
 * 
 * Provides a generic timer implementation using Qt's QTimer that can be
 * inherited by specialized clock classes for different simulation events.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QTimer> 

/**
 * @class Clock
 * @brief Abstract base class for all clock/timer functionality
 * 
 * This class wraps Qt's QTimer to provide a consistent timing interface
 * for the nursery simulation. Derived classes can use this to trigger
 * periodic events like customer arrivals, plant updates, or season changes.
 * 
 * @note Inherits from QObject for Qt signal-slot functionality
 */
class Clock : public QObject
{
    Q_OBJECT 

public:
    /**
     * @brief Constructs a Clock object
     * 
     * @param parent Optional parent QObject for Qt object hierarchy
     */
    explicit Clock(QObject *parent = nullptr);
    
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~Clock() = default; // Important for base classes
    
    /**
     * @brief Starts the clock with a specified interval
     * 
     * Initializes the internal timer to emit ticked() signals at regular intervals.
     * 
     * @param intervalMs The interval in milliseconds between ticks
     */
    void startClock(int intervalMs); 

signals:
    /**
     * @brief Signal emitted at each clock tick
     * 
     * Generic signal that derived classes can connect to for custom behavior.
     * Emitted when the internal timer times out.
     */
    void ticked(); 

private slots:
    /**
     * @brief Internal slot that handles timer timeout
     * 
     * Catches QTimer's timeout signal and emits the custom ticked() signal.
     */
    void onInternalTimeout(); 

private:
    QTimer* internalTimer;  ///< Internal Qt timer for tick generation
};

#endif