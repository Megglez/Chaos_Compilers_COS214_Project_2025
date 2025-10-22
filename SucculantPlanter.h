#ifndef SUCCULANTPLANTER_H
#define SUCCULANTPLANTER_H
#include <iostream>
#include "Planter.h"
using namespace std;

class SucculantPlanter : public Planter {
public:
	Plant* planterMethod();
	SucculantPlanter();
	virtual ~SucculantPlanter();
};

#endif
