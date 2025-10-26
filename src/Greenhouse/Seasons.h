#ifndef SEASONS_H
#define SEASONS_H

#include <iostream>
using namespace std;
#include "StateCommand.h"


class Seasons{
public:
    virtual void handleChange() = 0; // should take in facade as the context
    virtual std::string getSeason() = 0;
    Seasons();
    virtual ~Seasons();
protected:
    StateCommand* commands;
    

};

#endif