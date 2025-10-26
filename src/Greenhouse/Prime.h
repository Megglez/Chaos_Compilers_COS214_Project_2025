#ifndef PRIME_H
#define PRIME_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Prime : public StageOfDevelopment {
public:
	StageOfDevelopment getNextStage();
	void handle();
	Prime();
	virtual ~Prime();
};

#endif
