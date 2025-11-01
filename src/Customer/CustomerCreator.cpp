#include "CustomerCreator.h"
#include <QDebug>
#include <random>

CustomerCreator::CustomerCreator()
{
}

Customer* CustomerCreator::createNewCustomer(QObject* parent, Stock* stock)
{
    qDebug() << "CustomerCreator: A new customer has been successfully created.";


    // Randomly assign action (Browse or Enquire)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> actionDist(0, 1);
    int actionType = actionDist(gen);

    if (stock && stock->getStockListSize() > 0)
    {
        uniform_int_distribution<> plantDist(0, stock->getStockListSize() - 1);
        int plantIndex = plantDist(gen);
        Plant* chosenPlant = stock->getPlantByIndex(plantIndex);

        // Generate a random quantity between 1 and 10 for how many plants the customer wants
        uniform_int_distribution<> quantityDist(1, 10);
        int quantityWanted = quantityDist(gen);
    }
    else {
        Plant* chosenPlant = null;
        int quantityWanted = 0;
    }

    if (actionType == 0)
    {
        Customer* newCustomer = new Customer(new Browse(Plant* chosenPlant, int quantityWanted));
    }
    else
    {
        Customer* newCustomer = new Customer(new Enquire(Plant* chosenPlant));
    }

    return newCustomer;
}