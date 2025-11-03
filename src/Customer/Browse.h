#ifndef BROWSE_H
#define BROWSE_H
#include "Action.h"
#include "../Greenhouse/Plant.h"
#include <vector>
#include <QObject>
#include <QTimer>
class Customer;
class InfoDesk;

class Browse : public QObject, public Action
{
    Q_OBJECT
private:
    std::vector<Plant *> plantsToBuy;
    std::vector<int> quantities;
    QTimer *browseTimer;
    Customer *currentCustomer;

public:
    Browse(Plant *plant, int quantity) : Action("Browsing"), QObject(nullptr), currentCustomer(nullptr)
    {
        if (plant)
        {
            plantsToBuy.push_back(plant);
            quantities.push_back(quantity);
        }
        browseTimer = new QTimer(this);
        connect(browseTimer, &QTimer::timeout, this, &Browse::onBrowseTimeout);
    }
    Browse(std::vector<Plant *> plants, std::vector<int> quants) : Action("Browsing"), QObject(nullptr), plantsToBuy(plants), quantities(quants), currentCustomer(nullptr)
    {
        browseTimer = new QTimer(this);
        connect(browseTimer, &QTimer::timeout, this, &Browse::onBrowseTimeout);
    }
    virtual ~Browse() {}

    void handle() override;
    void handle(Customer *customer) override;
    void startBrowsing(Customer *customer); // Start async browsing with timer
    Action *getNextAction() override;
    void requestStaffAssistance(Customer *customer, InfoDesk &desk) override;

    std::vector<Plant *> getPlantsToBuy() const { return plantsToBuy; }
    std::vector<int> getQuantities() const { return quantities; }

private slots:
    void onBrowseTimeout(); // Called when browse timer expires
};

#endif // BROWSE_H