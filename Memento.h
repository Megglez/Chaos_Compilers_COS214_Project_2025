#ifndef MEMENTO_H
#define MEMENTO_H

class Memento {

private:
	Action state;

	Action getAction();

	void setAction(State state);

public:
	Memento();

	virtual void ~Memento() = 0;
};

#endif
