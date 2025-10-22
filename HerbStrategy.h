#ifndef HERBSTRATEGY_H
#define HERBSTRATEGY_H

class HerbStrategy : CareStrategy {


public:
	void helpPlant();

	HerbStrategy();

	virtual void ~HerbStrategy() = 0;
};

#endif
