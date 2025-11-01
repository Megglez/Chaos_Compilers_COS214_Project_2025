#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include <QObject>
#include "Action.h"
#include "Enquire.h"
#include "Browse.h"
#include "Purchasing.h"
#include"./Greenhouse/Plant.h"
using namespace std;


class Customer : public QObject
{
private:
	Action* action;
	int id;
	vector<Plant*> basket;
	Q_OBJECT

public:
	void request();
	void setAction(string ss);
	Customer(Action* action);
	virtual ~Customer();
	bool addToBasket(Plant*plants,int quantity);
	bool removeFromBasket(Plant* plants,int quantity);
	explicit Customer(QObject *parent = nullptr) : QObject(parent) {}
};

#endif