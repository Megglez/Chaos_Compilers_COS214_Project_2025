#ifndef HERBSTRATEGY_H
#define HERBSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class HerbStrategy : public CareStrategy {
public:
	void helpPlant();
	HerbStrategy();
	virtual ~HerbStrategy();
	CareStrategy* clone();
};

#endif
