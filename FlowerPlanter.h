#ifndef FLOWERPLANTER_H
#define FLOWERPLANTER_H
#include <iostream>
using namespace std;

class FlowerPlanter : Planter {


public:
	Plant* planterMethod();

	FlowerPlanter();

	virtual ~FlowerPlanter();
};

#endif
