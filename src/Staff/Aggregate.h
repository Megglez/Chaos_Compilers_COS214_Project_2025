/**
 * @file Aggregate.h
 * @brief Abstract aggregate interface for customer collections
 * 
 * Defines the aggregate interface for the Iterator design pattern,
 * providing a way to create iterators for customer collections.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef AGGREGATE_H
#define AGGREGATE_H

class Iterator;
class Customer;

/**
 * @class Aggregate
 * @brief Abstract base class for collections that can be iterated
 * 
 * This class implements the Aggregate role in the Iterator pattern,
 * providing an interface for creating iterators over customer collections.
 */
class Aggregate 
{
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Aggregate() {}

    /**
     * @brief Creates an iterator for this collection
     * @return Pointer to a new iterator for traversing the collection
     */
    virtual Iterator* createIterator() = 0;

    /**
     * @brief Gets the number of customers in the collection
     * @return The count of customers
     */
    virtual int getCount() const = 0;

    /**
     * @brief Gets a customer at a specific index
     * @param index The position of the customer
     * @return Pointer to the customer at the given index, or nullptr if invalid
     */
    virtual Customer* getCustomerAt(int index) const = 0;
};

#endif