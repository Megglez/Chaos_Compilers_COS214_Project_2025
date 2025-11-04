#include "Cashiers.h"
#include "../Customer/Customer.h"
#include <iostream>

Cashiers::Cashiers(string &name, string &id) : Staff(name, id)
{
    currentCustomer = nullptr;
    subject = nullptr;
    isProcessing = false;
}

Cashiers::~Cashiers()
{
    // Don't delete subject as it's managed elsewhere
    // Customers in queue are managed by Nursery
}

string Cashiers::getStaffType()
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
        cout << "Customer " << customer->getId() << " added to cashier queue. Queue size: "
                  << customerQueue.size() << endl;

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
    cout << "Customer " << customer->getId() << " dequeued from cashier. Remaining in queue: "
              << customerQueue.size() << endl;
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
        cout << "Cashier " << getName() << " is now processing Customer "
                  << currentCustomer->getId() << endl;
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
        cout << "Processing transaction for Customer " << currentCustomer->getId() << endl;
        emptyBasket(currentCustomer);

        // Transaction complete - customer leaves
        cout << "Transaction complete for Customer " << currentCustomer->getId() << endl;
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

    cout << "Emptying basket for Customer " << customer->getId() << endl;
    customer->clearBasket();
    cout << "Customer " << customer->getId() << " has completed their purchase." << endl;
}