#ifndef AUTCOMMAND_H
#define AUTCOMMAND_H

using namespace std;
#include <iostream>
#include "StateCommand.h"
#include "Inventory.h"

class AutumnCommand: public StateCommand{
private:
    Inventory* inventory;
public:
    virtual void execute() override;
    AutumnCommand(Inventory* inv);
    ~AutumnCommand();
};

#endif