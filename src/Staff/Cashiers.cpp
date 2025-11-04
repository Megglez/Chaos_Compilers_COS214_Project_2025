#include "Cashiers.h"
#include "../Customer/Customer.h"
#include <iostream>

Cashiers::Cashiers(std::string &name, std::string &id, InfoDesk *infodesk) : Staff(name, id, infodesk)
{
    currentCustomer = nullptr;
    subject = nullptr;
    isProcessing = false;
    setRole();
}

Cashiers::~Cashiers()
{
    // Don't delete subject as it's managed elsewhere
    // Customers in queue are managed by Nursery
}

std::string Cashiers::getStaffType()
{
    return "Cashier";
}

bool Cashiers::canHandleEnquiry()
{
    return false;
}

void Cashiers::enqueueCustomer(Customer *customer)
{
    if (customer)
    {
        customerQueue.push(customer);
        std::cout << "Customer " << customer->getId() << " added to cashier queue. Queue size: "
                  << customerQueue.size() << std::endl;

        // If cashier is not currently processing, start processing
        if (!isProcessing)
        {
            processNextCustomer();
        }
    }
}

Customer *Cashiers::dequeueCustomer()
{
    if (customerQueue.empty())
    {
        return nullptr;
    }

    Customer *customer = customerQueue.front();
    customerQueue.pop();
    std::cout << "Customer " << customer->getId() << " dequeued from cashier. Remaining in queue: "
              << customerQueue.size() << std::endl;
    return customer;
}

bool Cashiers::hasCustomersInQueue() const
{
    return !customerQueue.empty();
}

int Cashiers::getQueueSize() const
{
    return customerQueue.size();
}

void Cashiers::processNextCustomer()
{
    if (isProcessing || customerQueue.empty())
    {
        return;
    }

    // Dequeue the next customer
    currentCustomer = dequeueCustomer();
    if (currentCustomer)
    {
        isProcessing = true;
        std::cout << "Cashier " << getName() << " is now processing Customer "
                  << currentCustomer->getId() << std::endl;
        makeTransaction();
    }
}

void Cashiers::performDuty()
{
    // Check if we need to process the next customer
    if (!isProcessing && hasCustomersInQueue())
    {
        processNextCustomer();
    }
}

void Cashiers::makeTransaction()
{
    if (currentCustomer != nullptr)
    {
        std::cout << "Processing transaction for Customer " << currentCustomer->getId() << std::endl;
        emptyBasket(currentCustomer);

        // Transaction complete - customer leaves
        std::cout << "Transaction complete for Customer " << currentCustomer->getId() << std::endl;
        currentCustomer->processNextAction(); // This will trigger customer departure

        currentCustomer = nullptr;
        isProcessing = false;

        // Process next customer if any
        if (hasCustomersInQueue())
        {
            processNextCustomer();
        }
    }
}

void Cashiers::emptyBasket(Customer *customer)
{
    if (!customer)
    {
        return;
    }

    std::cout << "Emptying basket for Customer " << customer->getId() << std::endl;
    customer->clearBasket();
    std::cout << "Customer " << customer->getId() << " has completed their purchase." << std::endl;
}

void Cashiers::setRole()
{
    role = "Cashier";
}