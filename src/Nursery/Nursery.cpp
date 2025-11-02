#include "Nursery.h"
#include <QDebug>

Nursery::Nursery(QObject *parent) : QObject(parent) {
    qDebug() << "Nursery simulation core initialized.";
    
    // Initialize Customer Management
    customerFactory = new CustomerCreator();
    customerCount = 0;
    customerLimit = 20; // Can be adjusted as needed
    
    // Initialize Plant Management
    inventory = new Inventory();
    stock = new Stock(inventory);
    flowerFactory = new FlowerPlanter();
    herbFactory = new HerbPlanter();
    currentSeason = new Summer(inventory);  // Start with Summer season
    
    // Initialize Staff Management
    infoDesk = new InfoDesk();
}

Nursery::~Nursery() {
    // Clean up customers
    for (Customer* customer : activeCustomers) {
        delete customer;
    }
    activeCustomers.clear();
    delete customerFactory;
    
    // Clean up staff
    delete infoDesk;
    for (Staff* s : staff) {
        delete s;
    }
    staff.clear();
    
    // Clean up plant management
    delete stock;
    delete inventory;
    delete flowerFactory;
    delete herbFactory;
    delete currentSeason;
}

void Nursery::handleCustomerArrivalSignal() {
    if (customerCount >= customerLimit) {
        qDebug() << "Nursery is at capacity, cannot accept more customers.";
        return;
    }

    Customer* newCustomer = customerFactory->createNewCustomer(this, stock);
    if (newCustomer) {
        activeCustomers.push_back(newCustomer);
        customerCount++;
        qDebug() << "Nursery: Added new customer. Total active customers:" << activeCustomers.size();
        
        // Assign customer to InfoDesk for staff allocation
        infoDesk->handleCustomer(newCustomer);
    }
}

void Nursery::addCustomer(Customer* customer) {
    if (customer && customerCount < customerLimit) {
        activeCustomers.push_back(customer);
        customerCount++;
    }
}

void Nursery::removeCustomer(Customer* customer) {
    auto it = std::find(activeCustomers.begin(), activeCustomers.end(), customer);
    if (it != activeCustomers.end()) {
        activeCustomers.erase(it);
        customerCount--;
    }
}