#ifndef ADDSTOCK_H
#define ADDSTOCK_H
#include <iostream>
using namespace std;

class AddStock : public Command {

public:
	bool isEmpty;

	void execute();

	AddStock();

	virtual ~AddStock();
};

#endif
