#ifndef SUCCULENTSTRATEGY_H
#define SUCCULENTSTRATEGY_H
#include <iostream>
using namespace std;

class SucculentStrategy : CareStrategy {


public:
	void helpPlant();

	SucculentStrategy();

	virtual ~SucculentStrategy();
};

#endif
