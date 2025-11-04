#ifndef NURSERY_H
#define NURSERY_H

#include <QObject> // CRUCIAL: Must inherit from QObject for slots
#include <vector>
#include <iostream>
#include "../Customer/Customer.h"
#include "../Customer/CustomerCreator.h"
#include "../Staff/Staff.h"
#include "../Staff/InfoDesk.h"
#include "../Staff/Cashiers.h"
#include "../Greenhouse/Stock.h"
#include "../Greenhouse/Inventory.h"
#include "../Greenhouse/Seasons.h"
#include "../Greenhouse/Summer.h"
#include "../Greenhouse/FlowerPlanter.h"
#include "../Greenhouse/HerbPlanter.h"
#include "../Greenhouse/TreePlanter.h"
#include "../Greenhouse/SucculentPlanter.h"
#include "SeasonClock.h"
using namespace std;

class Nursery : public QObject // <-- INHERIT FROM QObject
{
    Q_OBJECT // REQUIRED
private:

    // Customer Management
    vector<Customer*> activeCustomers;  ///< Vector of currently active customers in the nursery
    CustomerCreator* customerFactory;   ///< Factory for creating new customers
    int customerCount;                  ///< Current number of active customers
    int customerLimit;                  ///< Maximum allowed customers in nursery at once

    // Staff Management
    InfoDesk *infoDesk;                 ///< InfoDesk managing staff and customer routing
    vector<Staff*> staff;               ///< Vector of staff members

    // Plant Management
    Stock *stock;                       ///< Stock system managing plant inventory
    Inventory *inventory;               ///< Inventory catalogue of available plants
    Seasons *currentSeason;             ///< Current season affecting plant availability
    AddStock* startPlants;              ///< Command for adding initial plant stock

public:
    explicit Nursery(QObject *parent = nullptr);
    
    /**
     * @brief Destroys the Nursery object
     * 
     * Cleans up all dynamically allocated subsystems and resources.
     */
    ~Nursery(); //override;

    // Getters
    Stock *getStock() const { return stock; }
    Inventory *getInventory() const { return inventory; }
    InfoDesk *getInfoDesk() const { return infoDesk; }
    
    /**
     * @brief Gets the current season
     * @return Pointer to the current Seasons object
     */
    Seasons *getCurrentSeason() const { return currentSeason; }

    //Setters
    
    /**
     * @brief Adds a plant to the nursery stock
     * 
     * @param plant Unique pointer to the plant to add
     * @param amount Quantity of plants to add
     */
    void setStock(unique_ptr<Plant> plant, int amount);
    
    /**
     * @brief Changes the current season and adjusts stock accordingly
     * 
     * @param newSeason Pointer to the new season to set
     */
    void setSeason(Seasons* newSeason);

    // Plant Factory Access
    FlowerPlanter *getFlowerFactory() const { return flowerFactory; }
    HerbPlanter *getHerbFactory() const { return herbFactory; }

    // Customer Management
    
    /**
     * @brief Adds a new customer to the active customers list
     * 
     * Checks capacity limits before adding. If capacity allows, adds customer
     * and requests staff assistance from the info desk.
     * 
     * @param customer Pointer to the customer to add
     */
    void addCustomer(Customer *customer);
    void removeCustomer(Customer *customer);
    void handleCustomerDeparture(Customer *customer);
    
    /**
     * @brief Gets the vector of active customers
     * @return Const reference to the active customers vector
     */
    const vector<Customer *> &getActiveCustomers() const { return activeCustomers; }

    void handleChange();

public slots:
    // This slot receives the signal from the CustomerClock
    void handleCustomerArrivalSignal();
};

#endif
