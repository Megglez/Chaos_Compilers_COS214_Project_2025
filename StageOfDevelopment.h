#ifndef STAGEOFDEVELOPMENT_H
#define STAGEOFDEVELOPMENT_H

class StageOfDevelopment {


public:
	virtual void handle() = 0;

	virtual StageOfDevelopment getNextStage() = 0;

	StageOfDevelopment();

	virtual ~StageOfDevelopment();
};

#endif
