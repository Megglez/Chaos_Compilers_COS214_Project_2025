#include "CustomerCreator.h"
#include <QDebug>
#include "Browse.h"
#include "Enquire.h"
#include <random>

Customer* CustomerCreator::createNewCustomer(QObject* parent, Stock* stock)
{
    Customer* newCustomer = new Customer(parent);
    qDebug() << "CustomerCreator: A new customer has been successfully spawned.";


    // Randomly assign action (Browse or Enquire)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> actionDist(0, 1);
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
        uniform_int_distribution<> plantDist(0, stock->getStockListSize() - 1);
        int plantIndex = plantDist(gen);
        Plant *chosenPlant = stock->getPlantByIndex(plantIndex);

        // Generate a random quantity between 1 and 10 for how many plants the customer wants
        uniform_int_distribution<> quantityDist(1, 10);
        int quantityWanted = quantityDist(gen);
    }

    return customer;
}