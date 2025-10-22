#ifndef PLANTER_H
#define PLANTER_H

class Planter {


public:
	virtual Plant* planterMethod() = 0;

	Planter();

	virtual void ~Planter() = 0;
};

#endif
