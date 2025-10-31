#ifndef PURCHASING_H
#define PURCHASING_H
#include <iostream>
#include "Action.h"
using namespace std;

class Purchasing : public Action
{
public:
	void handle();
	Action* getNextAction();
	Purchasing();
	virtual ~Purchasing();
	std::string getActionName() override;
	virtual void requestStaffAssistance() override;

};

#endif
