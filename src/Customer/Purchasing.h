#ifndef PURCHASING_H
#define PURCHASING_H

#include "Action.h"
#include "../Greenhouse/Plant.h"
#include <vector>

class Customer;
class InfoDesk;

class Purchasing : public Action
{
private:
    std::vector<Plant *> plantsToBuy;
    std::vector<int> quantities;

public:
    // This constructor matches the usage in Browse::getNextAction()
    Purchasing(Plant *plant, int quantity) : Action("Purchasing")
    {
        if (plant)
        {
            plantsToBuy.push_back(plant);
            quantities.push_back(quantity);
        }
    }
    Purchasing(std::vector<Plant *> plants, std::vector<int> quants) : Action("Purchasing"), plantsToBuy(plants), quantities(quants) {}
    virtual ~Purchasing() {}

    void handle() override;
    void handle(Customer *customer) override;
    Action *getNextAction() override; // Should return a completed state or back to browsing/leaving
    void requestStaffAssistance(Customer *customer, InfoDesk &desk) override;
};
#endif