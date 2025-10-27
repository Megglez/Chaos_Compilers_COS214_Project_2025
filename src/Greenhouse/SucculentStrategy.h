#ifndef SUCCULENTSTRATEGY_H
#define SUCCULENTSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class SucculentStrategy : public CareStrategy 
{
public:
	void helpPlant();
	SucculentStrategy();
	virtual ~SucculentStrategy();
};

#endif
