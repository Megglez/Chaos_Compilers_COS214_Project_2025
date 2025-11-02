#include "CustomerCreator.h"
#include <QDebug>
#include <random>
#include <map>
#include <string>
#include "../Nursery/Nursery.h"

CustomerCreator::CustomerCreator()
{
}

CustomerCreator::~CustomerCreator()
{
}

Customer *CustomerCreator::createNewCustomer(Nursery *nursery, Stock *stock)
{
    qDebug() << "CustomerCreator: A new customer is being created.";

    Plant *chosenPlant = nullptr;
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
    else
    {
        qDebug() << "Warning: Stock is empty. Customer will not target a specific plant/quantity.";
    }

    Customer *newCustomer = nullptr;
    int actionType = actionDist(gen);

    if (actionType == 0)
    {
        newCustomer = new Customer(new Browse(chosenPlant, quantityWanted), nursery, nursery);
        qDebug() << "CustomerCreator: Created a Browsing Customer.";
    }
    else
    {
        // Create map of enquiry questions
        std::map<int, std::string> enquiryQuestions = {
            {0, "What summer plants are available?"},
            {1, "What winter plants do you have?"},
            {2, "What is the best time of day to water my plants?"},
            {3, "How many categories of plants do you sell?"}};

        // Generate random question key (0-3)
        uniform_int_distribution<> questionDist(0, 3);
        int questionKey = questionDist(gen);
        std::string selectedQuestion = enquiryQuestions[questionKey];

        newCustomer = new Customer(new Enquire(chosenPlant, selectedQuestion), nursery, nursery);
        qDebug() << "CustomerCreator: Created an Inquiring Customer with question:" << selectedQuestion.c_str();
    }

    return newCustomer;
}