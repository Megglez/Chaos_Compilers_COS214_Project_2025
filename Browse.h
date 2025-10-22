#ifndef BROWSE_H
#define BROWSE_H

class Browse : Action {


public:
	void handle();

	Action getNextAction();

	Browse();

	virtual ~Browse();
};

#endif
