#ifndef PURCHASING_H
#define PURCHASING_H
#include <iostream>
using namespace std;

class Purchasing : public Action {

public:
	State state;

	void handle();

	Action getNextAction();

	Memento createMemento();

	void setMemento(Memento memento);

	Purchasing();

	virtual ~Purchasing();
};

#endif
