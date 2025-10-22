#ifndef DEAD_H
#define DEAD_H

class Dead : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();

	Dead();

	virtual void ~Dead() = 0;
};

#endif
