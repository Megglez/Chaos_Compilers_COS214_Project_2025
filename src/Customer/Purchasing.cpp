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
    std::cout << "Customer is purchasing:" << std::endl;
    for (size_t i = 0; i < plantsToBuy.size(); i++)
    {
        std::cout << "  - " << quantities[i] << " of "
                  << (plantsToBuy[i] ? plantsToBuy[i]->getName() : "unknown plant") << std::endl;
    }
}

void Purchasing::handle(Customer *customer)
{
    if (!customer)
    {
        std::cerr << "Error: Null customer in Purchasing state." << std::endl;
        return;
    }

    std::cout << "Customer " << customer->getId() << " is ready to purchase:" << std::endl;
    for (size_t i = 0; i < plantsToBuy.size(); i++)
    {
        std::cout << "  - " << quantities[i] << " of "
                  << (plantsToBuy[i] ? plantsToBuy[i]->getName() : "unknown plant") << std::endl;
    }

    // Get the cashier from nursery and enqueue the customer
    Nursery *nursery = customer->getNursery();
    if (nursery)
    {
        Cashiers *cashier = nursery->getCashier();
        if (cashier)
        {
            std::cout << "Customer " << customer->getId() << " joining cashier queue..." << std::endl;
            cashier->enqueueCustomer(customer);
        }
        else
        {
            std::cerr << "Error: No cashier available in nursery." << std::endl;
        }
    }
    else
    {
        std::cerr << "Error: Customer has no nursery assigned." << std::endl;
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
    std::cout << "Customer needs assistance with purchase. Requesting staff help." << std::endl;
    desk.handleCustomer(customer);
}
