#ifndef BROWSE_H
#define BROWSE_H
#include <iostream>
#include "Action.h"
using namespace std;

class Browse : public Action {
public:
	void handle();
	Action getNextAction();
	Browse();
	virtual ~Browse();
};

#endif
