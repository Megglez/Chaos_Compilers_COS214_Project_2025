#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;

class Customer {

private:
	Action action;

public:
	void request();

	void setAction();

	Customer();

	virtual ~Customer();
};

#endif
