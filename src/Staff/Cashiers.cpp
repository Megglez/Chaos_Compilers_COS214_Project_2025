/**
 * @file Cashiers.cpp
 * @brief Implementation of Cashiers class
 * 
 * Provides the implementation for cashier operations including
 * customer queue processing using the Iterator pattern.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include "Cashiers.h"
#include "Iterator.h"
#include "../Customer/Customer.h"
#include "../Nursery/Nursery.h"
#include <iostream>

Cashiers::Cashiers(std::string& name, std::string& id) : Staff(name, id)
{
    currentCustomer = nullptr;
    subject = nullptr;
    customerQueue = new ConcreteAggregate();
}

Cashiers::~Cashiers()
{
    if (subject)
    {
        delete subject;
    }
    if (customerQueue)
    {
        delete customerQueue;
    }
}

std::string Cashiers::getStaffType()
{
    return "Cashier";
}

bool Cashiers::canHandleEnquiry()
{
    return false;
}

void Cashiers::performDuty()
{
    if (currentCustomer != nullptr)
    {
        makeTransaction();
    }
    
    // Process the entire queue using iterator pattern
    processCustomerQueue();
}

void Cashiers::makeTransaction()
{
    if (currentCustomer != nullptr)
    {
        std::cout << "Cashier " << getName() << " is processing transaction for customer "
                  << currentCustomer->getId() << std::endl;
        emptyBasket();
    }
}

void Cashiers::emptyBasket()
{
    if (currentCustomer != nullptr)
    {
        std::cout << "Emptying basket for customer " << currentCustomer->getId() << std::endl;
        // Basket is emptied - customer can now leave
    }
}

void Cashiers::processCustomerQueue()
{
    if (customerQueue->isEmpty())
    {
        return;
    }

    std::cout << "\n=== Cashier Processing Queue with Iterator Pattern ===" << std::endl;
    std::cout << "Total customers in queue: " << customerQueue->getCount() << std::endl;

    // Create iterator for the customer queue
    Iterator* iterator = customerQueue->createIterator();
    
    // Collect customers with empty baskets to remove
    std::vector<Customer*> customersToRemove;

    // Iterate through all customers in the queue
    for (Customer* customer = iterator->first(); !iterator->isDone(); customer = iterator->next())
    {
        if (customer != nullptr)
        {
            std::cout << "Checking customer " << customer->getId() << "..." << std::endl;
            
            // Check if customer's basket is empty
            if (customer->isBasketEmpty())
            {
                std::cout << "  -> Customer " << customer->getId() 
                          << " has an empty basket. Marking for departure." << std::endl;
                customersToRemove.push_back(customer);
            }
            else
            {
                std::cout << "  -> Customer " << customer->getId() 
                          << " still has items in basket." << std::endl;
            }
        }
    }

    // Clean up iterator
    delete iterator;

    // Remove customers with empty baskets and make them leave
    for (Customer* customer : customersToRemove)
    {
        std::cout << "Removing customer " << customer->getId() 
                  << " from queue and asking them to leave nursery." << std::endl;
        customerQueue->removeCustomer(customer);
        
        // Make customer leave the nursery
        // Note: This assumes customer has a reference to nursery
        // The customer will handle their own departure through processNextAction
    }

    std::cout << "Queue processing complete. Remaining customers: " 
              << customerQueue->getCount() << std::endl;
    std::cout << "======================================================\n" << std::endl;
}

void Cashiers::addToQueue(Customer* customer)
{
    if (customer != nullptr)
    {
        customerQueue->addCustomer(customer);
        std::cout << "Customer " << customer->getId() 
                  << " added to cashier queue. Queue size: " 
                  << customerQueue->getCount() << std::endl;
    }
}
