#ifndef MEMENTO_H
#define MEMENTO_H

class Memento {

private:
	Action state;

	Action getAction();

	void setAction(State state);
};

#endif
