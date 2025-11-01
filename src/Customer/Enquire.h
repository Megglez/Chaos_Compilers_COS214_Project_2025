#ifndef ENQUIRE_H
#define ENQUIRE_H

#include "Action.h"
#include "../Greenhouse/Plant.h"

class Customer;
class InfoDesk;

class Enquire : public Action
{
private:
    Plant* plantOfInterest;

public:
    Enquire(Plant* plant) : Action("Enquiring"), plantOfInterest(plant) {}
    virtual ~Enquire() {}
    
    void handle() override;
    Action* getNextAction() override;
    void requestStaffAssistance(Customer *customer, InfoDesk& desk) override;
};
#endif