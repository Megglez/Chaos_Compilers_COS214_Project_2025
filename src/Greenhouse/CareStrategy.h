#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H
#include <iostream>
using namespace std;

class CareStrategy {
public:
	virtual void helpPlant();
	CareStrategy() {};
	virtual ~CareStrategy();
};

#endif
