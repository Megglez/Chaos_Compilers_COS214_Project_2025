/**
 * @file Nursery.h
 * @brief Facade class that coordinates all nursery subsystems
 * 
 * The Nursery class acts as the main facade for the plant nursery simulation system.
 * It manages customers, staff, inventory, stock, and seasonal changes, providing a
 * unified interface for the entire nursery operation.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

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
#include "../Greenhouse/Spring.h"
#include "../Greenhouse/Winter.h"
#include "../Greenhouse/Autumn.h"
#include "../Greenhouse/FlowerPlanter.h"
#include "../Greenhouse/HerbPlanter.h"
#include "../Greenhouse/TreePlanter.h"
#include "../Greenhouse/SucculentPlanter.h"
#include "SeasonClock.h"
using namespace std;

/**
 * @class Nursery
 * @brief Main facade class for the plant nursery simulation system
 * 
 * This class implements the Facade pattern to provide a simplified interface
 * to the complex subsystems of the nursery including customer management,
 * staff coordination, inventory tracking, and seasonal plant stock management.
 * Inherits from QObject to support Qt's signal-slot mechanism for event handling.
 * 
 * @note Inherits from QObject for Qt signal-slot functionality
 */
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
    /**
     * @brief Constructs a new Nursery object
     * 
     * Initializes all subsystems including inventory, stock, info desk, and season.
     * Sets up the initial state with Spring season and populates stock with plants.
     * 
     * @param parent Optional parent QObject for Qt object hierarchy
     */
    explicit Nursery(QObject *parent = nullptr);
    
    /**
     * @brief Destroys the Nursery object
     * 
     * Cleans up all dynamically allocated subsystems and resources.
     */
    ~Nursery(); //override;

    // Getters
    
    /**
     * @brief Gets the stock management system
     * @return Pointer to the Stock object
     */
    Stock *getStock() const { return stock; }
    
    /**
     * @brief Gets the inventory catalogue system
     * @return Pointer to the Inventory object
     */
    Inventory *getInventory() const { return inventory; }
    
    /**
     * @brief Gets the info desk for staff management
     * @return Pointer to the InfoDesk object
     */
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
    // FlowerPlanter *getFlowerFactory() const { return flowerFactory; }
    // HerbPlanter *getHerbFactory() const { return herbFactory; }
    // TreePlanter *getTreeFactory() const { return treeFactory; }
    // SucculentPlanter *getSucculentFactory() const { return succulentFactory; }


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
    
    /**
     * @brief Removes a customer from the active customers list
     * 
     * @param customer Pointer to the customer to remove
     */
    void removeCustomer(Customer *customer);
    
    /**
     * @brief Handles a customer leaving the nursery
     * 
     * Removes customer from active list, updates count, and frees any assigned staff.
     * 
     * @param customer Pointer to the departing customer
     */
    void handleCustomerDeparture(Customer *customer);
    
    /**
     * @brief Gets the vector of active customers
     * @return Const reference to the active customers vector
     */
    const vector<Customer *> &getActiveCustomers() const { return activeCustomers; }

    void handleChange();

public slots:
    /**
     * @brief Slot that handles customer arrival signals
     * 
     * Creates a new random customer using the customer factory and adds them
     * to the nursery if capacity allows.
     */
    void handleCustomerArrivalSignal();
    
    /**
     * @brief Slot that handles season change signals
     * 
     * Updates the current season and adjusts plant stock accordingly.
     * 
     * @param newSeason The new season to transition to
     */
    void updateSeason(Season newSeason);
};

#endif
