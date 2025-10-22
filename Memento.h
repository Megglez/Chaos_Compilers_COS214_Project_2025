#ifndef MEMENTO_H
#define MEMENTO_H
#include <iostream>
using namespace std;

class Memento {

private:
	Action state;

	Action getAction();

	void setAction(State state);

public:
	Memento();

	virtual ~Memento();
};

#endif
