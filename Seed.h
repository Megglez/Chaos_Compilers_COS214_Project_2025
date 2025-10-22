#ifndef SEED_H
#define SEED_H
#include <iostream>
using namespace std;

class Seed : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Seed();

	virtual ~Seed();
};

#endif
