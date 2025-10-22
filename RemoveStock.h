#ifndef REMOVESTOCK_H
#define REMOVESTOCK_H
#include <iostream>
#include "Command.h"
using namespace std;

class RemoveStock : public Command {
public:
	bool isEmpty;
	void execute();
	RemoveStock();
	virtual ~RemoveStock();
};

#endif
