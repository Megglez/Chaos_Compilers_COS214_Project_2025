#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include <iostream>
#include "Customer.h"
#include "./Greenhouse/Stock.h"
using namespace std;


class CustomerCreator
{
public:
    CustomerCreator() = default;
    
    // Factory method to create a new Customer object
    // It takes a QObject parent (the Nursery) for proper memory cleanup
    Customer* createNewCustomer(QObject* parent, Stock* stock);
};

#endif