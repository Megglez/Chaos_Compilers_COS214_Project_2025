#ifndef ACTION_H
#define ACTION_H
#include <iostream>

// Forward declarations to break circular dependencies
class Customer;
class InfoDesk;
using namespace std;

class Action
{
protected:
	string name;

public:
	Action(const string &actionName) : name(actionName) {}
	virtual ~Action() {}

	virtual void handle() = 0;
	virtual void handle(Customer *customer) { handle(); } // Default implementation calls handle()
	virtual Action *getNextAction() = 0;
	virtual void requestStaffAssistance(Customer *customer, InfoDesk &desk) = 0;

	string getActionName() const { return name; }
	bool matches(const string &other_name) const { return name == other_name; }
};

#endif