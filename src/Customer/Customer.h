#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include <QObject>
#include "Action.h"
#include "Enquire.h"
#include "Browse.h"
#include "Purchasing.h"
#include "../Staff/Staff.h"
#include "../Greenhouse/Plant.h"

class InfoDesk;
class Nursery;
using namespace std;

class Customer : public QObject
{
	Q_OBJECT

private:
	Action *action;
	int id;
	vector<Plant*> basket;
	Staff *assignedStaff = nullptr;
	Nursery *nursery;

public:
	Customer(Action *action, Nursery *nursery, QObject *parent = nullptr);
	virtual ~Customer();

	void request();
	void setAction(Action *newAction);
	void processNextAction(); // Process state transitions and handle departures

	bool addToBasket(Plant *plants, int quantity);
	bool removeFromBasket(Plant *plants, int quantity);
	bool isBasketEmpty() const { return basket.empty(); }

	int getId() const;
	Action *getAction() const;

	void setAssignedStaff(Staff *staff);
	Staff *getAssignedStaff() const { return assignedStaff; }
};

#endif