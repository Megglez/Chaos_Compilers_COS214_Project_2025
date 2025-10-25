#ifndef STATE_H
#define STATE_H

using namespace std;
#include <iostream>
#include "Inventory.h"

class StateCommand{

public:
    virtual void execute() = 0;
    StateCommand(){};
    ~StateCommand(){};
};

#endif