#ifndef SEED_H
#define SEED_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Seed : public StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Seed();

	virtual ~Seed();
};

#endif
