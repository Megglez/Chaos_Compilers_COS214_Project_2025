#ifndef ACTION_H
#define ACTION_H

class Action {


public:
	virtual void handle() = 0;

	virtual Action getNextAction() = 0;

	Action();

	virtual ~Action();
};

#endif
