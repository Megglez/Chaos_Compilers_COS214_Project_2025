#ifndef WILTING_H
#define WILTING_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Wilting : public StageOfDevelopment {


public:
	void handle();

	virtual StageOfDevelopment getNextStage() = 0;

	Wilting();

	virtual ~Wilting();
};

#endif
