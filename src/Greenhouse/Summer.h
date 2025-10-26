#ifndef SUMMER_H
#define SUMMER_H

#include <iostream>
using namespace std;
#include "Seasons.h"

class Summer : public Seasons{
public:
    virtual void handleChange() override;
    virtual std::string getSeason() override;
    Summer(Inventory* inv);
    ~Summer();
private:
    Inventory* inventory;
};

#endif