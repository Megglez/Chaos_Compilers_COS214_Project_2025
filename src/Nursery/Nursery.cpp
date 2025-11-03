/**
 * @file Nursery.cpp
 * @brief Implementation of the Nursery facade class
 * 
 * Contains the implementation of all Nursery methods for managing
 * the complete nursery simulation system.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

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
    currentSeason = new Spring(inventory);
    
    // Initialize Staff Management
    infoDesk = new InfoDesk();
    startPlants = new AddStock(inventory);
}

void Nursery::setStock(unique_ptr<Plant> plant, int amount)
{
    startPlants->execute(move(plant), amount);
}

void Nursery::setSeason(Seasons* newSeason)
{
    if (currentSeason) {
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
    for (Staff *s : staff)
    {
        delete s;
    }
    staff.clear();

    // Clean up plant management
    delete stock;
    delete inventory;
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

void Nursery::handleChange(){
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

void Nursery::updateSeason(Season newSeason)
{
    qDebug() << "Nursery updating season state...";
    if (currentSeason) {
        delete currentSeason; // Delete the old season object
    }

    // Create the new season object.
    // The constructor for each Season (e.g., Spring(inventory))
    // automatically executes its command (e.g., SpringCommand)
    // and updates the inventory.
    switch (newSeason)
    {
        case SPRING:
            currentSeason = new Spring(inventory);
            break;
        case SUMMER:
            currentSeason = new Summer(inventory);
            break;
        case AUTUMN:
            currentSeason = new Autumn(inventory);
            break;
        case WINTER:
            currentSeason = new Winter(inventory);
            break;
    }
    
    qDebug() << "Nursery season changed to:" << currentSeason->getSeason().c_str();
}
