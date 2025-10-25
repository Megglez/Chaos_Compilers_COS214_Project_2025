#ifndef SUMCOMMAND_H
#define SUMCOMMAND_H

using namespace std;
#include <iostream>
#include "StateCommand.h"
#include "Inventory.h"

class SummerCommand: public StateCommand{
private:
    Inventory* inventory;
public:
    virtual void execute() override;
    SummerCommand(Inventory* inv);
    ~SummerCommand();
};

#endif