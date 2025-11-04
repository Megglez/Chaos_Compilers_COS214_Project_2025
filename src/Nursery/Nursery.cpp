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
    stock->Add(std::unique_ptr<Plant>(flowerFactory->planterMethod("Rose")), 20);
    stock->Add(std::unique_ptr<Plant>(flowerFactory->planterMethod("Tulip")), 15);
    stock->Add(std::unique_ptr<Plant>(flowerFactory->planterMethod("Lily")), 10);
    stock->Add(std::unique_ptr<Plant>(flowerFactory->planterMethod("Sunflower")), 12);
    stock->Add(std::unique_ptr<Plant>(flowerFactory->planterMethod("Daisy")), 18);

    // Herbs
    stock->Add(std::unique_ptr<Plant>(herbFactory->planterMethod("Basil")), 25);
    stock->Add(std::unique_ptr<Plant>(herbFactory->planterMethod("Mint")), 30);
    stock->Add(std::unique_ptr<Plant>(herbFactory->planterMethod("Rosemary")), 16);
    stock->Add(std::unique_ptr<Plant>(herbFactory->planterMethod("Thyme")), 14);
    stock->Add(std::unique_ptr<Plant>(herbFactory->planterMethod("Oregano")), 22);

    // Trees
    stock->Add(std::unique_ptr<Plant>(treeFactory->planterMethod("Oak")), 8);
    stock->Add(std::unique_ptr<Plant>(treeFactory->planterMethod("Maple")), 6);
    stock->Add(std::unique_ptr<Plant>(treeFactory->planterMethod("Pine")), 10);
    stock->Add(std::unique_ptr<Plant>(treeFactory->planterMethod("Apple")), 7);

    // Succulents
    stock->Add(std::unique_ptr<Plant>(succulentFactory->planterMethod("Aloe")), 24);
    stock->Add(std::unique_ptr<Plant>(succulentFactory->planterMethod("Cactus")), 28);
    stock->Add(std::unique_ptr<Plant>(succulentFactory->planterMethod("Jade")), 19);
    stock->Add(std::unique_ptr<Plant>(succulentFactory->planterMethod("Echeveria")), 13);

    qDebug() << "Initial stock added:" << stock->getStockListSize() << "plant types";

    // Initialize Staff Management
    infoDesk = new InfoDesk();
    cashier = nullptr; // Initialize to nullptr - will be created when needed
    startPlants = new AddStock(inventory);
}

void Nursery::setStock(unique_ptr<Plant> plant, int amount)
{
    startPlants->execute(move(plant), amount);
}

void Nursery::setSeason(Seasons *newSeason)
{
    if (currentSeason)
    {
        delete currentSeason;
    }
    currentSeason = newSeason;
    qDebug() << "Season changed to:" << currentSeason->getSeason().c_str();
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

void Nursery::handleChange()
{
    currentSeason->handleChange(this);
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

// Note: If seasonal update functionality is needed, it should be declared in the header first
// The setState method in the header can be used for setting seasons

Cashiers *Nursery::getCashier() const
{
    if (infoDesk)
    {
        std::vector<Staff *> cashiers = infoDesk->getStaffByType("Cashier");
        if (!cashiers.empty())
        {
            return dynamic_cast<Cashiers *>(cashiers[0]);
        }
    }
    return nullptr;
}