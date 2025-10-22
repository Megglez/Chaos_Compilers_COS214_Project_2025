#ifndef SUCCULENTSTRATEGY_H
#define SUCCULENTSTRATEGY_H
#include <iostream>
using namespace std;

class SucculentStrategy : public CareStrategy {


public:
	void helpPlant();

	SucculentStrategy();

	virtual ~SucculentStrategy();
};

#endif
