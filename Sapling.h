#ifndef SAPLING_H
#define SAPLING_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Sapling : public StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Sapling();

	virtual ~Sapling();
};

#endif
