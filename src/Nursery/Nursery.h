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

// Forward declaration
class AddStock;

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
    private :

    // Customer Management
    vector<Customer *>
        activeCustomers;              ///< Vector of currently active customers in the nursery
    CustomerCreator *customerFactory; ///< Factory for creating new customers
    int customerCount;                ///< Current number of active customers
    int customerLimit;                ///< Maximum allowed customers in nursery at once

    // Staff Management
    InfoDesk *infoDesk;    ///< InfoDesk managing staff and customer routing
    vector<Staff *> staff; ///< Vector of staff members
    Cashiers *cashier;     ///< Cashier for checkout operations

    // Plant Management
    Stock *stock;
    class AddStock *startPlants; ///< Command for adding initial plants
    Inventory *inventory;
    FlowerPlanter *flowerFactory;
    HerbPlanter *herbFactory;
    TreePlanter *treeFactory;
    SucculentPlanter *succulentFactory;
    Seasons *currentSeason;

public:
    explicit Nursery(QObject *parent = nullptr);

    /**
     * @brief Destroys the Nursery object
     *
     * Cleans up all dynamically allocated subsystems and resources.
     */
    ~Nursery(); // override;

    // Getters
    Stock *getStock() const { return stock; }
    Inventory *getInventory() const { return inventory; }
    InfoDesk *getInfoDesk() const { return infoDesk; }
    Cashiers *getCashier() const;

    /**
     * @brief Gets the current season
     * @return Pointer to the current Seasons object
     */
    Seasons *getCurrentSeason() const { return currentSeason; }

    // void setSeason(Seasons* newSeason);  // Commented out - not implemented
    // void setStock(std::unique_ptr<Plant> plant, int amount);  // Commented out - causes issues
    // Setter for season changes
    void setState(Seasons *newSeason)
    {
        if (currentSeason)
        {
            delete currentSeason;
        }
        currentSeason = newSeason;
    }

    void setStock(std::unique_ptr<Plant> plant, int amount);
    void setSeason(Seasons *newSeason);

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
    const std::vector<Customer *> &getActiveCustomers() const { return activeCustomers; }
    void handleChange();

public slots:
    // This slot receives the signal from the CustomerClock
    void handleCustomerArrivalSignal();
    // void updateSeason(Season newSeason);  // Commented out - Season enum not defined
};

#endif
