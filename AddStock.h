#ifndef ADDSTOCK_H
#define ADDSTOCK_H

class AddStock : Command {

public:
	bool isEmpty;

	void execute();

	AddStock();

	virtual ~AddStock();
};

#endif
