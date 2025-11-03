/**
 * @file ConcreteAggregate.h
 * @brief Concrete implementation of aggregate for customer queue
 * 
 * Implements the Aggregate interface specifically for managing a queue
 * of customers at the cashier, providing iteration capabilities.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef CONCRETEAGGREGATE_H
#define CONCRETEAGGREGATE_H

#include <vector>
#include "Aggregate.h"

class Customer;
class Iterator;

/**
 * @class ConcreteAggregate
 * @brief Concrete aggregate implementation for customer queue management
 * 
 * This class implements the Aggregate interface to manage a collection of
 * customers in a queue. It provides methods to add/remove customers and
 * create iterators to traverse the queue.
 */
class ConcreteAggregate : public Aggregate
{
private:
    std::vector<Customer*> customers;  ///< Internal storage for customer queue

public:
    /**
     * @brief Constructs an empty customer aggregate
     */
    ConcreteAggregate();

    /**
     * @brief Destroys the aggregate
     */
    virtual ~ConcreteAggregate();

    /**
     * @brief Creates an iterator for this customer collection
     * @return Pointer to a new ConcreteIterator for this aggregate
     */
    Iterator* createIterator() override;

    /**
     * @brief Gets the number of customers in the queue
     * @return The count of customers
     */
    int getCount() const override;

    /**
     * @brief Gets a customer at a specific index
     * @param index The position in the queue
     * @return Pointer to the customer at the given index, or nullptr if invalid
     */
    Customer* getCustomerAt(int index) const override;

    /**
     * @brief Adds a customer to the queue
     * @param customer Pointer to the customer to add
     */
    void addCustomer(Customer* customer);

    /**
     * @brief Removes a customer from the queue at a specific index
     * @param index The position of the customer to remove
     */
    void removeCustomer(int index);

    /**
     * @brief Removes a specific customer from the queue
     * @param customer Pointer to the customer to remove
     */
    void removeCustomer(Customer* customer);

    /**
     * @brief Checks if the queue is empty
     * @return true if queue has no customers, false otherwise
     */
    bool isEmpty() const;
};

#endif