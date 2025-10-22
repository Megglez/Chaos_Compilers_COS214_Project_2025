#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

class CareStrategy {


public:
	virtual void helpPlant() = 0;

	CareStrategy();

	virtual ~CareStrategy();
};

#endif
