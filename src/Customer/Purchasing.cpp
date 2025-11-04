/**
 * @file Purchasing.cpp
 * @brief Implementation of the Purchasing action class
 *
 * Implements purchasing behavior including cashier queue management,
 * checkout processing, and customer departure after purchase completion.
 */

#include "Purchasing.h"
#include "Customer.h"
#include "../Staff/InfoDesk.h"
#include "../Staff/Cashiers.h"
#include "../Nursery/Nursery.h"
#include <iostream>

void Purchasing::handle()
{
    // TODO: Implement actual purchasing logic
    cout << "Customer is purchasing:" << endl;
    for (size_t i = 0; i < plantsToBuy.size(); i++)
    {
        cout << "  - " << quantities[i] << " of "
                  << (plantsToBuy[i] ? plantsToBuy[i]->getName() : "unknown plant") << endl;
    }
}

void Purchasing::handle(Customer *customer)
{
    if (!customer)
    {
        cerr << "Error: Null customer in Purchasing state." << endl;
        return;
    }

    cout << "Customer " << customer->getId() << " is ready to purchase:" << endl;
    for (size_t i = 0; i < plantsToBuy.size(); i++)
    {
        cout << "  - " << quantities[i] << " of "
                  << (plantsToBuy[i] ? plantsToBuy[i]->getName() : "unknown plant") << endl;
    }

    // Get the cashier from nursery and enqueue the customer
    Nursery *nursery = customer->getNursery();
    if (nursery)
    {
        Cashiers *cashier = nursery->getCashier();
        if (cashier)
        {
            cout << "Customer " << customer->getId() << " joining cashier queue..." << endl;
            cashier->enqueueCustomer(customer);
        }
        else
        {
            cerr << "Error: No cashier available in nursery." << endl;
        }
    }
    else
    {
        cerr << "Error: Customer has no nursery assigned." << endl;
    }
}

Action *Purchasing::getNextAction()
{
    // After purchasing, the customer is done with their transaction
    // Return nullptr to indicate no further actions
    return nullptr;
}

void Purchasing::requestStaffAssistance(Customer *customer, InfoDesk &desk)
{
    cout << "Customer needs assistance with purchase. Requesting staff help." << endl;
    desk.handleCustomer(customer);
}
