#ifndef FLOWERSTRATEGY_H
#define FLOWERSTRATEGY_H

class FlowerStrategy : CareStrategy {


public:
	void helpPlant();

	FlowerStrategy();

	virtual void ~FlowerStrategy() = 0;
};

#endif
