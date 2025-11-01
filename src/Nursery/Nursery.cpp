#include "Nursery.h"
#include <QDebug>

Nursery::Nursery(QObject *parent) : QObject(parent) {
    qDebug() << "Nursery simulation core initialized.";
    // Initialize the stock with a new Inventory
    stock = new Stock(new Inventory());
}

Nursery::~Nursery() {
    // Clean up customers
    for (Customer* customer : activeCustomers) {
        delete customer;
    }
    activeCustomers.clear();
    
    // Clean up stock
    delete stock;
}

void Nursery::handleCustomerArrivalSignal() {
    // 1. Delegate the creation job to the CustomerCreator
    // Pass both the parent QObject and the stock system
    Customer* newCustomer = customerFactory.createNewCustomer(this, stock);
    
    // 2. Manage the newly created customer
    activeCustomers.push_back(newCustomer);

    qDebug() << "Nursery: Added new customer. Total active customers:" << activeCustomers.size();
    
    // This is where the Nursery would call methods to:
    // - Assign the customer to a staff member
    // - Display the customer in the GUI/simulation viewport
}