#ifndef DEAD_H
#define DEAD_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Dead : public StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Dead();

	virtual ~Dead();
};

#endif
