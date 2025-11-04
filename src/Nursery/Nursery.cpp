#include "Nursery.h"
#include "../Staff/Cashiers.h"
#include "../Greenhouse/AddStock.h"
#include "../Greenhouse/Autumn.h"
#include "../Greenhouse/Winter.h"
#include "../Greenhouse/Summer.h"
#include <QDebug>
#include <algorithm>
#include <memory>
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
    treeFactory = new TreePlanter();
    succulentFactory = new SucculentPlanter();
    currentSeason = new Spring(inventory);

    // Add diverse initial plants to stock for customers to browse
    // Flowers
    stock->Add(unique_ptr<Plant>(flowerFactory->planterMethod("Rose")), 20);
    stock->Add(unique_ptr<Plant>(flowerFactory->planterMethod("Tulip")), 15);
    stock->Add(unique_ptr<Plant>(flowerFactory->planterMethod("Lily")), 10);
    stock->Add(unique_ptr<Plant>(flowerFactory->planterMethod("Sunflower")), 12);
    stock->Add(unique_ptr<Plant>(flowerFactory->planterMethod("Daisy")), 18);

    // Herbs
    stock->Add(unique_ptr<Plant>(herbFactory->planterMethod("Basil")), 25);
    stock->Add(unique_ptr<Plant>(herbFactory->planterMethod("Mint")), 30);
    stock->Add(unique_ptr<Plant>(herbFactory->planterMethod("Rosemary")), 16);
    stock->Add(unique_ptr<Plant>(herbFactory->planterMethod("Thyme")), 14);
    stock->Add(unique_ptr<Plant>(herbFactory->planterMethod("Oregano")), 22);

    // Trees
    stock->Add(unique_ptr<Plant>(treeFactory->planterMethod("Oak")), 8);
    stock->Add(unique_ptr<Plant>(treeFactory->planterMethod("Maple")), 6);
    stock->Add(unique_ptr<Plant>(treeFactory->planterMethod("Pine")), 10);
    stock->Add(unique_ptr<Plant>(treeFactory->planterMethod("Apple")), 7);

    // Succulents
    stock->Add(unique_ptr<Plant>(succulentFactory->planterMethod("Aloe")), 24);
    stock->Add(unique_ptr<Plant>(succulentFactory->planterMethod("Cactus")), 28);
    stock->Add(unique_ptr<Plant>(succulentFactory->planterMethod("Jade")), 19);
    stock->Add(unique_ptr<Plant>(succulentFactory->planterMethod("Echeveria")), 13);

    qDebug() << "Initial stock added:" << stock->getStockListSize() << "plant types";

    // Initialize Staff Management
    infoDesk = new InfoDesk();

    // Initialize Cashier
    string cashierName = "John";
    string cashierId = "CASH001";
    cashier = new Cashiers(cashierName, cashierId);
    cashier->subject = inventory;
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
    delete cashier;
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
    delete treeFactory;
    delete succulentFactory;
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
    auto it = find(activeCustomers.begin(), activeCustomers.end(), customer);
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
    auto it = find(activeCustomers.begin(), activeCustomers.end(), customer);
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

void Nursery::handleChange()
{
}

// Note: If seasonal update functionality is needed, it should be declared in the header first
// The setState method in the header can be used for setting seasons