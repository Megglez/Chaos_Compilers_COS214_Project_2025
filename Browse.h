#ifndef BROWSE_H
#define BROWSE_H
#include <iostream>
using namespace std;

class Browse : Action {


public:
	void handle();

	Action getNextAction();

	Browse();

	virtual ~Browse();
};

#endif
