#ifndef BROWSE_H
#define BROWSE_H

class Browse : Action {


public:
	void handle();

	Action getNextAction();

	Browse();

	virtual void ~Browse() = 0;
};

#endif
