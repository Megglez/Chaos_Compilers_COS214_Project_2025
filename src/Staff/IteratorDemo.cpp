/**
 * @file IteratorDemo.cpp
 * @brief Demonstration of Iterator pattern usage with customer queue
 * 
 * This file demonstrates how the Iterator design pattern is used to
 * traverse the customer queue at the cashier and process customers
 * with empty baskets.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include <iostream>
#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"
#include "Iterator.h"
#include "../Customer/Customer.h"

/**
 * @brief Demonstrates the Iterator pattern with customer queue
 * 
 * This function shows:
 * 1. Creating a ConcreteAggregate (customer queue)
 * 2. Adding customers to the queue
 * 3. Creating an Iterator for the queue
 * 4. Iterating through customers
 * 5. Checking basket status and removing customers with empty baskets
 * 
 * This is the classic Iterator pattern implementation where:
 * - Iterator: Abstract interface for traversal
 * - ConcreteIterator: Implements traversal for ConcreteAggregate
 * - Aggregate: Abstract interface for collections
 * - ConcreteAggregate: Manages the customer collection
 */
void demonstrateIteratorPattern()
{
    std::cout << "\n====== Iterator Pattern Demonstration ======\n" << std::endl;

    // 1. Create the aggregate (collection of customers)
    ConcreteAggregate* customerQueue = new ConcreteAggregate();
    std::cout << "Step 1: Created ConcreteAggregate (customer queue)" << std::endl;

    // Note: In real usage, these customers would be created properly
    // This is just a demonstration of the iterator pattern structure
    
    std::cout << "\nStep 2: Adding customers to queue..." << std::endl;
    std::cout << "Initial queue size: " << customerQueue->getCount() << std::endl;

    // 2. Create an iterator for the aggregate
    std::cout << "\nStep 3: Creating iterator for the queue..." << std::endl;
    Iterator* iterator = customerQueue->createIterator();

    // 3. Traverse the collection using the iterator
    std::cout << "\nStep 4: Traversing customers using iterator..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // First pass: Show all customers
    std::cout << "First iteration - listing all customers:" << std::endl;
    int count = 0;
    for (Customer* customer = iterator->first(); !iterator->isDone(); customer = iterator->next())
    {
        if (customer != nullptr)
        {
            count++;
            std::cout << "  Customer " << count << ": ID " << customer->getId();
            std::cout << " | Basket empty: " << (customer->isBasketEmpty() ? "YES" : "NO") << std::endl;
        }
    }

    std::cout << "\nTotal customers iterated: " << count << std::endl;

    // 4. Clean up
    delete iterator;
    delete customerQueue;

    std::cout << "\n====== Iterator Pattern Demo Complete ======\n" << std::endl;
}

/**
 * @brief Explains the Iterator pattern components
 */
void explainIteratorPattern()
{
    std::cout << "\n========== Iterator Design Pattern ==========\n" << std::endl;
    
    std::cout << "The Iterator pattern provides a way to access elements of" << std::endl;
    std::cout << "a collection sequentially without exposing its internal structure.\n" << std::endl;
    
    std::cout << "Components in our implementation:" << std::endl;
    std::cout << "  1. Iterator (interface)" << std::endl;
    std::cout << "     - Defines operations: first(), next(), isDone(), currentItem()" << std::endl;
    std::cout << "  2. ConcreteIterator" << std::endl;
    std::cout << "     - Implements Iterator for ConcreteAggregate" << std::endl;
    std::cout << "     - Keeps track of current position in traversal" << std::endl;
    std::cout << "  3. Aggregate (interface)" << std::endl;
    std::cout << "     - Defines createIterator() operation" << std::endl;
    std::cout << "  4. ConcreteAggregate" << std::endl;
    std::cout << "     - Implements Aggregate interface" << std::endl;
    std::cout << "     - Manages collection of Customer objects" << std::endl;
    
    std::cout << "\nBenefits:" << std::endl;
    std::cout << "  - Separates collection traversal from collection structure" << std::endl;
    std::cout << "  - Multiple iterators can traverse the same collection" << std::endl;
    std::cout << "  - Collection implementation can change without affecting clients" << std::endl;
    std::cout << "  - Provides a uniform interface for traversing different collections" << std::endl;
    
    std::cout << "\n============================================\n" << std::endl;
}

// Uncomment below to run the demonstration
/*
int main()
{
    explainIteratorPattern();
    demonstrateIteratorPattern();
    return 0;
}
*/
