#ifndef BROWSE_H
#define BROWSE_H
#include "Action.h"
#include "../Greenhouse/Plant.h" 
class Customer; 
class InfoDesk; 

class Browse : public Action
{
private:
    Plant* plantToBuy;
    int quantity;

public:
    Browse(Plant* plant, int quantity) : Action("Browsing"), plantToBuy(plant), quantity(quantity) {}
    virtual ~Browse() {}
    
    void handle() override;
    Action* getNextAction() override;
    void requestStaffAssistance(Customer *customer, InfoDesk& desk) override;
};

#endif // BROWSE_H