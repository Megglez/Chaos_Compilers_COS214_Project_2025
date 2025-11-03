/**
 * @file ConcreteIterator.h
 * @brief Concrete implementation of iterator for customer queue
 * 
 * Implements the Iterator interface specifically for traversing a
 * customer queue managed by ConcreteAggregate.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"

class ConcreteAggregate;
class Customer;

/**
 * @class ConcreteIterator
 * @brief Concrete iterator implementation for customer queue traversal
 * 
 * This class implements the Iterator interface to provide sequential
 * access to customers in a ConcreteAggregate collection without exposing
 * the underlying data structure.
 */
class ConcreteIterator : public Iterator
{
private:
    const ConcreteAggregate* aggregate;  ///< The aggregate being iterated over
    int currentIndex;                    ///< Current position in the collection

public:
    /**
     * @brief Constructs an iterator for a given aggregate
     * @param agg Pointer to the ConcreteAggregate to iterate over
     */
    ConcreteIterator(const ConcreteAggregate* agg);

    /**
     * @brief Destroys the iterator
     */
    virtual ~ConcreteIterator();

    /**
     * @brief Moves iterator to the first customer
     * @return Pointer to the first customer, or nullptr if collection is empty
     */
    Customer* first() override;

    /**
     * @brief Advances iterator to the next customer
     * @return Pointer to the next customer, or nullptr if at end
     */
    Customer* next() override;

    /**
     * @brief Checks if iteration has finished
     * @return true if there are no more customers to iterate, false otherwise
     */
    bool isDone() const override;

    /**
     * @brief Gets the current customer without advancing the iterator
     * @return Pointer to the current customer, or nullptr if iterator is exhausted
     */
    Customer* currentItem() const override;
};

#endif