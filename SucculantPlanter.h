#ifndef SUCCULANTPLANTER_H
#define SUCCULANTPLANTER_H
#include <iostream>
using namespace std;

class SucculantPlanter : Planter {


public:
	Plant* planterMethod();

	SucculantPlanter();

	virtual ~SucculantPlanter();
};

#endif
