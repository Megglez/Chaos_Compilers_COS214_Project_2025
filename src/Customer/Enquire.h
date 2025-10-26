#ifndef ENQUIRE_H
#define ENQUIRE_H
#include <iostream>
#include "Action.h"
using namespace std;

class Enquire : public Action
{
public:
	void handle();
	Action getNextAction();
	Enquire();
	virtual ~Enquire();
};

#endif
