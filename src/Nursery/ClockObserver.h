/**
 * @file ClockObserver.h
 * @brief Observer interface for clock events
 * 
 * Defines the interface for objects that need to be notified when
 * clock ticks occur in the nursery simulation.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef CLOCKOBSERVER_H
#define CLOCKOBDERVER_H

/**
 * @class ClockObserver
 * @brief Abstract observer class for clock tick notifications
 * 
 * This class implements the Observer pattern for clock events.
 * Derived classes must implement the update() method to define
 * their response to clock ticks.
 */
class ClockObserver 
{
private:
public:
    /**
     * @brief Constructs a ClockObserver
     */
    ClockObserver();
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~ClockObserver();
    
    /**
     * @brief Pure virtual method called when clock ticks
     * 
     * This method must be implemented by derived classes to define
     * their behavior when notified of a clock tick event.
     */
    virtual void update();
};

#endif