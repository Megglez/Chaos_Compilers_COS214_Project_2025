#ifndef NURSERY_H
#define NURSERY_H

#include <QObject> // CRUCIAL: Must inherit from QObject for slots
#include <vector>
#include <iostream>
#include "./Customer/Customer.h"
#include "./Customer/CustomerCreator.h"
#include "../Staff/Staff.h"

class Nursery : public QObject // <-- INHERIT FROM QObject
{
Q_OBJECT // REQUIRED
private:
    std::vector<Customer*> activeCustomers; // List to hold created customers
    CustomerCreator customerFactory;        // The creator object
    vector<Staff*> staff;
    int customerCount;
    int customerLimit;

public:
    // Change constructor to take a QObject parent
    explicit Nursery(QObject *parent = nullptr); 
    virtual ~Nursery() override = default;

public slots:
    // This slot receives the signal from the CustomerClock
    void handleCustomerArrivalSignal(); 
};

#endif