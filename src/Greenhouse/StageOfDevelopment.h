#ifndef STAGEOFDEVELOPMENT_H
#define STAGEOFDEVELOPMENT_H
#include <iostream>
using namespace std;

class StageOfDevelopment {
public:
	virtual void handle();
	virtual StageOfDevelopment getNextStage();
	StageOfDevelopment();
	virtual ~StageOfDevelopment();
};

#endif
