/**
 * @file CustomerCreator.cpp
 * @brief Implementation of the CustomerCreator factory class
 *
 * Implements customer creation with comprehensive randomization including:
 * - Initial state selection (Browse/Enquire)
 * - Plant selection with distinct type enforcement
 * - Question type selection (advice/information)
 * - Plant decoration application (GiftWrap/Pot/SpecialArrangement)
 */

#include "CustomerCreator.h"
#include <QDebug>
#include <random>
#include <map>
#include <string>
#include <algorithm>
#include "../Nursery/Nursery.h"
#include "../Greenhouse/GiftWrap.h"
#include "../Greenhouse/Pot.h"
#include "../Greenhouse/SpecialArrangement.h"

CustomerCreator::CustomerCreator()
{
}

CustomerCreator::~CustomerCreator()
{
}

Customer *CustomerCreator::createNewCustomer(Nursery* nursery, Stock* stock)
{
    qDebug() << "=== CustomerCreator: Creating new customer ===";
    qDebug() << "Stock pointer:" << stock;
    qDebug() << "Stock size:" << (stock ? stock->getStockListSize() : 0);

     vector<Plant*> chosenPlants;
     vector<int> quantitiesWanted;

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
        vector<string> selectedPlantNames;

        for (int i = 0; i < numPlants; i++)
        {
            Plant* chosenPlant = nullptr;
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
            } while (chosenPlant && find(selectedPlantNames.begin(), selectedPlantNames.end(), chosenPlant->getName()) != selectedPlantNames.end());

            // Skip if this is a duplicate plant name and we already have at least one plant
            if (chosenPlant && find(selectedPlantNames.begin(), selectedPlantNames.end(), chosenPlant->getName()) != selectedPlantNames.end() && !selectedPlantNames.empty())
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

    Customer* newCustomer = nullptr;
    int actionType = actionDist(gen);

    if (actionType == 0)
    {
        // Customer is browsing - check if they want plant decorations
        uniform_int_distribution<> decorationDist(0, 1);
        int wantsDecoration = decorationDist(gen);

        if (wantsDecoration == 1 && chosenPlants.size() > 0)
        {
            // Generate random decoration type (0-3)
            uniform_int_distribution<> decorationTypeDist(0, 2);
            int decorationType = decorationTypeDist(gen);

            // Apply decoration to the plants
            vector<Plant*> decoratedPlants;
            for (Plant* plant : chosenPlants)
            {
                Plant* decoratedPlant = plant;
                switch (decorationType)
                {
                case 0:
                    decoratedPlant = new GiftWrap(plant->clone());
                    qDebug() << "CustomerCreator: Customer wants GiftWrap decoration.";
                    break;
                case 1:
                    decoratedPlant = new Pot(plant->clone());
                    qDebug() << "CustomerCreator: Customer wants Pot decoration.";
                    break;
                case 2:
                    decoratedPlant = new SpecialArrangement(plant->clone());
                    qDebug() << "CustomerCreator: Customer wants SpecialArrangement decoration.";
                    break;
                }
                decoratedPlants.push_back(decoratedPlant);
            }

            newCustomer = new Customer(new Browse(decoratedPlants, quantitiesWanted), nursery, nursery);
            qDebug() << "CustomerCreator: Created a Browsing Customer with decorated plants.";
        }
        else if (chosenPlants.size() > 0)
        {
            // Clone the plants so we have our own copies
            vector<Plant*> clonedPlants;
            for (Plant* plant : chosenPlants)
            {
                if (plant)
                {
                    clonedPlants.push_back(plant->clone());
                    qDebug() << "CustomerCreator: Cloned plant" << plant->getName().c_str() << "for customer";
                }
            }
            qDebug() << "CustomerCreator: About to create Browse with" << clonedPlants.size() << "plants and" << quantitiesWanted.size() << "quantities";
            Browse* browseAction = new Browse(clonedPlants, quantitiesWanted);
            qDebug() << "CustomerCreator: Browse created, checking contents...";
            qDebug() << "CustomerCreator: Browse has" << browseAction->getPlantsToBuy().size() << "plants";
            newCustomer = new Customer(browseAction, nursery, nursery);
            qDebug() << "CustomerCreator: Created a Browsing Customer with" << clonedPlants.size() << "plants.";
        }
        else
        {
            newCustomer = new Customer(new Browse(nullptr, 0), nursery, nursery);
            qDebug() << "CustomerCreator: Created a Browsing Customer with no plants.";
        }
    }
    else
    {
        // Customer is enquiring - determine question type (0 = advice, 1 = information)
        uniform_int_distribution<> questionTypeDist(0, 1);
        int questionType = questionTypeDist(gen);
        string selectedQuestion;

        if (questionType == 0)
        {
            // Advice question - use the map with random selection
            map<int, string> adviceQuestions = {
                {0, "What summer flowers are available?"},
                {1, "What winter flowers do you have?"},
                {2, "What is the best time of day to water my plants?"},
                {3, "How many categories of plants do you sell?"}};

            // Generate random question key (0-3)
            uniform_int_distribution<> questionDist(0, 3);
            int questionKey = questionDist(gen);
            selectedQuestion = adviceQuestions[questionKey];

            if (chosenPlants.size() > 0)
            {
                newCustomer = new Customer(new Enquire(chosenPlants, selectedQuestion, 0), nursery, nursery);
                qDebug() << "CustomerCreator: Created an Inquiring Customer with advice question:" << selectedQuestion.c_str();
            }
            else
            {
                newCustomer = new Customer(new Enquire(nullptr, selectedQuestion, 0), nursery, nursery);
                qDebug() << "CustomerCreator: Created an Inquiring Customer with advice question (no plants).";
            }
        }
        else
        {
            // Information question - ask about inventory quantity of a specific plant
            if (stock && stock->getStockListSize() > 0)
            {
                // Generate random index between 0 and max index of stock vector
                uniform_int_distribution<> plantIndexDist(0, stock->getStockListSize() - 1);
                int plantIndex = plantIndexDist(gen);
                Plant* questionPlant = stock->getPlantByIndex(plantIndex);

                if (questionPlant)
                {
                    // Get the inventory to check quantity
                    int quantity = 0;
                    if (nursery)
                    {
                        Inventory* inventory = nursery->getInventory();
                        if (inventory)
                        {
                            auto &invMap = inventory->getInventory();
                            auto it = invMap.find(questionPlant->getName());
                            if (it != invMap.end())
                            {
                                quantity = it->second.second;
                            }
                        }
                    }

                    // Create the information question
                    selectedQuestion = "How many " + questionPlant->getName() + " do you have in stock?";

                    // Create customer with the plant they're asking about
                    vector<Plant*> enquiryPlants = {questionPlant};
                    newCustomer = new Customer(new Enquire(enquiryPlants, selectedQuestion, 1), nursery, nursery);
                    qDebug() << "CustomerCreator: Created an Inquiring Customer with information question:"
                             << selectedQuestion.c_str() << "(Answer:" << quantity << ")";
                }
                else
                {
                    // Fallback to advice question if plant not found
                    selectedQuestion = "What plants do you have available?";
                    newCustomer = new Customer(new Enquire(nullptr, selectedQuestion, 0), nursery, nursery);
                    qDebug() << "CustomerCreator: Created an Inquiring Customer with fallback question.";
                }
            }
            else
            {
                // Stock is empty, fallback to advice question
                selectedQuestion = "What plants do you have available?";
                newCustomer = new Customer(new Enquire(nullptr, selectedQuestion, 0), nursery, nursery);
                qDebug() << "CustomerCreator: Created an Inquiring Customer with fallback question (empty stock).";
            }
        }
    }

    return newCustomer;
}