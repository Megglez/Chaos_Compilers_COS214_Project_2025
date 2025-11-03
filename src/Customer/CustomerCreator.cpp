#include "CustomerCreator.h"
#include <QDebug>
#include <random>
#include <map>
#include <string>
#include <algorithm>
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

    std::vector<Plant *> chosenPlants;
    std::vector<int> quantitiesWanted;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> actionDist(0, 1);

    if (stock && stock->getStockListSize() > 0)
    {
        // Random integer between 0 and 1 to determine if customer wants 1 or 2 plants
        uniform_int_distribution<> numTypesDist(0, 1);
        int numPlants = numTypesDist(gen) + 1; // Results in 1 or 2

        // Random index between 0 and last index of stock vector for plant selection
        uniform_int_distribution<> plantIndexDist(0, stock->getStockListSize() - 1);
        uniform_int_distribution<> quantityDist(1, 10);

        // Keep track of already selected plant names to ensure distinct plant types
        std::vector<std::string> selectedPlantNames;

        for (int i = 0; i < numPlants; i++)
        {
            Plant *chosenPlant = nullptr;
            int attempts = 0;
            const int maxAttempts = 50; // Prevent infinite loop

            // Generate random index and get the plant
            // Ensure the plant name is different from already selected plants
            do
            {
                int plantIndex = plantIndexDist(gen);
                chosenPlant = stock->getPlantByIndex(plantIndex);
                attempts++;

                // If only 1 plant available in stock, or too many attempts, accept whatever we get
                if (attempts >= maxAttempts || stock->getStockListSize() == 1)
                {
                    break;
                }
            } while (chosenPlant && std::find(selectedPlantNames.begin(), selectedPlantNames.end(), chosenPlant->getName()) != selectedPlantNames.end());

            // Skip if this is a duplicate plant name and we already have at least one plant
            if (chosenPlant && std::find(selectedPlantNames.begin(), selectedPlantNames.end(), chosenPlant->getName()) != selectedPlantNames.end() && !selectedPlantNames.empty())
            {
                continue;
            }

            if (chosenPlant)
            {
                selectedPlantNames.push_back(chosenPlant->getName());
                int quantityWanted = quantityDist(gen);

                chosenPlants.push_back(chosenPlant);
                quantitiesWanted.push_back(quantityWanted);

                qDebug() << "CustomerCreator: Customer wants" << quantityWanted << "of" << chosenPlant->getName().c_str();
            }
        }

        qDebug() << "CustomerCreator: Customer wants" << chosenPlants.size() << "plant(s).";
    }
    else
    {
        qDebug() << "Warning: Stock is empty. Customer will not target a specific plant/quantity.";
    }

    Customer *newCustomer = nullptr;
    int actionType = actionDist(gen);

    if (actionType == 0)
    {
        if (chosenPlants.size() > 0)
        {
            newCustomer = new Customer(new Browse(chosenPlants, quantitiesWanted), nursery, nursery);
            qDebug() << "CustomerCreator: Created a Browsing Customer.";
        }
        else
        {
            newCustomer = new Customer(new Browse(nullptr, 0), nursery, nursery);
            qDebug() << "CustomerCreator: Created a Browsing Customer with no plants.";
        }
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

        if (chosenPlants.size() > 0)
        {
            newCustomer = new Customer(new Enquire(chosenPlants, selectedQuestion), nursery, nursery);
            qDebug() << "CustomerCreator: Created an Inquiring Customer with question:" << selectedQuestion.c_str();
        }
        else
        {
            newCustomer = new Customer(new Enquire(nullptr, selectedQuestion), nursery, nursery);
            qDebug() << "CustomerCreator: Created an Inquiring Customer with no plants.";
        }
    }

    return newCustomer;
}