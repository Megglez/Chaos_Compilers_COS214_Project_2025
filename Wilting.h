#ifndef WILTING_H
#define WILTING_H
#include <iostream>
using namespace std;

class Wilting : StageOfDevelopment {


public:
	void handle();

	virtual StageOfDevelopment getNextStage() = 0;

	Wilting();

	virtual ~Wilting();
};

#endif
