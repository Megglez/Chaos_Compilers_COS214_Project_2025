#include "Nursery.h"
#include <QDebug>
#include "../Greenhouse/Spring.h"

Nursery::Nursery(QObject *parent) : QObject(parent)
{
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
    currentSeason = new Spring(inventory);
    
    // Initialize Staff Management
    infoDesk = new InfoDesk();
}

Nursery::~Nursery()
{
    // Clean up customers
    for (Customer *customer : activeCustomers)
    {
        delete customer;
    }
    activeCustomers.clear();
    delete customerFactory;

    // Clean up staff
    delete infoDesk;
    for (Staff *s : staff)
    {
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

void Nursery::handleCustomerArrivalSignal()
{
    if (customerCount >= customerLimit)
    {
        qDebug() << "Nursery is at capacity, cannot accept more customers.";
        return;
    }

    Customer *newCustomer = customerFactory->createNewCustomer(this, stock);
    if (newCustomer)
    {
        activeCustomers.push_back(newCustomer);
        customerCount++;
        qDebug() << "Nursery: Added new customer. Total active customers:" << activeCustomers.size();

        // Assign customer to InfoDesk for staff allocation
        infoDesk->handleCustomer(newCustomer);
    }
}

void Nursery::addCustomer(Customer *customer)
{
    if (customer && customerCount < customerLimit)
    {
        activeCustomers.push_back(customer);
        customerCount++;
    }
}

void Nursery::removeCustomer(Customer *customer)
{
    auto it = std::find(activeCustomers.begin(), activeCustomers.end(), customer);
    if (it != activeCustomers.end())
    {
        activeCustomers.erase(it);
        customerCount--;
    }
}

void Nursery::handleCustomerDeparture(Customer *customer)
{
    if (!customer)
    {
        qDebug() << "Warning: Attempted to remove null customer.";
        return;
    }

    qDebug() << "Customer" << customer->getId() << "is leaving the nursery.";

    // Remove from active customers list and update count
    auto it = std::find(activeCustomers.begin(), activeCustomers.end(), customer);
    if (it != activeCustomers.end())
    {
        activeCustomers.erase(it);
        customerCount--;
        qDebug() << "Customer" << customer->getId() << "removed. Total active customers:" << activeCustomers.size();

        // Free any assigned staff
        if (customer->getAssignedStaff())
        {
            // Staff becomes available again (implementation depends on your staff state system)
            qDebug() << "Freeing staff assigned to departing customer.";
        }

        // Delete the customer object and free memory
        delete customer;

        qDebug() << "Customer memory deallocated. Current customer count:" << customerCount;
    }
    else
    {
        qDebug() << "Warning: Customer" << customer->getId() << "not found in active customers list.";
    }
}