#ifndef HERBSTRATEGY_H
#define HERBSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class HerbStrategy : public CareStrategy {
public:
	virtual void helpPlant(std::string& care) override;
	HerbStrategy();
	virtual ~HerbStrategy();
};

#endif
