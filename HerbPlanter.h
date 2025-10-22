#ifndef HERBPLANTER_H
#define HERBPLANTER_H
#include <iostream>
#include "Planter.h"
using namespace std;

class HerbPlanter : public Planter {
public:
	Plant* planterMethod();
	HerbPlanter();
	virtual ~HerbPlanter();
};

#endif
