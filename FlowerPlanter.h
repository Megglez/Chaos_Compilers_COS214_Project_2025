#ifndef FLOWERPLANTER_H
#define FLOWERPLANTER_H
#include <iostream>
#include "Planter.h"
using namespace std;

class FlowerPlanter : public Planter {
public:
	Plant* planterMethod();
	FlowerPlanter();
	virtual ~FlowerPlanter();
};

#endif
