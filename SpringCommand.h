#ifndef SPRCOMMAND_H
#define SPRCOMMAND_H

using namespace std;
#include <iostream>
#include "StateCommand.h"
#include "Inventory.h"

class SpringCommand: public StateCommand{
private:
    Inventory* inventory;
public:
    virtual void execute() override;
    SpringCommand(Inventory* inv);
    ~SpringCommand();
};

#endif