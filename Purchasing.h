#ifndef PURCHASING_H
#define PURCHASING_H

class Purchasing : Action {

public:
	State state;

	void handle();

	Action getNextAction();

	Memento createMemento();

	void setMemento(Memento memento);
};

#endif
