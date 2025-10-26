#ifndef SUCCULENTPLANTER_H
#define SUCCULENTPLANTER_H
#include <iostream>
#include "Planter.h"
using namespace std;

class SucculentPlanter : public Planter {
public:
	Plant* planterMethod();
	SucculentPlanter();
	virtual ~SucculentPlanter();
};

#endif
