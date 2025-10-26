#ifndef SPRING_H
#define SPRING_H

#include <iostream>
using namespace std;
#include "Seasons.h"

class Spring : public Seasons{
    virtual void handleChange() override;
    virtual std::string getSeason() override;
    Spring(Inventory* inv);
    ~Spring();
private:
    Inventory* inventory;
};

#endif