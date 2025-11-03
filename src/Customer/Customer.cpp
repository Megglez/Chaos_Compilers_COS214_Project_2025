#include "Customer.h"
#include <QDebug> 
#include "../Staff/Staff.h"

Customer::Customer(Action* action, QObject* parent) : QObject(parent)
{
    static int nextId = 1;
	this->id = nextId++;
	this->action = action;
}

Customer::~Customer()
{
	delete action;
}

//request from staff
void Customer::request() {
    //TODO: Update for 
	cout << "Customer " << id << " is requesting assistance for action: " << action->getActionName() << endl;

}

void Customer::setAction(Action* newAction) {
    if (this->action) {
        delete this->action;
    }
    this->action = newAction;
}

bool Customer::addToBasket(Plant *plants, int quantity)
{
	std::cout << quantity;
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
    return nullptr;
}

// ... (other methods: addToBasket, removeFromBasket, getId, getAction) ...

void Customer::setAssignedStaff(Staff* staff)
{
    this->assignedStaff = staff;
    cout << "Customer " << id << " is now being assisted by staff member " << staff->getName() << endl;
}