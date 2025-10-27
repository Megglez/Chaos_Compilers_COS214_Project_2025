#ifndef FLOWERSTRATEGY_H
#define FLOWERSTRATEGY_H
#include <iostream>
#include "CareStrategy.h"
using namespace std;

class FlowerStrategy : public CareStrategy 
{
public:
	virtual void helpPlant(std::string& care) override;
	FlowerStrategy();
	virtual ~FlowerStrategy();
	CareStrategy* clone();
};

#endif
