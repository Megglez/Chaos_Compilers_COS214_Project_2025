#ifndef FLOWERPLANTER_H
#define FLOWERPLANTER_H

class FlowerPlanter : Planter {


public:
	Plant* planterMethod();

	FlowerPlanter();

	virtual void ~FlowerPlanter() = 0;
};

#endif
