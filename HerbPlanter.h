#ifndef HERBPLANTER_H
#define HERBPLANTER_H

class HerbPlanter : Planter {


public:
	Plant* planterMethod();

	HerbPlanter();

	virtual void ~HerbPlanter() = 0;
};

#endif
