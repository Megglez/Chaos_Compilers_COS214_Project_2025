/**
 * @file Iterator.h
 * @brief Abstract iterator interface for traversing customer collections
 * 
 * Defines the iterator interface for the Iterator design pattern,
 * allowing traversal of customer queues without exposing internal structure.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef ITERATOR_H
#define ITERATOR_H

class Customer;

/**
 * @class Iterator
 * @brief Abstract base class for iterating through customer collections
 * 
 * This class implements the Iterator pattern, providing a standard interface
 * for traversing collections of customers without exposing the underlying
 * data structure implementation.
 */
class Iterator
{
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Iterator() {}

    /**
     * @brief Moves iterator to the first customer in the collection
     * @return Pointer to the first customer, or nullptr if collection is empty
     */
    virtual Customer* first() = 0;

    /**
     * @brief Advances iterator to the next customer
     * @return Pointer to the next customer, or nullptr if at end
     */
    virtual Customer* next() = 0;

    /**
     * @brief Checks if iteration has finished
     * @return true if there are no more customers to iterate, false otherwise
     */
    virtual bool isDone() const = 0;

    /**
     * @brief Gets the current customer without advancing the iterator
     * @return Pointer to the current customer, or nullptr if iterator is exhausted
     */
    virtual Customer* currentItem() const = 0;
};

#endif