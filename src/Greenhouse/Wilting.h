#ifndef WILTING_H
#define WILTING_H
#include <iostream>
#include "StageOfDevelopment.h"
using namespace std;

class Wilting : public StageOfDevelopment {
public:
	void handle();
	StageOfDevelopment getNextStage();
	Wilting();
	virtual ~Wilting();
};

#endif
