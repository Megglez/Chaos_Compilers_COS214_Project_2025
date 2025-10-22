#ifndef CUSTOMER_H
#define CUSTOMER_H

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
