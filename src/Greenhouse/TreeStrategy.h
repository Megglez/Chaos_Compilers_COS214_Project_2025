#ifndef TREESTRATEGY_H
#define TREESTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class TreeStrategy : public CareStrategy {
public:
	virtual void helpPlant(std::string& care) override;
	TreeStrategy();
	virtual ~TreeStrategy();
};

#endif
