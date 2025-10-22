#ifndef SUCCULANTPLANTER_H
#define SUCCULANTPLANTER_H

class SucculantPlanter : Planter {


public:
	Plant* planterMethod();

	SucculantPlanter();

	virtual void ~SucculantPlanter() = 0;
};

#endif
