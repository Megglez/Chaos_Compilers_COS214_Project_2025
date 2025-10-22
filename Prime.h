#ifndef PRIME_H
#define PRIME_H
#include <iostream>
using namespace std;

class Prime : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Prime();

	virtual ~Prime();
};

#endif
