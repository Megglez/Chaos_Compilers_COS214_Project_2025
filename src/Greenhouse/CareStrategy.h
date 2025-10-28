#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H
#include <iostream>
using namespace std;

class CareStrategy {
public:
	virtual void helpPlant(std::string& care) = 0;
	CareStrategy() {};
	virtual ~CareStrategy();
	virtual CareStrategy* clone()= 0;
};

#endif
