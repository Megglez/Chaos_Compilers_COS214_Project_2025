#ifndef TREESTRATEGY_H
#define TREESTRATEGY_H
#include <iostream>
using namespace std;

class TreeStrategy : public CareStrategy {


public:
	void helpPlant();

	TreeStrategy();

	virtual ~TreeStrategy();
};

#endif
