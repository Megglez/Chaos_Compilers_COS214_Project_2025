#ifndef SUCCULENTSTRATEGY_H
#define SUCCULENTSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class SucculentStrategy : public CareStrategy 
{
public:
	virtual void helpPlant(std::string& care) override;
	SucculentStrategy();
	virtual ~SucculentStrategy();
};

#endif
