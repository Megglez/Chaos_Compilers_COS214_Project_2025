/**
 * @file ConcreteAggregate.cpp
 * @brief Implementation of ConcreteAggregate class
 * 
 * Provides the implementation for managing a collection of customers
 * and creating iterators to traverse them.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"
#include "../Customer/Customer.h"
#include <algorithm>

ConcreteAggregate::ConcreteAggregate()
{
    // Initialize empty customer queue
}

ConcreteAggregate::~ConcreteAggregate()
{
    // Note: We don't delete customers here as they are managed externally
    customers.clear();
}

Iterator* ConcreteAggregate::createIterator()
{
    return new ConcreteIterator(this);
}

int ConcreteAggregate::getCount() const
{
    return customers.size();
}

Customer* ConcreteAggregate::getCustomerAt(int index) const
{
    if (index >= 0 && index < static_cast<int>(customers.size()))
    {
        return customers[index];
    }
    return nullptr;
}

void ConcreteAggregate::addCustomer(Customer* customer)
{
    if (customer != nullptr)
    {
        customers.push_back(customer);
    }
}

void ConcreteAggregate::removeCustomer(int index)
{
    if (index >= 0 && index < static_cast<int>(customers.size()))
    {
        customers.erase(customers.begin() + index);
    }
}

void ConcreteAggregate::removeCustomer(Customer* customer)
{
    auto it = std::find(customers.begin(), customers.end(), customer);
    if (it != customers.end())
    {
        customers.erase(it);
    }
}

bool ConcreteAggregate::isEmpty() const
{
    return customers.empty();
}
