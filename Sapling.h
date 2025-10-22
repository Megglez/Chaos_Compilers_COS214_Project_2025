#ifndef SAPLING_H
#define SAPLING_H

class Sapling : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Sapling();

	virtual ~Sapling();
};

#endif
