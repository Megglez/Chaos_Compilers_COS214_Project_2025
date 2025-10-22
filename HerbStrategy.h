#ifndef HERBSTRATEGY_H
#define HERBSTRATEGY_H
#include <iostream>
using namespace std;

class HerbStrategy : CareStrategy {


public:
	void helpPlant();

	HerbStrategy();

	virtual ~HerbStrategy();
};

#endif
