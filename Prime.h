#ifndef PRIME_H
#define PRIME_H

class Prime : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Prime();

	virtual void ~Prime() = 0;
};

#endif
