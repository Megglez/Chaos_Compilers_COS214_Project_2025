#ifndef WINTER_H
#define WINTER_H

#include <iostream>
using namespace std;
#include "Seasons.h"


class Winter : public Seasons{
public:
    virtual void handleChange() override;
    virtual std::string getSeason() override;
    Winter(Inventory* inv);
    ~Winter();
private:
    Inventory* inventory;

};

#endif