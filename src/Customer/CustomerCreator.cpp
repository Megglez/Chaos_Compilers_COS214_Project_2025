#include "CustomerCreator.h"
#include <QDebug>
#include <random>

CustomerCreator::CustomerCreator()
{
}

CustomerCreator::~CustomerCreator() 
{
}

Customer* CustomerCreator::createNewCustomer(QObject* parent, Stock* stock)
{
    qDebug() << "CustomerCreator: A new customer is being created.";

    Plant* chosenPlant = nullptr;
    int quantityWanted = 0;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> actionDist(0, 1);
    
    if (stock && stock->getStockListSize() > 0)
    {
        uniform_int_distribution<> plantDist(0, stock->getStockListSize() - 1);
        int plantIndex = plantDist(gen);
        
        chosenPlant = stock->getPlantByIndex(plantIndex);
        
        uniform_int_distribution<> quantityDist(1, 10);
        quantityWanted = quantityDist(gen);
    }
    else {
        qDebug() << "Warning: Stock is empty. Customer will not target a specific plant/quantity.";
    }

    Customer* newCustomer = nullptr; 
    int actionType = actionDist(gen);

    if (actionType == 0)
    {
        newCustomer = new Customer(new Browse(chosenPlant, quantityWanted), parent); 
        qDebug() << "CustomerCreator: Created a Browsing Customer.";
    }
    else
    {
        newCustomer = new Customer(new Enquire(chosenPlant), parent); 
        qDebug() << "CustomerCreator: Created an Inquiring Customer.";
    }

    return newCustomer;
}