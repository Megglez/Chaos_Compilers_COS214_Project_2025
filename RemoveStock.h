#ifndef REMOVESTOCK_H
#define REMOVESTOCK_H
#include <iostream>
using namespace std;

class RemoveStock : Command {

public:
	bool isEmpty;

	void execute();

	RemoveStock();

	virtual ~RemoveStock();
};

#endif
