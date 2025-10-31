#include "CustomerSpawner.h"
#include "Browse.h"
#include "Enquire.h"
#include <random>
#include "Stock.h"

Customer *CustomerSpawner::spawnCustomer(Stock *stock)
{
    Customer *customer = new Customer();

    // Randomly assign action (Browse or Enquire)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> actionDist(0, 1);
    int actionType = actionDist(gen);
    if (actionType == 0)
    {
        customer->setAction(new Browse());
    }
    else
    {
        customer->setAction(new Enquire());
    }

    // Assign a random plant from StockList (if available)
    if (stock && stock->getStockListSize() > 0)
    {
        std::uniform_int_distribution<> plantDist(0, stock->getStockListSize() - 1);
        int plantIndex = plantDist(gen);
        Plant *chosenPlant = stock->getPlantByIndex(plantIndex);

        // Generate a random quantity between 1 and 10 for how many plants the customer wants
        std::uniform_int_distribution<> quantityDist(1, 10);
        int quantityWanted = quantityDist(gen);

        // Here you can add logic to store the chosen plant and quantity in the customer,
        // or set a desired plant type and quantity, depending on your Customer class design.
        // For example:
        // customer->setDesiredPlant(chosenPlant);
        // customer->setDesiredQuantity(quantityWanted);
        // Or store the plant name/type and quantity in the customer for later use.
    }

    return customer;
}