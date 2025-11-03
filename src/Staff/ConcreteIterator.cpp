/**
 * @file ConcreteIterator.cpp
 * @brief Implementation of ConcreteIterator class
 * 
 * Provides the implementation for iterating through a customer collection
 * managed by ConcreteAggregate.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include "ConcreteIterator.h"
#include "ConcreteAggregate.h"
#include "../Customer/Customer.h"

ConcreteIterator::ConcreteIterator(const ConcreteAggregate* agg)
    : aggregate(agg), currentIndex(0)
{
}

ConcreteIterator::~ConcreteIterator()
{
    // No cleanup needed - we don't own the aggregate or customers
}

Customer* ConcreteIterator::first()
{
    currentIndex = 0;
    return currentItem();
}

Customer* ConcreteIterator::next()
{
    currentIndex++;
    return currentItem();
}

bool ConcreteIterator::isDone() const
{
    return currentIndex >= aggregate->getCount();
}

Customer* ConcreteIterator::currentItem() const
{
    if (isDone())
    {
        return nullptr;
    }
    return aggregate->getCustomerAt(currentIndex);
}
