#ifndef SAPLING_H
#define SAPLING_H
#include <iostream>
using namespace std;

class Sapling : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Sapling();

	virtual ~Sapling();
};

#endif
