#ifndef REMOVESTOCK_H
#define REMOVESTOCK_H

class RemoveStock : Command {

public:
	bool isEmpty;

	void execute();

	RemoveStock();

	virtual void ~RemoveStock() = 0;
};

#endif
