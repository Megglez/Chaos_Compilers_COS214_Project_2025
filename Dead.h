#ifndef DEAD_H
#define DEAD_H

class Dead : StageOfDevelopment {


public:
	virtual StageOfDevelopment getNextStage() = 0;

	void handle();
};

#endif
