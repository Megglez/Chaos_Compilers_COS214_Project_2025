#ifndef WINCOMMAND_H
#define WINCOMMAND_H

using namespace std;
#include <iostream>
#include "StateCommand.h"
#include "Inventory.h"

class WinterCommand: public StateCommand{
private:
    Inventory* inventory;
public:
    virtual void execute() override;
    WinterCommand(Inventory* inv);
    ~WinterCommand();
};

#endif