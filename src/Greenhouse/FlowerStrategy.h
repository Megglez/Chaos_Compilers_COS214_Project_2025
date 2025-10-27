#ifndef FLOWERSTRATEGY_H
#define FLOWERSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class FlowerStrategy : public CareStrategy 
{
public:
	void helpPlant();
	FlowerStrategy();
	virtual ~FlowerStrategy();
	CareStrategy* clone();
};

#endif
