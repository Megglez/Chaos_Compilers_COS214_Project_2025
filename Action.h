#ifndef ACTION_H
#define ACTION_H
#include <iostream>
using namespace std;

class Action {


public:
	virtual void handle() = 0;

	virtual Action getNextAction() = 0;

	Action();

	virtual ~Action();
};

#endif
