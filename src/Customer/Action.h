#ifndef ACTION_H
#define ACTION_H
#include <iostream>
using namespace std;

class Action {
public:
	virtual void handle();
	virtual Action* getNextAction();
	virtual std::string getActionName() = 0;
	Action();
	virtual ~Action();
	virtual void requestStaffAssistance()=0;
};

#endif
