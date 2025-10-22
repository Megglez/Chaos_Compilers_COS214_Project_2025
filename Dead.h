#ifndef DEAD_H
#define DEAD_H
#include <iostream>
using namespace std;

class Dead : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Dead();

	virtual ~Dead();
};

#endif
