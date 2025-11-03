#ifndef PURCHASING_H
#define PURCHASING_H

#include "Action.h"
#include "../Greenhouse/Plant.h"

class Customer;
class InfoDesk;

class Purchasing : public Action
{
private:
    Plant* plantToBuy;
    int quantity;
    
public:
    // This constructor matches the usage in Browse::getNextAction()
    Purchasing(Plant* plant, int quantity) : Action("Purchasing"), plantToBuy(plant), quantity(quantity) {}
    virtual ~Purchasing() {}
    
    void handle() override;
    Action* getNextAction() override; // Should return a completed state or back to browsing/leaving
    void requestStaffAssistance(Customer *customer, InfoDesk& desk) override; // Assistance to pay
};
#endif