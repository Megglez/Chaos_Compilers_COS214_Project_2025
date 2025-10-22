#ifndef PRIME_H
#define PRIME_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Prime : public StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Prime();

	virtual ~Prime();
};

#endif
