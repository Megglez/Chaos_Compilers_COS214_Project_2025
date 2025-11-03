#include "Browse.h"
#include "Purchasing.h" // Needed for getNextAction()
#include "Customer.h"   // Need full Customer definition
#include "Enquire.h"    // Need Enquire definition for new Enquire()
#include "../Staff/InfoDesk.h"

#include <QRandomGenerator>
#include "../Nursery/Nursery.h"

void Browse::handle()
{
    std::cout << "Customer is browsing. They are considering buying:" << std::endl;
    for (size_t i = 0; i < plantsToBuy.size(); i++)
    {
        std::cout << "  - " << quantities[i] << " of "
                  << (plantsToBuy[i] ? plantsToBuy[i]->getName() : "a generic plant") << std::endl;
    }
}

void Browse::handle(Customer *customer)
{
    // Use async version
    startBrowsing(customer);
}

void Browse::startBrowsing(Customer *customer)
{
    if (!customer)
    {
        std::cerr << "Error: Browse::startBrowsing() received null customer pointer." << std::endl;
        return;
    }

    currentCustomer = customer;

    std::cout << "Customer is browsing. They are considering buying:" << std::endl;
    for (size_t i = 0; i < plantsToBuy.size(); i++)
    {
        std::cout << "  - " << quantities[i] << " of "
                  << (plantsToBuy[i] ? plantsToBuy[i]->getName() : "a generic plant") << std::endl;
    }

    // Generate random time between 5 and 10 seconds (in milliseconds)
    int sleepTime = QRandomGenerator::global()->bounded(6) + 5; // 5 to 10 seconds
    std::cout << "Customer will browse for " << sleepTime << " seconds..." << std::endl;

    // Start timer (convert seconds to milliseconds)
    browseTimer->start(sleepTime * 1000);
}

void Browse::onBrowseTimeout()
{
    std::cout << "Browse time completed. Customer deciding next action..." << std::endl;

    // Decide next state: 0 = Enquire, 1 = Purchasing
    int nextState = QRandomGenerator::global()->bounded(2);

    if (!currentCustomer)
    {
        std::cerr << "Error: Browse timeout but no customer reference stored." << std::endl;
        return;
    }

    if (nextState == 0)
    {
        // Go to infodesk (enquire)
        std::cout << "Customer decided to enquire. Going to infodesk." << std::endl;
        if (currentCustomer->getAction())
            delete currentCustomer->getAction();
        currentCustomer->setAction(new Enquire(plantsToBuy));
        // You may want to call requestStaffAssistance here if InfoDesk is available
    }
    else
    {
        // Try to purchase all plants in the list
        std::cout << "Customer decided to purchase." << std::endl;
        Nursery *nursery = currentCustomer->getNursery();
        if (!nursery)
        {
            std::cerr << "Error: No nursery assigned to customer." << std::endl;
            return;
        }
        Inventory *inventory = nursery->getInventory();
        if (!inventory)
        {
            std::cerr << "Error: No inventory available." << std::endl;
            return;
        }
        auto &invMap = inventory->getInventory();

        // Process each plant type the customer wants
        std::vector<Plant *> plantsToPurchase;
        std::vector<int> quantitiesToPurchase;

        for (size_t i = 0; i < plantsToBuy.size(); i++)
        {
            Plant *plant = plantsToBuy[i];
            int quantity = quantities[i];

            if (!plant)
                continue;

            std::string plantName = plant->getName();
            auto it = invMap.find(plantName);
            int available = 0;
            if (it != invMap.end())
            {
                available = it->second.second;
            }
            int toTake = std::min(quantity, available);

            if (toTake > 0)
            {
                // Add to basket
                for (int j = 0; j < toTake; ++j)
                {
                    currentCustomer->addToBasket(plant, 1);
                }
                // Update inventory
                it->second.second -= toTake;
                std::cout << "Customer added " << toTake << " of " << plantName
                          << " to basket. Inventory now: " << it->second.second << std::endl;

                plantsToPurchase.push_back(plant);
                quantitiesToPurchase.push_back(toTake);
            }
            else
            {
                std::cout << "No stock available for " << plantName << ". Customer cannot add to basket." << std::endl;
            }
            // If customer wanted more than available, take max and set inventory to zero
            if (quantity > available && it != invMap.end())
            {
                it->second.second = 0;
                std::cout << "Customer wanted more " << plantName << " than available. Inventory set to zero." << std::endl;
            }
        }

        // Change state to purchasing with all plants
        if (currentCustomer->getAction())
            delete currentCustomer->getAction();
        currentCustomer->setAction(new Purchasing(plantsToPurchase, quantitiesToPurchase));
    }
}

Action *Browse::getNextAction()
{
    // FIX: Correctly instantiate a pointer to the next state, e.g., Purchasing.
    // Assuming Purchasing uses the same constructor parameters.
    return new Purchasing(plantsToBuy, quantities);
}

void Browse::requestStaffAssistance(Customer *customer, InfoDesk &desk)
{
    // Browsing customer decides to Enquire. Transition to the Enquire state.
    desk.getInfodesk();
    std::cout << "Customer wants to Enquire while browsing. Transitioning to Enquire state." << std::endl;
    customer->setAction(new Enquire(plantsToBuy));
}