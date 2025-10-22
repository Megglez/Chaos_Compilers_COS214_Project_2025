#ifndef ENQUIRE_H
#define ENQUIRE_H
#include <iostream>
using namespace std;

class Enquire : Action {


public:
	void handle();

	Action getNextAction();

	Enquire();

	virtual ~Enquire();
};

#endif
