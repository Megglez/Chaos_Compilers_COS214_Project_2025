#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Action.h"
#include "Enquire.h"
#include "Browse.h"
#include "Purchasing.h"
#include"Greenhouse/Plant.h"
using namespace std;


class Customer
{
private:
	Action * action;
	int id;
	vector<Plant> *basket;



public:
	void request();
	void setAction(std::string ss);
	Customer();
	virtual ~Customer();
	bool addToBasket(Plant*plants,int quantity);
	bool removeFromBasket(Plant* plants,int quantity);
};

#endif
