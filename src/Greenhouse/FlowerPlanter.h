#ifndef FLOWERPLANTER_H
#define FLOWERPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
#include "FlowerStrategy.h"
using namespace std;

class FlowerPlanter : public Planter {
public:
	virtual Plant* planterMethod(std::string name) override;
	FlowerPlanter();
	virtual ~FlowerPlanter();
};

#endif
