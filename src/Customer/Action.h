#ifndef ACTION_H
#define ACTION_H
#include <iostream>
using namespace std;

class Action {
public:
	virtual void handle();
	virtual Action getNextAction();
	Action();
	virtual ~Action();
};

#endif
