#ifndef WILTING_H
#define WILTING_H

class Wilting : StageOfDevelopment {


public:
	void handle();

	virtual StageOfDevelopment getNextStage() = 0;
};

#endif
