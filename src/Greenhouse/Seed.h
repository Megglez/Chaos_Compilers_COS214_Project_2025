#ifndef SEED_H
#define SEED_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Seed : public StageOfDevelopment {
public:
	StageOfDevelopment getNextStage();
	void handle();
	Seed();
	virtual ~Seed();
};

#endif
