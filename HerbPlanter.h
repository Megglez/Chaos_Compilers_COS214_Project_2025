#ifndef HERBPLANTER_H
#define HERBPLANTER_H
#include <iostream>
using namespace std;

class HerbPlanter : public Planter {


public:
	Plant* planterMethod();

	HerbPlanter();

	virtual ~HerbPlanter();
};

#endif
