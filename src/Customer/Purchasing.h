#ifndef PURCHASING_H
#define PURCHASING_H
#include <iostream>
#include "Action.h"
using namespace std;

class Purchasing : public Action
{
public:
	void handle();
	virtual Action getNextAction() override;
	Purchasing();
	virtual ~Purchasing();
};

#endif
