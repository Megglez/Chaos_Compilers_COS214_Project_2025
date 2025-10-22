#ifndef FLOWERSTRATEGY_H
#define FLOWERSTRATEGY_H
#include <iostream>
using namespace std;

class FlowerStrategy : CareStrategy {


public:
	void helpPlant();

	FlowerStrategy();

	virtual ~FlowerStrategy();
};

#endif
