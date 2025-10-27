#ifndef TREESTRATEGY_H
#define TREESTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class TreeStrategy : public CareStrategy {
public:
	void helpPlant();
	TreeStrategy();
	virtual ~TreeStrategy();
};

#endif
