#include "Customer.h"
#include <QDebug>
#include "../Staff/Staff.h"
#include "../Nursery/Nursery.h"

Customer::Customer(Action *action, Nursery *nursery, QObject *parent) : QObject(parent)
{
    static int nextId = 1;
    this->id = nextId++;
    this->action = action;
    this->nursery = nursery;
}

Customer::~Customer()
{
    delete action;
}

// request from staff
void Customer::request()
{
    // TODO: Update for
    cout << "Customer " << id << " is requesting assistance for action: " << action->getActionName() << endl;
}

void Customer::setAction(Action *newAction)
{
    if (this->action)
    {
        delete this->action;
    }
    this->action = newAction;
}

bool Customer::addToBasket(Plant *plants, int quantity)
{
    if (nursery-)
    plants->getName();
    return false;
}

bool Customer::removeFromBasket(Plant *plants, int quantity)
{
    std::cout << quantity;
    plants->getName();
    return false;
}

int Customer::getId() const
{
    return id;
}

Action *Customer::getAction() const
{
    return action;
}

// ... (other methods: addToBasket, removeFromBasket, getId, getAction) ...

void Customer::setAssignedStaff(Staff *staff)
{
    this->assignedStaff = staff;
    cout << "Customer " << id << " is now being assisted by staff member " << staff->getName() << endl;
}

void Customer::processNextAction()
{
    if (!action)
    {
        return;
    }

    // Get the next action from current state
    Action *nextAction = action->getNextAction();

    if (nextAction == nullptr)
    {
        // Customer is leaving
        qDebug() << "Customer" << id << "is leaving the nursery";

        // Only notify nursery if one is assigned (not in testing mode)
        if (nursery)
        {
            nursery->handleCustomerDeparture(this);
        }
        else
        {
            qDebug() << "Customer" << id << "departure handled in test mode (no nursery assigned)";
        }
    }
    else
    {
        // Transition to next state
        setAction(nextAction);
        qDebug() << "Customer" << id << "transitioned to" << nextAction->getActionName().c_str();
    }
}