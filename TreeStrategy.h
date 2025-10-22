#ifndef TREESTRATEGY_H
#define TREESTRATEGY_H

class TreeStrategy : CareStrategy {


public:
	void helpPlant();

	TreeStrategy();

	virtual void ~TreeStrategy() = 0;
};

#endif
