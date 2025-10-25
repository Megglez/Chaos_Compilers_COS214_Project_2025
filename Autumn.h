#ifndef AUTUMN_H
#define AUTUMN_H

#include <iostream>
using namespace std;
#include "Seasons.h"

class Autumn : public Seasons{
public:
    virtual void handleChange() override;
    virtual std::string getSeason() override;
    Autumn(Inventory* inv);
    ~Autumn();
private:
    Inventory* inventory;
};

#endif