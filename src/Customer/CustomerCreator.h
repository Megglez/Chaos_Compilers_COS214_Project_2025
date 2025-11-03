#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include <iostream>
#include "Customer.h"
#include "./Nursery/ClockObserver.h"
#include "Browse.h"
#include "Enquire.h"
#include "../Greenhouse/Stock.h"
using namespace std;

class Nursery;

class CustomerCreator : public ClockObserver
{
public:
    CustomerCreator();
    ~CustomerCreator();
    // Factory method to create a new Customer object
    // It takes a QObject parent (the Nursery) for proper memory cleanup
    Customer *createNewCustomer(Nursery *nursery, Stock *stock);
};

#endif