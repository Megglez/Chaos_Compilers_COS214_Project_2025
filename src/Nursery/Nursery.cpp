#include "Nursery.h"
#include <QDebug>

Nursery::Nursery(QObject *parent) : QObject(parent) {
    qDebug() << "Nursery simulation core initialized.";
}

void Nursery::handleCustomerArrivalSignal() {
    // 1. Delegate the creation job to the CustomerCreator
    // The 'this' pointer is passed as the parent for the new Customer object
    Customer* newCustomer = customerFactory.createNewCustomer(this); 
    
    // 2. Manage the newly created customer
    activeCustomers.push_back(newCustomer);

    qDebug() << "Nursery: Added new customer. Total active customers:" << activeCustomers.size();
    
    // This is where the Nursery would call methods to:
    // - Assign the customer to a staff member
    // - Display the customer in the GUI/simulation viewport
}