#ifndef NURSERY_H
#define NURSERY_H

#include <QObject> // CRUCIAL: Must inherit from QObject for slots
#include <vector>
#include <iostream>
#include "../Customer/Customer.h"
#include "../Customer/CustomerCreator.h"
#include "../Staff/Staff.h"
#include "../Staff/InfoDesk.h"
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
    vector<Customer*> activeCustomers;
    CustomerCreator* customerFactory;
    int customerCount;
    int customerLimit;

    // Staff Management
    InfoDesk *infoDesk;
    vector<Staff*> staff;

    // Plant Management
    Stock *stock;
    Inventory *inventory;
    Seasons *currentSeason;
    AddStock* startPlants;

public:
    explicit Nursery(QObject *parent = nullptr);
    virtual ~Nursery() override;

    // Getters
    Stock *getStock() const { return stock; }
    Inventory *getInventory() const { return inventory; }
    InfoDesk *getInfoDesk() const { return infoDesk; }
    Seasons *getCurrentSeason() const { return currentSeason; }

    //Setters
    void setStock(unique_ptr<Plant>&& plant, int amount);

    // Plant Factory Access
    FlowerPlanter *getFlowerFactory() const { return flowerFactory; }
    HerbPlanter *getHerbFactory() const { return herbFactory; }
    TreePlanter *getTreeFactory() const { return treeFactory; }
    SucculentPlanter *getSucculentFactory() const { return succulentFactory; }


    // Customer Management
    void addCustomer(Customer *customer);
    void removeCustomer(Customer *customer);
    void handleCustomerDeparture(Customer *customer);
    const vector<Customer *> &getActiveCustomers() const { return activeCustomers; }

public slots:
    // This slot receives the signal from the CustomerClock
    void handleCustomerArrivalSignal();
    void updateSeason(Season newSeason);
};

#endif