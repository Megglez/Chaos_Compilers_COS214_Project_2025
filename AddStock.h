#ifndef ADDSTOCK_H
#define ADDSTOCK_H
#include <iostream>
#include "Command.h"
using namespace std;

class AddStock : public Command {
public:
	bool isEmpty;
	void execute();
	AddStock();
	virtual ~AddStock();
};

#endif
