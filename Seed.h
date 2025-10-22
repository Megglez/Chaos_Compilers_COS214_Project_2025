#ifndef SEED_H
#define SEED_H

class Seed : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Seed();

	virtual void ~Seed() = 0;
};

#endif
