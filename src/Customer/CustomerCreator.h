#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include "Customer.h"

class CustomerCreator
{
public:
    CustomerCreator() = default;
    
    // Factory method to create a new Customer object
    // It takes a QObject parent (the Nursery) for proper memory cleanup
    Customer* createNewCustomer(QObject* parent, Stock* stock);
};

#endif