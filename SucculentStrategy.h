#ifndef SUCCULENTSTRATEGY_H
#define SUCCULENTSTRATEGY_H

class SucculentStrategy : CareStrategy {


public:
	void helpPlant();

	SucculentStrategy();

	virtual void ~SucculentStrategy() = 0;
};

#endif
